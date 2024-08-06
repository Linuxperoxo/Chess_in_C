#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "piece.h"

Piece* new_Piece(const unsigned int color, const char type, const unsigned int row, const unsigned int col){
  Piece* newPiece = (Piece*)malloc(sizeof(Piece));
  
  if(newPiece == NULL){
    fprintf(stderr, "Error: Memory allocation failed for Piece struct\n");
    exit(EXIT_FAILURE);
  }

  newPiece->type = (color == 0 ? toupper(type) : tolower(type));
  newPiece->color = color;
  newPiece->row = row;
  newPiece->col = col;
  newPiece->old_row = row;
  newPiece->old_col = col;

  newPiece->destroyer = delete_Piece;

  return newPiece;
}

void delete_Piece(Piece* piece){
  if(piece){
    free(piece);
  }
}
