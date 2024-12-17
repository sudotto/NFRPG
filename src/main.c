#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <time.h>

#include "include/rend.h"
#include "include/player.h"

// MAIN

int main(int argc, char** argv){
	system("clear");
	struct termios term;
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	renderer rend = new_renderer();
	bool running = true;
	player pl = new_player();
	char key;
	while(running){
		printf("\033[H");
		rend = fill_renderer(rend, " ", WHITE);
		key = getchar();
		switch(key){
			case 'q':
				running = false;
				break;
		}

		pl = control_player(pl, key);
		rend = render_player(rend, pl);

		render_renderer(rend);
	}
	term.c_lflag |= (ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	system("clear");
	return 0;
}
