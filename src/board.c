#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <time.h>

#include "board.h"

Board* new_Board(){
  Board* newBoard = (Board*)malloc(sizeof(Board));

  if(newBoard == NULL){
    fprintf(stderr, "Error: Memory allocation failed for Board struct\n");
    exit(EXIT_FAILURE);
  }

  newBoard->board = (void***)malloc(sizeof(void**) * MAX_BOARD);

  if(newBoard->board == NULL){
    fprintf(stderr, "Error: Memory allocation failed for Board->board\n");
    free(newBoard);
    exit(EXIT_FAILURE);
  }

  for(int row = 0; row < MAX_BOARD; row++){
    newBoard->board[row] = (void**) malloc(sizeof(void*) * MAX_BOARD);
    if(newBoard->board[row] == NULL){
      fprintf(stderr, "Error: Memory allocation failed for Board->board[%d]\n", row);
      for(int index = 0; index < row; index--){
        free(newBoard->board[index]);
      }
      free(newBoard->board);
      free(newBoard);
      exit(EXIT_FAILURE);
    }
  }
  return newBoard;
}

void delete_Board(Board* board_obj){
  if(board_obj){
    for(int row = 0; row < MAX_BOARD; row++){
      free(board_obj->board[row]);
    } 
    free(board_obj->board);
    free(board_obj);
  }
}


void print_Board(Board* board_obj){
  for(int row = 0; row < MAX_BOARD; row++){
    for(int col = 0; col < MAX_BOARD; col++){
      if(board_obj->board[row][col] == NULL){
        printf("%c ", 'N');
      } else {
        printf("%c ", 'S');
      }
    }
    printf("\n");
  }
}
