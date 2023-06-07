#include "../header/inc.h"
#include "krog.h"

namespace pfiz {
	class krogList {
	protected:
		std::list<Krog*> seznam, seznamBrisi;


	public:
		krogList() {};
		~krogList() {};

		//Ce bom dodal vec moznih oblik moram spremeniti parametre
		void dodajTelo(Krog* el) {
			seznam.push_back(el);
		}

		void dodajBrisiTabeli(Krog* el) {
			seznamBrisi.push_back(el);
		}

		void brisi() {
			std::list<Krog*>::iterator it;
			for (Krog* i : seznamBrisi) {
				if (!seznam.empty()) {
					if (seznam.begin() != seznam.end()) {
						it = std::find(seznam.begin(), seznam.end(), i);
						seznam.erase(it);
					}
					else {
						seznam.clear();
					}
				}
				delete i;
			}
		}

		void posodobiOblike(sf::RenderWindow* kOkno, sf::Time dCas) {
			std::list<Krog*>::iterator it;
			for (it = this->seznam.begin(); it != this->seznam.end(); ++it) {
				/*Najprej preveri ali je
				 *oblika v zraku, ce je
				 *potem gravitacija vpliva
				 */
				Krog* i = *it;

				this->preveriStike(kOkno, i);
				i->premikOblike();

				/*
				sf::Vector2f poz = i->vrniObliko()->getPosition();
				std::cout << poz.x << " " << poz.y << std::endl;
				*/

				//std::cout << (float)dCas.asSeconds() << std::endl;

				i->vrniObliko()->move(i->vrniVel().x * (float)dCas.asSeconds(),
									  i->vrniVel().y * (float)dCas.asSeconds());
				kOkno->draw(*(i->vrniObliko()));

				//Posodobi vrednosti kraja oblike v razredu oblike pogona
				i->nastaviPoz(i->vrniObliko()->getPosition());
			}
		}

		void preveriStike(sf::RenderWindow* kOkno, Krog* k) {
			sf::Vector2u vel = kOkno->getSize();
			sf::Vector2f poz = k->vrniPoz();
			float r = k->vrniObliko()->getRadius()*2;
			//Preveri ali oblika pada
			if ( ((poz.y + r) < vel.y) && 
				 ((poz.x + r) < vel.x) &&
				 (poz.y > 0) && 
				 (poz.x > 0) && k->vrniTrk()) {
				k->nastaviPadec(1);
			} else {
				k->nastaviPadec(0);
				if ((poz.y + r) > vel.y) { k->vrniObliko()->setPosition(poz.x, vel.y - r); }
			}
		}

		std::size_t vrniVel() {
			return seznam.size();
		}
		
		void izprazniSeznam() {
			for (Krog* i : seznam) {
				delete i;
			}
		}

		std::list<Krog*>* vrniSeznam() {
			std::list<Krog*>* kSeznam = &this->seznam;
			return kSeznam;
		}

		bool aliPrazen() {
			if (this->seznam.empty())
				return 0;
			else
				return 1;
		}
	};
}