#ifndef SHAKE_H
#define SHAKE_H
#include <windows.h>
#include <vector>

using namespace std;

#define WIDTH 50
#define HEIGHT 25

class Snake{
	private:
		COORD pos;//structure in window.h
        int speed; //speed of the snake
        char direction; // moving direction
        int length;//length of the snake
        

	public:
		Snake(COORD pos,int speed);
		~Snake();
	
};