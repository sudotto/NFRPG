#ifndef REND_H
#define REND_H

#define BLACK   "\e[0;30m"
#define RED     "\e[0;31m"
#define GREEN   "\e[0;32m"
#define YELLOW  "\e[0;33m"
#define BLUE    "\e[0;34m"
#define MAGENTA "\e[0;35m"
#define CYAN    "\e[0;36m"
#define WHITE   "\e[0;37m"

// RENDERER STRUCTURE

typedef struct {
	int w;
	int h;
	char* syms[100][100];
	char* colors[100][100];
} renderer;

renderer new_renderer();
renderer draw_renderer(renderer rend, char* sym, char* color, int x, int y);
renderer fill_renderer(renderer rend, char* sym, char* color);
void render_renderer(renderer rend);

#endif
