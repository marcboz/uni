#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


using namespace sf;


int main()
{
	const int N=3;
	int check=0;
  	int keyonoff=1;
   	int circle_size=20;
	int window_sizex=1200;
	int window_sizey=700;
	float vx=0.5,vy=0.5;
	float x[N],y[N];
	float velx[3],vely[3];
	
	int32_t old_time=0;
	RenderWindow window(VideoMode(window_sizex, window_sizey), "Nasze okno");
	int xdir[N];
	int ydir[N];
	CircleShape shape[N];

	for(int count=0;count<N;count++)
	{
		check=0;
		shape[count].setRadius(circle_size);	
		//CircleShape shape1(circle_size);
		//CircleShape shape2(circle_size);
		//shape0.setFillColor(Color::Green);
		//shape1.setFillColor(Color::Blue);
		//shape2.setFillColor(Color::Red);
	
		//shape.setPosition(250,150);	//centrowanie bez zmiennych
	
		x[count]=window_sizex/2-circle_size;
		y[count]=window_sizey/2-circle_size;
		FloatRect colbox[count]=shape[count].getGlobalBounds();
		if(count>0&&count%2==0&&N>4) x[count]=x[count]+circle_size*(3+(count-3));
		else x[count]=x[count]+circle_size*(3*(count-3));
		if(count>0&&count%2==1&&N>4) x[count]=x[count]-circle_size*(3+(count-3));
		else x[count]=x[count]+circle_size*(3*(count-3));


		if(count%2==0){shape[count].setFillColor(Color::Blue);check++;}
		if(count%3==0){shape[count].setFillColor(Color::Red);check++;}
		if(check!=0)shape[count].setFillColor(Color::Green);
		
		

		/*
		x[1]=(window_sizex/2-circle_size)-150;
		y[1]=(window_sizey/2-circle_size);
		shape1.setPosition(x[1],y[1]);
		FloatRect colbox1=shape1.getGlobalBounds();

		//trzecie kolo
		x[2]=(window_sizex/2-circle_size)+150;
		y[2]=(window_sizey/2-circle_size);
		shape2.setPosition(x[2],y[2]);
		FloatRect colbox2=shape2.getGlobalBounds();*/
		xdir[count]=1;
		ydir[count]=1;
	}
	int32_t dt;
	Time time;
	Clock clock;
	//boundingCircle=shape.getGlobalBounds();

	while (window.isOpen())   	 // dopoki okno jest otwarte...
	{


   		// w tym obiekcie klasy sf::Event
   		// bedziemy mieli informacje co zrobil uzytkownik
    		Event event;
       	 
	    	while (window.pollEvent(event))
	    	{
			// uzytkownik kliknal zamkniecie  okna
			if (event.type == Event::Closed)
	   		 	window.close();
	   			 
	   	 	// uzytkownik nacisnal klawisz
	   	 	if(event.type== Event::KeyPressed)
	   			 keyonoff=1-keyonoff;
	    	}
    
		// czyszczenie (na czarno)
   		window.clear(Color::Black);




    		// rysuj kolo w zaleznosci od stanu zmiennej keyonoff
		for(int count=0;count<N;count++)
		{    		
			if(keyonoff) window.draw(shape[count]);
       		}
		window.display();
		//zamyka okno po wcisnieciu esc
		if(Keyboard::isKeyPressed(Keyboard::Escape))window.close();

		//ruch kola
		time=clock.getElapsedTime();
		dt=time.asMilliseconds()-old_time;
		old_time=time.asMilliseconds();
		for(int count=0;count<N;count++)
		{
			velx[count]=vx*dt;
			vely[count]=vy*dt;
		}
		for(int count=0;count<N;count++)
		{
			
			if((x[count]==x[0]&&count!=0)||(x[count]==x[1]&&count!=1)||(x[count]==x[2]&&count!=2)||(x[count]==(x[0]+circle_size)&&count!=0)||(x[count]==(x[1]+circle_size)&&count!=1)||(x[count]==(x[2]+circle_size)&&count!=2))xdir[count]=1-xdir[count];
			if((y[count]==y[0]&&count!=0)||(y[count]==y[1]&&count!=1)||(y[count]==y[2]&&count!=2)||(y[count]==(y[0]+circle_size)&&count!=0)||(y[count]==(y[1]+circle_size)&&count!=1)||(y[count]==(y[2]+circle_size)&&count!=2))ydir[count]=1-ydir[count];
			
			if(x[count]<0||x[count]>window_sizex-circle_size*2)xdir[count]=1-xdir[count];
			if(y[count]<0||y[count]>window_sizey-circle_size*2)ydir[count]=1-ydir[count];

			if(xdir[count]==0)velx[count]=velx[count]*-1;
			if(ydir[count]==0)vely[count]=vely[count]*-1;
			
			if(count%2==0){x[count]=x[count]+(velx[count])*2;y[count]=y[count]+(vely[count])*2;}
			if(count%3==0){x[count]=x[count]+(velx[count])*3;y[count]=y[count]+(vely[count])*3;}
			else{x[count]=x[count]+velx[count];y[count]=y[count]+vely[count];}
			
			
		}
		
		
		/*if(colbox0.intersects(colbox1)||colbox0.intersects(colbox2))
		{
			xdir[0]=1-xdir[0];
			ydir[0]=1-ydir[0];
		}

		if(colbox1.intersects(colbox0)||colbox1.intersects(colbox2))
		{
			xdir[1]=1-xdir[1];
			ydir[1]=1-ydir[1];
		}
		
		if(colbox2.intersects(colbox0)||colbox2.intersects(colbox1))
		{
			xdir[2]=1-xdir[2];
			ydir[2]=1-ydir[2];
		}
		*/
		/*for(int count=0;count<N;count++)
		{
			if(x[count]<0||x[count]>window_sizex-circle_size*2)xdir[count]=1-xdir[count];
			if(y[count]<0||y[count]>window_sizey-circle_size*2)ydir[count]=1-ydir[count];
			if(xdir[count]==0)velx[count]=velx[count]*-1;
			if(ydir[count]==0)vely[count]=vely[count]*-1;
			x[count]=x[count]+velx[count];y[count]=y[count]+vely[count];
		}*/
		for(int count=0;count<N;count++)
		{
			shape[count].setPosition(x[count],y[count]);
		}
		
		
	}
	return 0;
}

