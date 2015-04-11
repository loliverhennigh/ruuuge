#include "map.h"
#include "unit.h"
#include "print.h"
#include "curser.h"

#include <ncurses.h>
#include <malloc.h>
#include <math.h>

map * map_create(int size_x, int size_y, int size_army_a, int size_army_b)
{
	int i = 0;
	map * m = (map *)malloc(sizeof(map));
	m->land_piece = (char *)malloc(sizeof(char) * size_x * size_y);
	m->army_a = (unit **)malloc(sizeof(unit *) * size_army_a);
	m->army_b = (unit **)malloc(sizeof(unit *) * size_army_b);
	for(i = 0; i < size_army_a; i++)
	{
		m->army_a[i] = (unit *)malloc(sizeof(unit));
	}
	for(i = 0; i < size_army_b; i++)
	{
		m->army_b[i] = (unit *)malloc(sizeof(unit));
	}
	m->size_x = size_x;
	m->size_y = size_y;
	m->size_army_a = size_army_a;
	m->size_army_b = size_army_b;

	return m;
}

void map_set_land_piece(map * m, int pos, char c)
{
	m->land_piece[pos] = c;
}

void map_set_army_a(map * m, int pos, int type, int pos_x, int pos_y, int order, int direction)
{
	if(type == 1)
	{
		unit_init_regular(m->army_a[pos], pos_x, pos_y, order, direction);
	}
	if(type == 2)
	{
		unit_init_archer(m->army_a[pos], pos_x, pos_y, order, direction);
	}
}

void map_set_army_b(map * m, int pos, int type, int pos_x, int pos_y, int order, int direction)
{
	if(type == 1)
	{
		unit_init_regular(m->army_b[pos], pos_x, pos_y, order, direction);
	}
	if(type == 2)
	{
		unit_init_archer(m->army_b[pos], pos_x, pos_y, order, direction);
	}

}

void map_fill_land(map * m, char c)
{
	int i = 0;
	for(i = 0; i < m->size_x * m->size_y; i++)
	{
		map_set_land_piece(m, i, c);
	}
}


void map_print_land(map * m, WINDOW * erg_win)
{
	int i = 0;
	int j = 0;
	for(i = 0; i < m->size_x; i++)
	{
		for(j = 0; j < m->size_y; j++)
		{
			print_thing(erg_win, j, i, m->land_piece[i*m->size_y + j]);
		}
	}
	wrefresh(erg_win);
}

void map_print_army(map * m, WINDOW * erg_win)
{
	int i = 0;
	attron(COLOR_PAIR(3));
	for(i = 0; i < m->size_army_a; i++)
	{
		print_thing(erg_win, m->army_a[i]->pos_x, m->army_a[i]->pos_y, m->army_a[i]->character);
	}
	attron(COLOR_PAIR(2));
	for(i = 0; i < m->size_army_b; i++)
	{
		print_thing(erg_win, m->army_b[i]->pos_x, m->army_b[i]->pos_y, m->army_b[i]->character);
	}
	attron(COLOR_PAIR(1));
	refresh();
}

int map_is_unit_a(map * m, curser * c)
{
	int ret = -1;
	int i = 0;
	for(i = 0; i < m->size_army_a; i++)
	{
		if (m->army_a[i]->pos_x == c->x && m->army_a[i]->pos_y == c->y)
		{
			ret = i;
		}
	}
	return ret;
}

int map_is_unit_b(map * m, curser * c)
{
	int ret = -1;
	int i = 0;
	for(i = 0; i < m->size_army_b; i++)
	{
		if (m->army_b[i]->pos_x == c->x && m->army_b[i]->pos_y == c->y)
		{
			ret = i;
		}
	}
	return ret;
}


void map_update_death(map * m)
{
	
}

void map_update_movment(map * m)
{

}



