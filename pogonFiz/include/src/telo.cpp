#include "../header/telo.h"

pfiz::Telo::Telo(float x, float y) :
	masa((rand() % 5 + 1)*10),
	g(0.f),
	povrnitev(1 / ((rand() % 1000 + 1))),
	staticno(1),
	padec(0),
	poz(x,y),
	grav(0.f, 0.f),
	vel(0.f, 0.f),
	trk(1)
{}

pfiz::Telo::~Telo() {
}

void pfiz::Telo::premikOblike() {
	if (this->staticno) {
		if (this->padec) {
			if (this->grav.y < 5.f) {
				this->grav.y += (1 / this->masa);
			}
			this->vel += this->grav;
			this->g += this->grav.y;
		}
		else {
			this->vel.y -= this->g;
			this->grav.y = 0.0;
			this->g = 0.0;
		}
	}
}

void pfiz::Telo::spremnGrav(float g) {
	this->vel.y += g;
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

void pfiz::Telo::nastaviVel(float x, float y) {
	this->vel.x = x;
	this->vel.y = y;
}
void pfiz::Telo::nastaviVel(sf::Vector2f v) {
	this->vel.x = v.x;
	this->vel.y = v.y;
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

float pfiz::Telo::vrniPov() {
	return this->povrnitev;
}

void pfiz::Telo::nastaviPov(float pov) {
	this->povrnitev = pov;
}

float pfiz::Telo::vrniGrav() {
	return this->povrnitev;
}
void pfiz::Telo::nastaviGrav(float pov) {
	this->g = pov;
}

void pfiz::Telo::nastaviTrk(bool trk) {
	this->trk = trk;
}
bool pfiz::Telo::vrniTrk() {
	return this->trk;
}