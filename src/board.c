#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "board.h"

Board* new_Board(){
  Board* newBoard = (Board*) malloc(sizeof(Board));

  if(newBoard == NULL){
    fprintf(stderr, "Error: Memory allocation failed for Board struct!\n");
    exit(EXIT_FAILURE);
  }

  newBoard->board = (Piece***) malloc(sizeof(Piece**) * MAX_BOARD_SIZE);

  if(newBoard->board == NULL){
    fprintf(stderr, "Error: Memory allocation failed for Board->board!\n");
    free(newBoard);
    exit(EXIT_FAILURE);
  }

  for(uint8_t row = 0; row < MAX_BOARD_SIZE; row++){
    newBoard->board[row] = (Piece**) malloc(sizeof(Piece*) * MAX_BOARD_SIZE);
    
    if(newBoard->board[row] == NULL){
      fprintf(stderr, "Error: Memory allocation failed for Board->board[%d]!\n", row);
      
      for(uint8_t deleting_row = 0; deleting_row < row; deleting_row++){
        free(newBoard->board[deleting_row]);
      }

      free(newBoard->board);
      free(newBoard);

      exit(EXIT_FAILURE);
    }
  }

  newBoard->clear = clear_Board;
  newBoard->clear(newBoard);
  newBoard->put_piece = put_piece;
  newBoard->print = print;
  newBoard->struct_destroyer = delete_Board;

  return newBoard;
}

void put_piece(Board* board, Piece* piece){
  board->board[piece->old_row][piece->old_col] = NULL;
  board->board[piece->row][piece->col] = piece;
}

void print(Board* board){
  for(uint8_t row = MAX_BOARD_SIZE; row >= MIN_BOARD_SIZE; row--){
    printf("  +---+---+---+---+---+---+---+---+\n");
    printf("%d", row);
    for(uint8_t col = 0; col < MAX_BOARD_SIZE; col++){
      if(board->board[row - 1][col] != NULL){
         printf(" | %c", board->board[row - 1][col]->type);
      } else {
        printf(" |  ");
      }
    }
    printf(" |\n");
  }
  printf("  +---+---+---+---+---+---+---+---+\n");
  printf("    1   2   3   4   5   6   7   8\n");
}

void clear_Board(Board* board){
  if(board->board){
    for(uint8_t row = 0; row < MAX_BOARD_SIZE; row++){
      for(uint8_t col = 0; col < MAX_BOARD_SIZE; col++){
        if(board->board[row][col] != NULL){
          board->board[row][col] = NULL;
        }
      }
    }
  }
}

void delete_Board(Board** board){
  if(board){
    if((*board)->board){
      (*board)->clear((*board));
      for(uint8_t row = 0; row < MAX_BOARD_SIZE; row++){
        free((*board)->board[row]);
      }
      free((*board)->board);
      (*board)->board = NULL;
    }
    free((*board));
    *board = NULL;
  }
}
