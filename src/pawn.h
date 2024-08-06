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
};

/**
 * Construtor da "classe"
 * Aloca e inicializa uma nova instância de Pawn.
 * @param color A cor do peão.
 * @param row A linha onde o peão está.
 * @param col A coluna onde o peão está.
 * @return Um ponteiro para a nova instância de Pawn.
 */

struct Pawn* create_Pawn(const unsigned int color, const unsigned int row, const unsigned col);

/**
 * Destrutor da "classe"
 * Libera a memória alocada para a instância de Pawn.
 * @param pawn_ptr Ponteiro para a instância de Pawn a ser destruída.
 * @return 1 se a destruição for bem-sucedida, 0 em caso de erro.
 */

int destroyer_Pawn(struct Pawn* pawn_ptr);

#endif
