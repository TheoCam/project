#ifndef _EXECUTION_H
#define _EXECUTION_H

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
#include <stdlib.h>
#include <time.h>
using namespace std;

struct node{ //node represents each section of the snake's body
	int x;
	int y;
	char text;
};

void print_snake(vector<node> snake);

vector<node> create_snake(int x, int y);

void generate_foodx(int& food_x, int& food_y, vector<node> snake);

char read_input();

void print_food(int food_x, int food_y, char food);

void delete_food(int food_x, int food_y);

void print_node(int x, int y, char text);

void delete_node(int x, int y);

bool judge_success(int round, int level, string food_list[10]);

void run_game(vector<node> snake, int level);

//Bao's Part
void saving_game(int current_level);

int reading();

bool check_game_over(vector<node> snake/*éå§ã*/);

#endif
