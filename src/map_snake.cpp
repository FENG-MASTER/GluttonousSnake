#include "map_snake.h"
#include <iostream>
#include <iomanip>
#include<windows.h>

map_snake::map_snake(char (*data_map)[14],int x,int y)
{
    //ctor
    data=data_map;
    sn=new snake(x,y);
    sn->set_map(this);
    _apple=new apple();
    _apple->set_map(this);
    player_char='@';
    game_flat=1;
    speed=300;


}

map_snake::~map_snake()
{
    //dtor
}

void map_snake::showmap(){
    using namespace std;
    system("cls");
    data[(sn->po_data.front()).x][(sn->po_data.front()).y]=player_char;


    for(int i=0;i<14;i++){
        for(int j=0;j<14;j++){
            cout << setw(2)<<data[i][j] ;
        }
            cout <<"\n";

    }



}

void map_snake::Goto_xy(int gox,int goy){
/*
    标准输入输出中修改光标输入位置，用来对屏幕修改，解决闪屏问题

*/
    HANDLE hout;
	COORD coord;
	coord.X=goy*2+1;
	coord.Y=gox;
	hout=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout,coord);

}
