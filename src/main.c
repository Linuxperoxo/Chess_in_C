#include <time.h>
#include <stdio.h>

#include "pawn.h"
#include "board.h"

int main(int argc, char* argv[]){
  Pawn* pawn1 = new_Pawn(0, 5, 6);
  Board* board = new_Board();

  board->put_piece(board, pawn1->base);
  
  board->print(board);
  
  board->struct_destroyer(&board);
   
  return 0;
}
