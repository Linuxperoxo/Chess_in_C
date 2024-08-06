#ifndef BOARD_H
#define BOARD_H

#define MAX_BOARD 8

#include "piece.h"

typedef struct Board{
  Piece*** board;

  void (*print)(struct Board* board);
  void (*destroyer)(struct Board* board);
}Board;

Board* new_Board();

void put_Piece(Piece* piece);

void print_Board(Board* board);

void delete_Board(Board* board);

#endif
