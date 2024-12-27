#ifndef LEVEL_H
#define LEVEL_H

#include "player.h"
//#include "npc.h"
#include "block.h"

// LEVEL STRUCTURE

typedef struct {
	block blocks[10000];
} level;

level new_level();
level push_block(level lv, block bl);

#endif
