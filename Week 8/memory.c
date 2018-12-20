#include <stdio.h>
#include <stdlib.h>

/*data*/
int A = 0;
/*BSS*/
int B;
/*data*/
int C = 0;
/*BSS*/
int D;

/*stack */
int main (int argc, char ** argv){
/*heap */
  int * E = malloc (sizeof(int) * 2);
  printf("%x\n", &E);
  printf("%x\n", &main);
  printf("%x", &A);
  return 0;  
}
