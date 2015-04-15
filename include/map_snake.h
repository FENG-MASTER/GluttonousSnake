#ifndef MAP_SNAKE_H
#define MAP_SNAKE_H
#include<snake.h>
#include<po.h>
#include<apple.h>
class snake;
class apple;
class map_snake
{
    public:
        map_snake(char (*data_map)[14],int x,int y);
        virtual ~map_snake();
        char (*data)[14];
        snake *sn;
        char player_char;
        apple *_apple;
        void showmap();
        bool game_flat;//1表示游戏继续进行，0表示退出
        int speed;
    protected:
    private:
        void Goto_xy(int gox,int goy);

};

#endif // MAP_SNAKE_H
