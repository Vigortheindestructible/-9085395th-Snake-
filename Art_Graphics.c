//##########################################################################################

//File used for artwork and decoration. It`s not a lot but gives a bit more visual candy. 
//As I suck at art, I took the ascii art from asciiart.eu and a person named Max Strandberg created it. Credit goes to this person

void snakeart(WINDOW *title_screen)
{
	mvwprintw(title_screen,1,1,"         /^\\/^\\                                      ");
	mvwprintw(title_screen,2,1,"         _|__|  O|                                     ");
	mvwprintw(title_screen,3,1,"\\/     /~     \\_/ \\                                 ");
	mvwprintw(title_screen,4,1," \\____|__________/  \\                                  ");
	mvwprintw(title_screen,5,1,"        \\_______      \\                                ");
	mvwprintw(title_screen,6,1,"                `\\     \\                 \\             ");
	mvwprintw(title_screen,7,1,"                  |     |                  \\           ");
	mvwprintw(title_screen,8,1,"                 /      /                    \\         ");
	mvwprintw(title_screen,9,1,"                /     /                       \\\\       ");
	mvwprintw(title_screen,10,1,"              /      /                         \\ \\    ");
	mvwprintw(title_screen,11,1,"             /     /                            \\  \\  ");
	mvwprintw(title_screen,12,1,"           /     /             _----_            \\   \\");
	mvwprintw(title_screen,13,1,"          /     /           _-~      ~-_         |   |");
	mvwprintw(title_screen,14,1,"         (      (        _-~    _--_    ~-_     _/   |");
	mvwprintw(title_screen,15,1,"          \\      ~-____-~    _-~    ~-_    ~-_-~    / ");
	mvwprintw(title_screen,16,1,"            ~-_           _-~          ~-_       _-~  ");
	mvwprintw(title_screen,17,1,"               ~--______-~                ~-___-~     ");
	mvwprintw(title_screen,18,1,"                          ----------------------------");
	mvwprintw(title_screen,19,1,"                         9085395th-Snake Game 1.0 Beta");
	
}

void decoration(int ymax,int xmax)
{
	mvwprintw(stdscr, ymax/3,ymax/3, "\\|/");
	mvwprintw(stdscr, ymax/4,xmax/4, "\\|/");
	mvwprintw(stdscr, ymax/5,xmax/5, "\\|/");
	mvwprintw(stdscr, ymax/6,xmax/6, "\\|/");

	mvwprintw(stdscr, ymax/3,xmax-xmax/6, "\\|/");
	mvwprintw(stdscr, ymax/4,xmax-xmax/3, "\\|/");
	mvwprintw(stdscr, ymax/5,xmax-xmax/5, "\\|/");
	mvwprintw(stdscr, ymax/6,xmax-xmax/4, "\\|/");
	
	mvwprintw(stdscr, ymax -ymax/6,ymax/3, "\\|/");
	mvwprintw(stdscr, ymax -ymax/3,xmax/4, "\\|/");
	mvwprintw(stdscr, ymax -ymax/5,xmax/5, "\\|/");
	mvwprintw(stdscr, ymax -ymax/4,xmax/6, "\\|/");
	
	mvwprintw(stdscr, ymax -ymax/6,xmax-xmax/3, "\\|/");
	mvwprintw(stdscr, ymax -ymax/5+2,xmax-xmax/5-1, "\\|/");
	mvwprintw(stdscr, ymax -ymax/4,xmax-xmax/6, "\\|/");

	wrefresh(stdscr);
}



