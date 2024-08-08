#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "piece.h"

Piece* new_Piece(const char type, const uint8_t color, const uint8_t row, const uint8_t col){
  Piece* newPiece = (Piece*) malloc(sizeof(Piece));

  if(newPiece == NULL){
    fprintf(stderr, "Error: Memory allocation failed for Piece struct!\n");
    exit(EXIT_FAILURE);
  }

  newPiece->color = (color != 0 ? 1 : color);
  newPiece->type = (color == 0 ? toupper(type) : tolower(type));
  newPiece->row = row;
  newPiece->col = col;
  newPiece->old_row = row;
  newPiece->col = col;
  newPiece->struct_destroyer = delete_Piece;

  return newPiece;
}

void delete_Piece(Piece** piece){
  if(piece && *piece){
    free(*piece);
    *piece = NULL;
  }
}
