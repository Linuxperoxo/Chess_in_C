#include <stdio.h>
#include <stdlib.h>

#include "pawn.h"
#include "board.h"

int main(){
  Pawn* pawn1 = new_Pawn(0, 12, 11);
  Board* board = new_Board();

  printf("%c %d %d %d %d %d\n", pawn1->base->type, pawn1->base->color, pawn1->base->row, pawn1->base->col, pawn1->base->old_row, pawn1->base->old_col);
  
  board->print(board);

  pawn1->destroyer(pawn1);  
  return 0;
}
