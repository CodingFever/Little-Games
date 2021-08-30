#include <iostream>
#include <cstdlib>
#include <ncurses.h>
#include "Snake.h"
using namespace std;
#define WIDTH 50
#define HEIGHT 25

//Snake snake(WIDTH/2, HEIGHT/2,1);

//initial the playing background
void board(){
	
	for (int i = 0; i < HEIGHT; i++){
		cout << "\t\t#";
		for(int j = 0; j < WIDTH-2; j++){
			if(i == 0|| i == HEIGHT-1){cout << "#";}
			else if (i == 10 && j == 10){cout << "o";}
			else{cout << " ";}
		}
		cout << "#\n";
	}
}

int main(){
	
	board();
	

	
		
	return 0;
}