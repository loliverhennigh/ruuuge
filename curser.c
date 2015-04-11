#include "curser.h"


#include <ncurses.h>
#include <malloc.h>
#include <math.h>

curser * curser_create(int x, int y)
{
	curser * c = (curser *)malloc(sizeof(curser));
	c->x = x;
	c->y = y;
	c->y_0 = y;
	c->x_0 = x;
}

void curser_add_x(curser * c)
{
	c->x = c->x + 1;
}
void curser_add_y(curser * c)
{
	c->y = c->y + 1;
}
void curser_set_x_0(curser * c)
{
	c->x_0 = c->x;
}

void curser_set_y_0(curser * c)
{
	c->y_0 = c->y;
}

void curser_print(curser * c, WINDOW * erg_win)
{
	attron(COLOR_PAIR(3));
	print_thing(erg_win, c->x, c->y, '*');
	attron(COLOR_PAIR(1));
	refresh();
}
