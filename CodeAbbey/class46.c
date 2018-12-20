#include <stdio.h>
#include <stdlib.h>

int checkwin(int* board){
  if(board[1] == board[2] && board[2] == board[3])
    return 1;
  else if(board[4] == board[5] && board[5] == board[6])
    return 1;
  else if(board[7] == board[8] && board[8] == board[9])
    return 1;
  else if(board[1] == board[4] && board[4] == board[7])
    return 1;
  else if(board[2] == board[5] && board[5] == board[8])
    return 1;
  else if(board[3] == board[6] && board[6] == board[9])
    return 1;
  else if(board[1] == board[5] && board[5] == board[9])
    return 1;
  else if(board[3] == board[5] && board[5] == board[7])
    return 1;
  else if (board[1] != '1' && board[2] != '2'  && board[3] != '3' &&
        board[4] != '4' && board[5] != '5' && board[6] != '6'  && board[7] 
        != '7' && board[8] != '8' && board[9] != '9')
    return 0;
  else
    return -1;
}


int main(int argc, char** argv){
  if (argc != 3){
    printf("Please enter an input and an output\n");
    return 0;
  }

  char* input_file = argv[1];
  char* output_file = argv[2];

  FILE* fd = fopen(input_file, "r");
  FILE* fdw = fopen(output_file, "w");

  int N;
  fscanf(fd, "%d", &N);
  
  for(int i = 0; i < N; i++){
    int board[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int win_condition = 0;
    for(int j = 0; j < 9; j++){
      int stor;
      int player = 0;
      fscanf(fd, "%d", &stor);
      if (j%2 == 1)
        player = 1;
      board[stor] = player;
      win_condition = checkwin(board);
      if (win_condition == 1){
	printf("%d ", j+1);
	for (int k = 0; k < 8-j; k++){
	  fscanf(fd, "%d", &stor);
	}
	break;
      }
      else if (win_condition == 0){
        printf("0 ");
	for (int k = 0; k < 8-j; k++){
	  fscanf(fd, "%d", &stor);
	}
	break;
      }
    }
  }
  return 0;
}
