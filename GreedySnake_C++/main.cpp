/*
Since I am using mac, I cannot use window.h header. Instead, 
I"ll using ncurses to make this game 
*/
#include <iostream>
#include <cstdlib>
#include <ncurses.h>

using namespace std;
const int WIDTH = 20, HEIGHT = 20;

enum eDirection
{
	STOP = 0,
	LEFT,
	RIGHT,
	UP,
	DOWN
};
eDirection dir;

int BodyX[100], BodyY[100];
int Body_len = 0;
bool gameOver;
//position_x, position_y, point_pos_x, point_pox_y, score_gained
int x, y, Pointx, Pointy, score;

void SetUp()
{
	/*
	The following function is in curses header
	to make sure ncurses can run successfully, put in initial
	*/

	// start curses
	initscr();
	//using clearok to clean screen
	clear();
	//close key in
	noecho();
	//if input a key, send into code
	cbreak();
	//setting appearance.
	// 0 - invisible
	// 1 - terminal normal mode
	// 2 - terminal high visible mode
	curs_set(0);

	/*
	The main set-up for the snake start
	*/
	gameOver = false;
	dir = STOP;
	//set snack position in the middle
	x = WIDTH / 2;
	y = HEIGHT / 2;
	//point will be generated randomly in the map
	Pointx = (rand() % WIDTH) + 1;
	Pointy = (rand() % HEIGHT) + 1;
	score = 0;
}

void Drew()
{
	//start with clear the window
	clear();
	//there are 2 boundary to print, therefore, WIDTH+2
	for (int i = 0; i < WIDTH + 2; i++)
	{ //the mvprintw is like printf() in <ncurses.h>,
		//print the horizantal boundary
		mvprintw(0, i, "|");
	}

	//double for loop for print the whole board
	for (int a = 0; a < HEIGHT + 2; a++)
	{
		for (int b = 0; b < WIDTH + 2; b++)
		{ //up and down boundary
			if (a == 0 || a == 26)
			{
				mvprintw(a, b, "--");
			}
			else if (b == 0 | b == 21)
			{
				mvprintw(a, b, "+");
			}
			//head of the snake
			else if (a == y && b == x)
			{
				mvprintw(a, b, "S");
			}
			//point generate and print
			else if (a == Pointx && b == Pointy)
				mvprintw(a, b, "P");
			//print the snake body
			else
				for (int k = 0; k < Body_len; k++)
				{
					if (BodyX[k] == b && BodyY[k] == a)
						mvprintw(a, b, "o");
				}
		}
	}
	//print the total score
	mvprintw(23, 0, "Score %d", score);
	//add end to the print
	refresh();
	getch();
	//end curses
	endwin();
}

int main()
{
	SetUp();
	Drew();
	return 0;
}