#include <stdio.h>
#include <stdlib.h>
int main (int argc, char** argv){
	int A,B;
	int C = 0 ;
	if (argc != 3){
	printf("Please enter two arguments, one input and one output.\n");
	return 0;
	};
	
	//get inputs 
	//print outputs
	FILE* fd = fopen(argv[1], "r");
	if (!fd) {printf("Could not open the file.\n"); exit (1);};

	//assign memory
	//unsigned char * buf = malloc(sizeof(unsigned char) * 3);
	//int read = fread(buf, sizeof(unsigned char), 3, fd);
	fscanf(fd, "%d", &A);

	for (int i = 0; i < A; i++){
	  fscanf(fd, "%d", &B);
	  C = C + B;
	};

	fclose(fd);

	printf("%d\n", C);

	FILE* fc = fopen(argv[2], "w");
	if (!fc) {printf("Could not open the file.\n"); exit (1);};
	fprintf(fc, "%d", C);
	fclose(fc);
};
2
