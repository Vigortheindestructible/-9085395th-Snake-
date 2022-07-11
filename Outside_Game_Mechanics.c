//###################################################################################

//This file contains all aspects of the game not related to game mechanics(movement etc) and is more about score, game over screen and everything around it



//Doesnt do much but when pressing q it shows this information

void debuginginformation(int ymax, int xmax, int wymax, int wxmax,int snakelocationy,int snakelocationx,int snakequeuey[],int snakequeuex[],int tailsize, int foodlocationy, int foodlocationx)
{
	mvwprintw(stdscr,1,1,"Debugging Information");
	mvwprintw(stdscr,2,1,"Screen Ymax: %d | Screen Xmax: %d", ymax,xmax);
	mvwprintw(stdscr,3,1,"Window Ymax: %d | Window Xmax: %d", wymax,wxmax);
	mvwprintw(stdscr,4,1,"Snake Location y:%d | Snake Location x:%d ", snakelocationy,snakelocationx);
	mvwprintw(stdscr,5,1,"Tailsize :%d", tailsize);
	mvwprintw(stdscr,6,1,"food Location y:%d | food Location x:%d ", foodlocationy,foodlocationy);
	
	
	for (int i=0;i<tailsize;i++)
	{
		mvwprintw(stdscr,6+i,1,"snakequeue y[%d]:  %d | Snakequeue x [%d]: %d ", i,snakequeuey[i],i,snakequeuex[i]);
	}
}	



//Draws the score

void drawscore(WINDOW* border, int score, int tailsize, int ymax, int xmax)
	{
		wattron(stdscr,A_REVERSE);
		mvwprintw(stdscr,1,1,"score: %d", score);
	}



// Game over screen

void game_over(WINDOW* game_over_screen, bool *pExitgame, bool *pRestartgame)
	{
		char input;
		int wymax,wxmax;
		getmaxyx(game_over_screen,wymax,wxmax);
		mvwprintw(game_over_screen,wymax/2,wxmax/2, "Game over");
		mvwprintw(game_over_screen,wymax/2+2,wxmax/2, "Restart Game?");
		mvwprintw(game_over_screen,wymax/2+4,wxmax/2, "Y/N?");
		input=wgetch(game_over_screen);
		if (input=='N' || input=='n')
		{
			(*pExitgame)=true;
		}
		else if (input=='Y' || input=='y')
		{
			(*pRestartgame)=true;
			wclear(game_over_screen);			
		}
		else
		{
			NULL;
		}
	}
	


//Khbit function for Ncurses. I did not make this function myself and I could not find the original creator. As khbit is not included in Ncurses, I had to figure out a method to simulate this. As long as it works. Credit goes to [Fill in your name here if it is you]

bool kbhit(void)
{

   	initscr();             
   	cbreak();
   	noecho();
   	nodelay(stdscr, TRUE);

    	scrollok(stdscr, TRUE);
    	int ch = getch();
    	if (ch != ERR) 
		{
        		ungetch(ch);
        		refresh();
        		return true;
    		} 
    	else 
		{
        		refresh();
       			return false;
   		}
}



//Resets values when the Snake dies. Better than addressing main(), which I understand is a sin in programming

void resetvalues(WINDOW* border, int *pSnakelocationy, int *pSnakelocationx, int *pSnakedelaytime,int *pInput,int *pTailsize, bool *pSnakeatefood,int *pCount, bool *pDead,bool *pExitgame,int *pDirection,int snakequeuey[],int snakequeuex[], int wymax, int wxmax,bool *pRestartgame, int *pScore )
{
	wclear(border);
	box(border,0,0);
	*pSnakelocationy=wymax/2;
	*pSnakelocationx=wxmax/2;
	*pSnakeatefood=true;
	*pTailsize=0;
	*pCount=-1;
	*pDead=false;
	*pExitgame=false;
	*pDirection=4;
	snakequeuey[0]=(*pSnakelocationy);
	snakequeuex[0]=(*pSnakelocationx);
	*pDead=false;
	*pExitgame=false;
	*pRestartgame=false;
	*pScore=0;
	refresh();
	wrefresh(border);
}

//In an early version there was a countdown but I replaced it with a tip of the day-type  instruction. Well, actually it just says how to move the Snake.

void countdownready(WINDOW *border,int wymax,int wxmax)
{
	mvwprintw(border,wymax/2,wxmax/5, "Welcome to 9085395th-Snake");
	mvwprintw(border,wymax/2+2,wxmax/5, "Use the Arrow keys or WASD to move the snake");
	mvwprintw(border,wymax/2+3,wxmax/5, "Press a key to begin");
	wrefresh(border);
	getch();
	wclear(border);
}

//Set Snake move speed at certain difficulty level

void setplaymode(int set_difficulty, int *pSnakedelaytime)
{
	
	if (set_difficulty==0)//Easy
	{
		(*pSnakedelaytime)=200000;
	}
	else if (set_difficulty==1)//Normal
	{
		(*pSnakedelaytime)=75000;
	}
	else if (set_difficulty==2)//Hard
	{
		(*pSnakedelaytime)=50000;
	}
}

//Some extra stuff added but not required
void premios(int score,int ymax, int xmax)
{
	if (score>499)
		{
			wattroff(stdscr,A_REVERSE);
			mvwprintw(stdscr,ymax/9,xmax/9, "--_o.o_--");
		}
	if (score>999)
		{
			mvwprintw(stdscr,ymax-ymax/7,xmax-xmax/6,"Ƹ̵̡Ӝ̵̨̄Ʒ");
		}
	if (score>1449)
		{
			mvwprintw(stdscr,ymax-ymax/5,xmax-xmax/9,"ᕦ(ò_óˇ)ᕤ");	
		}
}

