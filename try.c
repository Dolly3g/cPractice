#include <stdio.h>

int main(){
	// char a;
	// int n =0;
	// while(!n){
	// 	printf("\nEnter value: ");
	// 	a = getchar();
	// 	clear_buffer();
	// 	printf("\nYou Entered-%c",a);
	// 	if(a == 'Y'){
	// 		n=1;
	// 	}
	// }

	// char c;

 //   printf("Enter character: ");
 //   c = getc(stdin);
 //   printf("Character entered: ");
 //   putc(c, stdout);


	int *array;
	char *string;

	array = (int *)malloc(12);
	string = array;

	array[0] =1;
	printf("\narray %d\n",array);
	printf("string %d",string);

	free(array);
	printf("\narray %d\n",array);
	printf("string %d",string);

}