//==========================================|
//   FILE: piece.h                          |
//   AUTHOR: Linuxperoxo                    |
//   COPYRIGHT: (c) 2024 per Linuxperoxo.   |
//==========================================/

//==========================================================| LIBS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//==========================================================| .H

#include "pawn.h"

//==========================================================| "CLASS" FUNCTIONS

struct Pawn* create_Pawn(const unsigned int color, const unsigned int row, const unsigned int col){
  
  /**
   * Alocando espaço para a nova instância
  */

  struct Pawn* new_Pawn = (struct Pawn*)(malloc(sizeof(struct Pawn)));
  
  /**
   * Definindo as vars da instância
  */
  
  new_Pawn->type = (color == 0 ? 'P' : 'p');
  new_Pawn->color = color;
  new_Pawn->row = row;
  new_Pawn->col = col;
  
  /**
   * Verificando se o malloc não teve nenhum problema
   */

  if(new_Pawn == NULL){
    fprintf(stderr, "Error: Memory allocation failed for Pawn struct\n");
    exit(EXIT_FAILURE);
  }

  return new_Pawn;
}

int destroyer_Pawn(struct Pawn *pawn_ptr){
  
  /**
   * Liberando espaço alocado 
   * Mas antes vamos verificar se não é um nullptr
  */

  if(pawn_ptr != NULL){
    free(pawn_ptr);
    return 1;
  }
  return 0;
}
