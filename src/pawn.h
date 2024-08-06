#ifndef PAWN_H
#define PAWN_H

typedef struct Pawn{
  char type;
  unsigned int color;
  unsigned int row;
  unsigned int col;
  unsigned int old_row;
  unsigned int old_col;

  void (*destroyer)(struct Pawn* pawn);
}Pawn;

Pawn* new_Pawn(unsigned int color, unsigned int row, unsigned int col);

void delete_Pawn(Pawn* pawn);

#endif
