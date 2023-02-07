#include "../header/upraviteljTeles.h"

pfiz::UpraviteljTeles::UpraviteljTeles() {

}
pfiz::UpraviteljTeles::~UpraviteljTeles() {

}

void pfiz::UpraviteljTeles::prazniSezname() {
	this->krogi.izprazniSeznam();
	//this->skotniki.prazniSeznam();
}
void pfiz::UpraviteljTeles::posodobiOblike(sf::Time dCas) {
	this->stikOblik();
	krogi.posodobiOblike(this->kOkno, dCas);
}

void pfiz::UpraviteljTeles::dodajKrog(float x, float y, float r) {
	std::list<Krog*> tmp = this->krogi.vrniSeznam();
	for (Krog* i : tmp) {
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

void pfiz::UpraviteljTeles::stikOblik() {
	if (this->krogi.aliPrazen()) {
		std::list<Krog*>::iterator it;
		for (it = this->krogi.vrniSeznam().begin(); it != this->krogi.vrniSeznam().end(); ++it) {

			Krog* k = *it;

			if (this->krogi.preveriStikKroga(k)) {
				std::cout << "trk" << std::endl;
			}
			//Preveri se za stike s stirikotniki
		}
	}
	//Enako ponovi za stirikotnike
}

void pfiz::UpraviteljTeles::nastavikOkno(sf::RenderWindow* kOkno) {
	this->kOkno = kOkno;
}
sf::RenderWindow* pfiz::UpraviteljTeles::vrnikOkno() {
	return this->kOkno;
}