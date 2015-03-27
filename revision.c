#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

int fibo(int n, int *array){
	int i;
	if(n<=0)
		return 0;
	if(n == 1)
		array[0] = 0;
	else{
		array[0] = 0;
		array[1] = 1;
		for(i=2 ; i<n ; i++){
			array[i] = array[i-1] + array[i-2]; 
		}
	}
	return 1;
}

int concat(int *array1,int len_of_array_1,int *array2,int len_of_array_2,int *result_array){
	int i,j,k=0;
	int len = len_of_array_1 + len_of_array_2;

	for(i=0;i<len_of_array_1;i++)
		result_array[i] = array1[i];

	for(j=len_of_array_1 ; j<len ; j++,k++)
		result_array[j] = array2[k];

	return len_of_array_1 + len_of_array_2;

}

int filter(int *array, int len, int threshold, int **result_array){
	int i,lenght_of_result=0;
	for(i=0 ; i<len ; i++)
		array[i] >= threshold && lenght_of_result++;
	
	*result_array = (int *)malloc(sizeof(int)*lenght_of_result);
	
	
	for(i=0,lenght_of_result = 0 ; i<len ; i++){
		if(array[i] >= threshold)
			(*result_array)[lenght_of_result++] = array[i];
	}
	return lenght_of_result;
}

int reverse(int *array, int len){
	int i,j,temp[len],temp_len=len;

	for(i=0 ; i<len ; i++)
		temp[i] = array[i]; 

	for(j=0 ; j<len ; j++)
		array[j] = temp[--temp_len];
	
	return 1;
}

int reverseReturn(int *array, int len, int *result_array){
	int i,temp_len = len;
	for(i=0 ; i<len ; i++){
		result_array[--temp_len] = array[i];
	}
	return 1;
}

// int isPalindrome(int num){
// 	int count=1,temp=num,new_num=0;
// 	while(num != 0){
// 		new_num += num%10 * count;
// 		num = num/10;
// 		count = count * 10;
// 	}

// 	printf("%d %d",temp,new_num);

// 	if(new_num == temp)
// 		return 1;
// 	return 0;
// }

int slice (int *array, int len, int start, int end, int **result_array){
	int i,count;
	*result_array = (int *)malloc(sizeof(int)*(end-start));
	for(i=start,count=0 ; i<end ; i++){
		(*result_array)[count++] = array[i];
	}
	return end-start;
}

int isPrime(int n){
	int i,is_prime = 1;
	if(n<=1)
		return 0;
	if(n==2)
		return 1;
	for(i=2 ; i<=floor(sqrt(n)) ; i++){
		if(n%i == 0){
			is_prime = 0;
			break;
		}
	}
	return is_prime;
}

int getPrimes(int **primes, int start, int end){
	int i,count = 0;
	for(i=start ; i<end ; i++){
		isPrime(i) && count++;
	}
	*primes = (int *)malloc(sizeof(int)*count);
	for(i=start,count=0; i<end ; i++){
		isPrime(i) && ((*primes)[count++] = i);
	}
	return count;
}

int strCmp(char *str1 , char *str2){
	int i;
	int l1 = strlen(str1);
	int l2 = strlen(str2);
	
	int length = l1>l2 ? l1 : l2;

	for(i=0 ; i<length ; i++){
		int ascii1 = str1[i];
		int ascii2 = str2[i];
		if(ascii1 != ascii2)
			return ascii1 - ascii2;
	}

	return 0;
}

int forEach(int *array,int len, void *(fn_ptr)(int,int,int*)){
	int i;
	if(len ==0)
		return 0;
	for(i=0 ; i<len ; i++){
		(*fn_ptr)(array[i],i,array);
	}
	return 1;
}

int forEachChar(char *array,int len,void (*fn_ptr)(char,int,char*)){
	int i;
	if(len == 0)
		return 0;
	for(i=0 ; i<len ; i++){
		(*fn_ptr)(array[i],i,array);
	}
	return 1;
}

int forEachString(char **array,int len,void (*fn_ptr)(char*,int,char**)){
	int i;
	for(i=0;i<len;i++){
		(*fn_ptr)(array[i],i,array);
	}
	return 1;
}

int filterArray(int *array, int len, int (*fn_ptr)(int,int,int*), int **result_array){
	int i,len_of_result=0,flag;
	for(i=0 ; i<len ; i++){
		flag = fn_ptr(array[i],i,array);
		if(flag == 1)
			len_of_result++;
	}
	*result_array = (int *)malloc(sizeof(int)*len_of_result);
	for(i=0,len_of_result=0 ; i<len ; i++){
		flag = fn_ptr(array[i],i,array);
		if(flag == 1)
			(*result_array)[len_of_result++] = array[i];
	}
	return len_of_result;
}

int filterStrings(char **array, int len, int (*fn_ptr)(char*,int,char**),char ***result_array){
	int i,flag,len_of_result =0;
	for(i=0 ; i<len ; i++){
		flag = fn_ptr(array[i],len,array);
		flag == 1 && len_of_result++;
	}
	*result_array = (char **)malloc(sizeof(char*)*len_of_result);

	for(i=0,len_of_result=0 ; i<len ; i++){
		flag = fn_ptr(array[i],i,array);
		flag == 1 && ((*result_array)[len_of_result++] = array[i]);
	}
	return len_of_result;
}

int* mapInt (int *array,int len,int (*fn_ptr)(int,int,int*)){
	int i;
	int *result_array = (int *)malloc(sizeof(int)*len);
	for(i=0 ; i<len ; i++){
		result_array[i] = fn_ptr(array[i],len,array);
	}
	return result_array;
}

char** mapString (char **array , int len, char* (*fn_ptr)(char*,int,char**)){
	int i;
	char **result_array = (char**)malloc(sizeof(char*)*len);

	for(i=0 ; i<len ; i++){
		result_array[i] = fn_ptr(array[i],len,array);
	}
	return result_array;
}

int reduce(int *array, int len, int (*fn_ptr)(int,int,int,int*),int pv){
	int i,result;
	for(i=0 ; i<len; i++){
		pv = fn_ptr(pv,array[i],i,array);
	}
	return pv;
}

int areConsecutive(int *array,int length){
	int i,flag=1;
	for(i=1 ; i<length-1 ; i++){
		printf("~~~~~~~~~~~~~~~~~~~~~~~     %d %d %d",array[i],array[i-1],i);
		if(array[i] != array[i-1]+1){
			flag = 0;
			break;
		}
	}
	return flag;
}

int indexOf (char* str, char* substr){
	int i,j,count,str_len=strlen(str),substr_len=strlen(substr),index=-1;

	for(i=0,count=0 ; i<substr_len ; i++,count++){
		for(j=0 ; j<str_len ; j++){
			index++;
			while(str[j] == substr[i]){
				i++;
				j++;
				if(i == substr_len)
					return index;
			}
			if(index == str_len){
				return -1;
			}
			
		}
	}
	return index;
}

char* reduceStrings(char **array, int len, char* (*fn_ptr)(char*, char*, int, char **)){
	int i,initial_len=strlen(array[0]);
	char* pv = (char*)malloc(sizeof(char)*initial_len);
	strcpy(pv,array[0]) ;
	for(i=1 ; i<len ; i++){
		strcpy(pv,fn_ptr(pv,array[i],len,array));
	}
	return pv;
}