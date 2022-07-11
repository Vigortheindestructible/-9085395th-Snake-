//############################################################################################

//File related to the titlescreen. Created this seperately because it got longer than I expected


void title(WINDOW *title_screen,int wymax,int wxmax, int *pSet_difficulty, int ymax, int xmax)
	{
		keypad(title_screen,true);
		wclear(title_screen);
		char *mainmenu[50]={"Start Game","Difficulty"};
		char *difficulty[50]={"Easy  ","Normal","Hard  "};
		int highlight=0;
		int choice;

	while(1)
	{
		snakeart(title_screen);
	
		//Mainmenu

		for (int i=0;i<2;i++)
		{
			mvwprintw(title_screen,20+i,1, mainmenu[i]);
			if (i==highlight)
			{
				wattron(title_screen,A_STANDOUT);
				mvwprintw(title_screen,20+i,1, mainmenu[i]);
				wattroff(title_screen,A_STANDOUT);
			}
		}
		
		//Difficulty setting

		for (int i=0;i<3;i++)
		{
			if (i==(*pSet_difficulty))
			{
				mvwprintw(title_screen,21,15, difficulty[i]);
			}
		}
		
		mvwprintw(stdscr,ymax-4,1+xmax/4, "Written by Jean-Pierre Jacobs");
		mvwprintw(stdscr,ymax-3,1+xmax/4, "Art from www.asciiart.eu, by Max Strandberg");
		mvwprintw(stdscr,ymax-2,1+xmax/4, "Orignal Snake game and credit to Taneli Armanto.");
		refresh();
	
		choice = wgetch(title_screen);
		
		switch (choice)
		{
			case KEY_DOWN:
			highlight++;
			if (highlight==2)
			{
				highlight=1;
			}
			break;
			case KEY_UP:
			highlight--;
			if (highlight==-1)
			{
				highlight=0;
			}
			break;
			case KEY_RIGHT:
			(*pSet_difficulty)++;
			if ((*pSet_difficulty)==3)
			{
				(*pSet_difficulty)=2;
			}
			break;
			case KEY_LEFT:
			(*pSet_difficulty)--;
			if ((*pSet_difficulty)==-1)
			{
				(*pSet_difficulty)=0;
			}
			break;
			case '\n':
			break;
			default:
			break;
		}
		if (choice=='\n' && highlight==0)
		{
			clear();
			break;
		}			
	}
}
