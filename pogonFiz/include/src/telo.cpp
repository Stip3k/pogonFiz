#include "../header/telo.h"

pfiz::Telo::Telo(float x, float y) :
	masa(0),
	g(0.f),
	staticno(0),
	premik(0),
	padec(0),
	poz(x,y),
	grav(0.f, 0.f),
	vel(0.f, 0.f)
	//velTmp(5.f, 5.f)
{}

pfiz::Telo::~Telo() {
}

void pfiz::Telo::premikOblike() {
	if (this->padec) {
		if (this->grav.y < 5.f) {
			this->grav.y += 0.01;
		}
		this->vel += this->grav;
		this->g += this->grav.y;
	} else {
		std::cout << "velja" << std::endl;
		this->vel.y -= this->g;
		this->grav.y = 0.0;
		this->g = 0.0;
	}
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

void pfiz::Telo::nastaviPadec(bool padec) {
	this->padec = padec;
}
bool pfiz::Telo::vrniPadec() {
	return this->padec;
}

void pfiz::Telo::nastaviPoz(float x, float y) {
	this->poz.x = x;
	this->poz.y = y;
}
void pfiz::Telo::nastaviPoz(sf::Vector2f v) {
	this->poz.x = v.x;
	this->poz.y = v.y;
}
sf::Vector2f pfiz::Telo::vrniPoz() {
	return this->poz;
}