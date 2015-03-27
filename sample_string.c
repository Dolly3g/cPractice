#include <stdio.h>
#include <math.h>

int main()
{	char str1[] = "dolly";
	char str2[] = "pooja";
	strcat(str1,str2);
	printf("%s %p\n",str1,str1 );
	printf("%s %p\n",str2,str2 );
	return 0;
}