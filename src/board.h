#ifndef BOARD_h
#define BOARD_h

#define MAX_BOARD 8
#define MIN_BOARD 1

#include "pawn.h"

typedef struct Board{
  void*** board;
  
  void (*destroyer_Board)(struct Board* board_obj);
}Board;

Board* new_Board();

void print_Board(Board* board_obj);

void delete_Board(Board* board_obj);

#endif


