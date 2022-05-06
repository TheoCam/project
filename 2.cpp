#include <iostream>
#include <vector>
#include <cstdlib>
#include <unistd.h>
#include <string>
//#include <termios.h>
using namespace std;

struct node{ //node represents each section of the snake's body
	int x;
	int y;
	char text;
};

void print_snake(vector<node> snake){// This function shows the snake on the screeen (missing method of specifying position of output)
	//Not complete!
	cout << "\033c";
	for (int i=0; i<snake.size(); i++){
		cout << "\033[]" << snake[i].text << endl;
	}
}

void add_node(vector<node> snake, int x, int y, char text){//This function adds one node to the snake
	node body;
	body.x = x;
	body.y = y;
	body.text = text;
	
	snake.push_back(body);
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

int generate_foodx(){//This function generates the x-coordinate of the food (missing board size)
	//Not Complete!
}

int generate_foody(){//This function generates the y-coordinate of the food (missing board size)
	//Not Complete!
}

char read_input(){
//    char input;
//    termios new_mode;//termios is a struct defined in termios.h which stores the data of the terminal
//    termios old_mode;//These two lines two termios type variable to store the charateristics of terminal
//    tcgetattr(0, &old_mode);//This line gets the input parameters associated with the terminal
//                            //and stores in ond_mode
//                            //0 is a file descriptor representing standard input
//    new_mode = old_mode;
//    new_mode.c_lflag &= (~ICANON);//disable the conical mode of reading input
//                                  //(the end of reading input will not be simply judged by an EOL)
//    new_mode.c_lflag &= (~ECHO);//disable the echoing of reading input (the input text will not be shown)
//    new_mode.c_cc[VMIN] = 1;    //setting the length of the expected input
//    new_mode.c_cc[VTIME] = 0;   //setting the time of input timeout
//    tcsetattr(0, TCSANOW, &new_mode);//set the input mode of the terminal
//                                     //TCSANOW means update immediately
//    input = getchar();//read a character from user;
//    tcsetattr(0, TCSANOW, &old_mode);//reset the input mode to the original one
//    return input;
}

void pause(){//This function allows the user to pause the current running game (Press p again to continue)
	char ans;
	while(true){
		ans = read_input();
		if (ans == 'p')
			break;		
	}
}

void save_and_quit_game(){//This function allows the user to save and quit the game (Bao's Part)
	//Not Complete!
}

void judge_fail(vector<node> snake){//This function judges whether the player loses the game or not (Bao's Part)
	//Not Complete!
}

void print_food(int food_x, int food_y, char food){//This function prints the food (missing method of specifying position of output)
	//Not Complete!
}

void eat_food(vector<node> snake, int food_x, int food_y, char food, int direction){//This function judge whether the food is eaten by the snake or not. 
	int new_node_x, new_node_y;                                                     //If so, add the corresponding letter to the body of the snake
	if (snake[0].x == food_x && snake[0].y == food_y){
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
		add_node(snake, new_node_x, new_node_y, food);
	}
}

bool judge_success(int round, int level, string food_list[10]){//This function judges whether the word for the current level is completed or not
	if ((round+1) == food_list[level].length())// round+1 represents number of letters on the snake's body, food_list[level].length() is the length of the word of the current level
		return true;
	else
		return false;
}

void make_move(vector<node> snake, int direction){   //This function updates the position of each node of the snake according to direction
	int next_xpos, next_ypos, prev_xpos, prev_ypos;
	for (int i=0; i<snake.size(); i++){
		if (i==0){
			prev_xpos = snake[i].x;
			prev_ypos = snake[i].y;
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
		}
		else{
			next_xpos = snake[i].x;
			next_ypos = snake[i].y;
			snake[i].x = prev_xpos;
			snake[i].y = prev_ypos;
			prev_xpos = next_xpos;
			prev_ypos = next_ypos;
		}
	}
}

void run_game(vector<node> snake, int level){	
	int sleep_time = 0.5;//setting the time interval for each movement (unit: second)
	char input, food;
	int direction = 3;//Initialize the snake so that it faces right
	int food_x, food_y;
	int round=0;
	string food_list[10] = {"apple", "math", "linear", "algebra", "physics", "computer", "elementary", "international", "application", "entertainment"};
	food_x = generate_foodx();
	food_y = generate_foody();
	food = 	food_list[level][round];
	print_food(food_x, food_y, food);
	
	while (true){
		
		input = read_input();
		if (input <= 'Z' && input >= 'A') // make the input case insensitive
			input += ('a'-'A');
		
		if (input == 'a' && direction != 3)//move to the left
			direction = 1;
		else if (input == 'd' && direction != 1)//move to the right
			direction = 3;
		else if (input == 'w' && direction != 4)//move upward
			direction = 2;
		else if (input == 's' && direction != 2)//move downward
			direction = 4;
		else if (input == 'p')//p means pause the game
			pause();
		else if (input == 'q')//q means quit the game
			save_and_quit_game();
		
		make_move(snake, direction);//make movement
		print_snake(snake);//show the snake on the screen
		
		eat_food(snake, food_x, food_y, food, direction);
		judge_fail(snake);
		
		if (judge_success(round, level, food_list)){
			level += 1;
			round = 0;
		}
		else{
			round += 1;
		}
		
		food_x = generate_foodx();
		food_y = generate_foody();
		food = 	food_list[level][round];	
		//sleep() is the function that sets the pause time (measured in seconds)
		//this function is included in the library <unistd.h>
		sleep(sleep_time);
	}
}

int main(){
	int level;
	vector<node> snake = create_snake(70, 25);//use a vector variable to store the information of snake (parameters need to be double-checked)
	print_snake(snake);
	//level = load_game() Not Complete!
	run_game(snake, level);
	
	return 0;
}
