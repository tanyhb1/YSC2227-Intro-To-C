#include<stdio.h>

void printbin(int v){
	if(v==0){
		printf("0");	
	}
	else if(v%2==0){
		v = v/2;
		printbin(v);
		printf("0");
	}
	else{
		if(v==-1){
		printf("11");
		}
		else if(v==1){
		printf("01");
		}
		else{
			if(v>0){
				v = (v-1)/2;
				printbin(v);
				printf("1");		
			}
			else{
				v = (v+1)/2;
				printbin(v);
				printf("1");		
			}		
		}
	}

}

void printbin2(int v){
	for (int i = (sizeof(int) * 8) - 1; i >= 0; i--)
		printf("%d", (v >> i) & i);
	printf("\n");
}

int len(const char * s){
  int i = 0;
  int acc = 0;
  while(s[i] != '\0'){
    acc++;
    i++;
  }
  return acc;
}

int len2(const char * s){
	int i = 0;
	for(i = 0; s[i] != 0; i++){
	}
	return i;
}
int main()
{
	printbin(-1234);
	printf("asdfdsafaf\n");
	char my_string [] = "Bonjour!";
	printf("%d", len(my_string));
	printf("%d", len2(my_string));
	printf("\n");
	return 0;
}
