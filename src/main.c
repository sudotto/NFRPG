#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <time.h>

#include "rend.h"

// MAIN

int main(int argc, char** argv){
	system("clear");
	struct termios term;
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	renderer rend = new_renderer();
	bool running = true;
	char key;
	int x = 0;
	int y = 0;
	while(running){
		printf("\033[H");
		rend = fill_renderer(rend, ' ', WHITE);
		rend = draw_renderer(rend, 'x', RED, x, y);
		render_renderer(rend);
		key = getchar();
		switch(key){
			case 'q':
				running = false;
				break;
			case 'w':
				y -= 1;
				break;
			case 'a':
				x -= 1;
				break;
			case 's':
				y += 1;
				break;
			case 'd':
				x += 1;
				break;
		}
	}
	term.c_lflag |= (ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	system("clear");
	return 0;
}
