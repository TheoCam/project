#include <iostream>
#include <windows.h>  // WORD COORD HANDLE ...
#include <stdlib.h>
#include <time.h>
using namespace std;



#define green  0x33
#define blue 0x13


WORD old_color = 0;  
#define STD_OUTPUT_HANDLE ((DWORD)-11)

void MoveCursorPosition(int x, int y)
{
    
    COORD position = {x, y};  

    // ??????? 获得标准的输出设备的句柄 即获得cmd窗口的打印控制
    HANDLE hCmdWindow;    
    hCmdWindow = GetStdHandle(STD_OUTPUT_HANDLE);

    // ???????
    SetConsoleCursorPosition(hCmdWindow, position);
    return;
}



void PrintAtCursor(char *ch, int x , int y) {
    MoveCursorPosition(x, y);
    cout << ch;
}



// 修改当前打印将使用的颜色 （并且保存修改前的设置）
void SetColor(WORD  NewColor, WORD  *old )
{
    // ???????? 获得打印窗口的操作句柄
    HANDLE handle;
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    
    // ?????????记住当前正在使用的颜色
    if(old) {
        CONSOLE_SCREEN_BUFFER_INFO Info;   
        GetConsoleScreenBufferInfo(handle, &Info);
        *old = Info.wAttributes; 
    }

    // 设定颜色
    SetConsoleTextAttribute(handle, NewColor);
    return;
}



void create_game_area(int width, int height)
{
    int width_index = 0;
    int height_index = 0;

    // green game area
    SetColor(green, & old_color);

    for(width_index = 0; width_index < width; width_index++) {
        for(height_index = 0; height_index < height ; height_index++) {
            
            // from (2,1), print "■", width=2, height=1
            PrintAtCursor("■", 2+width_index*2, 1+height_index);
        }
    }

    // return to old color
    SetColor(old_color, NULL);

    return;
}



void create_game_area_frame(int width,int height)
{
    int width_index = 0;
    int height_index = 0;

    
    SetColor(blue, & old_color);

    // upper
    for(width_index = 0; width_index < width ; width_index++) {
        
        PrintAtCursor("■", 2+width_index*2, 0);
    }

    // left
    for(height_index = 0; height_index < height ; height_index++) {
        
        PrintAtCursor("■", 0, 1+height_index);
    }

    // lower
    for(width_index = 0; width_index < width ; width_index++) {
        
        PrintAtCursor("■", 2+width_index*2, height+1);
    }

    // right
    for(height_index = 0; height_index < height; height_index++) {
        
        PrintAtCursor("■", 2+width*2, 1+height_index);
    }

    // return old color
    SetColor(old_color, NULL);

    
    MoveCursorPosition(0, 42);

    return;
}




// ---------------------------------------part2 -----------------------------------------

// print snake
void print_snake(vector<node> snake/*蛇头*/ ) 
{
    SetColor(blue, & old_color);

    for ( int i=0; i<snake.size(); ++i) {

        if ( i==0) {
            PrintAtCursor("◆", snake[i].x, snake[i].y);
        }

        else {
            PrintAtCursor(& snake[i].text, snake[i].x, snake[i].y);
        }

    }    

}



boolean check_game_over(vector<node> snake/*蛇头*/) 
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




void game_pause(int width, int height)    //暂停
{
    PrintAtCursor("!!!pause!!!", width/2, height+2);

    while (true) {
        
        Sleep(1000);   // 滞留1秒

        if (GetAsyncKeyState(VK_SPACE)) {
            break;
        }
    }
    
    PrintAtCursor("                    ", width/2, height+2);
    return;
}



// save current game
void saving(int current_level)
{
    if() {   // enter Q to save the game
        
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
void reading() 
{
    if() {   // start from current level
        char game_level[100] = "game_level.txt";
        ifstream fin;
        fin.open(game_level);

    
        if ( fin.fail() ) {
            cout << "Error in file opening!" << endl;
        }
        exit(1);

        fin >> current_level >> endl;
        fin.close();
}

