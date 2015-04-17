#include <stdio.h>
#include <ncurses.h>
#include "print.h"
int init_colors(){
	// Initialize Colors
	if(has_colors() == FALSE)
	{	endwin();
		printf("Your terminal does not support color\n");
		return(1);
	}
	start_color();
	init_color(COLOR_BLACK, 0, 0, 0);
	init_color(COLOR_GREEN, 0, 1000, 0);
	init_color(COLOR_BLUE, 0, 0, 1000);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	return 0;
}

// Helper to print a character at a place.
void print_thing(WINDOW *erg_win, int x, int y, char thing){
	char cstr[2];
	cstr[0] = thing;
	cstr[1] = '\0';
	mvprintw(y, 2*x, cstr);
//	mvprintw(y, 2*x, cstr);
	wrefresh(erg_win);
	wmove(erg_win, y, x);
}

