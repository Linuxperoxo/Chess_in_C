#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "pawn.h"
#include "piece.h"

Pawn* new_Pawn(const uint8_t color, const uint8_t row, const uint8_t col){
  Pawn* newPawn = (Pawn*) malloc(sizeof(Pawn));

  if(newPawn == NULL){
    fprintf(stderr, "Error: Memory allocation failed for Pawn strct!\n");
    exit(EXIT_FAILURE);
  }

  newPawn->base = new_Piece('p', color, row, col);

  newPawn->struct_destroyer = delete_Pawn;

  return newPawn;
}

void delete_Pawn(Pawn **pawn){
  if(pawn && *pawn){
    if((*pawn)->base){
      (*pawn)->base->struct_destroyer(&(*pawn)->base);
      (*pawn)->base = NULL;
    }
    free(*pawn);
    *pawn = NULL;
  }
}
