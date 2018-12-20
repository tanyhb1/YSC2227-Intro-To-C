#include <stdio.h>
struct A{
	int x;
	int y;
};
union B{
	int x;
	char y;
};



int main (){
	struct A A1;
	A1.x = 5;
	A1.y = 10;
	printf("%d %d\n", A1.x, A1.y);
	union B B1;
	B1.x = 5;
	B1.y = 'a';
	printf("%d %d\n", B1.x, B1.y); 
	struct A* A2 = &A1;
	(*A2).x = 5;
	(*A2).y = 10;
	printf("%d %d\n", (*A2).x, (*A2).y);
	int * numbers = malloc(12*sizeof(int));
	for (int i = 0; i< 12; numbers[i++] = i);
	for (int i = 0; i< 12; i++) printf("%d\n", i);
	free(numbers);
	return 0;
}
