#include <stdio.h>

#include "pawn.h"
#include "board.h"

int main(int argc, char* argv[]){
  Pawn* pawn1 = new_Pawn(0, 23, 123);
  printf("%c %d %d %d %d %d \n", pawn1->type, pawn1->color, pawn1->row, pawn1->col, pawn1->old_row, pawn1->old_col);
//  pawn1->destroyer(pawn1);
//  printf("%c %d %d %d %d %d \n", pawn1->type, pawn1->color, pawn1->row, pawn1->col, pawn1->old_row, pawn1->old_col);
  
  Board* board = new_Board();

  print_Board(board);

  delete_Board(board);

  print_Board(board);
  
  return 0;
}
