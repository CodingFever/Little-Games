#include <iostream>

using namespace std;

#define WIDTH 50
#define HEIGHT 25

//initial the playing background
void board(){
	for (int i = 0; i < HEIGHT; i++){
		cout << "#";
		for(int j = 0; j < WIDTH; j++){
			if(i == 0|| i == HEIGHT-1){cout << "#";}
			else{cout << " ";}
		}
		cout << "#\n";
	}
}

int main(){
	board();
	return 0;
}