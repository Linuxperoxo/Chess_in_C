#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

typedef struct Pawn{
  Piece* base;

  void (*destroyer)(struct Pawn* pawn);
}Pawn;

Pawn* new_Pawn(const unsigned int color, const unsigned int row, const unsigned int col);

void delete_Pawn(Pawn* pawn);

#endif


