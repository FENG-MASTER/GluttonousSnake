#ifndef DOX_PRINT_X_Y_H
#define DOX_PRINT_X_Y_H

void print_x_y(char *str,int _x,int _y){
/*
    标准输入输出中修改光标输入位置，用来对屏幕修改，解决闪屏问题

*/

    HANDLE hout;
	COORD coord;
	coord.X=_x;
	coord.Y=_y;
	hout=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout,coord);
	std::cout <<str;




}

#endif // DOX_PRINT_X_Y_H
