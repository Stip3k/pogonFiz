#include "inc.h";
#include "pogon.h";

namespace pfiz {
	
	class Svet {
	private:
		sf::RenderWindow okno;
		sf::ContextSettings nastavitve;
		int32_t oknoStil;

		sf::Clock stevnik; //getElapsedTime(), restart()
		Pogon pogon;

	public:
		Svet();
		~Svet();

		void nastaviOkno();

	};
}