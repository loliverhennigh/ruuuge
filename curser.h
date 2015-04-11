#ifndef CURSER_H
#define CURSER_H

#include <ncurses.h>

typedef struct{
	int x;
	int y;
	int x_0;
	int y_0;
} curser;

curser * curser_create(int x, int y);
void curser_add_x(curser * c);
void curser_add_y(curser * c);
void curser_set_x_0(curser * c);
void curser_set_y_0(curser * c);
void curser_print(curser * c, WINDOW * erg_win);


#endif

