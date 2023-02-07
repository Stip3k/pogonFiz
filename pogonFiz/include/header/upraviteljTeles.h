#include "krogList.h"

namespace pfiz {
	class UpraviteljTeles {
	protected:
		krogList krogi;
		sf::RenderWindow* kOkno;
		//stirikotnikList skotniki;

	public:
		UpraviteljTeles();
		~UpraviteljTeles();

		void prazniSezname();
		void posodobiOblike(sf::Time dCas);

		void dodajKrog(float x, float y, float r);
		void stikOblik();

		void nastavikOkno(sf::RenderWindow* kOkno);
		sf::RenderWindow* vrnikOkno();
		
		//void dodajStirikotnik();
		//bool stikaTockaStirikotnik();
	};
}