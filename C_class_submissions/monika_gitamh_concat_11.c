//AIM:TO CHECK DIVISIBILITY BY 11
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *repeat(int size, const char *num)
{
	size_t length = strlen(num);//Finding the string length
	char *dest = malloc(size*length + 1);//allocating memory dynamically 
	int index;
	char *ptr;
	for (index = 0, ptr = dest; index< size; ++index, ptr += length)//taking a loop to copy the number size times
	{
		memcpy(ptr, num, length);//copying the number size times
	}
	*ptr = '\0';
	int num1 = atoi(dest);//converting char* to num
	int var1 = 0, var2 = 0;
	//code to check divisibility of number by 11
	while (num1 != 0)
	{
		var1 = num1 % 10 + var1;//adding all even position digits
		num1 = num1/ 10;
		var2 = num1 % 10 + var2;//adding all odd position digits
		num1 = num1 / 10;
	}
	//printing statements
	if (var1 == var2)
		printf("the number is divisible by 11\n");
	else
		printf("it's not divisible by 11\n");

	return dest;
}

main()
{
	//calling a function
	char *result = repeat(6, "121");
	puts(result);//printing result
	free(result);//freeing memory
	return 0;
}