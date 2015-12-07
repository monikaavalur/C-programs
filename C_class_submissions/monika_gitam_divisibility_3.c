//AIM:AN UNSIGNED NUMBER Q IS FORMED BY TAKING INPUT P WHICH IS AN UNSIGNED INTEGER IN STRING FORMAT
//K IS NUMBER OF TIMES P IS REPEATED TO FORM Q. WRITE A FUNCTION TO FIND WHETHER THE NUMBER IS 
//DIVISIBLE BY 3 OR NOT
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//function to repeat p,k times
char *repeat(int size, const char *num)
{
	size_t length = strlen(num);//finding the string length of the number
	char *dest = malloc(size*length + 1);//allocating a memory of k*length+1 i.e., if k=5 and len=3
	                                   //then allocated memory is 16 bits
	int index;
	char *var1;
	for (index = 0, var1 = dest; index < size; ++index, var1 += length)
	{
		memcpy(var1, num, length);// copying the number k times
	}
	*var1 = '\0';
    int num1=atoi(dest);
	int index1= 1;
	int product = 0;
	while (product <= num1)//loop repeats till product is less than var1
	{

		product = 3 * index1; //each time multiplying the index with 3 and storing it in product
		                     //incrementing index for every iteration
		index1++;
	}
	int remainder = num1 - (product - 3); //the remainder is equal to the number subrtacted by prroduct -3
	if (remainder == 0)//if remainder is zero the num is divisible by 3 else no
		printf("The num is divisible by 3\n");
	else
		printf("the num is not divisible by 3\n");
			return dest;//returning the number to main
}
main()
{
	char *result = repeat(5, "2");//calling the function repeat and storing the value sent by repeat in result
	puts(result);//printing result
	free(result);//freeing result
	return 0;
}
