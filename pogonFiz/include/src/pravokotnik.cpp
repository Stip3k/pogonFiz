#include "../header/pravokotnik.h"

pfiz::Pravokotnik::Pravokotnik(float x, float y, float w, float h) :
	Telo(x,y) {
	this->pravoKot = new sf::RectangleShape();
	Telo::nastaviStaticno(0);
	this->pravoKot->setPosition(Telo::poz);
	this->nastaviVel(w, h);
	Telo::nastaviMaso(0);
}

pfiz::Pravokotnik::~Pravokotnik() {
	delete this->pravoKot;
}

sf::RectangleShape* pfiz::Pravokotnik::vrniObliko() {
	return this->pravoKot;
}

void pfiz::Pravokotnik::nastaviVel(float x, float y) {
	sf::Vector2f vel(x, y);
	this->pravoKot->setSize(vel);
}