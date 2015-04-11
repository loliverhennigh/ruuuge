#ifndef UNIT_H
#define UNIT_H

typedef struct{
	int type;
	char character;
	int pos_x;
	int pos_y;
	int order;
	int direction;
	int free;
} unit;

//generates the level
void unit_init_regular(unit * u, int pos_x, int pos_y, int order, int direction);
void unit_init_archer(unit * u, int pos_x, int pos_y, int order, int direction);



#endif



