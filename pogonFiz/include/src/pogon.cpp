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
	std::cout << "pritisk miske" << this->dogodek.type << std::endl;
	switch (this->dogodek.mouseButton.button) {
	case sf::Mouse::Left:
		krogi.dodajTelo(
			dogodek.mouseButton.x,
			dogodek.mouseButton.y,
			30
		);
		break;
	case sf::Mouse::Right: /*Brisi telo*/;
		break;
	}
}

void pfiz::Pogon::zakljuciPogon()
{
	kOkno->close();
}