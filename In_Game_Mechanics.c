#define SNAKE_HEAD 'O'
#define SNAKE_TAIL 'o'
#define FOOD '@'
#define EMPTY_SPACE ' '

//File related to all ingame movement etc

void movesnake(int *pSnakelocationy, int *pSnakelocationx,int snakedelaytime, int input, int *pDirection)
{
		
		if (input==KEY_UP || input== 'w')//up
		{
			(*pSnakelocationy)--;
			(*pDirection)=0;
			usleep(snakedelaytime);
		}
		else if (input==KEY_DOWN || input=='s')//down
		{
			(*pSnakelocationy)++;
			(*pDirection)=2;
			usleep(snakedelaytime);
		}
		else if (input==KEY_LEFT || input=='a')//Left
		{
			(*pSnakelocationx)--;
			(*pDirection)=1;
			usleep(snakedelaytime);
		}
		else if (input==KEY_RIGHT || input=='d')//Right
		{
			(*pSnakelocationx)++;
			(*pDirection)=3;
			usleep(snakedelaytime);
		}
		else 
		{
			(*pSnakelocationy)--;
			usleep(snakedelaytime);
		}
}

void insertintoqueue(int tailsize, int snakelocationy, int snakelocationx, int *pCount, int snakequeuey[], int snakequeuex[])
{
			snakequeuey[*pCount + 1]=snakelocationy;
			snakequeuex[*pCount + 1]=snakelocationx;
			
			if ((*pCount)==tailsize)
			{
			(*pCount)=-1;
			snakequeuey[0]=snakelocationy;
			snakequeuex[0]=snakelocationx;
			}
}

void draw_snake(WINDOW *border, int snakelocationy,int snakelocationx,int snakequeuey[], int snakequeuex[],int tailsize,int count)
{				

		mvwaddch(border, snakelocationy, snakelocationx, SNAKE_HEAD);
		mvwaddch(border, snakequeuey[count+1], snakequeuex[count+1], EMPTY_SPACE);
	
}

void generaterandomnumber(int wymax,int wxmax, int *pWymaxrand, int *pWxmaxrand)
{
	*pWymaxrand=rand()%wymax;
	*pWxmaxrand=rand()%wxmax;
}

void foodlocation(WINDOW *border, int wymaxrand,int wxmaxrand,int *wFoodlocationy, int *wFoodlocationx,bool *pSnakeatefood)
{
	if (mvwinch(border, wymaxrand, wxmaxrand)==' ' && *pSnakeatefood==true)
	{
	*wFoodlocationy=wymaxrand;
	*wFoodlocationx=wxmaxrand;
	mvwaddch(border, *wFoodlocationy, *wFoodlocationx, FOOD);
	 *pSnakeatefood=false;
	}
}

void snakehitsfood(bool *pSnakeatefood,int snakelocationy, int foodlocationy,int snakelocationx,int foodlocationx,int *pTailsize,int *pScore)
{
	if (snakelocationy==foodlocationy && snakelocationx==foodlocationx)
	{
		(*pTailsize)++;
		*pSnakeatefood=true;
		(*pScore)++;
		
	}
}

void setsnakeborder(WINDOW *border, int wymax,int wxmax, int *pSnakelocationy, int *pSnakelocationx, int set_difficulty, bool *pDead)
{
	if ((*pSnakelocationy) == wymax+1 && set_difficulty != 2)
	{
		(*pSnakelocationy)=0;
	}
	else if ((*pSnakelocationy) == 0 && set_difficulty != 2)
	{
		(*pSnakelocationy)=wymax;
	}
	else if ((*pSnakelocationx) == wxmax && set_difficulty != 2)
	{
		(*pSnakelocationx)=0;
	}
	else if ((*pSnakelocationx) == 0 && set_difficulty != 2)
	{
		(*pSnakelocationx)=wxmax;
	}
	//Settings for hard mode
	
	if ((*pSnakelocationy) == wymax+1 && set_difficulty == 2)
	{
		(*pDead)=true;
	}
	else if ((*pSnakelocationy) == 0 && set_difficulty == 2)
	{
		(*pDead)=true;
	}
	else if ((*pSnakelocationx) == wxmax && set_difficulty == 2)
	{
		(*pDead)=true;
	}
	else if ((*pSnakelocationx) == 0 && set_difficulty == 2)
	{
		(*pDead)=true;
	}
	box(border,0,0);
}

void preventtangle(int direction,int *pInput)
{
		if ((direction==0 && (*pInput)==KEY_DOWN) || (direction==0 && (*pInput)=='s'))
		{
			(*pInput)=KEY_UP;
		}
		else if ((direction==2 && (*pInput)==KEY_UP) || (direction==2 && (*pInput)=='w'))
		{
			(*pInput)=KEY_DOWN;
		}
		else if ((direction==1 && (*pInput)==KEY_RIGHT) || (direction==1 && (*pInput)=='d'))
		{
			(*pInput)=KEY_LEFT;
		}
		else if ((direction==3 && (*pInput)==KEY_LEFT) || (direction==3 && (*pInput)=='a'))
		{
			(*pInput)=KEY_RIGHT;
		}
}

void snakehitsitself(int snakelocationy,int snakelocationx,int snakequeuey[],int snakequeuex[],int tailsize, bool *pDead)
{
	for (int i=0;i<tailsize;i++)
	{
		if (snakelocationy==snakequeuey[i] && snakelocationx==snakequeuex[i])
		{
			(*pDead)=true;
		}
	}
}
