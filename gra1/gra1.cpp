#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;


float xscale=0.46875;
float yscale=0.46875;
int window_sizex=600;
int window_sizey=600;
RenderWindow window(VideoMode(window_sizex, window_sizey), "gra");
bool movedone=false;
int player_side,init_pos_white,init_pos_black;

void menu(Sprite &white,Sprite &black)
{
	bool enter_pressed=false;
	bool menu_is_open=true;
	Font font;
	font.loadFromFile("arial.ttf");
	Text welcome("WARCABY",font,100);
	welcome.setColor(Color::Black);
	welcome.setStyle(Text::Bold);
	Text welcome2("Nacisnij Spacje aby kontynuowac",font,30);
	welcome2.setColor(Color::Blue);
	Text selection("Wybierz swoj kolor pionkow",font,30);
	selection.setColor(Color::Black);
	Color bgrcolor(210,210,210);

	welcome.setPosition(50,10);
	welcome2.setPosition(75,270);
	selection.setPosition(100,100);
	white.setPosition(100,300);
	black.setPosition(400,300);

	while(menu_is_open==true)
	{
		window.clear(Color::White);
		while(enter_pressed==false)
		{
			Event event;
			while(window.pollEvent(event))
			{
				if(event.type==Event::Closed) window.close();
			}
			window.clear(Color::White);
			window.draw(welcome);
			window.draw(welcome2);
			if(Keyboard::isKeyPressed(Keyboard::Space))
			{
				while(menu_is_open==true)
				{
					while(window.pollEvent(event))
					{
						if(event.type==Event::Closed) window.close();
					}
					window.clear(bgrcolor);
					window.draw(selection);
					window.draw(black);
					window.draw(white);
					window.display();
					if(white.getGlobalBounds().contains(Mouse::getPosition(window).x,Mouse::getPosition(window).y)&&Mouse::isButtonPressed(Mouse::Left))
					{
						player_side=0;
						menu_is_open=false;
					}
					if(black.getGlobalBounds().contains(Mouse::getPosition(window).x,Mouse::getPosition(window).y)&&Mouse::isButtonPressed(Mouse::Left))
					{
						player_side=1;
						menu_is_open=false;
					}

				}
				enter_pressed=true;
			}
			window.display();
		}
	}

}

Vector2f setupWhite(Vector2f position[20])
{
	float xposition_step,yposition_step;
	int rowcount=0,colcount=0,oddrow;
	int position_null_white=0;
	int count;

	xposition_step=(128*xscale)*2;
	yposition_step=(128*yscale);

	for(count=0;count<20;count++)
	{
		if(colcount>0&&colcount%5==0)
		{
			colcount=0;
			rowcount++;
		}
		if(rowcount>0&&rowcount%2!=0)oddrow=xposition_step/2;
		else oddrow=0;
		position[count].x=position_null_white+xposition_step*colcount+oddrow;
		position[count].y=position_null_white+yposition_step*rowcount;
		colcount++;
	}

}
Vector2f setupBlack(Vector2f position[20])
{
	float xposition_step,yposition_step;
	int rowcount=0,colcount=0,oddrow;
	float xposition_null_black,yposition_null_black;
	int count;

	xposition_null_black=1280*xscale;
	yposition_null_black=1280*yscale;

	xposition_step=(128*xscale)*2;
	yposition_step=(128*yscale);


	for(count=0;count<20;count++)
	{
		if(colcount>0&&colcount%5==0)
		{
			colcount=0;
			rowcount++;
		}
		if(rowcount>0&&rowcount%2!=0)oddrow=xposition_step/2;
		else oddrow=0;
		position[count].x=xposition_null_black-(xposition_step*colcount+oddrow)-xposition_step/2;
		position[count].y=yposition_null_black-(yposition_step*rowcount)-yposition_step;
		colcount++;
	}
}
Vector2f setupTile(Vector2f position[20])
{
	float xposition_step,yposition_step;
	int rowcount=0,colcount=0,oddrow,count;

	xposition_step=(128*xscale)*2;
	yposition_step=(128*yscale);

	for(count=0;count<50;count++)
	{
		if(colcount>0&&colcount%5==0)
		{
			colcount=0;
			rowcount++;
		}
		if(rowcount>0&&rowcount%2!=0)oddrow=xposition_step/2;
		else oddrow=0;
		position[count].x=xposition_step*colcount+oddrow;
		position[count].y=yposition_step*rowcount;
		colcount++;
	}
}
void setup(Vector2f *setup_position_tile,Vector2f *setup_position_white,Vector2f *setup_position_black,Sprite *white,Sprite *black,RectangleShape *tile)
{
	int count;
	setupTile(setup_position_tile);
	for(count=0;count<50;count++)
	{
		tile[count].setPosition(setup_position_tile[count]);
		if(count==49);
	}
	setupWhite(setup_position_white);
	for(count=0;count<20;count++)
	{
		white[count].setPosition(setup_position_white[count]);
		if(count==19);
	}
	setupBlack(setup_position_black);
	for(count=0;count<20;count++)
	{
		black[count].setPosition(setup_position_black[count]);
		if(count==19);
	}

}
void draw_checkers(Sprite *white,Sprite *black)
{
	int count;
	for(count=0;count<20;count++)
	{
		window.draw(white[count]);
		window.draw(black[count]);
	}

}
bool move_allowed_white(Sprite *white,RectangleShape *tile,Sprite *black)
{
	bool tilegood=false;

	if((init_pos_white!=0||init_pos_white!=10||init_pos_white!=20||init_pos_white!=30||init_pos_white!=40||init_pos_white!=9||init_pos_white!=19||init_pos_white!=29||init_pos_white!=39)&&(init_pos_white+4<=49&&init_pos_white+5<=49))
	{
		if((init_pos_white>0&&init_pos_white<5)||(init_pos_white>10&&init_pos_white<15)||(init_pos_white>20&&init_pos_white<25)||(init_pos_white>30&&init_pos_white<35)||(init_pos_white>40&&init_pos_white<45))
		{
			if((tile[init_pos_white+4].getGlobalBounds().contains(Mouse::getPosition(window).x,Mouse::getPosition(window).y)||(tile[init_pos_white+5].getGlobalBounds().contains(Mouse::getPosition(window).x,Mouse::getPosition(window).y))))tilegood=true;
			for(int count=0;count<20;count++)
			{
				if((init_pos_white!=4||init_pos_white!=14||init_pos_white!=24||init_pos_white!=34)&&(init_pos_white<=39))
				{
					if(black[count].getPosition()==tile[init_pos_white+4].getPosition())
					{
						if(tile[init_pos_white+9].getGlobalBounds().contains(Mouse::getPosition(window).x,Mouse::getPosition(window).y))tilegood=true;
					}
					if(black[count].getPosition()==tile[init_pos_white+5].getPosition())
					{
						if(tile[init_pos_white+11].getGlobalBounds().contains(Mouse::getPosition(window).x,Mouse::getPosition(window).y))tilegood=true;
					}
				}
				if((init_pos_white==4||init_pos_white==14||init_pos_white==24||init_pos_white==34)&&(init_pos_white<=39))
				{
					if(black[count].getPosition()==tile[init_pos_white+4].getPosition())
					{
						if(tile[init_pos_white+9].getGlobalBounds().contains(Mouse::getPosition(window).x,Mouse::getPosition(window).y))tilegood=true;
					}
				}
			}
		}
		if((init_pos_white>5&&init_pos_white<10)||(init_pos_white>15&&init_pos_white<20)||(init_pos_white>25&&init_pos_white<30)||(init_pos_white>35&&init_pos_white<40)||(init_pos_white>45&&init_pos_white<50))
		{
			if((tile[init_pos_white+5].getGlobalBounds().contains(Mouse::getPosition(window).x,Mouse::getPosition(window).y)||(tile[init_pos_white+6].getGlobalBounds().contains(Mouse::getPosition(window).x,Mouse::getPosition(window).y))))tilegood=true;
			for(int count=0;count<20;count++)
			{
				if((init_pos_white!=9||init_pos_white!=19||init_pos_white!=29||init_pos_white!=39)&&(init_pos_white<=39))
				{
					if(black[count].getPosition()==tile[init_pos_white+5].getPosition())
					{
						if(tile[init_pos_white+9].getGlobalBounds().contains(Mouse::getPosition(window).x,Mouse::getPosition(window).y))tilegood=true;
					}
					if(black[count].getPosition()==tile[init_pos_white+6].getPosition())
					{
						if(tile[init_pos_white+11].getGlobalBounds().contains(Mouse::getPosition(window).x,Mouse::getPosition(window).y))tilegood=true;
					}
				}

			}
		}
	}
	if((init_pos_white==9||init_pos_white==19||init_pos_white==29||init_pos_white==39)&&(init_pos_white<=39))
	{
		if(tile[init_pos_white+5].getGlobalBounds().contains(Mouse::getPosition(window).x,Mouse::getPosition(window).y))tilegood=true;
		for(int count=0;count<20;count++)
		{
			if(black[count].getPosition()==tile[init_pos_white+5].getPosition())
			{
				if(tile[init_pos_white+9].getGlobalBounds().contains(Mouse::getPosition(window).x,Mouse::getPosition(window).y))tilegood=true;
			}
		}
	}
	if(init_pos_white==0||init_pos_white==10||init_pos_white==20||init_pos_white==30||init_pos_white==40||init_pos_white==9||init_pos_white==19||init_pos_white==29||init_pos_white==39)
	{
		if(tile[init_pos_white+5].getGlobalBounds().contains(Mouse::getPosition(window).x,Mouse::getPosition(window).y))tilegood=true;
		for(int count=0;count<20;count++)
		{
			if((init_pos_white!=9||init_pos_white!=19||init_pos_white!=29||init_pos_white!=39)&&(init_pos_white<=39))
			{
				if(black[count].getPosition()==tile[init_pos_white+5].getPosition())
				{
					if(tile[init_pos_white+11].getGlobalBounds().contains(Mouse::getPosition(window).x,Mouse::getPosition(window).y))tilegood=true;
				}
			}
		}
	}
	if(init_pos_white==5||init_pos_white==15||init_pos_white==25||init_pos_white==35)
	{
		if((tile[init_pos_white+5].getGlobalBounds().contains(Mouse::getPosition(window).x,Mouse::getPosition(window).y)||(tile[init_pos_white+6].getGlobalBounds().contains(Mouse::getPosition(window).x,Mouse::getPosition(window).y))))tilegood=true;
		for(int count=0;count<20;count++)
		{
			if(black[count].getPosition()==tile[init_pos_white+6].getPosition())
			{
				if(tile[init_pos_white+11].getGlobalBounds().contains(Mouse::getPosition(window).x,Mouse::getPosition(window).y))tilegood=true;
			}
		}
	}
	if(tilegood==true)return true;
	if(tilegood==false)return false;
}
bool move_allowed_black(Sprite *white,RectangleShape *tile,Sprite *black)
{
	bool tilegood=false;

	if((init_pos_black!=0||init_pos_black!=10||init_pos_black!=20||init_pos_black!=30||init_pos_black!=40||init_pos_black!=9||init_pos_black!=19||init_pos_black!=29||init_pos_black!=39||init_pos_black!=49)&&(init_pos_black-5>=0&&init_pos_black-6>=0))
	{
		if((init_pos_black>10&&init_pos_black<15)||(init_pos_black>20&&init_pos_black<25)||(init_pos_black>30&&init_pos_black<35)||(init_pos_black>40&&init_pos_black<45))
		{
			if((tile[init_pos_black-5].getGlobalBounds().contains(Mouse::getPosition(window).x,Mouse::getPosition(window).y)||(tile[init_pos_black-6].getGlobalBounds().contains(Mouse::getPosition(window).x,Mouse::getPosition(window).y))))tilegood=true;
			for(int count=0;count<20;count++)
			{
				if((init_pos_black!=44||init_pos_black!=14||init_pos_black!=24||init_pos_black!=34)&&(init_pos_black>=9))
				{
					if(white[count].getPosition()==tile[init_pos_black-5].getPosition())
					{
						if(tile[init_pos_black-9].getGlobalBounds().contains(Mouse::getPosition(window).x,Mouse::getPosition(window).y))tilegood=true;
					}
					if(white[count].getPosition()==tile[init_pos_black-6].getPosition())
					{
						if(tile[init_pos_black-11].getGlobalBounds().contains(Mouse::getPosition(window).x,Mouse::getPosition(window).y))tilegood=true;
					}
				}
				if((init_pos_black==44||init_pos_black==14||init_pos_black==24||init_pos_black==34)&&(init_pos_black>=9))
				{
					if(white[count].getPosition()==tile[init_pos_black-6].getPosition())
					{
						if(tile[init_pos_black-11].getGlobalBounds().contains(Mouse::getPosition(window).x,Mouse::getPosition(window).y))tilegood=true;
					}
				}
			}
		}
		if((init_pos_black>5&&init_pos_black<10)||(init_pos_black>15&&init_pos_black<20)||(init_pos_black>25&&init_pos_black<30)||(init_pos_black>35&&init_pos_black<40)||(init_pos_black>45&&init_pos_black<50))
		{
			if((tile[init_pos_black-4].getGlobalBounds().contains(Mouse::getPosition(window).x,Mouse::getPosition(window).y)||(tile[init_pos_black-5].getGlobalBounds().contains(Mouse::getPosition(window).x,Mouse::getPosition(window).y))))tilegood=true;
			for(int count=0;count<20;count++)
			{
				if((init_pos_black!=49||init_pos_black!=19||init_pos_black!=29||init_pos_black!=39)&&(init_pos_black>=9))
				{
					if(white[count].getPosition()==tile[init_pos_black-4].getPosition())
					{
						if(tile[init_pos_black-9].getGlobalBounds().contains(Mouse::getPosition(window).x,Mouse::getPosition(window).y))tilegood=true;
					}
					if(white[count].getPosition()==tile[init_pos_black-5].getPosition())
					{
						if(tile[init_pos_black-11].getGlobalBounds().contains(Mouse::getPosition(window).x,Mouse::getPosition(window).y))tilegood=true;
					}
				}

			}
		}
	}
	if(init_pos_black==9||init_pos_black==19||init_pos_black==29||init_pos_black==39||init_pos_black==49)
	{
		if(tile[init_pos_black-5].getGlobalBounds().contains(Mouse::getPosition(window).x,Mouse::getPosition(window).y))tilegood=true;
		if(init_pos_black>9)
		{
			for(int count=0;count<20;count++)
			{
				if(white[count].getPosition()==tile[init_pos_black-5].getPosition())
				{
					if(tile[init_pos_black-11].getGlobalBounds().contains(Mouse::getPosition(window).x,Mouse::getPosition(window).y))tilegood=true;
				}
			}
		}
	}
	if(init_pos_black==10||init_pos_black==20||init_pos_black==30||init_pos_black==40)
	{
		if(tile[init_pos_black-5].getGlobalBounds().contains(Mouse::getPosition(window).x,Mouse::getPosition(window).y))tilegood=true;
		for(int count=0;count<20;count++)
		{
			if(white[count].getPosition()==tile[init_pos_black-5].getPosition())
			{
				if(tile[init_pos_black-9].getGlobalBounds().contains(Mouse::getPosition(window).x,Mouse::getPosition(window).y))tilegood=true;
			}
		}
	}
	if(init_pos_black==5||init_pos_black==15||init_pos_black==25||init_pos_black==35||init_pos_black==45)
	{
		if((tile[init_pos_black-4].getGlobalBounds().contains(Mouse::getPosition(window).x,Mouse::getPosition(window).y)||(tile[init_pos_black-5].getGlobalBounds().contains(Mouse::getPosition(window).x,Mouse::getPosition(window).y))))tilegood=true;
		for(int count=0;count<20;count++)
		{
			if(init_pos_black>9)
			{
				if(white[count].getPosition()==tile[init_pos_black-4].getPosition())
				{
					if(tile[init_pos_black-9].getGlobalBounds().contains(Mouse::getPosition(window).x,Mouse::getPosition(window).y))tilegood=true;
				}
			}
		}
	}
	if(tilegood==true)return true;
	if(tilegood==false)return false;
}
void player_move_white(Sprite *white,RectangleShape *tile,Sprite *black,int pick,bool chepicked,bool restricted,Sprite board)
{
	while(movedone==false)
	{
		Event event;
		while(window.pollEvent(event))
		{
			if(event.type==Event::Closed) window.close();
		}
		window.clear(Color::White);

		if(Keyboard::isKeyPressed(Keyboard::Escape))window.close();

		int count;
		for(count=0;count<20;count++)
		{
			if(Mouse::isButtonPressed(Mouse::Left)&&white[count].getGlobalBounds().contains(Mouse::getPosition(window).x,Mouse::getPosition(window).y))
			{
				chepicked=true;
				pick=count;
				init_pos_white=count;
				break;
			}
		}
		if(chepicked==true)white[pick].setPosition((Mouse::getPosition(window).x)-((128*xscale)/2),(Mouse::getPosition(window).y)-((128*yscale)/2));
		if(Mouse::isButtonPressed(Mouse::Right)&&chepicked==true)
		{
			for(count=0;count<20;count++)
			{
				//if(white[pick].getGlobalBounds().intersects(black[count].getGlobalBounds()))restricted=true;
				if(black[count].getGlobalBounds().contains(Mouse::getPosition(window).x,Mouse::getPosition(window).y))restricted=true;
			}
			for(count=0;count<20;count++)
			{
				if(count==pick)continue;
				//if(white[pick].getGlobalBounds().intersects(white[count].getGlobalBounds()))restricted=true;
				if(white[count].getGlobalBounds().contains(Mouse::getPosition(window).x,Mouse::getPosition(window).y))restricted=true;
			}
			for(count=0;count<50;count++)
			{
				//if(white[pick].getGlobalBounds().intersects(tile[count].getGlobalBounds())&&restricted==false)
				if(tile[count].getGlobalBounds().contains(Mouse::getPosition(window).x,Mouse::getPosition(window).y)&&restricted==false)
				{
					white[pick].setPosition(tile[count].getPosition());
					chepicked=false;
					movedone=true;
				}
				if(count==49)restricted=false;
			}
		}
		window.draw(board);
		draw_checkers(white,black);
		window.display();

	}

}
void player_move_black(Sprite *white,RectangleShape *tile,Sprite *black,int pick,bool chepicked,bool restricted,Sprite board)
{
	while(movedone==false)
	{
		Event event;
		while(window.pollEvent(event))
		{
			if(event.type==Event::Closed) window.close();
		}
		window.clear(Color::White);

		if(Keyboard::isKeyPressed(Keyboard::Escape))window.close();

		int count;
		for(count=0;count<20;count++)
		{
			if(Mouse::isButtonPressed(Mouse::Left)&&black[count].getGlobalBounds().contains(Mouse::getPosition(window).x,Mouse::getPosition(window).y))
			{
				chepicked=true;
				pick=count;
				break;
			}
		}
		if(chepicked==true)black[pick].setPosition((Mouse::getPosition(window).x)-((128*xscale)/2),(Mouse::getPosition(window).y)-((128*yscale)/2));
		if(Mouse::isButtonPressed(Mouse::Right)&&chepicked==true)
		{
			for(count=0;count<20;count++)
			{
				//if(white[pick].getGlobalBounds().intersects(black[count].getGlobalBounds()))restricted=true;
				if(white[count].getGlobalBounds().contains(Mouse::getPosition(window).x,Mouse::getPosition(window).y))restricted=true;
			}
			for(count=0;count<20;count++)
			{
				if(count==pick)continue;
				//if(white[pick].getGlobalBounds().intersects(white[count].getGlobalBounds()))restricted=true;
				if(black[count].getGlobalBounds().contains(Mouse::getPosition(window).x,Mouse::getPosition(window).y))restricted=true;
			}
			for(count=0;count<50;count++)
			{
				//if(white[pick].getGlobalBounds().intersects(tile[count].getGlobalBounds())&&restricted==false)
				if(tile[count].getGlobalBounds().contains(Mouse::getPosition(window).x,Mouse::getPosition(window).y)&&restricted==false)
				{
					black[pick].setPosition(tile[count].getPosition());
					chepicked=false;
					movedone=true;
				}
				if(count==49)restricted=false;
			}
		}
		window.draw(board);
		draw_checkers(white,black);
		window.display();
	}
}


int main()
{
	int pick;
	bool restricted=false;
	bool chepicked;
	//zmienne
	bool menu_is_open=true;
	bool setup_done=false;


	float tile_sizey=128*yscale;
	float tile_sizex=128*xscale;
	int count,player_selection,lmbpressed,picked;

	lmbpressed=0;


	Vector2f setup_position_white[20],setup_position_black[20],setup_position_tile[50];

	Vector2f tile_size(tile_sizex,tile_sizey);
	Vector2f oldposition;

	Vector2f mpos;

	//tekstury
	Texture boardtexture;
	boardtexture.loadFromFile("board.png");
	Texture whitecheckertext;
	whitecheckertext.loadFromFile("whitechecker.png");
	Texture blackcheckertext;
	blackcheckertext.loadFromFile("blackchecker.png");
	Texture graycheckertext;
	graycheckertext.loadFromFile("graychecker.png");

	//debug
	CircleShape debugcircle(30);
	debugcircle.setFillColor(Color::Green);
	int debugon=0;

	//szachownica
	Sprite board;
	board.setTexture(boardtexture);
	board.setScale(0.46875,0.46875);
	RectangleShape tile[50];
	for(count=0;count<50;count++)
	{
		tile[count].setSize(tile_size);
	}

	//obiekty
	Sprite gray;
	gray.setTexture(graycheckertext);
	gray.setScale(0.46875,0.46875);

	Sprite white_img;
	white_img.setTexture(whitecheckertext);
	white_img.setScale(0.46875,0.46875);
	Sprite black_img;
	black_img.setTexture(blackcheckertext);
	black_img.setScale(0.46875,0.46875);
	Sprite white[20];
	for(count=0;count<20;count++)
	{
		white[count].setTexture(whitecheckertext);
		white[count].setScale(0.46875,0.46875);
	}

	Sprite black[20];
	for(count=0;count<20;count++)
	{
		black[count].setTexture(blackcheckertext);
		black[count].setScale(0.46875,0.46875);
	}



	//gra
	while(window.isOpen())
	{
		Event event;
		while(window.pollEvent(event))
		{
			if(event.type==Event::Closed) window.close();
		}
		window.clear(Color::White);

		if(Keyboard::isKeyPressed(Keyboard::Escape))window.close(); // na razie;
		//debug
		if(Keyboard::isKeyPressed(Keyboard::D))debugon=1-debugon;
		debugcircle.setPosition(Mouse::getPosition(window).x,Mouse::getPosition(window).y);
		if(debugon==1)window.draw(debugcircle);
		if(Keyboard::isKeyPressed(Keyboard::R))movedone=false;
		//-debug

		//menu
		if(menu_is_open==true)
		{
			menu(white_img,black_img);
			menu_is_open=false;
		}
		window.draw(board);
		//ustawienie pozycji
		if(setup_done==false)
		{
			setup(setup_position_tile,setup_position_white,setup_position_black,white,black,tile);
			setup_done=true;
		}
		//ruch gracza
		if(movedone==false&&player_side==0)
		{
			player_move_white(white,tile,black,pick,chepicked,restricted,board);
		}
		if(movedone==false&&player_side==1)
		{
			player_move_black(white,tile,black,pick,chepicked,restricted,board);
		}




		//rysowanie pionkow
		draw_checkers(white,black);
		window.display();

	}
	return 0;
}
