#include "pogon.h"
#include "pogon.h";

void pfiz::Pogon::glavnaZanka(sf::RenderWindow& okno, sf::Clock stevnik)
{
	while (okno.isOpen()) {
		this->dCas = stevnik.restart();
		okno.clear();
		posodobi();
		okno.display();

	}
}

void pfiz::Pogon::posodobi()
{
	preveriDogodke();
}
