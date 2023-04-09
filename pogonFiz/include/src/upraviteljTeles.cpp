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
	Pravokotnik* el = new Pravokotnik(x, y, w,h);
	skotniki.dodajTelo(el);
}

void pfiz::UpraviteljTeles::stikOblik() {
	if (this->krogi.aliPrazen() && (this->krogi.vrniSeznam()->size() > 1)) {
		std::list<Krog*>::iterator it;
		for (it = this->krogi.vrniSeznam()->begin(); it != this->krogi.vrniSeznam()->end(); ++it) {

			Krog* k = *(it);
			
			std::list<Krog*>::iterator it2;
			for (it2 = this->krogi.vrniSeznam()->begin(); it2 != this->krogi.vrniSeznam()->end(); ++it2) {
				
				Krog* k2 = *(it2);
				
				/*//Manj ucinkovito in natancno
					if (k != k2) {
						if (k->vrniObliko()->getGlobalBounds().intersects(
							k2->vrniObliko()->getGlobalBounds())) {
							this->opraviTrk(k, k2);
						}
					}
				*/
				
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

				//if (k->vrniObliko()->getGlobalBounds().intersects(
					//p2->vrniObliko()->getGlobalBounds())) {
					this->opraviTrk(k, p2);
				//}
		
			}
		}
	}
}

void pfiz::UpraviteljTeles::opraviTrk(Krog* k, Krog* k2) {
	sf::Vector2f kVel = k->vrniVel();
	sf::Vector2f k2Vel = k2->vrniVel();

	sf::Vector2f rv = kVel - k2Vel;

	sf::Vector2f normala = this->normalaTrka(k->vrniPoz(), k2->vrniPoz());
	float velNormale = this->skalarniProd(rv, normala);

	if (velNormale > 0) return; //Telesa se en priblizujeta

	float povrnitevTelesa = std::min(k->vrniPov(), k2->vrniPov());
	float impSkalar = -(1 + povrnitevTelesa) * velNormale;//Sila skozi cas trka
	sf::Vector2f impulz = impSkalar * normala;


	k->nastaviVel(kVel + (1/k->vrniMaso()*impulz));
	k2->nastaviVel(k2Vel - (1 / k2->vrniMaso() * impulz));
}

void pfiz::UpraviteljTeles::opraviTrk(Krog* k, Pravokotnik* k2) {
	sf::Vector2f kVel = k->vrniVel();
	sf::Vector2f k2Vel = k2->vrniVel();

	sf::Vector2f rv = kVel - k2Vel;

	sf::Vector2f closest;
	sf::Vector2f v2 = k2->vrniObliko()->getSize();

	sf::Vector2f poz;
	poz = k->vrniObliko()->getPosition();

	closest.x = clamp(poz.x, k2->vrniPoz().x - v2.x, k2->vrniPoz().x + v2.x );
	closest.y = clamp(poz.y, k2->vrniPoz().y - v2.y, k2->vrniPoz().y + v2.y );

	//std::cout << poz.x << " poz " << poz.y << std::endl;
	//std::cout << poz.x << " je med " << k2->vrniPoz().x - v2.x << " - " << k2->vrniPoz().x + v2.x << std::endl;
	//std::cout << closest.x << " closest " << closest.y << std::endl;

	// Check if the closest point is inside the circle
	sf::Vector2f dist = closest - k->vrniPoz();


	if (std::sqrt(dist.x * dist.x + dist.y * dist.y) > k->vrniObliko()->getRadius()) {
		return;
	}

	sf::Vector2f normala = dist / std::sqrt(dist.x * dist.x + dist.y * dist.y);
	float velNormale = this->skalarniProd(rv, normala);

	if (velNormale > 0) { return; }

	float povrnitevTelesa = std::min(k->vrniPov(), k2->vrniPov());
	float impSkalar = -(1 + povrnitevTelesa) *velNormale; // Sila skozi cas trka
	sf::Vector2f impulz = impSkalar * normala;

	k->nastaviVel(kVel + (1 / k->vrniMaso() * impulz));
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

float pfiz::UpraviteljTeles::skalarniProd(sf::Vector2f rv, sf::Vector2f normala) {
	float sp;
	sp = (rv.x * normala.x) + (rv.y * normala.y);
	return sp;
}

float pfiz::UpraviteljTeles::clamp(float value, float low, float high) {
	return (value < low) ? low : ((value > high) ? high : value);
}