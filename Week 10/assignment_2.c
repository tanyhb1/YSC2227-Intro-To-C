#include <stdio.h>

char* strchr(char* str, int c){
  char* ptr = NULL;
  for(int i = 0; str[i] != 0; i++){
    if(str[i] == c){
      ptr = &str[i];
      return ptr;
    }
  }
  return ptr;
}

char* strrchr(char* str, int c){
  char* ptr = NULL;
  for(int i = 0; str[i] != 0; i++){
    if(str[i] == c){
      ptr = &str[i];
    }
  }
  return ptr;
}

int strcmp(char* left, char* right){
  //assuming both strings are the same length...
  for(int i = 0; left[i] != 0 || right[i] != 0; i++){
    if(left[i] > right[i]){
      return 1;
    }
    else if(left[i] < right[i]){
      return -1;
    }
  }
  return 0;
}

void* memset(void* ptr, int value, size_t num){
  char* str = ptr;
  for(int i = 0; i < num; i++){
    str[i] = value;
  }
  return ptr;
}

int main(void){
  char* ptr;
  ptr = strchr("Hello Worled", 101);
  printf("%d\n", ptr);
  ptr = strrchr("Hello Worled", 101);
  printf("%d\n", ptr);
  printf("%d\n", strcmp("Hello World", "Hello Worlc"));
  return 0;
}
