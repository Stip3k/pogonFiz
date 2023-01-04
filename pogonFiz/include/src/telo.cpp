#include "../header/telo.h"

pfiz::Telo::Telo(float x, float y) :
	masa(0),
	staticno(0),
	premik(0),
	vel(0,0),
	poz(x,y),
	k(0.99)
{}

pfiz::Telo::~Telo()
{
}

//Vmensiki
void pfiz::Telo::nastaviMaso(float maso) {
	this->masa = masa;
}
float pfiz::Telo::vrniMaso() {
	return this->masa;
}

void pfiz::Telo::nastaviStaticno(bool staticno) {
	this->staticno = staticno;
}
bool pfiz::Telo::vrniStaticno() {
	return this->staticno;
}

void pfiz::Telo::nastaviPremik(bool premik) {
	this->premik = premik;
}
bool pfiz::Telo::vrniPremik() {
	return this->premik;
}

void pfiz::Telo::nastaviVel(float x, float y) {
	this->vel.x = x;
	this->vel.y = y;
}
sf::Vector2f pfiz::Telo::vrniVel() {
	return this->vel;
}

void pfiz::Telo::nastaviPoz(float x, float y) {
	this->poz.x = x;
	this->poz.y = y;
}
sf::Vector2f pfiz::Telo::vrniPoz() {
	return this->poz;
}