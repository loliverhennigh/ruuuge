#include <ncurses.h>
#include "unit.h"
#include "curser.h"

#ifndef MAP_H
#define MAP_H

typedef struct{
	int size_x;
	int size_y;
	char * land_piece;	
	int size_army_a;
	int size_army_b;
	unit ** army_a;
	unit ** army_b;
} map;

//generates the level
map * map_create(int size_x, int size_y, int size_army_a, int size_army_b);
void map_set_land_piece(map * m, int pos, char c);
void map_set_army_a(map * m, int pos, int type, int pos_x, int pos_y, int order, int direction);
void map_set_army_b(map * m, int pos, int type, int pos_x, int pos_y, int order, int direction);
void map_fill_land(map * m, char c);

void map_print_land(map * m, WINDOW * erg_win);
void map_print_army(map * m, WINDOW * erg_win);
void map_update_death(map * m);
void map_update_movment(map * m);
int map_is_unit_b(map * m, curser * c);
int map_is_unit_a(map * m, curser * c);

#endif

