#include "map.h"
#include "unit.h"
#include "print.h"
#include "curser.h"

#include <ncurses.h>
#include <malloc.h>
#include <math.h>
#include <stdio.h>

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

map * map_create_file(char file_name[])
{
	FILE * fp;
	int i = 0;
	int size_x = 1;
	int size_y = 1;
	int size_army_a = 1;
	int size_army_b = 1;
	int pos_x = 0;
	int pos_y = 0;
	fp = fopen(file_name, "r");
	fscanf(fp, "%i", &size_x);
	fscanf(fp, "%i", &size_y);
	fscanf(fp, "%i", &size_army_a);
	fscanf(fp, "%i", &size_army_b);

	map * m = map_create(size_x, size_y, size_army_a, size_army_b);

	for(i = 0; i < size_army_a; i++)
	{
		fscanf(fp, "%i", &pos_x);
		fscanf(fp, "%i", &pos_y);
		map_set_army_a(m,i,1,pos_x, pos_y, 0, 0);
	}
	for(i = 0; i < size_army_b; i++)
	{
		fscanf(fp, "%i", &pos_x);
		fscanf(fp, "%i", &pos_y);
		map_set_army_b(m,i,1,pos_x, pos_y, 0, 0);
	}
	fclose(fp);
	return m;
}

void map_print_file(map * m, char file_name[])
{
	FILE * fp;
	int i = 0;
	fp = fopen(file_name, "w+");
	fprintf(fp, "%i \n", m->size_x);
	fprintf(fp, "%i \n", m->size_y);
	fprintf(fp, "%i \n", m->size_army_a);
	fprintf(fp, "%i \n", m->size_army_b);
	for(i = 0; i < m->size_army_a; i++)
	{
		fprintf(fp, "%i \n", unit_get_pos_x(m->army_a[i]));
		fprintf(fp, "%i \n", unit_get_pos_y(m->army_a[i]));
	}
	for(i = 0; i < m->size_army_b; i++)
	{
		fprintf(fp, "%i \n", unit_get_pos_x(m->army_b[i]));
		fprintf(fp, "%i \n", unit_get_pos_y(m->army_b[i]));
	}
	fclose(fp);
}

void map_set_land_piece(map * m, int pos, char c)
{
	m->land_piece[pos] = c;
}

void map_set_army_a(map * m, int pos, int type, int pos_x, int pos_y, int order, int direction)
{
	unit_init_regular(m->army_a[pos], pos_x, pos_y);
}

void map_set_army_b(map * m, int pos, int type, int pos_x, int pos_y, int order, int direction)
{
	unit_init_regular(m->army_b[pos], pos_x, pos_y);
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

int map_is_unit_a_pos(map * m, int pos_x, int pos_y)
{
	int ret = -1;
	int i = 0;
	for(i = 0; i < m->size_army_a; i++)
	{
		if (m->army_a[i]->pos_x == pos_x && m->army_a[i]->pos_y == pos_y)
		{
			ret = i;
		}
	}
	return ret;
}


int map_is_unit_b_pos(map * m, int pos_x, int pos_y)
{
	int ret = -1;
	int i = 0;
	for(i = 0; i < m->size_army_b; i++)
	{
		if (m->army_b[i]->pos_x == pos_x && m->army_b[i]->pos_y == pos_y)
		{
			ret = i;
		}
	}
	return ret;
}



int map_unit_move_a(map * m, int pos)
{
	int ret = 0;
	int new_pos_x = unit_get_pos_x(m->army_a[pos]) + unit_get_direction_x(m->army_a[pos]);
	int new_pos_y = unit_get_pos_y(m->army_a[pos]) + unit_get_direction_y(m->army_a[pos]);
	int enemy = map_is_unit_a_pos(m, new_pos_x, new_pos_y) + map_is_unit_b_pos(m, new_pos_x, new_pos_y);	

	if((0 <= new_pos_x) && (new_pos_x < m->size_y) && (0 <= new_pos_y) && (new_pos_y < m->size_x) && (enemy == -2))
	{
		ret = 1;
	}
	return ret;
}

void map_army_kill_a(map *m, int pos)
{
	int new_pos_x = unit_get_pos_x(m->army_a[pos]) + unit_get_direction_x(m->army_a[pos]);
	int new_pos_y = unit_get_pos_y(m->army_a[pos]) + unit_get_direction_y(m->army_a[pos]);
	int enemy = map_is_unit_b_pos(m, new_pos_x, new_pos_y);	
	unit_kill(m->army_b[enemy]);
}

int map_unit_attack_a(map * m, int pos)
{
	int ret = 0;
	int new_pos_x = unit_get_pos_x(m->army_a[pos]) + unit_get_direction_x(m->army_a[pos]);
	int new_pos_y = unit_get_pos_y(m->army_a[pos]) + unit_get_direction_y(m->army_a[pos]);
	
	if(map_is_unit_b_pos(m, new_pos_x, new_pos_y) > -1)
	{
		ret = 1;
	}
	return ret;
}

void map_update_movement_a(map * m)
{
	int i = 0;
	int cont = 0;
	while(cont == 0)
	{
		cont = 1;
		for(i = 0; i < m->size_army_a; i++)
		{
			if(unit_has_moved(m->army_a[i]) == 0 && map_unit_move_a(m, i) == 1)
			{
				unit_set_pos_x(m->army_a[i], unit_get_pos_x(m->army_a[i]) + unit_get_direction_x(m->army_a[i]));
				unit_set_pos_y(m->army_a[i], unit_get_pos_y(m->army_a[i]) + unit_get_direction_y(m->army_a[i]));
				unit_set_move(m->army_a[i], 1);
				cont = 0;
			}
			if(unit_has_moved(m->army_a[i]) == 0 && map_unit_attack_a(m, i) == 1)
			{
				map_army_kill_a(m, i);
				unit_set_move(m->army_a[i], 1);
				cont = 0;
			}
		}
	}
	map_reset_move_a(m);
}

void map_reset_move_a(map * m)
{
	int i = 0;
	for(i = 0; i < m->size_army_a; i++)
	{
		if(unit_get_alive(m->army_a[i]) == 1)
		{
			unit_set_move(m->army_a[i], 0);
		}
	}
}

