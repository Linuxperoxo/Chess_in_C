#ifndef PIECE_H
#define PIECE_H

typedef struct Piece{
  char type;
  unsigned int color;
  unsigned int row;
  unsigned int col;
  unsigned int old_row;
  unsigned int old_col;

  void (*destroyer)(struct Piece* piece);
}Piece;

Piece* new_Piece(const unsigned int color, const char type, const unsigned int row, const unsigned int col);

void delete_Piece(Piece* piece);

#endif
