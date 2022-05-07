#include <iostream>
#include <vector>
#include <cstdlib>
#include <unistd.h>
#include <string>
#include <ctime>
#include <stdio.h>
#include <termios.h>
#include <iomanip>

#include <fstream>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "execution.h"
#include "Game.h"
using namespace std;



int main(){
	srand(time(NULL));
	int level;

	vector<node> snake = create_snake(20, 10);//use a vector variable to store the information of snake (parameters need to be double-checked)
	cout << "\033[8;40;70t";//set the size of the console to be 40x70
	cout << "\033c"; //clear the screen
	create_game_area();//prints the board of the game

	print_snake(snake);
	level = reading();//read the saved level

	run_game(snake, level);

	return 0;
}
