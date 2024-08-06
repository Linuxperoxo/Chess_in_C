#include <stdio.h>
#include <stdlib.h>

#include "pawn.h"

Pawn* new_Pawn(unsigned int color, unsigned int row, unsigned int col){
  Pawn* pawn = (Pawn*)malloc(sizeof(Pawn));

  if(pawn == NULL){
    fprintf(stderr, "%s\n", "Error: Memory allocation failed for Pawn struct");
    exit(EXIT_FAILURE);
  }

  pawn->type = (color == 0 ? 'P' : 'p');
  pawn->row = row;
  pawn->col = col;
  pawn->old_row = row;
  pawn->old_col = col;

  return pawn;
}

void delete_Pawn(Pawn* pawn){
  if(pawn){
    free(pawn);
  }
}
