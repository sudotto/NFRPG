#include "include/rend.h"
#include "include/player.h"

// PLAYER

player new_player(){
	player pl;
	pl.x = 1;
	pl.y = 1;
	pl.x_spd = 2;
	pl.y_spd = 1;
	char* name = "Player";
	return pl;
}

player control_player(player pl, char key){
	switch(key){
		case 'w':
			pl.y -= pl.y_spd;
			break;
		case 'a':
			pl.x -= pl.x_spd;
			break;
		case 's':
			pl.y += pl.y_spd;
			break;
		case 'd':
			pl.x += pl.x_spd;
			break;
	}
	return pl;
}

renderer render_player(renderer rend, player pl){
	rend = draw_renderer(rend, "", WHITE, pl.x, pl.y);
	return rend;
}
