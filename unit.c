#include "unit.h"


void unit_init_regular(unit * u, int pos_x, int pos_y)
{
	u->type = 1; 
	u->character = 'R'; 
	u->pos_x = pos_x; 
	u->pos_y = pos_y;
	u->direction_x = 0; 
	u->direction_y = 0; 
	u->move = 0;
	u->alive = 1;
}


int unit_has_moved(unit * u) {return u->move;}


int unit_get_pos_x(unit * u) {return u->pos_x; }
int unit_get_pos_y(unit * u) {return u->pos_y; }
int unit_get_direction_x(unit * u) {return u->direction_x; }
int unit_get_direction_y(unit * u) {return u->direction_y; }
int unit_get_alive(unit * u) {return u->alive; }
void unit_set_pos_x(unit * u, int pos_x) {u->pos_x = pos_x; }
void unit_set_pos_y(unit * u, int pos_y) {u->pos_y = pos_y; }
void unit_set_direction_x(unit * u, int direction_x) {u->direction_x = direction_x; }
void unit_set_direction_y(unit * u, int direction_y) {u->direction_y = direction_y; }
void unit_set_move(unit * u, int move) {u->move = move; }


void unit_kill(unit * u)
{
	u->alive = 0;
	u->move = 0;
	u->pos_x = -1;
	u->pos_y = -1;
}

