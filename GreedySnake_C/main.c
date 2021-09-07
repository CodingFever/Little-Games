#include <ncurses.h>
#include <stdlib.h>
#include <time.h> 
#define WIDTH 25
#define HEIGHT 20

enum eDirection
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
int direction = RIGHT;//snake default moving direction
int ch;//input
int speed = 100;

typedef struct pos {
    int x;
    int y;
} position_list;

int Score = 0;
int SnakeLength = 1;//initial snack-body-len
WINDOW *snakeys_world;//window size

void SetUp(void){
    initscr();
    noecho();
    cbreak();
    timeout(speed);
    keypad(stdscr, TRUE);//recognize input
    int offsetx = (COLS - WIDTH) / 2;
    int offsety = (LINES - HEIGHT) / 2;
    snakeys_world = newwin(HEIGHT, WIDTH,offsety,offsetx);//get new window
    
        
}

int main(){
    SetUp();
    //WaitGame();
    //Game();
    return 0;
}