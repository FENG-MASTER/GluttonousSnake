#include "apple.h"
#include <iostream>
#include<windows.h>
#include<time.h>
apple::apple()
{
    //ctor
     char_apple='O';
}

apple::~apple()
{
    //dtor
}
void apple::draw_apple(){
    using namespace std;
    apple_po=ramd_of_apple();
    Goto_xy(apple_po.x,apple_po.y);
    cout << char_apple;
}


void apple::set_map(map_snake *_map){
    smap=_map;


}

void apple::Goto_xy(int gox,int goy){
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



po apple::ramd_of_apple(){
 /*
    随机生成一个apple，排除蛇本身的格子，返回一个po
    取随机一个内存地址内容转换为int做种子


 */



    int temp_x;
    int temp_y;
    bool flat=true;
    while(flat){
            srand((unsigned)time(0));
            temp_x=rand()%14;
            srand((int)*(&temp_x+time(0)%20));
            temp_y=rand()%14;

            if(temp_x==0||temp_x==13||temp_y==0||temp_y==13){
                continue;
            }
            for(std::list<po>::iterator it=smap->sn->po_data.begin();it!=smap->sn->po_data.end();++it){

                if(temp_x==(*it).x&&temp_y==(*it).y){
                    flat=true;
                }else{
                    flat=false;
                }

            }
    }
    po loca;
    loca.x=temp_x;
    loca.y=temp_y;

    return loca;
}
