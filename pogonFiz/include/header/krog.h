#include "inc.h"
#include "telo.h"

namespace pfiz {

	class Krog: public Telo{
	protected:
		sf::CircleShape* krog;
		float radij;
		
	public:
		Krog(float x, float y, float rad);
		~Krog();

		sf::CircleShape* vrniObliko();
		/*
		Pravokotnik* vrniSled();
		void nastaviSled(Pravokotnik* k);
		*/

		//Upravljanje z obliko
	};
}