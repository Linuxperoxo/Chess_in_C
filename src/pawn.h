#ifndef PAWN_H
#define PAWN_H

#include <stdint.h>

#include "piece.h"

typedef struct Pawn{
  Piece* base;

  void(*struct_destroyer)(struct Pawn**);

}Pawn;

Pawn* new_Pawn(const uint8_t color, const uint8_t row, const uint8_t col);

void delete_Pawn(Pawn** pawn);

#endif
