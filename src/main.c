//==========================================|
//   FILE: main.c                           |
//   AUTHOR: Linuxperoxo                    |
//   COPYRIGHT: (c) 2024 per Linuxperoxo.   |
//==========================================/

//==========================================================| LIBS

#include <stdio.h>

//==========================================================| .H

#include "pawn.h"

//==========================================================| MAIN

int main(){
  struct Pawn* pawn1 = create_Pawn(1, 0, 0);
  struct Pawn* pawn2 = create_Pawn(0, 10, 11);
  
  printf("%c %d %d %d\n", pawn1->type, pawn1->color, pawn1->row, pawn1->col);
  printf("%c %d %d %d\n", pawn2->type, pawn2->color, pawn2->row, pawn2->col);
  return 0;
}
