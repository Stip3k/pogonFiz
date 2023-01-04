#include <list>
#include <iterator>
#include <algorithm>
#include <iostream>

namespace pfiz {
	template<class telo>
	class povezanSeznamTeles {
	protected:
		std::list<telo*> seznam, seznamBrisi;

	public:
		povezanSeznamTeles() {};
		~povezanSeznamTeles() {};

		//Ce bom dodal vec moznih oblik moram spremeniti parametre
		void dodajTelo(float x, float y, float rad) {
			telo el = new telo(x, y, rad);
			seznam.push_back(el);
		}

		void dodajBrisiTabeli(telo* el) {
			seznamBrisi.push_back(el);
		}

		void brisi() {
			for (telo i : seznamBrisi) {
				if (!seznam.empty()) {
					if (seznam.begin() != seznam.end()) {
						it = std::find(seznam.begin(), seznam.end(), i);
						seznam.erase(it);
					}
					else {
						seznam.clear()
					}
				}
				delete i;
			}
		}
	};
}