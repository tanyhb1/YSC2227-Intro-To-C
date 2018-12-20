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
    int A,B;
    fscanf(fd, "%d %d", &A, &B);
    if (i == N-1){
      fprintf(fc, "%d\n", A<B ? A : B );
    }
    else{
      fprintf(fc, "%d ", A<B? A : B);
    }
  }
  
  fclose(fd);
  fclose(fc);
  return 0;
}
