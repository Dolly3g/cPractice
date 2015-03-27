#include <stdio.h>

int main(void)
{
	int a = 12;
	int *a_ptr;
	int **aa_ptr;

	a_ptr = &a;
	aa_ptr = &a_ptr;

	printf("Value in a %d",a);
	printf("\nAddress of a %d",&a);
	printf("\nvalue in a_ptr %d",a_ptr);
	printf("\na_ptr pointing to %d",*a_ptr);
	printf("\nAddress of a_ptr %d",&a_ptr);

	printf("Size of a %d",sizeof(a));
	printf("Size of a_ptr %d",sizeof(a_ptr));
	printf("Size of aa_ptr %d",sizeof(aa_ptr));

	return 0;
}