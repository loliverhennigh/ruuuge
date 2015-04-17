#ifndef UNIT_H
#define UNIT_H

typedef struct{
	int type;
	char character;
	int pos_x;
	int pos_y;
	int direction_x;
	int direction_y;
	int move;
	int alive;
} unit;

//generates the level
void unit_init_regular(unit * u, int pos_x, int pos_y);
int unit_get_pos_x(unit * u);
int unit_get_pos_y(unit * u);
int unit_get_direction_x(unit * u);
int unit_get_direction_y(unit * u);
int unit_get_alive(unit * u);
int unit_has_moved(unit * u);
void unit_set_pos_x(unit * u, int pos_x);
void unit_set_pos_y(unit * u, int pos_y);
void unit_set_direction_x(unit * u, int direction_x);
void unit_set_direction_y(unit * u, int direction_y);
void unit_set_move(unit * u, int move);
void unit_kill(unit * u);


#endif



