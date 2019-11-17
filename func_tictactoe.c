#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include <malloc.h>
#include"func_tictactoe.h"
#include"validation.h"
#include<time.h>

void Print_Intro(int *option, WINDOW *menu_win)
{
	int startx = 0, starty = 0, highlight = 1, choice = 0, c;
    initscr();
    clear();
    noecho();
    cbreak();       // Line buffering disabled. pass on everything 
    starty = (LINES - PHEIGHT) / 2;  // Calculating for a center placement 
    startx = (COLS - PWIDTH) / 2;    // of the window                
	char *choices[] = {
                        "1) Game v/s Computer",
                        "2) Game v/s Player",
						"3) View Past Records",
                      };
	int n_choices = sizeof(choices) / sizeof(char *);
    menu_win = newwin(PHEIGHT, PWIDTH, starty, startx);
    keypad(menu_win, TRUE);
    mvprintw(startx-70, starty+63, "****TIC TAC TOE GAME WITH AI****");
	mvprintw(startx-68, starty+71, "SELECT AN OPTION");
    refresh();
    Print_Menu(menu_win, highlight, n_choices, choices);
    while(1)
    {       
		c = wgetch(menu_win);
        switch(c)
        {   
			case KEY_UP:
			{
                if(highlight == 1)
				{
                    highlight = n_choices;
				}
                else
				{
                    --highlight;
                }
				break;
			}
            case KEY_DOWN:
			{
                if(highlight == n_choices)
				{
                    highlight = 1;
				}
                else
				{
                    ++highlight;
                }
				break;
			}
            case 10:
			{
                choice = highlight;
                break;
			}
        }
        Print_Menu(menu_win, highlight, n_choices, choices);
        if(choice != 0) // User did a choice come out of the infinite loop 
		{
            break;
		}
    } 
	*option=choice;
    clrtoeol();
	clear();
    refresh();
    endwin();
}

void Accept_Options(int option, WINDOW *menu_win)
{
	char pl1ch;
	if(option == 1) //Option selected as Game v/s Computer
	{
		int startx = 0, starty = 0, highlight = 1, choice = 0, c;
        initscr();
        clear();
        noecho();
        cbreak();       // Line buffering disabled. pass on everything 
        starty = (LINES - AHEIGHT) / 2;  // Calculating for a center placement 
        startx = (COLS - AWIDTH) / 2;    // of the window                
		char *choices[] = {
                        "1) Select 'X' as your choice",
                        "2) Select 'O' as your choice",
                        };
		int n_choices = sizeof(choices) / sizeof(char *);
        menu_win = newwin(AHEIGHT, AWIDTH, starty, startx);
        keypad(menu_win, TRUE);
        mvprintw(startx-65, starty+64, "Select 'X' or 'O' for Player 1");
        refresh();
        Print_Menu(menu_win, highlight, n_choices, choices);
        while(1)
        {   
			c = wgetch(menu_win);
            switch(c)
            {   
				case KEY_UP:
				{
                    if(highlight == 1)
					{
                        highlight = n_choices;
					}
                    else
					{
                        --highlight;
                    }
					break;
				}
                case KEY_DOWN:
				{
                    if(highlight == n_choices)
					{
                        highlight = 1;
					}
                    else
					{
                        ++highlight;
                    }
					break;
				}
                case 10:
				{
                    choice = highlight;
                    break;
				}
            }
            Print_Menu(menu_win, highlight, n_choices, choices);
            if(choice != 0) // User did a choice come out of the infinite loop 
			{
                break;
			}
        } 
		if(choice==1)
		{
			pl1ch='X';
		}
		else
		{
			pl1ch='O';
		}
        clrtoeol();
		clear();
        refresh();
        endwin();
		With_Computer(option,pl1ch,menu_win);
	}
	else if(option == 2) //Option selected as Game v/s Player
	{
		int startx = 0, starty = 0, highlight = 1, choice = 0, c;
        initscr();
        clear();
        noecho();
        cbreak();       // Line buffering disabled. pass on everything 
        starty = (LINES - AHEIGHT) / 2;  // Calculating for a center placement 
        startx = (COLS - AWIDTH) / 2;    // of the window                
		char *choices[] = {
                        "1) Select 'X' as your choice",
                        "2) Select 'O' as your choice",
                        };
		int n_choices = sizeof(choices) / sizeof(char *);
        menu_win = newwin(AHEIGHT, AWIDTH, starty, startx);
        keypad(menu_win, TRUE);
        mvprintw(startx-65, starty+59, "Player 1 Select 'X' or 'O' as your choice");
        refresh();
        Print_Menu(menu_win, highlight, n_choices, choices);
        while(1)
        {   
			c = wgetch(menu_win);
            switch(c)
            {   
				case KEY_UP:
				{
                    if(highlight == 1)
					{
                        highlight = n_choices;
					}
                    else
					{
                        --highlight;
                    }
					break;
				}
                case KEY_DOWN:
				{
                    if(highlight == n_choices)
					{
                        highlight = 1;
					}
                    else
					{
                        ++highlight;
					}
					break;
				}
                case 10:
				{
                    choice = highlight;
                    break;
				}
            }
            Print_Menu(menu_win, highlight, n_choices, choices);
            if(choice != 0) // User did a choice come out of the infinite loop 
			{
                break;
			}
        } 
		if(choice==1)
		{
			pl1ch='X';
		}
		else
		{
			pl1ch='O';
		}
        clrtoeol();
		clear();
        refresh();
        endwin();
		With_Player(option,pl1ch,menu_win);
	}
	else if(option == 3) //Option selected as View Past Records
	{
		View_Results(menu_win);
	}
}

void Terminate(int *flag, WINDOW *menu_win)
{
	int startx = 0, starty = 0, highlight = 1, choice = 0, c;
    initscr();
    clear();
    noecho();
    cbreak();       // Line buffering disabled. pass on everything 
    starty = (LINES - THEIGHT) / 2;  // Calculating for a center placement 
    startx = (COLS - TWIDTH) / 2;    // of the window                
	char *choices[] = {
                        "1) Yes.",
                        "2) No.",
                      };
	int n_choices = sizeof(choices) / sizeof(char *);
    menu_win = newwin(THEIGHT, TWIDTH, starty, startx);
    keypad(menu_win, TRUE);
    mvprintw(startx-71, starty+52, "Play another game?, Press ENTER to select a choice.");
    refresh();
    Print_Menu(menu_win, highlight, n_choices, choices);
    while(1)
    {   
		c = wgetch(menu_win);
        switch(c)
        {       
			case KEY_UP:
			{
                if(highlight == 1)
				{
                    highlight = n_choices;
				}
                else
				{
                    --highlight;
				}
                break;
			}
            case KEY_DOWN:
			{
                if(highlight == n_choices)
				{
                    highlight = 1;
				}
                else
				{
                    ++highlight;
				}
                break;
			}
            case 10:
			{
                choice = highlight;
                break;
			}
        }
        Print_Menu(menu_win, highlight, n_choices, choices);
        if(choice != 0) // User did a choice come out of the infinite loop 
		{
            break;
		}
    } 
	*flag=choice;
    clrtoeol();
	clear();
    refresh();
    endwin();
}

void With_Computer(int option,char pl1ch, WINDOW *menu_win)
{
	char player1[PLMAX], player2[PLMAX], win[PLMAX], pl2ch, board[BMAX];
	int player = 1, count = 0, playerNum = 1, didWin = 0, canWeMove = 0, nMoves = 0, startx = 0, starty = 0, highlight = 1, choice = 0, c, i, x = 100, y = 24;
	Accept_Names(option,player1,player2,menu_win);
	if(pl1ch=='X')
	{
		pl2ch='O';
	}
	else
	{
		pl2ch='X';
	}
	initscr();
    clear();
	cbreak(); 
    noecho();
    keypad(stdscr, TRUE);
    for(i=1; i<=9;i++)
	{
		board[i] = ' ';
	}
	Draw_Board(menu_win,startx,starty);
	mvprintw(18, 82, "Use UP,DOWN,LEFT,RIGHT keys to move on the board");
	mvprintw(19, 82, "Press ENTER to select a position");
	mvprintw(20, 82, "Press SPACE to end the game");
	mvprintw(22, 82, "It is %s turn to place an (%c)",player1,pl1ch);
	move(y, x);
	refresh();
			
	while (c != ' ')
	{
		if(nMoves == 9) 
		{
			mvprintw(30, 82, "Tie game, Press ENTER to continue.");
			c = getch();
			erase();
			clrtoeol();
			clear();
			refresh();
			endwin();
			break;
		}
			
		if(playerNum == 1)
			c = getch();

		if(c != 10 && playerNum == PLAYER_1)	
		{
			switch (c)
			{
				case KEY_UP:
				{
					if(y == 26 || y == 28)
					{
						move(y-=2, x);
					}
					break;
				}
				case KEY_DOWN:
				{
					if(y == 24 || y == 26)
					{
						move(y+=2, x);
					}
					break;
				}
				case KEY_LEFT:
				{
					if(x == 108 || x == 104)
					{
						move(y, x-=4);
					}
					break;
				}
				case KEY_RIGHT:
				{
					if(x == 100 || x == 104)
					{
						move(y, x+=4);
					}
					break;
				}						
			}
		}
		else if(playerNum == PLAYER_1 && c == 10)
		{
			getyx(stdscr, y, x);
			canWeMove = Update_Board(board, x, y,pl1ch);
			if(canWeMove == OKAY) 
			{
				mvaddch(y, x, pl1ch);
				/* Returns 1 if last move caused winning scenario */
				didWin = Check(board, pl1ch);
				if(didWin)
				{
                    mvprintw(30, 82, "%s wins, Press ENTER to continue.",player1);
					c = getch();
					Save_Results(option, player1, player2, player1);
					erase();
					clrtoeol();
					clear();
					refresh();
					endwin();						
					break;
				}
				nMoves += 1;
				playerNum = 2;
				move(y, x);
			}
		}
		else if(playerNum == PLAYER_2)	
		{
			Computer_Move(board, &x, &y);//Computers move selection
			canWeMove = Update_Board(board, x, y,pl2ch);
			if(canWeMove == OKAY) 
			{
				mvaddch(y, x, pl2ch);
				/* Returns 1 if last move caused winning scenario */
				didWin = Check(board,pl2ch);
				if(didWin)
				{
					mvprintw(30, 82, "%s wins, Press ENTER to continue.",player2);
					c = getch();
					Save_Results(option, player1, player2, player2);
					erase();
					clrtoeol();
					clear();
					refresh();
					endwin();						
					break;
				}
				nMoves += 1;
				playerNum = 1;
				mvprintw(22, 82, "It is %s turn to place an (%c)",player1,pl1ch);
				move(y, x);
			}
		}
		refresh();
	}
	clrtoeol();
	clear();
    refresh();
    endwin();
}

void Computer_Move(char board[], int *x, int *y)
{
	int r,random;
	//Computer wining condition
	if(board[1]==' ' && board[2]=='O' && board[3]=='O')
	{
		*y = 24;*x = 100;//board[1]='O';
	}
	else if(board[4]==' ' && board[5]=='O' && board[6]=='O')
	{
		*y = 26;*x = 100;//board[4]='O';
	}
	else if(board[7]==' ' && board[8]=='O' && board[9]=='O')
	{
		 *y = 28;*x = 100;//board[7]='O';
	}
	else if(board[1]=='O' && board[2]==' ' && board[3]=='O')
	{
		*y = 24;*x = 104;//board[2]='O'; 
	}		
	else if(board[4]=='O' && board[5]==' ' && board[6]=='O')
	{
		*y = 26;*x = 104;//board[5]='O';
	}		
	else if(board[7]=='O' && board[8]==' ' && board[9]=='O')
	{
		*y = 28;*x = 104;//board[8]='O'; 
	}
	else if(board[1]=='O' && board[2]=='O' && board[3]==' ')
	{
		*y = 24;*x = 108;//board[3]='O';
	}		
	else if(board[4]=='O' && board[5]=='O' && board[6]==' ')
	{
		*y = 26;*x = 108;//board[6]='O';
	}		
	else if(board[7]=='O' && board[8]=='O' && board[9]==' ')
	{
		*y = 28;*x = 108;//board[9]='O'; 
	}        
    else if(board[1]==' ' && board[4]=='O' && board[7]=='O')
	{
		*y = 24;*x = 100;//board[1]='O';
	}		
	else if(board[2]==' ' && board[5]=='O' && board[8]=='O')
	{
		*y = 24;*x = 104;//board[2]='O';
	}		
	else if(board[3]==' ' && board[6]=='O' && board[9]=='O')
	{
		*y = 24;*x = 108;//board[3]='O'; 
	}
    else if(board[1]=='O' && board[4]==' ' && board[7]=='O')
	{
		*y = 26;*x = 100;//board[4]='O';
	}		
	else if(board[2]=='O' && board[5]==' ' && board[8]=='O')
	{
		*y = 26;*x = 104;//board[5]='O';
	}		
	else if(board[3]=='O' && board[6]==' ' && board[9]=='O')
	{
		*y = 26;*x = 108;//board[6]='O';
	}
	else if(board[1]=='O' && board[4]=='O' && board[7]==' ')
	{
		*y = 28;*x = 100;//board[7]='O';
	}		
	else if(board[2]=='O' && board[5]=='O' && board[8]==' ')
	{
		*y = 28;*x = 104;//board[8]='O';
	}		
	else if(board[3]=='O' && board[6]=='O' && board[9]==' ')
	{
		*y = 28;*x = 108;//board[9]='O'; 
	}      
	else if(board[1]==' ' && board[5]=='O' && board[9]=='O')
	{
		*y = 24;*x = 100;//board[1]='O';
	}		
	else if(board[1]=='O' && board[5]==' ' && board[9]=='O')
	{
		*y = 26;*x = 104;//board[5]='O';
	}		
	else if(board[1]=='O' && board[5]=='O' && board[9]==' ')
	{
		*y = 28;*x = 108;//board[9]='O';
	}
	else if(board[3]==' ' && board[5]=='O' && board[7]=='O')
	{
		*y = 24;*x = 108;//board[3]='O';
	}		
	else if(board[3]=='O' && board[5]==' ' && board[7]=='O')
	{
		*y = 26;*x = 104;//board[5]='O';
	}		
	else if(board[3]=='O' && board[5]=='O' && board[7]==' ')
	{
		*y = 28;*x = 100;//board[7]='O';
	}
	//Player winning condition
	else if(board[1]==' ' && board[2]=='X' && board[3]=='X')
	{
		*y = 24;*x = 100;//board[1]='O';
	}		
	else if(board[4]==' ' && board[5]=='X' && board[6]=='X')
	{
		*y = 26;*x = 100;//board[4]='O';
	}		
	else if(board[7]==' ' && board[8]=='X' && board[9]=='X')
	{
		*y = 28;*x = 100;//board[7]='O';
	}
	else if(board[1]=='X' && board[2]==' ' && board[3]=='X')
	{
		*y = 24;*x = 104;//board[2]='O';
	}		
	else if(board[4]=='X' && board[5]==' ' && board[6]=='X')
	{
		*y = 26;*x = 104;//board[5]='O';
	}		
	else if(board[7]=='X' && board[8]==' ' && board[9]=='X')
	{
		*y = 28;*x = 104;//board[8]='O';
	}
	else if(board[1]=='X' && board[2]=='X' && board[3]==' ')
	{
		*y = 24;*x = 108;//board[3]='O';
	}
	else if(board[4]=='X' && board[5]=='X' && board[6]==' ')
	{
		*y = 26;*x = 108;//board[6]='O';
	}		
	else if(board[7]=='X' && board[8]=='X' && board[9]==' ')
	{
		*y = 28;*x = 108;//board[9]='O'; 
    }
    else if(board[1]==' ' && board[4]=='X' && board[7]=='X')
	{
		*y = 24;*x = 100;//board[1]='O';
	}		
	else if(board[2]==' ' && board[5]=='X' && board[8]=='X')
	{
		*y = 24;*x = 104;//board[2]='O';
	}		
	else if(board[3]==' ' && board[6]=='X' && board[9]=='X')
	{
		*y = 24;*x = 108;//board[3]='O'; 
	}
    else if(board[1]=='X' && board[4]==' ' && board[7]=='X')
	{
		*y = 26;*x = 100;//board[4]='O';
	}		
	else if(board[2]=='X' && board[5]==' ' && board[8]=='X')
	{
		*y = 26;*x = 104;//board[5]='O';
	}
	else if(board[3]=='X' && board[6]==' ' && board[9]=='X')
	{
		*y = 26;*x = 108;//board[6]='O';
	}		
	else if(board[1]=='X' && board[4]=='X' && board[7]==' ')
	{
		*y = 28;*x = 100;//board[7]='O';
	}		
	else if(board[2]=='X' && board[5]=='X' && board[8]==' ')
	{
		*y = 28;*x = 104;//board[8]='O';
	}		
	else if(board[3]=='X' && board[6]=='X' && board[9]==' ')
	{
		*y = 28;*x = 108;//board[9]='O';
	}
	else if(board[1]==' ' && board[5]=='X' && board[9]=='X')
	{
		*y = 24;*x = 100;//board[1]='O';
	}
	else if(board[1]=='X' && board[5]==' ' && board[9]=='X')
	{
		*y = 26;*x = 104;//board[5]='O';
	}
	else if(board[1]=='X' && board[5]=='X' && board[9]==' ')
	{
		*y = 28;*x = 108;//board[9]='O';
	}
	else if(board[3]==' ' && board[5]=='X' && board[7]=='X')
	{
		*y = 24;*x = 108;//board[3]='O';
	}
	else if(board[3]=='X' && board[5]==' ' && board[7]=='X')
	{
		*y = 26;*x = 104;//board[5]='O';
	}
	else if(board[3]=='X' && board[5]=='X' && board[7]==' ')
	{
		*y = 28;*x = 100;//board[7]='O';
	}
    else 
	{
		r=0;
		while(r!=1)//Randomisation algorithm
		{
			srand(time(NULL));
			random=rand() % 9 + 1;
			if(board[1]==' ' && random==1)
			{
				*y = 24;*x = 100;//board[1]='O';
				r=1;
			}
			if(board[2]==' ' && random==2)
			{
				*y = 24;*x = 104;//board[2]='O';
				r=1;
			}
			if(board[3]==' ' && random==3)
			{
				*y = 24;*x = 108;//board[3]='O';
				r=1;
			}
			if(board[4]==' ' && random==4)
			{
				*y = 26;*x = 100;//board[4]='O';
				r=1;
			}
			if(board[5]==' ' && random ==5)
			{
				*y = 26;*x = 104;//board[5]='O';
				r=1;
			}
			if(board[6]==' ' && random==6)
			{
				*y = 26;*x = 108;//board[6]='O';
				r=1;
			}
			if(board[7]==' ' && random==7)
			{
				*y = 28;*x = 100;//board[7]='O';
				r=1;
			}
			if(board[8]==' ' && random==8)
			{
				*y = 28;*x = 104;//board[8]='O';
				r=1;
			}
			if(board[9]==' ' && random==9)
			{
				*y = 28;*x = 108;//board[9]='O';
				r=1;
			}           
    	}
	}
}

void View_Results(WINDOW *menu_win)
{
	int startx = 0, starty = 0, highlight = 1, choice = 0, c;
    initscr();
    clear();
    noecho();
    cbreak();       // Line buffering disabled. pass on everything 
    starty = (LINES - VHEIGHT) / 2;  // Calculating for a center placement 
    startx = (COLS - VWIDTH) / 2;    // of the window                
	char *choices[] = {
                        "1) View records of Player v/s Player game",
                        "2) View records of Player v/s Computer game",
                      };
	int n_choices = sizeof(choices) / sizeof(char *);
    menu_win = newwin(VHEIGHT, VWIDTH, starty, startx);
    keypad(menu_win, TRUE);
    mvprintw(startx-55, starty+70, "SELECT AN OPTION");
    refresh();
    Print_Menu(menu_win, highlight, n_choices, choices);
    while(1)
    {
		c = wgetch(menu_win);
        switch(c)
        {       
			case KEY_UP:
			{
                if(highlight == 1)
				{
                    highlight = n_choices;
				}
                else
				{
                    --highlight;
				}
                break;
			}
            case KEY_DOWN:
			{
                if(highlight == n_choices)
				{
                    highlight = 1;
				}
                else
				{
                    ++highlight;
				}
                break;
			}
             case 10:
			 {
                choice = highlight;
                break;
			 }
        }
        Print_Menu(menu_win, highlight, n_choices, choices);
        if(choice != 0) // User did a choice come out of the infinite loop 
		{
            break;
		}
	} 
	clrtoeol();
	clear();
    refresh();
    endwin();
	Fetch_Results(choice);
}

void Save_Results(int option, char player1[], char player2[], char win[])
{
	time_t t;
	time(&t);
	FILE *cfPtr;
	if(option==1)
	{
		cfPtr = fopen( "withcomputer.txt", "a" );
	}
	else
	{
		cfPtr = fopen( "withplayer.txt", "a" );
	}
	
	if (cfPtr == NULL )
	{
	    puts( "File could not be opened" );
	} // end if
	else 
	{ 
		fprintf( cfPtr, "Game: %s v/s %s, Won by: %s, On: %s\r\n", player1, player2, win , ctime(&t));
	   	fclose( cfPtr ); // fclose closes file   
	} // end else
}

void Fetch_Results(int option)
{
	char player1[PLMAX], player2[PLMAX], win[PLMAX];
	time_t t;
	time(&t);
	FILE *cfPtr;
	int i;
	const size_t line_size = 300;
	char* line = malloc(line_size);
	if(option==1)
	{
		cfPtr = fopen( "withplayer.txt", "r" );
	}
	else
	{
		cfPtr = fopen( "withcomputer.txt", "r" );		
	}
	i=0;
	initscr();
	clear();
	noecho();
	cbreak();  
    mvprintw(9, 55, "********************************************GAME RECORDS********************************************");
	fseek (cfPtr, 0, SEEK_END);
	if(ftell(cfPtr)==0) 
	{
		mvprintw(11, 65, "No records were found");
		refresh();
	}
    else 
	{ 
		rewind(cfPtr);
		while (fgets(line, line_size, cfPtr))
	    {		    
        	mvprintw(11+i, 65, "%s",line);
			i++;
	    }
	    free(line); 
	    
	    refresh();
	}
	fclose(cfPtr);
	clrtoeol();
	getch();
    endwin();	
}

void Accept_Names(int option, char player1[], char player2[], WINDOW *menu_win)
{
	int i, h, y = (LINES - ANHEIGHT) / 2, x = (COLS - ANWIDTH) / 2;
	menu_win = newwin(ANHEIGHT, ANWIDTH, y, x);
	box(menu_win, 0, 0);
	wrefresh(menu_win);
	mvprintw(25, 100, "INPUT NAMES");refresh();
	if(option == 1)
	{
		//Enter player1 name
		mvprintw(27,82,"Enter the name of Player 1: ");refresh();
		echo();
		scanw("%[^\n]s",player1);
		stpcpy(player2,"Computer");
	}
	else
	{
		mvprintw(27,82,"Enter the name of Player 1: ");refresh();
		echo();
		scanw("%[^\n]s",player1);
		mvprintw(30,82,"Enter the name of Player 2: ");refresh();
		echo();
		scanw("%[^\n]s",player2);
	}
	clrtoeol();
	clear();
	refresh();
    endwin();
}

void Print_Menu(WINDOW *menu_win, int highlight, int n_choices, char *choices[])
{
	int x = 2, y = 2, i;    
	box(menu_win, 0, 0);
	for(i = 0; i < n_choices; ++i)
    {   
		if(highlight == i + 1) /* High light the present choice */
        {       
			wattron(menu_win, A_REVERSE);
            mvwprintw(menu_win, y, x, "%s", choices[i]);
            wattroff(menu_win, A_REVERSE);
        }
        else
		{
            mvwprintw(menu_win, y, x, "%s", choices[i]);
		}
        ++y;
    }
    wrefresh(menu_win);
}

void With_Player(int option, char pl1ch, WINDOW *menu_win)
{
	char player1[PLMAX], player2[PLMAX], win[PLMAX], pl2ch;
	int player, count;
	player = 1;count = 0;
	Accept_Names(option,player1,player2,menu_win);
	if(pl1ch=='X')
	{
		pl2ch='O';
	}
	else
	{
		pl2ch='X';
	}
	
	char board[BMAX];
	int playerNum = 1, didWin = 0, canWeMove = 0, nMoves = 0, startx = 0, starty = 0, highlight = 1, choice = 0, c, i, x = 100, y = 24;
	initscr();
    cbreak(); 
    noecho();
    keypad(stdscr, TRUE);
    for(i=1; i<=9;i++)
	{
		board[i] = ' ';
	}
		
    Draw_Board(menu_win,startx,starty);
	mvprintw(18, 82, "Use UP,DOWN,LEFT,RIGHT keys to move on the board");
	mvprintw(19, 82, "Press ENTER to select a position");
	mvprintw(20, 82, "Press SPACE to end the game");
	mvprintw(22, 82, "It is %s turn to place an (%c)",player1,pl1ch);//////////////////
	move(y, x);
	refresh();
			
	while (c != ' ')
	{
		if(nMoves == 9) 
		{
			mvprintw(30, 82, "Tie game, Press ENTER to continue.");
			c = getch();
			erase();
			clrtoeol();
			clear();
			refresh();
			endwin();
			break;
		}
		c = getch();

		/* If not spacebar, they are moving */
		if(c != 10)
		{
			switch (c)
			{
				case KEY_UP:
				{
					if(y == 26 || y == 28)
					{
						move(y-=2, x);
					}
					break;
				}
				case KEY_DOWN:
				{
					if(y == 24 || y == 26)
					{
						move(y+=2, x);
					}
					break;
				}
				case KEY_LEFT:
				{
					if(x == 108 || x == 104)
					{
						move(y, x-=4);
					}
					break;
				}
				case KEY_RIGHT:
				{
					if(x == 100 || x == 104)
					{
						move(y, x+=4);
					}
					break;	
				}						
			}
		}
		else if(playerNum == PLAYER_1 && c == 10) // Player's move
		{
			getyx(stdscr, y, x);
			canWeMove = Update_Board(board, x, y,pl1ch);
			if(canWeMove == OKAY) 
			{
				mvaddch(y, x, pl1ch);
				/* Returns 1 if last move caused winning scenario */
				didWin = Check(board, pl1ch);
				if(didWin)
				{
                    mvprintw(30, 82, "%s wins, Press ENTER to continue.",player1);
					c = getch();
					Save_Results(option, player1, player2, player1);
					erase();
					clrtoeol();
					clear();
					refresh();
					endwin();
					break;
				}
				nMoves += 1;
				playerNum = 2;
				mvprintw(22, 82, "It is %s turn to place an (%c)",player2,pl2ch);
				move(y, x);
			}
		}
		else if(playerNum == PLAYER_2 && c == 10) //Computer's move
		{
			getyx(stdscr, y, x);
			canWeMove = Update_Board(board, x, y,pl2ch);
			if(canWeMove == OKAY) 
			{
				mvaddch(y, x, pl2ch);
				/* Returns 1 if last move caused winning scenario */
				didWin = Check(board,pl2ch);
				if(didWin)
				{
					mvprintw(30, 82, "%s wins, Press ENTER to continue.",player2);
					c = getch();
					Save_Results(option, player1, player2, player2);
					erase();
					clrtoeol();
					clear();
					refresh();
					endwin();
					break;
				}
				nMoves += 1;
				playerNum = 1;
				mvprintw(22, 82, "It is %s turn to place an (%c)",player1,pl1ch);
				move(y, x);
			}
		}
		refresh();
	}
	clrtoeol();
	clear();
    refresh();
    endwin();
}

void Draw_Board(WINDOW *menu_win, int startx,int starty) 
{

	int i, h, y = (LINES - BHEIGHT) / 2, x = (COLS - BWIDTH) / 2;
	WINDOW *win = newwin(BHEIGHT, BWIDTH, y, x);
	box(win, 0, 0);
	refresh();
	for(i=1;i<=5;i++) 
	{
		mvaddch(XOF+i, YOF+4, '|');
		mvaddch(XOF+i, YOF+8, '|');
		mvaddch(XOF+i, YOF+4, '|');
		mvaddch(XOF+i, YOF+8, '|');
		if(i%2 == 0)
		{
			for(h=0;h<=12;h++) 
			{
				mvaddch(XOF+i,YOF+h, '-');
			}
		}
		move(XOF+1,YOF+2);
	}
	wrefresh(win);
}

int Update_Board(char board[], int x, int y, char XorO) 
{
	/* Check row 1*/
	if(y == 24)
	{
		if(x == 100)
		{
			if(board[1] = ' ')
			{
				board[1] = XorO;
				return OKAY;
			}
		}
		else if( x == 104)
		{	
			if(board[2] = ' ')
			{
				board[2] = XorO;
				return OKAY;
			}
		}
		else if( x == 108)
		{
			if(board[3] = ' ')
			{
				board[3] = XorO;
				return OKAY;
			}
		}
	} 
	else if(y == 26)/* Check row 2 */
	{
		if(x == 100)
		{
			if(board[4] = ' ')
			{
				board[4] = XorO;
				return OKAY;
			}
		}	
		else if( x == 104)
		{	
			if(board[5] = ' ')
			{
				board[5] = XorO;
				return OKAY;
			}
		}
		else if( x == 108)
		{
			if(board[6] = ' ')
			{
				board[6] = XorO;
				return OKAY;
			}
		}
	}	
	else if(y == 28)/* Check row 3*/
	{			
		if(x == 100)
		{
			if(board[7] = ' ')
			{
				board[7] = XorO;
				return OKAY;
			}
		}
		else if( x == 104)
		{
			if(board[8] = ' ')
			{
				board[8] = XorO;
				return OKAY;
			}
			
		}
		else if( x == 108)
		{
			if(board[9] = ' ')
			{
				board[9] = XorO;
				return OKAY;
			}
		}
	}
	return FALSE;	
		   
}

int Check(char board[], char XorO) 
{
	if((board [1] == board [2] && board [2] == board [3] && board [3] == XorO) || (board [4] == board [5] && board [5] == board [6] && board [6] == XorO) || (board [7] == board [8] && board [8] == board [9] && board [9] == XorO) || (board [1] == board [4] && board [4] == board [7] && board [7] == XorO) || (board [2] == board [5] && board [5] == board [8] && board [8] == XorO) || (board [3] == board [6] && board [6] == board [9] && board [9] == XorO) || (board [1] == board [5] && board [5] == board [9] && board [9] == XorO) || (board [3] == board [5] && board [5] == board [7] && board [7] == XorO))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
