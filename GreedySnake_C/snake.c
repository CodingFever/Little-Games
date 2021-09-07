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
//get snake's pos for each part
position_list snake_pos[120];
position_list Point;
int direction = RIGHT; //snake default moving direction
int ch;                //input
int speed = 500;

int Score = 0;
int SnakeLength = 4; //initial snack-body-len
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

void Game_Page(offsetx,offsety)
{
    //int offsetx = (COLS - WIDTH) / 2;
    //int offsety = (LINES - HEIGHT) / 2;
    int i = 1, n = 0;
    //wait for the game start
    while (getch() != 's')
    {
        
        //if (getch() == 'q')
        //{
        //    break;
        //}
        wclear(board);
        mvprintw(offsety + HEIGHT / 2-5, offsetx+19, "Greedy Snake Game");
        mvprintw(offsety + HEIGHT / 2, offsetx+19, "Enter 'S' to start");
        mvprintw(offsety + HEIGHT / 2+1, offsetx+19, "Enter 'Q' to quit");
        mvprintw(3, offsetx+HEIGHT/2+14, "Score: %d", Score);
        box(board, 0, 0);
        wrefresh(board);
    }
}

void CreateSnake(offsetx,offsety)
{
    wclear(board);

    for(int i = 0;i < SnakeLength;i++){
        snake_pos[i].x = offsetx+10-i;
        snake_pos[i].y = offsety;
    }
    mvwaddch(board, snake_pos[0].y, snake_pos[0].x, '0');
    for(int i = 1;i < SnakeLength;i++){
        //snake body initial print
        mvwaddch(board, snake_pos[i].y, snake_pos[i].x, '#');
    }
    mvprintw(4, WIDTH / 2 + 11, "Score: %d", Score);
    box(board,0,0);
    wrefresh(board);
}
bool Generat_Point(){
    srand(time(NULL)); 
    int Point_y = (rand() % (HEIGHT-1));
    int Point_x = (rand() % (WIDTH-1));
    for(int i = 0;i<SnakeLength;i++ ){
        //generated on on snake's body
        if(snake_pos[i].x == Point_x && snake_pos[i].y == Point_y){
            return false;
        }
        //generated on the border
        else if(Point_y == 0 ||Point_x == 0){
            return false;
        }
    }
    
        Point.y = Point_y;
        Point.x = Point_x;
        return true;
}
void Game(offsetx,offsety)
{
    CreateSnake(offsetx,offsety);
    while(Generat_Point()){
        while ((ch = getch()) != 'q') {
            wclear(board);
            mvprintw(1,offsetx+HEIGHT/2+10, "Score: %d ",Score);
            box(board, 0 , 0);
            wrefresh(board);
        }
    }
}

int main()
{
    SetUp();
    int offsetx = (COLS - WIDTH) / 2;
    int offsety = (LINES - HEIGHT) / 2;
    Game_Page(offsetx,offsety);
    if(getch() == 's'){

        Game(offsetx,offsety);
    }
    
    return 0;
}