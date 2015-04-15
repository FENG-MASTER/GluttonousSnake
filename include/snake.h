#ifndef SNAKE_H
#define SNAKE_H
#include"map_snake.h"
#include<list>
#include<po.h>

class map_snake;
class snake
{
    public:
        snake(int _x,int _y);
        virtual ~snake();

        std::list<po> po_data;
        int x_head;
        int y_head;
        int x_end;
        int y_end;
        char last_direction;


        int len;
        map_snake *_map;
        void move_to(char fangxiang);
        void set_map(map_snake *_sn);
        void updata();



    protected:
        char (*data)[14];
    private:
        int flat_for_eat;
        void Goto_xy(int gox,int goy);

};

#endif // SNAKE_H
