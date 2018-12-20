#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
  if (argc <2){
    printf("please enter your input files\n");
    return 0;
  }
  int total_l = 0;
  int total_w = 0;
  int total_c = 0;
  for (int i = 1; i < argc; i++){
    char* input_file = argv[i];
    FILE* fd = fopen(input_file, "r");
    if (!fd){
      printf("Please enter valid input files. %s is not valid. \n", input_file);
    }
    else{
    int l_count = 0;
    int w_count = -1;
    int c_count = 0;
    int space = 1;
    int c = '\n';
    int last = '\n';
    while((c = fgetc(fd)) != EOF){
      last = c;
      c_count += 1;
      if (c == ' '){
	space = 1;
      }
      if (c == '\n'){
	c_count += 1;
	l_count += 1;
	w_count += 1;
      }
      else{
	w_count += space;
	space = 0;
      }
    }
    if (last != '\n'){
      l_count += 1;
    }

    fclose(fd);
    printf("%d %d %d %s\n", l_count, w_count, c_count, input_file);
    total_l += l_count;
    total_w += w_count;
    total_c += c_count;
    }
  }
  printf("%d %d %d total\n", total_l, total_w, total_c);
  return 0;
}



