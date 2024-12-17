#ifndef PLAYER_H
#define PLAYER_H

#include "rend.h"

// PLAYER STRUCTURE

typedef struct {
	int x;
	int y;
	int x_spd;
	int y_spd;
	char* name;
} player;

player new_player();
player control_player(player pl, char key);
renderer render_player(renderer rend, player pl);

#endif
