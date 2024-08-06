#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "board.h"
#include "piece.h"

Board* new_Board(){
  Board* newBoard = (Board*)malloc(sizeof(Board));

  if(newBoard == NULL){
    fprintf(stderr, "Error: Memory allocation failed for Board struct\n");
    exit(EXIT_FAILURE);
  }

  newBoard->board = (Piece***)malloc(sizeof(Piece**) * MAX_BOARD);

  if(newBoard->board == NULL){
    fprintf(stderr, "Error: Memory allocation failed for Board rows\n");
    free(newBoard);
    exit(EXIT_FAILURE);
  }

  for(int row = 0; row < MAX_BOARD; row++){
    newBoard->board[row] = (Piece**)malloc(sizeof(Piece*) * MAX_BOARD);
    
    if(newBoard->board[row] == NULL){
      fprintf(stderr, "Error: Memory allocation failed for Board row %d\n", row);
      
      for(int i = 0; i < row; i++){
        free(newBoard->board[row]);
      }
      free(newBoard->board);
      free(newBoard);
      exit(EXIT_FAILURE);
    }
  }
  newBoard->print = print_Board;
  newBoard->destroyer = delete_Board;
  return newBoard;
}

void print_Board(Board* board){
  for(int row = 0; row < MAX_BOARD; row++){
    printf("  +---+---+---+---+---+---+---+---+\n");
    printf("%d", row + 1);
    for(int col = 0; col < MAX_BOARD; col++){
      if(board->board[row][col] == NULL){
        printf(" | %c", 'A');
      } else {
        printf("  | %c", board->board[row][col]->type);
      }
    }
    printf(" |\n");
  }
  printf("  +---+---+---+---+---+---+---+---+\n");
  printf("    1   2   3   4   5   6   7   8\n");
}

void delete_Board(Board *board){
  if(board){
    free(board);
  }
}
