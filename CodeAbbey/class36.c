#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
  if (argc != 3){
    printf("Please enter 2 arguments\n");
    return 0;
  }
  char* input_file = argv[1];
  char* output_file = argv[2];

  FILE* fd = fopen(input_file, "r");
  FILE* fc = fopen(output_file, "w");

  int N;
  fscanf(fd, "%d", &N);
  int A[N];
  int B[N];
  int counter = 0;
  for (int i = 0; i<N; i++){
    int guess;
    int correct;
    fscanf(fd, "%d %d", &guess, &correct);
    if (correct != 0){
      A[counter] = guess;
      B[counter = correct;
      counter++;
    }
  }

  

  return 0;
}
