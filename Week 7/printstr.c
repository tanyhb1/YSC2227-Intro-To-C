#include <stdio.h>

int len2(const char * s){
	int i = 0;
	for(i = 0; s[i] != 0; i++){
	}
	return i;
}

int main()
{
  char my_string [] = "Bonjour!";
  printf("%d",len2(my_string));
  return 0;
}
