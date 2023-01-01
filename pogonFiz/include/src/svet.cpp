#include "../header/svet.h"

pfiz::Svet::Svet()
{
	nastaviOkno();
	this->pogon.glavnaZanka(this->okno, stevnik);
}

pfiz::Svet::~Svet()
{
}

void pfiz::Svet::nastaviOkno()
{
	okno.setFramerateLimit(60);
	nastavitve.antialiasingLevel = 4;

	this->okno.create(
		sf::VideoMode(1920, 1080),
		"pogonFiz",
		sf::Style::Default,
		nastavitve
	);
}
