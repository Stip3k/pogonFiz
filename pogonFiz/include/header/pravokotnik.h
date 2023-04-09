#include "./inc.h"
#include "telo.h"

namespace pfiz {

	class Pravokotnik: public Telo {
	protected:
		sf::RectangleShape* pravoKot;

	public:
		Pravokotnik(float x, float y, float w, float h);
		~Pravokotnik();

		sf::RectangleShape* vrniObliko();
		void nastaviVel(float x, float y);
	};
}