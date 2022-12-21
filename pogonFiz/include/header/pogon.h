#include "inc.h";

namespace pfiz {
	
	class Pogon {

	private:
		sf::Time dCas;

	public:
		Pogon();
		~Pogon();

		void glavnaZanka(sf::RenderWindow& okno, sf::Clock stevnik);
		void posodobi();
		void preveriDogodke();

	};
}