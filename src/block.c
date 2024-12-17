#include "include/rend.h"
#include "include/block.h"

block new_block(int x, int y, char* sym, char* color){
	block bl;
	bl.x = x;
	bl.y = y;
	bl.sym = sym;
	bl.color = color;
	return bl;
}

renderer render_block(renderer rend, block bl){
	rend = draw_renderer(rend, bl.sym, bl.color, bl.x, bl.y);
	return rend;
}
