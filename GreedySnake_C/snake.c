#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#define WIDTH 55
#define HEIGHT 20

typedef struct pos
{
    int x;
    int y;
} position_list;

enum eDirection
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

int direction = RIGHT; //snake default moving direction
int ch;                //input
int speed = 500;

int Score = 0;
int SnakeLength = 1; //initial snack-body-len
WINDOW *board;       //window size

void SetUp()
{

    initscr();
    noecho();
    cbreak();
    timeout(speed);
    keypad(stdscr, TRUE); //recognize input

    //COLS and LINES in ncurses filled in by initscr
    //initial as 0
    int offsetx = (COLS - WIDTH) / 2;
    int offsety = (LINES - HEIGHT) / 2;
    board = newwin(HEIGHT, WIDTH, offsety, offsetx); //get new board
}

void Game_Page()
{
    //int offsetx = (COLS - WIDTH) / 2;
    //int offsety = (LINES - HEIGHT) / 2;
    int i = 1, n = 0;
    //wait for the game start
    while (getch() != 's')
    {
        if (getch() == 'q')
        {
            break;
        }
        wclear(board);
        mvprintw(3 + HEIGHT / 2, WIDTH / 2 + 7, "Greedy Snake Game");
        mvprintw(6 + HEIGHT / 2, WIDTH / 2 + 7, "Enter 'S' to start");
        mvprintw(7 + HEIGHT / 2, WIDTH / 2 + 7, "Enter 'Q' to quit");
        mvprintw(4, WIDTH / 2 + 11, "Score: %d", Score);
        box(board, 0, 0);
        wrefresh(board);
    }
}

void CreateSnake()
{
}
void Game()
{
    int offsetx = (COLS - WIDTH) / 2;
    int offsety = (LINES - HEIGHT) / 2;
    //CreateSnake();
}

int main()
{
    SetUp();
    Game_Page();
    Game();
    return 0;
}