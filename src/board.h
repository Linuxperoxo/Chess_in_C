#ifndef BOARD_H
#define BOARD_H

#define MAX_BOARD 8
#define MIN_BOARD 1

#include "piece.h"

typedef struct Board{
  Piece*** board;

  void (*put)(struct Board* board, struct Piece* piece);
  void (*print)(struct Board* board);
  void (*destroyer)(struct Board* board);
}Board;

Board* new_Board();

void put_Piece(Board* board, Piece* piece);

void print_Board(Board* board);

void delete_Board(Board* board);

#endif
