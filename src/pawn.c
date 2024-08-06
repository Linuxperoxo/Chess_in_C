#include <stdio.h>
#include <stdlib.h>

#include "pawn.h"
#include "piece.h"

Pawn* new_Pawn(const unsigned int color, const unsigned int row, const unsigned int col){
  Pawn* newPawn = (Pawn*)malloc(sizeof(Pawn));
  
  if(newPawn == NULL){
    fprintf(stderr, "Error: Memory allocation failed for Pawn struct\n");
    exit(EXIT_FAILURE);
  }

  newPawn->base = new_Piece(color, 'p', row, col);

  newPawn->destroyer = delete_Pawn;

  return newPawn;
}

void delete_Pawn(Pawn *pawn){
  if(pawn){
    pawn->base->destroyer(pawn->base);
    free(pawn);
  }
}
