#include <stdio.h>

int islower(int c){
  if(c >= 97 && c <= 122){
    return 1;
  }
  else{
    return 0;
  }
}

int isupper(int c){
  if(c >= 65 && c <= 90){
    return 1;
  }
  else{
    return 0;
  }
}

int isalpha(int c){
  if (islower(c) || isupper(c)){
    return 1;
  }
  else{
    return 0;
  }

}

int isdigit(int c){
  if(c >= 48 && c <= 57){
    return 1;
  }
  else{
    return 0;
  }
}

int isalnum(int c){
  if (isalpha(c) || isdigit(c)){
    return 1;
  }
  else{
    return 0;
  }
}

int iscntrl(int c){
  if ((c >= 0 && c <= 31) || c == 127){
    return 1;
  }
  else{
    return 0;
  }
}
int main(){
  if (iscntrl(127)){
    printf("true");
  }
  else{
	printf("false");
  }
  return 0;

}
