#ifndef APPLE_H
#define APPLE_H
#include<po.h>
#include<list>
#include<map_snake.h>
class map_snake;
class apple
{
    public:
        apple();
        virtual ~apple();
        char char_apple;
        po apple_po;
        void draw_apple();
        void set_map(map_snake *_map);
    protected:
    private:
        map_snake *smap;
        po ramd_of_apple();
        void Goto_xy(int _x,int _y);

};

#endif // APPLE_H
