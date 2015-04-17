#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include "print.h"
#include "map.h"
#include "unit.h"
#include "curser.h"

void handle_curser(curser * cc, int key);
void first_place_units(map * m, curser * cc, WINDOW * erg_win);
void second_place_units(map * m, curser * cc, WINDOW * erg_win);
void first_move_units(map * m, curser * cc, WINDOW * erg_win);
void second_move_units(map * m, curser * cc, WINDOW * erg_win);

int main(){
//	map * m = map_create_file(HEIGHT, WIDTH, 30, 30);
	map * m = map_create_file("testt.txt");
	curser * cc = curser_create(1,1);
	int c;
	int placed_units = 0;

	map_fill_land(m, '~');
//	printf("sdf");

	WINDOW *erg_win;


	initscr();
	clear();
	noecho();
	cbreak();
	curs_set(0); // Hides cursor

	init_colors();

	// ncurses setup stuff
	erg_win = newwin(HEIGHT, WIDTH, 0, 0);
	keypad(erg_win, TRUE);

	map_print_land(m, erg_win);
	map_print_army(m, erg_win);
	
	mvprintw(24, 1, "Press q to quit"); // This needs a refresh() before it displays
	refresh();
	int num;

	int i = 0;
	for( i = 0; i < 10; i ++){
	first_move_units(m, cc, erg_win);
	map_update_movement_a(m);
	map_print_land(m, erg_win);
	map_print_army(m, erg_win);
	first_move_units(m, cc, erg_win);
	map_update_movement_a(m);
	map_print_land(m, erg_win);
	map_print_army(m, erg_win);
	first_move_units(m, cc, erg_win);
	map_update_movement_a(m);
	map_print_land(m, erg_win);
	map_print_army(m, erg_win);
	first_move_units(m, cc, erg_win);
	map_update_movement_a(m);
	map_print_land(m, erg_win);
	map_print_army(m, erg_win);
	first_move_units(m, cc, erg_win);
	map_update_movement_a(m);
	map_print_land(m, erg_win);
	map_print_army(m, erg_win);
	}

	clrtoeol();
	refresh();
	endwin();
	return 0;
}

void handle_curser(curser * cc, int key)
{
	switch(key)
	{
		case KEY_UP:
			if(cc->y>0){
					cc->y--;
			}
			break;
		case KEY_DOWN:
			if(cc->y <HEIGHT-1){
					cc->y++;
			}
			break;
		case KEY_LEFT:
			if(cc->x>0){
					cc->x--;
			}
			break;
		case KEY_RIGHT:
			if(cc->x<WIDTH-1){
			   cc->x++;
			}
			break; 
	}
}


void first_place_units(map * m, curser * cc, WINDOW * erg_win)
{
	int c;
	int placed_units = 0;
	while(placed_units < m->size_army_a){	
		c = wgetch(erg_win);
		handle_curser(cc, c);
		switch(c)
		{
			
			case 'f':
				if(placed_units < m->size_army_a)
				{
					map_set_army_a(m, placed_units, 1, cc->x, cc->y, 1,1);
					placed_units++;
				}
				break; 
			case 'q':
				clrtoeol();
				refresh();
				endwin();
		}
		map_print_land(m, erg_win);
		map_print_army(m, erg_win);
		curser_print(cc, erg_win);

	}
}


void second_place_units(map * m, curser * cc, WINDOW * erg_win)
{
	int c;
	int placed_units = 0;
	while(placed_units < m->size_army_b){	
		c = wgetch(erg_win);
		handle_curser(cc, c);
		switch(c)
		{
			case 'f':
				if(placed_units < m->size_army_a)
				{
					map_set_army_b(m, placed_units, 1, cc->x, cc->y, 1,1);
					placed_units++;
				}
				break; 
			case 'q':
				clrtoeol();
				refresh();
				endwin();
		}
		map_print_land(m, erg_win);
		map_print_army(m, erg_win);
		curser_print(cc, erg_win);

	}
}


void first_move_units(map * m, curser * cc, WINDOW * erg_win)
{
	int i = 0;
	int store;
	int c;
	while(i < 3){	
		c = wgetch(erg_win);
		handle_curser(cc, c);
		store = map_is_unit_a(m, cc);
		switch(c)
		{
			case 'w':
				if(store > -1)
				{
					m->army_a[store]->direction_y = -1;
					i++;
				}
				break;
			case 'a':
				if(store > -1)
				{
					m->army_a[store]->direction_x = -1;
					i++;
				}
				break; 
			case 's':
				if(store > -1)
				{
					m->army_a[store]->direction_y = 1;
					i++;
				}
				break; 
			case 'd':
				if(store > -1)
				{
					m->army_a[store]->direction_x = 1;
					i++;
				}
				break; 

		}
		map_print_land(m, erg_win);
		map_print_army(m, erg_win);
		curser_print(cc, erg_win);
	}
}


void second_move_units(map * m, curser * cc, WINDOW * erg_win)
{
	int i = 0;
	int store;
	int c;
	while(i < 3){	
		c = wgetch(erg_win);
		handle_curser(cc, c);
		store = map_is_unit_b(m, cc);
		switch(c)
		{
			case 'w':
				if(store > -1)
				{
					m->army_b[store]->direction_y = -1;
					i++;
				}
				break;
			case 'a':
				if(store > -1)
				{
					m->army_b[store]->direction_x = -1;
					i++;
				}
				break; 
			case 's':
				if(store > -1)
				{
					m->army_b[store]->direction_y = 1;
					i++;
				}
				break; 
			case 'd':
				if(store > -1)
				{
					m->army_b[store]->direction_x = 1;
					i++;
				}
				break; 

		}
		map_print_land(m, erg_win);
		map_print_army(m, erg_win);
		curser_print(cc, erg_win);
	}
}







