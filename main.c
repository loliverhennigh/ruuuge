#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include "print.h"
#include "map.h"
#include "unit.h"
#include "curser.h"

void first_place_units(map * m, curser * cc, WINDOW * erg_win);
void second_place_units(map * m, curser * cc, WINDOW * erg_win);
void first_move_units(map * m, curser * cc, WINDOW * erg_win);
void second_move_units(map * m, curser * cc, WINDOW * erg_win);

int main(){
	map * m = map_create(HEIGHT, WIDTH, 10, 10);
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
	curs_set(1); // Hides cursor

	init_colors();

	// ncurses setup stuff
	erg_win = newwin(HEIGHT, WIDTH, 0, 0);
	keypad(erg_win, TRUE);

	map_print_land(m, erg_win);
	map_print_army(m, erg_win);
	
	mvprintw(24, 1, "Press q to quit"); // This needs a refresh() before it displays
	refresh();
	int num;

	first_place_units(m, cc, erg_win);
	second_place_units(m, cc, erg_win);
	first_move_units(m, cc, erg_win);
	second_move_units(m, cc, erg_win);
	first_move_units(m, cc, erg_win);
	second_move_units(m, cc, erg_win);
	first_move_units(m, cc, erg_win);
	second_move_units(m, cc, erg_win);
	first_move_units(m, cc, erg_win);
	second_move_units(m, cc, erg_win);
	first_move_units(m, cc, erg_win);
	second_move_units(m, cc, erg_win);
	first_move_units(m, cc, erg_win);
	second_move_units(m, cc, erg_win);
	first_move_units(m, cc, erg_win);
	second_move_units(m, cc, erg_win);
	first_move_units(m, cc, erg_win);
	second_move_units(m, cc, erg_win);
	first_move_units(m, cc, erg_win);
	second_move_units(m, cc, erg_win);

	

	clrtoeol();
	refresh();
	endwin();
	return 0;
}

void first_place_units(map * m, curser * cc, WINDOW * erg_win)
{
	int c;
	int placed_units = 0;
	while(placed_units < m->size_army_a){	
		c = wgetch(erg_win);
		switch(c)
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
				if(cc->x<WIDTH){
				   cc->x++;
				}
				break; 
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
		switch(c)
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
				if(cc->x<WIDTH){
				   cc->x++;
				}
				break; 
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
		store = map_is_unit_a(m, cc);
		switch(c)
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
				if(cc->x<WIDTH){
				   cc->x++;
				}
				break; 
			case 'w':
				if(store > -1)
				{
					m->army_a[store]->pos_y--;
					i++;
				}
				break;
			case 'a':
				if(store > -1)
				{
					m->army_a[store]->pos_x--;
					i++;
				}
				break; 
			case 's':
				if(store > -1)
				{
					m->army_a[store]->pos_y++;
					i++;
				}
				break; 
			case 'd':
				if(store > -1)
				{
					m->army_a[store]->pos_x++;
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
		store = map_is_unit_b(m, cc);
		switch(c)
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
				if(cc->x<WIDTH){
				   cc->x++;
				}
				break; 
			case 'w':
				if(store > -1)
				{
					m->army_b[store]->pos_y--;
					i++;
				}
				break;
			case 'a':
				if(store > -1)
				{
					m->army_b[store]->pos_x--;
					i++;
				}
				break; 
			case 's':
				if(store > -1)
				{
					m->army_b[store]->pos_y++;
					i++;
				}
				break; 
			case 'd':
				if(store > -1)
				{
					m->army_b[store]->pos_x++;
					i++;
				}
				break; 

		}
		map_print_land(m, erg_win);
		map_print_army(m, erg_win);
		curser_print(cc, erg_win);
	}
}







