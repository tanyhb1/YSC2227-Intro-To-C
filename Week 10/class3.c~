#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
  if (argc != 3){
    printf("please enter 2 arguments\n");
    return 0;
  }
  char * input_file = argv[1];
  char* output_file = argv[2];

  FILE* fd = fopen(input_file, "r");
  FILE* fc = fopen(output_file, "w");

  int N;

  fscanf(fd, "%d", &N);

  for (int i = 0; i < N ; i++){
    int A,B,C;
    fscanf(fd, "%d %d %d", &A, &B, &C);

    if (i == N-1){
      if (A < B && A < C){
	fprintf(fc, "%d\n", A);
      }
      else if (B < A && B < C){
	fprintf(fc, "%d\n", B);
      }
      else{
	fprintf(fc, "%d\n", C);
      }

    }
    else{
      if (A < B && A < C){
	fprintf(fc, "%d ", A);
      }
      else if (B < A && B < C){
	fprintf(fc, "%d ", B);
      }
      else{
	fprintf(fc, "%d ", C);
      }
    }
  }
  
  fclose(fd);
  fclose(fc);
  return 0;
}
