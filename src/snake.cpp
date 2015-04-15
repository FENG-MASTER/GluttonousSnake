#include "snake.h"
#include<windows.h>
#include<conio.h>
#include <iostream>

snake::snake(int _x,int _y)
{
    //ctor
    po location;
    location.x=_x;
    location.y=_y;
    po_data.push_front(location);
    po_data.push_back(location);
    x_head=_x;
    y_head=_y;
    x_end=_x;
    y_end=_y;
    flat_for_eat=0;
    len=2;

}

snake::~snake()
{
    //dtor
}

void snake::set_map(map_snake *_sn){
    _map=_sn;
    data=_map->data;
}

void snake::move_to(char fangxiang){
    using namespace std;
    switch(fangxiang){
        case 'W':
        case 'w':
            if(data[x_head-1][y_head]=='*'){
                    _map->game_flat=0;
                    Goto_xy(14,0);
                    cout<<"YOU LOSE";
            }
            if(data[x_head-1][y_head]!='*'&&last_direction!='S'&&last_direction!='s'){
                Goto_xy(x_head-1,y_head);
                x_head--;
                cout <<"@";
                updata();
                Goto_xy(x_end,y_end);
                cout <<" ";
                last_direction=fangxiang;


            }
            break;
        case'S':
        case's':
            if(data[x_head+1][y_head]=='*'){
                _map->game_flat=0;
                Goto_xy(14,0);
                cout<<"YOU LOSE";
            }
            if(data[x_head+1][y_head]!='*'&&last_direction!='W'&&last_direction!='w'){
                Goto_xy(x_head+1,y_head);
                x_head++;
                cout <<"@";
                updata();
                Goto_xy(x_end,y_end);
                cout <<" ";
                last_direction=fangxiang;


            }
            break;
        case'A':
        case'a':
            if(data[x_head][y_head-1]=='*'){
                    _map->game_flat=0;
                    Goto_xy(14,0);
                    cout<<"YOU LOSE";
            }
            if(data[x_head][y_head-1]!='*'&&last_direction!='D'&&last_direction!='d'){
                Goto_xy(x_head,y_head-1);
                y_head--;
                cout <<"@";
                updata();
                Goto_xy(x_end,y_end);
                cout <<" ";
                last_direction=fangxiang;


            }
            break;

        case'D':
        case'd':
            if(data[x_head][y_head+1]=='*'){
                    _map->game_flat=0;
                    Goto_xy(14,0);
                    cout<<"YOU LOSE";
            }
            if(data[x_head][y_head+1]!='*'&&last_direction!='A'&&last_direction!='a'){
                Goto_xy(x_head,y_head+1);
                y_head++;
                cout <<"@";
                updata();
                Goto_xy(x_end,y_end);
                cout <<" ";
                last_direction=fangxiang;


            }
            break;

        default:break;




    }
    flat_for_eat=0;



    if(_map->_apple->apple_po.x==x_head&&_map->_apple->apple_po.y==y_head){
        //吃到apple后执行函数
        len++;
        Goto_xy(0,14);
        std::cout<<"point:"<< len;
        _map->speed=_map->speed-10;
        flat_for_eat=1;
        _map->_apple->draw_apple();
    }



}


void snake::Goto_xy(int gox,int goy){
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


void snake::updata(){
    /*
        更新函数。
        用来更新储存贪吃蛇所在位置是所有数据的list，
        一是更新开头，每次加入一个po对象
        二是读取末尾，在屏幕中去掉末尾显示
        三是删除结尾，每次把结尾去掉


    */
    using namespace std;
    po location;
    location.x=x_head;
    location.y=y_head;
    po_data.push_front(location);
    x_end=po_data.back().x;
    y_end=po_data.back().y;
    if(flat_for_eat!=1){
          po_data.pop_back();//如果吃了apple则不去掉list最后一个元素


    }


//    Goto_xy(14,0);
//    for(list<po>::iterator it=po_data.begin();it!=po_data.end();++it){
//        cout << "X:"<<(*it).x<<"Y:"<<(*it).y<<endl;
//
//    }

}


