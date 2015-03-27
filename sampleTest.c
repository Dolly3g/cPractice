#include "expr_assert.h"
int x;
void setup(){
	x = 5;
}
void teardown(){
	x = 0;
}
void test_pass(){
	assert(3*2 == 6);
}
void test_fail(){
	assert(5 == 4);
}

void test_start_at_5(){
	assert(x == 5);
	x++;
}

void test_goto_6(){
	assertEqual(x,6);
}

/*int array1[] = {1,2,3};
	int array2[] = {1,2,3};

	util1 = create(INT_SIZE,3);
	util1.base_ptr = (void*)array1;
	
	util2 = create(INT_SIZE,3);
	util2.base_ptr = (void*)array2;

	assertEqual(areEqual(util1,util2),1);

-------------------------------------------------------

void test_findIndex_returns_1_if_the_search_element_is_found_at_first_location (){
	char x = 'd';
	char array[] = {'a','d','x','v'};
	ArrayUtil util = initializeArrayUtil(array,sizeof(char),4);
	assertEqual(findIndex(util,&x),1);
}*/
