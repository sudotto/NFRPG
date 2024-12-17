#ifndef BLOCK_H
#define BLOCK_H

#include "rend.h"

// BLOCK STRUCTURE

typedef struct {
	int x;
	int y;
	char* sym;
	char* color;
} block;

block new_block(int x, int y, char* sym, char* color);
renderer render_block(renderer rend, block bl);

#endif
