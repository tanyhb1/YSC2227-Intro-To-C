#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef char cell;

static const cell EMPTY     =  ' ';
static const cell WILL_BORN =  'B';

static const cell ALIVE     =  'X';
static const cell WILL_DIE  =  'D';
static const cell WILL_STAY =  'S';

typedef struct {
  int   WIDTH;
  int   HEIGHT;
  cell* BOARD;
} board;


/**
 Allocation memory to store the board and initialize its content to EMPTY everywhere
 */
board * init (int W, int H) {
  // TO BE IMPLEMENTED
  board *game_board = (board*) malloc(sizeof(board));
  game_board->BOARD = (cell*) malloc(sizeof(cell) * W * H);
  game_board->WIDTH = W;
  printf("hello");
  game_board->HEIGHT = H;
  for (int i = 0; i < (W + H); i++){
    game_board->BOARD[i] = EMPTY;
    printf("%c", game_board->BOARD[i]);
    
  }
  return game_board;
}


/**
 reset a board to EMPTY everywhere
 */
void clear (board *b) {
  // TO BE IMPLEMENTED
}

/**
 return the current value of a cell
 */
cell* access (board * b , int X, int Y) {
  // TO BE IMPLEMENTED
  return NULL;
}


/**
 init from file 
 */
board*  readfile (char* filename) {
  // TO BE IMPLEMENTED
  return NULL;
  
}
/**
 step one time, update the board status 
 */
void process (board *b) {
  // TO BE IMPLEMENTED
}


/**
 Print the content of the board on screen
   ALREADY FILLED
 */
void print (board *b) {
  assert(b);
  for (int i = 0; i  < b->WIDTH * b->HEIGHT ; i++ ) {
    printf("|%c", b->BOARD[i]);
    if ( ( i + 1 )% b->WIDTH == 0)  {
      printf("|\n");
    }
  }
  printf("\n");
}

0/**
   will initialize the board with a test case 
   ALREADY FILLED
 */
void demo_setting (board *b) {
  assert(b);
  
  clear (b);
  
  assert (b->WIDTH >= 5);
  assert (b->HEIGHT >= 5);

  * access (b, 1 , 1) = ALIVE;
  * access (b, 2 , 1) = ALIVE;
  * access (b, 1 , 2) = ALIVE;
  * access (b, 3 , 2) = ALIVE;
  * access (b, 2 , 3) = ALIVE;	   
}

/**
   Front end of the program
   ALREADY FILLED
 */
int main (int argc, char ** argv) {
  board *b = NULL;
  printf("hello");
  fflush(stdout);
  if (argc > 1) {
    b = readfile(argv[1]);
  } else {
    b = init (5,5);
    demo_setting(b);
  }
  if (!b) exit (1);
  print(b);
  
  for (char c ; c = getc(stdin) != EOF;){
    process(b);
    print(b);
  }
  
}
