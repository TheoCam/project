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

struct snake{
    int x;
    int y;
    snake * next;
};

// print snake
void print_snake(snake *s/*蛇头*/ ) {

    snake * node = s;

    SetColor(blue, & old_color);

    //打印蛇头 
    if( node==s )  {
        PrintAtCursor("◆", s->x, s->y);
        node = node->next;
    }
    //打印蛇身 
    while (node != NULL)  {
        PrintAtCursor("●", node->x, node->y);
        node = node->next;
    }

    //打印完，恢复为原来的打印颜色，不影响后面的打印
    SetColor(old_color, NULL);

    

}



boolean check_game_over(snake *head/*蛇头*/, int width, int height) 
{
    // hit walls
    if (head->x==0 || head->x==width || head->y==0 || head->y==height) {
        return true;
    }

    // hit itself
    snake *node = head;
    while( node != NULL) {
        if ( head->x == node->x  &&  head->y == node->y) {
            return true;
        }
        node = node->next;
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



// 保存游戏进度



int main()
{
    //...


    int level=10;
    for (int i=0; i<10; ++i) {

    }
}

