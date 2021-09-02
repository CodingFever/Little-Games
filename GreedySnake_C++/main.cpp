/*
Since I am using mac, I cannot use window.h header. Instead, 
I"ll using ncurses to make this game 
*/
#include <iostream>
#include <cstdlib>
#include <ncurses.h>

using namespace std;

#define WIDTH 50
#define HEIGHT 25

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
	gameOver = false;
}

int main()
{
	SetUp();
}