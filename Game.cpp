#include "Game.h"
#include <fstream>


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


