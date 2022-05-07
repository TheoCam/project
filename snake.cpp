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
using namespace std;

struct node{ //node represents each section of the snake's body
	int x;
	int y;
	char text;
};

//Bao's Part
void MoveCursorPosition(int x, int y)
{
    printf (  "\033[%d;%dH", y,x );
}

void PrintAtCursor(char ch, int x, int y)
{
    MoveCursorPosition(x, y);
    printf(  "\033[0;30;47m %c \n", ch  );
}

// width = height/2
void create_game_area( )
{
    int width_index = 0;
    int height_index = 0;



    for(width_index = 0; width_index < 40; width_index++) {
        for(height_index = 0; height_index < 20 ; height_index++) {


            PrintAtCursor( ' ', width_index, height_index);
        }
    }

    return;
}


bool check_game_over(vector<node> snake/*铔囧ご*/)
{
    // hit walls
    if (snake[0].x==0 || snake[0].x==40 || snake[0].y==0 || snake[0].y==20) {
        return true;
    }

    // hit itself
    for ( int i=1; i<snake.size(); ++i) {
        if (snake[0].x == snake[i].x  &&  snake[0].y == snake[i].y) {
            return true;
        }
    }

    return false;
}

void saving_game(int current_level)
{

        ofstream fout;
        fout.open("game_level.txt");


        if ( fout.fail() ) {
            cout << "Error in file opening!" << endl;
						exit(1);
        }


        fout << current_level << endl;
        fout.close();


}

int reading()
{
        int current_level;
        char game_level[100] = "game_level.txt";
        ifstream fin;
        fin.open(game_level);


        if ( fin.fail() ) {
            cout << "Error in file opening!" << endl;
						exit(1);
        }



        fin >> current_level;
        fin.close();
        return current_level;

}

// timing
double timing(int current_level)
{
    clock_t start, end;
    start = clock();

    if ( current_level==10 ) {
        end = clock();
        double used_time = (double)(end-start)/ CLOCKS_PER_SEC;   // UNIT: s
        return used_time;
    }
}


void record_time(int used_time)
{

        ofstream fout;
        fout.open("time_record.txt", ios::app);   // 鑳戒笉鑳界洿鎺ュ湪鏂扮殑txt鏂囦欢append锛?


        if ( fout.fail() ) {
            cout << "Error in file opening!" << endl;
        }
        exit(1);

        fout << used_time << endl;
        fout.close();

}

//Liu's part
void print_snake(vector<node> snake){// This function shows the snake on the screeen (missing method of specifying position of output)
	//Not complete! (Bao's Part);
	for (int i=0; i<snake.size(); i++){
		printf("\033[%d;%dH", snake[i].y, snake[i].x);
		cout << snake[i].text;
	}
}

void add_node(vector<node> snake, int x, int y, char text){//This function adds one node to the snake

}

vector<node> create_snake(int x, int y){//This function creates the snake of type vector
	node head;
	head.x = x;
	head.y = y;
	head.text = '$';//The head of the snake is represented by the symbol $

	vector<node> snake;
	snake.push_back(head);
	return snake;
}

void generate_foodx(int& food_x, int& food_y, vector<node> snake){//This function generates the x-coordinate of the food (missing board size)
	food_x=(rand()%38+1); //generate a number in range [1, 69]. This is the x coordinate of the food
	food_y=(rand()%18+1);
	for(int i=0; i<snake.size(); i++){
		while(food_x==snake[i].x && food_y==snake[i].y){
			food_x = (rand()%38+2);
			food_y = (rand()%18+2);
		}
	}
}

// int generate_foody(vector<node> snake){//This function generates the y-coordinate of the food (missing board size)
// 	int y=(rand()%69+1); //generate a number in range [1, 69]. This is the y coordinate of the food
// 	for(int i=0; i<snake.size(); i++){
// 		while(y==snake[i].y){
// 			y = (rand()%69+1);
// 		}
// 	}
// 	return y;
// }

char read_input(){
   char input;
   termios new_mode;//termios is a struct defined in termios.h which stores the data of the terminal
   termios old_mode;//These two lines two termios type variable to store the charateristics of terminal
   tcgetattr(0, &old_mode);//This line gets the input parameters associated with the terminal
                           //and stores in ond_mode
                           //0 is a file descriptor representing standard input
   new_mode = old_mode;
   new_mode.c_lflag &= (~ICANON);//disable the conical mode of reading input
                                 //(the end of reading input will not be simply judged by an EOL)
   new_mode.c_lflag &= (~ECHO);//disable the echoing of reading input (the input text will not be shown)
   new_mode.c_cc[VMIN] = 1;    //setting the length of the expected input
   new_mode.c_cc[VTIME] = 0;   //setting the time of input timeout
   tcsetattr(0, TCSANOW, &new_mode);//set the input mode of the terminal
                                    //TCSANOW means update immediately
   input = getchar();//read a character from user;
   tcsetattr(0, TCSANOW, &old_mode);//reset the input mode to the original one
   return input;
}

// void pause(){//This function allows the user to pause the current running game (Press p again to continue)
// 	char ans;
// 	while(true){
// 		ans = read_input();
// 		if (ans == 'p')
// 			break;
// 	}
// }



void print_food(int food_x, int food_y, char food){//This function prints the food
	printf("\033[%d;%dH", food_y, food_x);  //this line uses the formating output in c to specify the position of the cursor
	cout << food;
}

void delete_food(int food_x, int food_y){//This function prints the food
	printf("\033[%d;%dH", food_y, food_x);  //this line uses the formating output in c to specify the position of the cursor
	cout << ' ';
}

void print_node(int x, int y, char text){
	printf("\033[%d;%dH", y, x);  //this line uses the formating output in c to specify the position of the cursor and printss out the text of the node
	cout << text;
}

void delete_node(int x, int y){
	printf("\033[%d;%dH", y, x);  //this line uses the formating output in c to specify the position of the cursor and covers the previously printed text
	cout << ' ';
}

void eat_food(vector<node> snake, int food_x, int food_y, char food, int direction, int &round){//This function judge whether the food is eaten by the snake or not.

}

bool judge_success(int round, int level, string food_list[10]){//This function judges whether the word for the current level is completed or not
	if ((round) == food_list[level].length())// round represents number of letters on the snake's body, food_list[level].length() is the length of the word of the current level
		return true;
	else
		return false;
}



void make_move(vector<node> snake, int direction){   //This function updates the position of each node of the snake according to direction

}

void run_game(vector<node> snake, int level){
	int next_xpos, next_ypos, prev_xpos, prev_ypos;
	int new_node_x, new_node_y;
	int sleep_time = 0.5;//setting the time interval for each movement (unit: second)
	char input, food;
	int direction = 0;//Initialize the snake so that it faces right
	int food_x, food_y;
	int round=0;
	string food_list[10] = {"apple", "math", "linear", "algebra", "physics", "computer", "elementary", "international", "application", "entertainment"};
	generate_foodx(food_x, food_y, snake);

	printf("\033[22;0H");
	cout << "food_x, food_y "<< setfill('0') << setw(2) << food_x << " " << setfill('0') << setw(2) << food_y;
	printf("\033[23;0H");
	cout << "level: " << level << " target: " << food_list[level];
	food = food_list[level][round];
	print_food(food_x, food_y, food);

	while (true){

		input = read_input();

		if (input <= 'Z' && input >= 'A') // make the input case insensitive
			input += ('a'-'A');

		bool con=true;
		while(con){
			if ((input == 'a' && direction != 3 )|| (input == 'a' && snake.size()==1 )){//move to the left
				direction = 1;
				con=false;
			}

			else if ((input == 'd' && direction != 1 )|| (input == 'd' && snake.size()==1 )){//move to the right
				direction = 3;
				con=false;
			}

			else if ((input == 'w' && direction != 4 )|| (input == 'w' && snake.size()==1 )){//move upward
				direction = 2;
				con=false;
			}

			else if ((input == 's' && direction != 2 )|| (input == 's' && snake.size()==1 )){//move downward
				direction = 4;
				con=false;
			}

			else if (input == 'q'){//q means quit the game
				saving_game(level);
				printf("\033[25;0H");
				cout << "Game saved and quit game ";
				break;
			}
			else{
				// printf("\033[25;0H");
				// cout << "Invalid input, try again!";
				input = read_input();
			}
		}



		// make_move(snake, direction);//make movement and show the snake on the screen


		for (int i=0; i<snake.size(); i++){
			if (i==0){
				prev_xpos = snake[i].x;
				prev_ypos = snake[i].y;
				delete_node(prev_xpos, prev_ypos);
				switch(direction){
					case 1://move to the left
						snake[i].x -= 1;
						break;
					case 2://move upward
						snake[i].y -= 1;

						break;
					case 3://move to the right
						snake[i].x += 1;
						break;
					case 4://move downward
						snake[i].y += 1;
						break;
				}

				print_node(snake[i].x, snake[i].y, snake[i].text);
			}
			else{
				next_xpos = snake[i].x;
				next_ypos = snake[i].y;
				delete_node(next_xpos, next_ypos);

				snake[i].x = prev_xpos;
				snake[i].y = prev_ypos;
				print_node(prev_xpos, prev_ypos, snake[i].text);

				prev_xpos = next_xpos;
				prev_ypos = next_ypos;
			}
		}

		// eat_food(snake, food_x, food_y, food, direction, round);

		                                                                //If so, add the corresponding letter to the body of the snake
		if (snake[0].x == food_x && snake[0].y == food_y){//to judge whetherthe posititon of the head coincides with the position of the food
			new_node_x = snake[snake.size()-1].x;
			new_node_y = snake[snake.size()-1].y;
			switch(direction){
				case 1:
					new_node_x += 1;
					break;
				case 2:
					new_node_y += 1;
					break;
				case 3:
					new_node_x -= 1;
					break;
				case 4:
					new_node_y -= 1;
					break;
			}
			delete_food(food_x, food_y);
			// add_node(snake, new_node_x, new_node_y, food);
			node body;
			body.x = new_node_x;
			body.y = new_node_y;
			body.text = food;

			snake.push_back(body);

			print_node(new_node_x, new_node_y, food);
			print_node(snake[0].x, snake[0].y, snake[0].text);
			round += 1;
			generate_foodx(food_x,food_y, snake);
			printf("\033[22;0H");
			cout << "food_x, food_y "<< setfill('0') << setw(2) << food_x << " " << setfill('0') << setw(2) << food_y;
			food = 	food_list[level][round];
			print_food(food_x, food_y, food);

		}

		if (check_game_over(snake)){
			printf("\033[24;0H");  //this line uses the formating output in c to specify the position of the cursor
			cout << "You fail, try again! ";
			break;
		}

		if (judge_success(round, level, food_list)){//to judge whether the word is fully spelled
			level += 1;
			round = 0;
			for (int i=0; i<snake.size(); i++){
				delete_node(snake[i].x, snake[i].y);
			}
			snake = create_snake(20,10);
			print_snake(snake);

			generate_foodx(food_x,food_y, snake);
			food = 	food_list[level][round];
			print_food(food_x, food_y, food);

			printf("\033[23;0H");
			printf("\033[K");
			cout << "level: " << level << " target: " << food_list[level];
		}


		if (level == 10){//judge whether the whole game is complete or not
			printf("\033[24;0H");  //this line uses the formating output in c to specify the position of the cursor
			cout << "Congratulations! You have completed all the levels!";
			saving_game(0);//Reset the level recorded in the txt file to be zero

			break;
		}


		//sleep() is the function that sets the pause time (measured in seconds)
		//this function is included in the library <unistd.h>

		// sleep(sleep_time);

	}
}

int main(){
	srand(time(NULL));
	int level;

	vector<node> snake = create_snake(20, 10);//use a vector variable to store the information of snake (parameters need to be double-checked)
	cout << "\033[8;40;70t";
	cout << "\033c"; //clear the screen
	create_game_area();
	//print_board

	print_snake(snake);
	level = reading();//read the saved level

	run_game(snake, level);

	return 0;
}
