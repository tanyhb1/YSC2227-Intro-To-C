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
  // element[i][j]= game_board[i * width + j]
  board *game_board = (board*) malloc(sizeof(board));
  game_board->BOARD = (cell*) malloc(sizeof(cell) * W * H);
  game_board->WIDTH = W;
  game_board->HEIGHT = H;
  for (int i = 0; i < (W * H); i++){
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
  for (int i = 0; i < (b->WIDTH * b->HEIGHT); i++){
    b->BOARD[i] = EMPTY;
  }

}

/**
 return the current value of a cell
 */
cell* access (board * b , int X, int Y) {
  // TO BE IMPLEMENTED
  // usage: access (b, 3, 3) = ALIVE;
  int W = b->WIDTH;
  return &(b->BOARD[Y*W + X]);
}


/**
 init from file 
 */

board* readfile (char* filename) {
  // TO BE IMPLEMENTED
  FILE* fd = fopen(filename, "r");
  int W = 1;
  int H = 1;
  int c;
  //count width and height of board first
  while((c=fgetc(fd))!=EOF){
    if(c == '\n'){
      H++;
    }
  }
  //set pointer to start of file again to re-read
  fseek(fd, 0, SEEK_SET);
  while((c=fgetc(fd))!='\n'){
    W++;
  }
  fseek(fd,0,SEEK_SET);
  //initialize board with cells
  board* b = init(W, H);
  int X = 0;
  int Y = 0;
  while((c=fgetc(fd))!=EOF){
    if(c != '\n'){
      X++;
      if(c == 'X')
      *access(b, X, Y) = ALIVE;
    }
    else if(c == '\n'){
      Y++;
      X = 0;
    }

  }
  fclose(fd);
  //return board
  return b;
  
}

int neighbours (board *b, int X, int Y){
  // returns number of Live neighbours
  int counter = 0;
  int W = b->WIDTH;
  int H = b->HEIGHT;
  if((X + 1) < W){
    if(*access(b, X+1, Y) != EMPTY && *access(b, X+1, Y) != WILL_BORN){
      counter++;
    }
    if((Y + 1) < H){
      if(*access(b, X+1, Y+1) != EMPTY && *access(b, X+1, Y+1) != WILL_BORN ){
	counter++;
      }
    }
    if(Y  != 0){
      if(*access(b, X+1, Y-1) != EMPTY && *access(b, X+1, Y-1) != WILL_BORN){
	counter++;
      }
    }
  }
  if(X != 0){
    if(*access(b, X-1, Y) != EMPTY && *access(b, X-1, Y) != WILL_BORN){
      counter++;
    }
    if((Y + 1) < H){
      if(*access(b, X-1, Y+1) != EMPTY && *access(b, X-1, Y+1) != WILL_BORN){
	counter++;
      }
    }
    if(Y != 0){
      if(*access(b, X-1, Y-1) != EMPTY && *access(b, X-1, Y-1) != WILL_BORN){
	counter++;
      }
    }
  }
  if((Y + 1) < H){
    if(*access(b, X, Y+1) != EMPTY && *access(b, X, Y+1) != WILL_BORN){
      counter++;
    }
  }
  if(Y != 0){
    if(*access(b, X, Y-1) != EMPTY && *access(b, X, Y-1) != WILL_BORN){
      counter++;
    }
  }
  return counter;
}
/**
 Print the content of the board on screen
   ALREADY FILLED
 */
void print (board *b) {
  assert(b);
  printf("\n");
  for (int i = 0; i  < b->WIDTH * b->HEIGHT ; i++ ) {
    printf("|%c", b->BOARD[i]);
    if ( ( i + 1 )% b->WIDTH == 0)  {
      printf("|\n");
    }
  }
  printf("\n");
}
/**
 step one time, update the board status 
 */
void process (board *b) {
  // TO BE IMPLEMENTED
  int W = b->WIDTH;
  int H = b->HEIGHT;
  for (int i = 0; i < W; i++){
    for (int j = 0; j < H; j++){
      if (*access(b, i, j) != EMPTY && *access(b, i, j) != WILL_DIE){
	//count number of live neighbours
	int counter = neighbours(b, i, j);
	//check if < 2 live neighbours
	if (counter < 2){
	  *access(b, i, j) = WILL_DIE;
	}
	//check if  2 or 3 live neighbours
	else if (counter == 2 || counter == 3){
	  *access(b, i, j) = WILL_STAY;
	}
	//check if >3 live neighbours
	else if (counter > 3){
	  *access(b, i, j) = WILL_DIE;
	}
      }
      else{
	//count number of live neighbours
	int counter = neighbours(b, i, j);
	//check if exactly 3 live neighbours
	if (counter == 3){
	  *access(b, i, j) = WILL_BORN;
	}
      }
    }
  }
  for (int i = 0; i < W; i++){
    for (int j = 0; j < H; j++){
      if (*access(b, i, j) == WILL_DIE || *access(b, i, j) == EMPTY){
	*access(b, i, j) = EMPTY;
      }
      else {
	*access(b, i, j) = ALIVE;
      }

    }
  }
  
  
}



/**
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
  if (argc > 1) {
    b = readfile(argv[1]);
  } else {
    b = init (5,5);
    demo_setting(b);    
  }
  if (!b) exit (1);
  print(b);
  fflush(stdout);
  
  for (char c ; (c = getc(stdin)) != EOF;){
    process(b);
    print(b);
    fflush(stdout);
  }
  
}
