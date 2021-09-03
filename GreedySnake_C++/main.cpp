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
	dir = LEFT;
	//set snack position in the middle
	x = WIDTH / 2;
	y = HEIGHT / 2;
	//point will be generated randomly in the map
	Pointx = (rand() % WIDTH) + 1;
	Pointy = (rand() % HEIGHT) + 1;
	score = 0;
}

void PrintBoard()
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
			if (a == 0 || a == HEIGHT + 1)
			{
				mvprintw(a, b, "-");
			}
			else if (b == 0 | b == WIDTH + 1)
			{
				mvprintw(a, b, "|");
			}
			//head of the snake
			else if (a == y && b == x)
			{
				mvprintw(a, b, "S");
			}
			//point generate and print
			else if (a == Pointy && b == Pointx)
			{
				mvprintw(a, b, "P");
			}
			//print the snake body
			else
				for (int k = 0; k < Body_len; k++)
				{
					if (BodyX[k] == b && BodyY[k] == a)
					{		
						mvprintw(a, b, "o");
					}
				}
		}
	}
	//print the total score
	mvprintw(HEIGHT + 3, 0, "Score %d", score);
	//add end to the print
	refresh();
}

//getting the operation
void Input()
{
	//initial state is FALSE.
	keypad(stdscr, TRUE);
	//halfdelay allow user to type something
	//then getch returns the keypress
	halfdelay(1); //gain input in 1 tenths sec

	int gain = getch();

	switch (gain)
	{ //getting input dir and change the snack dir
	case KEY_LEFT:
		dir = LEFT;
		break;
	case KEY_RIGHT:
		dir = RIGHT;
		break;
	case KEY_UP:
		dir = UP;
		break;
	case KEY_DOWN:
		dir = DOWN;
		break;
	case 113: //exit -> q == 113
		gameOver = true;
		break;
	}
}

void Movement()
{
	/*
	make sure the body print
	
	The logic will be like, when the next block move
	to the prev block, it makes the same operation
	eg: if head turn left at (1,1), the next body
	block will make trun at the same pos(1,1)
	again, if no change, then no change
	*/

	//gain the previous pos
	int prevX = BodyX[0];
	int prevY = BodyY[0];
	//temp var
	int x2,y2;
	//get cur_pos
	BodyX[0] = x;
	BodyY[0] = y;
	//update and make change
	//start when len>=1
	for (int i = 1; i < Body_len; i++){
		x2 = BodyX[i];
		BodyX[i] = prevX;
		prevX = x2;

		y2 = BodyY[i];
		BodyY[i] = prevY;
		prevY = y2;

	}

	//change direction
	switch (dir)
	{
		{
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case UP:
			y--;
			break;
		case DOWN:
			y++;
			break;
		default:
			break;
		}
	}
	//if hit the boudary
	if (x > WIDTH || y > HEIGHT || x < 1 || y < 1)
	{
		gameOver = true;
	}
	//if touch point
	if (x == Pointx && y == Pointy)
	{	
		//increase score
		score++;
		//generate new point pos
		Pointx = (rand() % WIDTH) + 1;
		Pointy = (rand() % HEIGHT) + 1;
		//body length
		Body_len++;
		
	}
	//if hit body
	for(int i = 0; i<Body_len; i++){
		if(BodyX[i] == x && BodyY[i] == y)
		{
			gameOver = true;
		}
	}

}
int main()
{
	SetUp();
	while (!gameOver)
	{
		PrintBoard();
		Input();
		Movement();
	}

	getch();
	//end curses
	endwin();
	return 0;
}