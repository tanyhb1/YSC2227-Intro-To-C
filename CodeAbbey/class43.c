#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char** argv){
  if (argc != 3){
    printf("sadfsadF");
    return 0;
  }

  char* input_file = argv[1];
  char* output_file = argv[2];

  FILE* fd = fopen(input_file, "r");
  FILE* fdw = fopen(output_file, "w");
  int N;
  fscanf(fd, "%d", &N);
  float stor;
  for (int i = 0; i<N; i++){
    fscanf(fd, "%f", &stor);
    stor = stor * 6;
    stor = (int) stor;
    stor = stor + 1;
    printf("%d ",(int) stor);
  }

  fclose(fd);
  fclose(fdw);
  return 0;

}
