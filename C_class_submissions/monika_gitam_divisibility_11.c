//AIM:GIVEN AN UNSIGNED NUMBER WRITE A FUNCTION TO CHECK WHETHER IT IS DIVISIBLE BY 11 OR NOT
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
//checking divisibility by simple modulo method
divisibility(int size, int num)
{
	int ptr;
	ptr = malloc(size*sizeof(int));//allocating memory dynamically
	if (num % 11 == 0)//if num mod 11 is zero 
		printf("the number is divisible by 11\n");
	else
		printf("it's not divisible by 11\n");

}
divisibility1(int size, int num)
{

	int *ptr;
	int var1 = 0, var2 = 0;
	ptr = malloc(size*sizeof(int));//allocating memory dynamically
	while (num != 0)
	{
		var1 = num % 10 + var1;//adding all even position digits
		num = num / 10;
		var2 = num % 10 + var2;//adding all odd position digits
		num = num / 10;
	}
	if (var1== var2)
		printf("the number is divisible by 11\n");
	else
		printf("it's not divisible by 11\n");
	free(ptr);

}
divisibility3(int size, int num)
{
	int var1 = 0, var2 = 0;
	int *ptr = malloc(size*sizeof(int));//allocating memory dynamically
	if (ptr == NULL)
	{
		printf("ERROR!");//if no size then it's an error
	}
	else{
		while (num > 0)
		{
			var1 += num % 10;//adding all even position digits
			num /= 10;
			var2 += num % 10;//adding all odd position digits
			num /= 10;
		}
		int diff = var1 > var2 ? (var1 - var2) : (var1 - var2);//calculating the difference
		if (diff % 11 == 0)//if difference is divisible by 11 then num is divisible
			printf("the number is divisible by 11\n");
		else
		printf("it's not divisible by 11\n");
	}
	free(ptr);
}



int main()
{
	char str[10000]={"1231"};
       int  size=3;
int num;
num=atoi(str);
	//calling the functions
	divisibility(size, num);
	divisibility1(size, num);
	divisibility3(size, num);
}
