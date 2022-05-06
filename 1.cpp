#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <stdio.h>
#include <unistd.h>


#include <stdlib.h>
#include <time.h>

using namespace std;



#define green  0x33
#define blue 0x13


void MoveCursorPosition(int x, int y)
{
    printf ("\033[x; yH");
}



void PrintAtCursor(char * ch, int x, int y)
{
    MoveCursorPosition(x, y);
    printf("\033[0;30;47m s% \n", ch);
}






// width=70, height=70
void create_game_area( )
{
    int width_index = 0;
    int height_index = 0;

    

    for(width_index = 0; width_index < 70; width_index++) {
        for(height_index = 0; height_index < 70 ; height_index++) {
            
            // from (2,1), print "■", width=2, height=1
            PrintAtCursor("■", 2+width_index*2, 1+height_index);
        }
    }

    

    return;
}



void create_game_area_frame( )
{
    int width_index = 0;
    int height_index = 0;


    // upper
    for(width_index = 0; width_index < 70 ; width_index++) {
        
        PrintAtCursor("■", 1+width_index, 0);
    }

    // left
    for(height_index = 0; height_index < 70 ; height_index++) {
        
        PrintAtCursor("■", 0, 1+height_index);
    }

    // lower
    for(width_index = 0; width_index < 70 ; width_index++) {
        
        PrintAtCursor("■", 1+width_index, 71);
    }

    // right
    for(height_index = 0; height_index < 70; height_index++) {
        
        PrintAtCursor("■", 2+70*2, 1+height_index);
    }


    
    MoveCursorPosition(0, 80);

    return;
}




// ---------------------------------------part2 -----------------------------------------

struct node { //node represents each section of the snake's body
	int x;
	int y;
	char text;
};


void add_node(vector<node> snake, int x, int y, char text) {//This function adds one node to the snake
	node body;
	body.x = x;
	body.y = y;
	body.text = text;
	
	snake.push_back(body);
}

vector<node> create_snake(int x, int y) {//This function creates the snake of type vector
	node head;
	head.x = x;
	head.y = y;
	head.text = '$';//The head of the snake is represented by the symbol $
	
	vector<node> snake;
	snake.push_back(head);
	return snake;
}



// print snake
void print_snake(vector<node> snake/*蛇头*/ ) 
{


    for ( int i=0; i<snake.size(); ++i) {

        if ( i==0) {
            PrintAtCursor("◆", snake[i].x, snake[i].y);
        }

        else {
            PrintAtCursor( & snake[i].text, snake[i].x, snake[i].y);
        }

    }    

}



bool check_game_over(vector<node> snake/*蛇头*/) 
{
    // hit walls
    if (snake[0].x==0 || snake[0].x==70 || snake[0].y==0 || snake[0].y==70) {
        return true;
    }

    // hit itself
    for ( int i=0; i<snake.size(); ++i) {
        if (snake[0].x == snake[i].x  &&  snake[0].y == snake[i].y) {
            return true;
        }
    }

    return false;
}



// 保存游戏进度
void saving(int current_level)
{
    
        ofstream fout;
        fout.open("game_level.txt");

    
        if ( fout.fail() ) {
            cout << "Error in file opening!" << endl;
        }
        exit(1);

        fout << current_level << endl;
        fout.close();
    

}



// read saved game
int reading() 
{ 
        int current_level;
        char game_level[100] = "game_level.txt";
        ifstream fin;
        fin.open(game_level);

    
        if ( fin.fail() ) {
            cout << "Error in file opening!" << endl;
        }
        exit(1);

    
        fin >> current_level;
        fin.close();
        return current_level;
    
}



int main()
{
    create_game_area( );
    create_game_area_frame( );

    int level;
	vector<node> snake = create_snake(70, 25);//use a vector variable to store the information of snake (parameters need to be double-checked)
	print_snake(snake);
	//level = load_game() Not Complete!
	// run_game(snake, level);
	
	return 0;

}
