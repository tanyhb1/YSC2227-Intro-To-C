#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char** argv){
  if (argc != 3){
    printf("please enter 2 arguments\n");
    return 0;
  }
  char* input_file = argv[1];
  char* output_file = argv[2];

  FILE* fd = fopen(input_file, "r");
  FILE* fc = fopen(output_file, "w");

  int N = 300;
  int mins = INT_MAX;
  int maxs = INT_MIN;
  
  for (int i = 0; i < 300; i++){
    int tmp;
    fscanf(fd, "%d", &tmp);    
    if (tmp > maxs){maxs = tmp;}
    if (tmp < mins){mins = tmp;}
  
  }
  printf("%d %d", maxs, mins);

  

  return 0;
}
