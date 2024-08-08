#ifndef PIECE_H
#define PIECE_H

#include <stdint.h>

typedef struct Piece{
  char type;

  uint8_t color;
  uint8_t row;
  uint8_t col;
  uint8_t old_row;
  uint8_t old_col;

  void(*struct_destroyer)(struct Piece**);

}Piece;

Piece* new_Piece(const char type, const uint8_t color, const uint8_t row, const uint8_t col);

void delete_Piece(Piece** piece);

#endif
