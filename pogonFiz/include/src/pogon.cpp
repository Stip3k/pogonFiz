#include "../header/pogon.h"

pfiz::Pogon::Pogon() {

}

pfiz::Pogon::~Pogon() {

}

void pfiz::Pogon::glavnaZanka(sf::RenderWindow& okno, sf::Clock stevnik)
{
	kOkno = &okno;

	while (kOkno->isOpen()) {
		this->dCas = stevnik.restart();
		
		kOkno->clear();
		posodobi();
		kOkno->display();
	}
}

void pfiz::Pogon::posodobi()
{
	preveriDogodke();
}

void pfiz::Pogon::preveriDogodke()
{
	while (kOkno->pollEvent(this->dogodek))
	{
		switch (this->dogodek.type) {
			case sf::Event::Closed: zakljuciPogon(); break;
			case sf::Event::MouseButtonPressed: pritisMiska(); break;
		}
	}
}

void pfiz::Pogon::pritisMiska()
{
	switch (this->dogodek.type) {
		case sf::Mouse::Left: /*Stvari entiteto*/; break;
		case sf::Mouse::Right: /*Brisi entiteto*/; break;
	}
}

void pfiz::Pogon::zakljuciPogon()
{
	kOkno->close();
}