#pragma once

#include "inc.h"

namespace pfiz {
	
	class Telo {
	protected:
		float masa, g, povrnitev;//Povrnitev se uporablja za odboj pri trkih
		bool staticno, padec, trk;
		sf::Vector2f poz, grav, vel, velTmp;

	public:
		Telo(float x, float y);
		~Telo();

		void premikOblike();
		void trkRegresija();//Samo dekl. nisem se nic def.
		void spremnGrav(float g);

		//Vmensiki spremenljivk:
		void nastaviMaso(float masa);
		float vrniMaso();

		void nastaviStaticno(bool staticno);
		bool vrniStaticno();

		void nastaviVel(float x, float y);
		void nastaviVel(sf::Vector2f v);
		sf::Vector2f vrniVel();

		void nastaviPadec(bool padec);
		bool vrniPadec();
		
		void nastaviPoz(sf::Vector2f v);
		void nastaviPoz(float x, float y);
		sf::Vector2f vrniPoz();

		float vrniPov();
		void nastaviPov(float pov);

		float vrniGrav();
		void nastaviGrav(float pov);

		void nastaviTrk(bool trk);
		bool vrniTrk();
	};
}