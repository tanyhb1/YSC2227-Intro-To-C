#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
  if (argc != 3){
    printf("please enter input and output\n");
    return 0;
  }

  char* input_file = argv[1];
  char* output_file = argv[2];

  FILE* fd = fopen(input_file, "r");
  FILE* fdw = fopen(output_file, "w");

  int N;
  fscanf(fd, "%d", &N);

  for(int i = 0; i < N; i++){
    int A, B, C, stor;
    int counter = 0;
    fscanf(fd, "%d %d %d", &A, &B, &C);
    stor = (A * B) + C;
    while(stor > 0){
      counter += stor%10;
      stor = stor/10;
    }
    fprintf(fdw, "%d ", counter);
  }

  fclose(fd);
  fclose(fdw);  
  return 0;
}
