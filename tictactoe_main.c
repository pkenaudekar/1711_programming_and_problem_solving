/*Author: Pratik Kenaudekar
Date Created: 16th October 2017
Date Modified: 14th November 2017
New feature: ncurses library
Title: Tic Tac Toa Game with AI using ncurses library*/ 

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include <malloc.h>
#include<time.h>
#include"func_tictactoe.h"


int main()
{       
		int flag = 0, option;
		WINDOW *menu_win;
		do
		{
			Print_Intro(&option, menu_win);
			Accept_Options(option, menu_win);
			Terminate(&flag, menu_win);
		}
		while(flag != 2);
		printf("Game terminated!!");
		return 0;
}
