#include "krogList.h"
#include "pravokotnikList.h"
#include "inc.h"

namespace pfiz {
	class UpraviteljTeles {
	protected:
		krogList krogi;
		pravokotnikList skotniki;
		sf::RenderWindow* kOkno;
		void opraviTrk(Krog* k, Krog* k2);
		void opraviTrk(Krog* k, Pravokotnik* k2);
		sf::Vector2f normalaTrka(sf::Vector2f p, sf::Vector2f d);
		float skalarniProd(sf::Vector2f rv, sf::Vector2f normala);
		float clamp(float value, float low, float high);
	public:
		UpraviteljTeles();
		~UpraviteljTeles();

		void prazniSezname();
		void posodobiOblike(sf::Time dCas);

		void dodajKrog(float x, float y, float r);
		void dodajStirikotnik(float x, float y, float w, float h);
		void stikOblik();

		void nastavikOkno(sf::RenderWindow* kOkno);
		sf::RenderWindow* vrnikOkno();
		
	};
}