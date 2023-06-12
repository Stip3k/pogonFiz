#include "../header/inc.h"
#include "./pravokotnik.h"

namespace pfiz {
	class pravokotnikList {
	protected:
		std::list<Pravokotnik*> seznam, seznamBrisi;


	public:
		pravokotnikList() {};
		~pravokotnikList() {};

		//Ce bom dodal vec moznih oblik moram spremeniti parametre
		void dodajTelo(Pravokotnik* el) {
			seznam.push_back(el);
		}

		void dodajBrisiTabeli(Pravokotnik* el) {
			seznamBrisi.push_back(el);
		}

		void brisi() {
			std::list<Pravokotnik*>::iterator it;
			for (Pravokotnik* i : seznamBrisi) {
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
			std::list<Pravokotnik*>::iterator it;
			for (it = this->seznam.begin(); it != this->seznam.end(); ++it) {
				/*Najprej preveri ali je
				 *oblika v zraku, ce je
				 *potem gravitacija vpliva
				 */
				Pravokotnik* i = *it;

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

		std::size_t vrniVel() {
			return seznam.size();
		}

		void izprazniSeznam() {
			for (Pravokotnik* i : seznam) {
				delete i;
			}
		}

		std::list<Pravokotnik*>* vrniSeznam() {
			std::list<Pravokotnik*>* kSeznam = &this->seznam;
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