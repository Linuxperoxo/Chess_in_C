#ifndef BOARD_H
#define BOARD_H

#include "piece.h"

#define MAX_BOARD_SIZE 8
#define MIN_BOARD_SIZE 1

typedef struct Board{
  Piece*** board;

  void(*put_piece)(struct Board*, struct Piece*);

  void(*clear)(struct Board*);

  void(*print)(struct Board*);

  void(*struct_destroyer)(struct Board**);

}Board;

Board* new_Board();

void put_piece(Board* board, Piece* piece);

void print(Board* board);

void clear_Board(Board* board);

void delete_Board(Board** board);

#endif
