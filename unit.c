#include "unit.h"


void unit_init_regular(unit * u, int pos_x, int pos_y, int order, int direction)
{
	u->type = 1; 
	u->character = 'R'; 
	u->pos_x = pos_x; 
	u->pos_y = pos_y; 
	u->order = order; 
	u->direction = direction; 
}

void unit_init_archer(unit * u, int pos_x, int pos_y, int order, int direction)
{
	u->type = 2; 
	u->character = 'A'; 
	u->pos_x = pos_x; 
	u->pos_y = pos_y; 
	u->order = order; 
	u->direction = direction; 
}


