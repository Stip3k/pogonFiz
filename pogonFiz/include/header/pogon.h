#include "inc.h";
#include "../header/telesaList.h"
#include "../header/krog.h"

namespace pfiz {
	
	class Pogon {

	private:
		sf::Time dCas;
		sf::Event dogodek;
		sf::RenderWindow* kOkno;
		povezanSeznamTeles<Krog> krogi;

		//Objekt za upravljanje z entitetami

	public:
		Pogon();
		~Pogon();

		void glavnaZanka(sf::RenderWindow& okno, sf::Clock stevnik);
		void posodobi();
		void zakljuciPogon();

		//Funkcije za preverjanje dogodkov:
		void preveriDogodke();
		void pritisMiska();
	};
}