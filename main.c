//####################################################################

// 9085395th-Snake Game VERSION 1.0 Beta

#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include "Art_Graphics.c"
#include "In_Game_Mechanics.c"
#include "Outside_Game_Mechanics.c"
#include "Title_Screen.c"

int main()
{
	int ymax,xmax; //Stdscr dimensions
	int wymax,wxmax;//Set border dimensions
	int snakelocationy,snakelocationx;
	int snakedelaytime;
	int input=0;
	int foodlocationy,foodlocationx;
	int wymaxrand,wxmaxrand;
	int tailsize=0;
	bool snakeatefood=true;
	srand(time(NULL));
	int snakequeuey[1500];
	int snakequeuex[1500];
	int count=-1;
	bool dead=false;
	bool exitgame=false;
	bool restartgame=false;
	int direction;
	int set_difficulty=0;
	int score=0;
	
	initscr(); curs_set(0); noecho();

	getmaxyx(stdscr,ymax,xmax);

	//Title screen Window

	WINDOW *title_screen=newwin(ymax/2,xmax/2,ymax/4,xmax/4);
	box(title_screen,1,1);
	keypad(title_screen,true);
	getmaxyx(title_screen,wymax,wxmax);
	
	title(title_screen,wymax,wxmax,&set_difficulty,ymax,xmax);
	setplaymode(set_difficulty, &snakedelaytime);

	//Game Border
	
	WINDOW* border=newwin(ymax/2,xmax/2,ymax/4,xmax/4); //Window border
	box(border,0,0);
	getmaxyx(border,wymax,wxmax);//Get Window Dimensions
	keypad(stdscr,true);

	//Game Over Screen
		
	WINDOW* game_over_screen=newwin(ymax/4,xmax/4,ymax/3,xmax/3); //Window border
	keypad(game_over_screen,true);

	//Snake Values

	snakelocationy=wymax/2;
	snakelocationx=wxmax/2;
	
	//Set decorations

	decoration(ymax,xmax);
	
	countdownready(border,wymax,wxmax);
	box(border,0,0);
	mvwaddch(border, snakelocationy, snakelocationx, SNAKE_HEAD);
	refresh();
	wrefresh(border);
	input=getch();
	
	mvwaddch(border, snakelocationy, snakelocationx, EMPTY_SPACE);
	
	snakequeuey[0]=snakelocationy;
	snakequeuex[0]=snakelocationx;

	while(1)
	{	
		foodlocation(border,wymaxrand,wxmaxrand,&foodlocationy,&foodlocationx,&snakeatefood);

		if (kbhit())
			{
				input=getch();
			}

		preventtangle(direction,&input);
		
		insertintoqueue(tailsize, snakelocationy,snakelocationx,&count,snakequeuey,snakequeuex);
		
		movesnake(&snakelocationy,&snakelocationx,snakedelaytime,input,&direction);
		
		count++;
		
		draw_snake(border,snakelocationy,snakelocationx,snakequeuey,snakequeuex,tailsize,count);
		
		generaterandomnumber(wymax,wxmax,&wymaxrand, &wxmaxrand);
		
		snakehitsfood(&snakeatefood,snakelocationy, foodlocationy,snakelocationx,foodlocationx,&tailsize,&score);
		
		drawscore(border,score, tailsize, ymax, xmax);
		
		premios(score,ymax,xmax);

		setsnakeborder(border,wymax,wxmax,&snakelocationy,&snakelocationx,set_difficulty, &dead);
		
		snakehitsitself(snakelocationy,snakelocationx,snakequeuey,snakequeuex,tailsize,&dead);
		
		if (dead==true)
			{
				game_over(game_over_screen, &exitgame, &restartgame);
			}

		if (restartgame==true)
			{
			resetvalues(border, &snakelocationy,&snakelocationx, &snakedelaytime,&input,&tailsize, &snakeatefood,&count, &dead, &exitgame, &direction, snakequeuey,snakequeuex,wymax,wxmax,&restartgame,&score);
			}

		if (exitgame==true)
			{
				break;
			}
		
		if (input== 'q' || input== 'Q')
		{
			debuginginformation(ymax,xmax,wymax,wxmax,snakelocationy,snakelocationx,snakequeuey,snakequeuex,tailsize,foodlocationy,foodlocationx);
		}

		refresh();
		wrefresh(border);

	}	// End of Game loop

		wclear(game_over_screen);
		wclear(stdscr);
		wclear(border);
		refresh();
		wrefresh(border);
		mvwprintw(game_over_screen, 0+1, 0, "Thank you for playing");
		mvwprintw(game_over_screen, 0+3, 0, "Press a key to exit");
		wgetch(game_over_screen);
	
	endwin();
	return 0;	
}

//###########################################################################
