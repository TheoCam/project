#include "Game.h"
#include <fstream>


void MoveCursorPosition(int x, int y)  // move the cursor to position (x,y)
{
    printf (  "\033[%d;%dH", y,x );  // the x,y coordinates is reversed
}                                    // '\033[y,xH" is used to move the cursor


void PrintAtCursor(char ch, int x, int y)
{
    MoveCursorPosition(x, y);
    printf(  "\033[0;30;47m %c \n", ch  );   // change the color of the background of the game area to green
}


// width = height/2
void create_game_area( )
{
    int width_index = 0;
    int height_index = 0;

    for(width_index = 0; width_index < 40; width_index++) {              // creat a 40x20 game area
        for(height_index = 0; height_index < 20 ; height_index++) {


            PrintAtCursor( ' ', width_index, height_index);
        }
    }

    return;
}


