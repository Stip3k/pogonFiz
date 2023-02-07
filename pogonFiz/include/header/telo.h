#include "inc.h"

namespace pfiz {
	
	class Telo {
	protected:
		float masa, g;
		bool staticno, premik, padec;
		sf::Vector2f poz, grav, vel, velTmp;

	public:
		Telo(float x, float y);
		~Telo();

		void premikOblike();
		void trkRegresija();//Samo dekl. nisem se nic def.

		//Vmensiki spremenljivk:
		void nastaviMaso(float masa);
		float vrniMaso();

		void nastaviStaticno(bool staticno);
		bool vrniStaticno();

		void nastaviPremik(bool premik);             
		bool vrniPremik();

		void nastaviVel(float x, float y);
		sf::Vector2f vrniVel();

		void nastaviPadec(bool padec);
		bool vrniPadec();
		
		void nastaviPoz(sf::Vector2f v);
		void nastaviPoz(float x, float y);
		sf::Vector2f vrniPoz();
	};
}