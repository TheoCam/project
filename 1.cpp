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


void MoveCursorPosition(int x, int y)
{
    printf (  "\033[%d;%dH", x,y  );
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



bool check_game_over(vector<node> snake/*蛇头*/) 
{
    // hit walls
    if (snake[0].x==0 || snake[0].x==20 || snake[0].y==0 || snake[0].y==40) {
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
void saving_game(int current_level)
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



/***********************************rank*************************************/

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
        fout.open("time_record.txt", ios::app);   // 能不能直接在新的txt文件append？

    
        if ( fout.fail() ) {
            cout << "Error in file opening!" << endl;
        }
        exit(1);

        fout << used_time << endl;
        fout.close();
    
}

void sort_time()
{
    
    char time_records[100] = "time_record.txt";
    ifstream fin;
    fin.open(time_records);
  
    if ( fin.fail() ) {
        cout << "Error in file opening!" << endl;
    }
    exit(1);

    double records[1000];
    fin >> ;
    fin.close();

}


/*************************************************************************************/



int main()
{
    cout << "\033[8;100;100t";

    //create_game_area( );
    //create_game_area_frame( );

    int level;
	vector<node> snake = create_snake(70, 25);//use a vector variable to store the information of snake (parameters need to be double-checked)
	// print_snake(snake);
	//level = load_game() Not Complete!
	// run_game(snake, level);
	
	return 0;

}

