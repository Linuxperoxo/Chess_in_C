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
  newBoard->put = put_Piece;
  newBoard->print = print_Board;
  newBoard->destroyer = delete_Board;
  
  return newBoard;
}

void put_Piece(Board* board, Piece* piece){
  if(board->board[piece->old_row][piece->old_col] != NULL){
    board->board[piece->old_row][piece->old_col] = NULL;
  }
  board->board[piece->row][piece->col] = piece;
}

void print_Board(Board* board){
  if(board == NULL || board->board == NULL){
    fprintf(stderr, "Error: Unable to access unallocated memory\n");
    exit(EXIT_FAILURE);
  }

  for(int row = 0; row < MAX_BOARD; row++){
    printf("  +---+---+---+---+---+---+---+---+\n");
    printf("%d", row + 1);
    for(int col = 0; col < MAX_BOARD; col++){
      if(board->board[row][col] == NULL){
        printf(" |  ");
      } else {
        printf(" | %c", board->board[row][col]->type);
      }
    }
    printf(" |\n");
  }
  printf("  +---+---+---+---+---+---+---+---+\n");
  printf("    1   2   3   4   5   6   7   8\n");
}

void delete_Board(Board *board){
  if(board){
    if(board->board){
      for(int row = 0; row < MAX_BOARD; row++){
        if(board->board[row]){
          for(int col = 0; col < MAX_BOARD; col++){
            if(board->board[row][col]){
              board->board[row][col]->destroyer(board->board[row][col]);
            }
          } 
          free(board->board[row]);
        }
      }
      free(board->board);
    }
    free(board);
  }
}
