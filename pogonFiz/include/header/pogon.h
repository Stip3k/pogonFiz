#include "inc.h"
#include "upraviteljTeles.h"

//Moram odstraniti ta namespace za pogon, ker ni del njega
namespace pfiz {
	
	class Pogon {

	private:
		sf::Time dCas;
		sf::Event dogodek;
		sf::RenderWindow* kOkno;
		UpraviteljTeles upravTel;

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