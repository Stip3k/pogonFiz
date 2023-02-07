#include "../header/pogon.h"

pfiz::Pogon::Pogon() {

}

pfiz::Pogon::~Pogon() {

}

void pfiz::Pogon::glavnaZanka(sf::RenderWindow& okno, sf::Clock stevnik)
{
	kOkno = &okno;
	upravTel.nastavikOkno(&okno);

	while (kOkno->isOpen()) {
		this->dCas = stevnik.restart();
		
		kOkno->clear();
		this->posodobi();
		kOkno->display();
	}
}

void pfiz::Pogon::posodobi()
{
	/*
	* Preveri dogodke
	* Posodobi oblike: (
		preveri trke,
		premik,
		...
	  )
	* Risi oblike
	*/
	this->upravTel.posodobiOblike(this->dCas);
	this->preveriDogodke();

	//Risi oblike
	this->upravTel.posodobiOblike(this->dCas);
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
	std::cout << "pritisk miske" << std::endl;
	switch (this->dogodek.mouseButton.button) {
	case sf::Mouse::Left: {
		//Preveri ali je kliknil na ze obstojeco obliko,
		//ce je potem ne ustvari nove.
		this->upravTel.dodajKrog(
			(float)dogodek.mouseButton.x - 30.0,
			(float)dogodek.mouseButton.y - 30.0,
			30.0
		);
	}
		break;
	case sf::Mouse::Right: /*Brisi telo*/;
		break;
	}
}

void pfiz::Pogon::zakljuciPogon()
{
	std::cout << "...brisanje elementov in zapiranje pogona.";
	this->upravTel.prazniSezname();
	kOkno->close();
}