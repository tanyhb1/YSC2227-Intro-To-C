#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int main(int argc, char** argv){
  if (argc !=3){
    printf("please enter input and output\n");
    return 0;
  }
  char* input_file = argv[1];
  char* output_file = argv[2];

  FILE* fd = fopen(input_file, "r");
  FILE* fdw = fopen(output_file, "w");

  int N;
  fscanf(fd, "%d", &N);

  for (int i = 0; i < N; i++){
    int F,C,ans;
    fscanf(fd, "%d", &F);
    C = ((F-32) * 5);
    ans = round((float)C/ 9.0);
    printf("%d ", ans);
  }
  return 0;
  
}
