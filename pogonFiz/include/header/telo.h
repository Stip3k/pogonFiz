#include "inc.h"

namespace pfiz {
	
	class Telo {
	protected:
		float masa;
		bool staticno, premik;
		sf::Vector2f vel, poz;
		const float k; //Kvocient za hitrost

	public:
		Telo(float x, float y);
		~Telo();

		//Vmensiki spremenljivk:
		void nastaviMaso(float masa);
		float vrniMaso();
		void nastaviStaticno(bool staticno);
		bool vrniStaticno();
		void nastaviPremik(bool premik);             
		bool vrniPremik();
		void nastaviVel(float x, float y);
		sf::Vector2f vrniVel();
		void nastaviPoz(float x, float y);
		sf::Vector2f vrniPoz();
	};
}