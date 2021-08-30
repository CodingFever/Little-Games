#ifndef SHAKE_H
#define SHAKE_H
#include <cstdlib>
#include <vector>

using namespace std;

#define WIDTH 50
#define HEIGHT 25

class Snake{
	private:
		
        int speed; //speed of the snake
        char direction; // moving direction
        int length;//length of the snake
        

	public:
		Snake();
		void change_direction(char dire);
		void movement();
		


		~Snake();
	
};
#endif 