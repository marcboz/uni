#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


int main()
{
  	 int keyonoff=1;
   
	sf::RenderWindow window(sf::VideoMode(800, 600), "Nasze okno");
	sf::CircleShape shape(400.f);
	shape.setFillColor(sf::Color::Red);


	while (window.isOpen())   	 // dopoki okno jest otwarte...
	{


   	 // w tym obiekcie klasy sf::Event
   	 // bedziemy mieli informacje co zrobil uzytkownik
    	sf::Event event;
       	 
    	while (window.pollEvent(event))
    	{
        	// uzytkownik kliknal zamkniecie  okna
        	if (event.type == sf::Event::Closed)
   		 	window.close();
   			 
   	 	// uzytkownik nacisnal klawisz
   	 	if(event.type== sf::Event::KeyPressed)
   			 keyonoff=1-keyonoff;
    }
    
	// czyszczenie (na czarno)
    window.clear(sf::Color::Black);




    // rysuj kolo w zaleznosci od stanu zmiennej keyonoff
    if(keyonoff)   	 
    	window.draw(shape);
       
	window.display();
	}
	return 0;
}

