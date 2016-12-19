#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>

using namespace sf;


float xscale=0.46875;
float yscale=0.46875;
int window_sizex=600;
int window_sizey=600;
RenderWindow window(VideoMode(window_sizex, window_sizey), "test");

int main()
{
	int a=0;
	int b=0;

	Texture whitecheckertext;
	whitecheckertext.loadFromFile("whitechecker.png");
	Texture blackcheckertext;
	blackcheckertext.loadFromFile("blackchecker.png");

	Sprite white;
	white.setTexture(whitecheckertext);
	white.setScale(0.46875,0.46875);
	white.setPosition(300,100);
	Sprite black;
	black.setTexture(blackcheckertext);
	black.setScale(0.46875,0.46875);
	black.setPosition(100,100);

	std::stringstream mousex;
	std::stringstream mousey;
	std::stringstream as;
	std::stringstream bs;
	Color bgc(210,210,210);
	Font font;
	font.loadFromFile("arial.ttf");
	Text mousexdisp("check",font,30);
	Text mouseydisp("check",font,30);
	mousexdisp.setColor(Color::Black);
	mouseydisp.setColor(Color::Black);
	mousexdisp.setPosition(10,10);
	mouseydisp.setPosition(100,10);
	
	Time time;
	time=seconds(1);
	
	while(window.isOpen())
	{

		Event event;
		while(window.pollEvent(event))
		{
			if(event.type==Event::Closed) window.close();
		}
		window.clear(bgc);
	
		if(Keyboard::isKeyPressed(Keyboard::Escape))window.close();
		a++;b++;
		//mousex<<Mouse::getPosition(window).x;
		//mousey<<Mouse::getPosition(window).y;
		//mousexdisp.setString(std::string(mousex.str()));
		//mouseydisp.setString(std::string(mousey.str()));
		as<<a;
		bs<<b;
		mousexdisp.setString(" ");
		mouseydisp.setString(" ");
		mousexdisp.setString(std::string(as.str()));
		mouseydisp.setString(std::string(bs.str()));
		window.clear(bgc);
		
		window.draw(mousexdisp);
		window.draw(mouseydisp);
		window.draw(white);
		window.draw(black);
		window.display();
		sleep(time);
	}
	return 0;
}

