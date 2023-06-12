#include "../header/upraviteljTeles.h"

pfiz::UpraviteljTeles::UpraviteljTeles() {
	srand(time(NULL));
}
pfiz::UpraviteljTeles::~UpraviteljTeles() {

}

void pfiz::UpraviteljTeles::prazniSezname() {
	this->krogi.izprazniSeznam();
	this->skotniki.izprazniSeznam();
}
void pfiz::UpraviteljTeles::posodobiOblike(sf::Time dCas) {
	this->stikOblik();
	krogi.posodobiOblike(this->kOkno, dCas);
	skotniki.posodobiOblike(this->kOkno, dCas);
}

void pfiz::UpraviteljTeles::dodajKrog(float x, float y, float r) {
	std::list<Krog*>* tmp = this->krogi.vrniSeznam();
	for (Krog* i : *tmp) {
		sf::Vector2f krog = i->vrniObliko()->getPosition();
		float d = (std::pow((x - krog.x), 2)) + (std::pow((y - krog.y), 2));
		if (r * 2 >= std::sqrt(d)) {
			//Izpis podatkov stika:
			//std::cout << krog.x << ";" << krog.y << ", " << x << ";" << y << ", " << std::sqrt(d) << std::endl;
			break;
		}
	}
	Krog* el = new Krog(x, y, r);
	krogi.dodajTelo(el);
}

void pfiz::UpraviteljTeles::dodajStirikotnik(float x, float y, float w, float h) {
	Pravokotnik* el = new Pravokotnik(x, y, w, h);
	skotniki.dodajTelo(el);
}

void pfiz::UpraviteljTeles::stikOblik() {
	if (this->krogi.aliPrazen() && (this->krogi.vrniSeznam()->size() > 0)) {
		std::list<Krog*>::iterator it;
		for (it = this->krogi.vrniSeznam()->begin(); it != this->krogi.vrniSeznam()->end(); ++it) {

			Krog* k = *(it);
			
			std::list<Krog*>::iterator it2;
			for (it2 = this->krogi.vrniSeznam()->begin(); it2 != this->krogi.vrniSeznam()->end(); ++it2) {
				
				Krog* k2 = *(it2);
				
				if (k != k2) {
					sf::Vector2f krog = k->vrniPoz();
					sf::Vector2f krog2 = k2->vrniPoz();
					double dx = krog2.x - krog.x;
					double dy = krog2.y - krog.y;
					float d = std::sqrt(dx * dx + dy * dy);
					float r = 30.0;//k->vrniObliko()->getRadius();
					float r2 = 30.0;//->vrniObliko()->getRadius();
					if (d < (r + r2)) {
						this->opraviTrk(k, k2);
					}
				}
			}
			std::list<Pravokotnik*>::iterator it3;
			for(it3 = this->skotniki.vrniSeznam()->begin(); it3 != this->skotniki.vrniSeznam()->end(); ++it3) {

				Pravokotnik* p2 = *(it3);

				sf::Vector2f closest;
				sf::Vector2f v2 = p2->vrniObliko()->getSize();

				sf::Vector2f poz;
				float radijKroga = k->vrniObliko()->getRadius();
				poz = k->vrniObliko()->getPosition();
				poz.x += radijKroga; poz.y += radijKroga;


				sf::Vector2f pozP;
				pozP = p2->vrniObliko()->getPosition();

				if ((((poz.x >= pozP.x) && (poz.x <= (pozP.x + v2.x))) &&
					((poz.y >= pozP.y) && (poz.y <= (pozP.y + v2.y))))) {
					k->nastaviTrk(0);

					closest.x = poz.x;
					closest.y = poz.y;

					//closest, pozp
					double xDal = closest.x - pozP.x;
					double yDal = closest.y - pozP.y;
					float radijPravo = std::sqrt(std::pow(2, xDal) + std::pow(2, yDal));

					double dx = pozP.x - poz.x;
					double dy = pozP.y - poz.y;
					float d = std::sqrt(dx * dx + dy * dy);

					if (d < (radijKroga + radijPravo)) {
						std::cout << "Orpavi trk---------------------" << std::endl;
						std::cout << closest.x << " --- " << closest.y << std::endl;

						this->opraviTrk(k, p2);
						k->nastaviVel(k->vrniVel().x, k->vrniVel().y-k->vrniGrav());
					}
				}
				else {
					k->nastaviTrk(1);
				}
			}
			this->preveriStike(kOkno, k);
		}
	}
}

void pfiz::UpraviteljTeles::opraviTrk(Krog* k, Krog* k2) {
	sf::Vector2f kVel = k->vrniVel();
	sf::Vector2f k2Vel = k2->vrniVel();

	sf::Vector2f rv = kVel - k2Vel;

	sf::Vector2f normala = this->normalaTrka(k->vrniPoz(), k2->vrniPoz());
	float velNormale = this->skalarniProd(rv, normala);

	if (velNormale > 0) return; //Telesa se ne priblizujeta

	float povrnitevTelesa = std::min(k->vrniPov(), k2->vrniPov());
	float impSkalar = -(1 + povrnitevTelesa) * velNormale;//Sila skozi cas trka
	sf::Vector2f impulz = impSkalar * normala;

	std::cout <<  "--Krog-Krog--" <<std::endl;
	std::cout << "Normala trka, x: " << normala.x << " in y: " << normala.y << std::endl;
	std::cout << "Vrednost impSkalar: " << impSkalar << std::endl;
	std::cout << "Vrednost impulza odboja: x= " << impulz.x << " y= " << impulz.y << std::endl;

	k->nastaviVel(kVel + (1/k->vrniMaso()*impulz));
	k2->nastaviVel(k2Vel - (1 / k2->vrniMaso() * impulz));
}

//Preverjanje trkov med krogi in pravokotniki
void pfiz::UpraviteljTeles::opraviTrk(Krog* k, Pravokotnik* k2) {
	std::cout << "--Pravokotnik--" << std::endl;

	sf::Vector2f kVel = k->vrniVel();
	sf::Vector2f k2Vel = k2->vrniVel();
	sf::Vector2f rv = kVel - k2Vel;

	std::cout << "Velocity: " << rv.x << " in y: " << rv.y << std::endl;

	sf::Vector2f normala = this->normalaTrka(k->vrniObliko()->getPosition(), k2->vrniObliko()->getPosition());
	double velNormale = this->skalarniProd(rv, normala);

	if (velNormale > 0) {
		return;
	}

	float povrnitevTelesa = 10;// k->vrniPov();
	float impSkalar = -(1 + povrnitevTelesa) * velNormale;//Sila skozi cas trka
	sf::Vector2f impulz = impSkalar* normala;

	std::cout << "VelNormale: " << velNormale<< std::endl;
	std::cout << "Normala trka, x: " << normala.x << " in y: " << normala.y << std::endl;
	std::cout << "Vrednost impSkalar: " << impSkalar << std::endl;
	std::cout << "Vrednost impulza odboja: x= " << impulz.x << " y= " << impulz.y << std::endl;

	k->nastaviVel(kVel + (1 / k->vrniMaso()) * impulz);
}

void pfiz::UpraviteljTeles::nastavikOkno(sf::RenderWindow* kOkno) {
	this->kOkno = kOkno;
}
sf::RenderWindow* pfiz::UpraviteljTeles::vrnikOkno() {
	return this->kOkno;
}

sf::Vector2f pfiz::UpraviteljTeles::normalaTrka(sf::Vector2f p, sf::Vector2f d) {
	sf::Vector2f normala;

	normala.x = p.x - d.x;
	normala.y = p.y - d.y;

	normala.x = normala.x / std::sqrt(std::pow(normala.x, 2) + std::pow(normala.y, 2));
	normala.y = normala.y / std::sqrt(std::pow(normala.x, 2) + std::pow(normala.y, 2));

	return normala;
}

double pfiz::UpraviteljTeles::skalarniProd(sf::Vector2f rv, sf::Vector2f normala) {
	double sp;
	sp = (rv.x * normala.x) + (rv.y * normala.y);
	return sp;
}

void pfiz::UpraviteljTeles::preveriStike(sf::RenderWindow* kOkno, Krog* k) {
	sf::Vector2u vel = kOkno->getSize();
	sf::Vector2f poz = k->vrniObliko()->getPosition();
	float r = k->vrniObliko()->getRadius() * 2;
	//Preveri ali oblika pada
	if (((poz.y + r) < vel.y) &&
		((poz.x + r) < vel.x) &&
		(poz.y > 0) &&
		(poz.x > 0) && k->vrniTrk()) {
		k->nastaviPadec(1);
	}
	else {
		std::cout << "--Rob--" << std::endl;

		sf::Vector2f rv = k->vrniVel();
		sf::Vector2f normala;
		sf::Vector2f tmp = k->vrniPoz();

		if ((poz.y + r) > vel.y) {
			k->vrniObliko()->setPosition(tmp.x, vel.y - r);
			tmp.y = tmp.y + r;
		}
		else if ((poz.x + r) > vel.x) {
			k->vrniObliko()->setPosition(vel.x - r, tmp.y);
			rv.x *= -1;
			tmp.x = tmp.x + r;
		}
		else if (poz.y < 0) {
			k->vrniObliko()->setPosition(poz.x, 0);
			rv.y *= -1;
			tmp.y = tmp.y - r;
		}
		else if (poz.x < 0) {
			k->vrniObliko()->setPosition(0, poz.y);
			rv.x *= -1;
			tmp.x = tmp.x - r;
		}
		
		k->nastaviVel(rv);
		k->nastaviPadec(0);
	}

}