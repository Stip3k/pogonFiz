#include "svet.h"
#include "svet.h"

pfiz::Svet::Svet()
{
	nastaviOkno();
}

void pfiz::Svet::nastaviOkno()
{
	okno.setFramerateLimit(60);
	window_style = sf::Style::Default;
	nastavitve.antialiasingLevel = 4;

	this->okno.create(
		sf::VideoMode(1920, 1080),
		"pogonFiz",
		window_style,
		nastavitve
	);
}
