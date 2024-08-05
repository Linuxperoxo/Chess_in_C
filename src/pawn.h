//==========================================|
//   FILE: pawn.h                           |
//   AUTHOR: Linuxperoxo                    |
//   COPYRIGHT: (c) 2024 per Linuxperoxo.   |
//==========================================/

#ifndef PAWN_H
#define PAWN_H

//==========================================================| CLASS DEFINITION

struct Pawn{
  char type;
  unsigned int color;
  unsigned int row;
  unsigned int col;


  struct Pawn* (*constructor)(const unsigned int color, const unsigned int row, const unsigned int col);
};

/**
 * Construtor da "classe" xD 
*/

struct Pawn* create_Pawn(const unsigned int color, const unsigned int row, const unsigned col);

/**
 * Destrutor da "classe"
*/

int destroyer_Pawn(struct Pawn* pawn_ptr);

#endif
