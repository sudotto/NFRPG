#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include "include/rend.h"

// RENDERER

renderer new_renderer(){
	renderer rend;
	struct winsize size;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
	rend.w = size.ws_col - 1;
	rend.h = size.ws_row - 2;
	if(rend.w >= 100){
		rend.w = 100;
	}
	if(rend.h >= 100){
		rend.h = 100;
	}
	return rend;
}

renderer draw_renderer(renderer rend, char* sym, char* color, int x, int y){
	if(y >= 0 && y <= rend.h){
		if(x >= 0 && x <= rend.w){
			rend.syms[y][x] = sym;
			rend.colors[y][x] = color;
		}
	}
	return rend;
}

renderer fill_renderer(renderer rend, char* sym, char* color){
	for(int y = 0; y <= rend.h; y++){
		for(int x = 0; x <= rend.w; x++){
			rend = draw_renderer(rend, sym, color, x, y);
		}
	}
	return rend;
}

void render_renderer(renderer rend){
	for(int y = 0; y <= rend.h; y++){
		for(int x = 0; x <= rend.w; x++){
			printf("%s%s", rend.colors[y][x], rend.syms[y][x]);
		}
		printf("\n");
	}
}
