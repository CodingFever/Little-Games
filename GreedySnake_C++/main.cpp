#include <iostream>

using namespace std;

#define WIDTH 50
#define HEIGHT 25
int x = 10;
int y = 10;
//initial the playing background
void board(){
	for (int i = 0; i < HEIGHT; i++){
		cout << "\t\t#";
		for(int j = 0; j < WIDTH-2; j++){
			if(i == 0|| i == HEIGHT-1){cout << "#";}
			else if (i == y && j == x){cout << "o";}
			else{cout << " ";}
		}
		cout << "#\n";
	}
}

int main(){
	board();
	return 0;
}