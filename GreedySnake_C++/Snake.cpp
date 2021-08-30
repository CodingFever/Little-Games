#include "Snake.h"
Snake::Snake (COORD pos,int speed){
	this->pos = pos;
	this->speed = speed;
	len = 1;
	direction = 'n';//none so far
}

void Snake::change_direction(char dire){
	direction = dire;
}

void Snake::movement(){
//change direction with excepting variaty inputs
	switch(dir)
    {// up | down | left | right
        case 'w': pos.Y -= vel; break;
        case 's': pos.Y += vel; break;
        case 'a': pos.X -= vel; break;
        case 'd': pos.X += vel; break;
    }
}

