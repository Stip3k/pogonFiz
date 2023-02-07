#include "../header/krog.h"

pfiz::Krog::Krog(float x, float y, float rad) : 
	Telo(x,y), radij(rad) {
	this->krog = new sf::CircleShape();
	this->krog->setRadius(rad);
	this->krog->setPosition(Telo::poz);
}

pfiz::Krog::~Krog() {
	delete this->krog;
}

sf::CircleShape* pfiz::Krog::vrniObliko() {
	return this->krog;
}