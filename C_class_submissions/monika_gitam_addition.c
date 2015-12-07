//AIM:to add two numbers
#include<stdio.h>
//adding using pointers
add1(long int num1, long int num2)
{
	long int *ptr1, *ptr2, sum;
	ptr1 = &num1; //assigning the address of the numbers to the pointers
	ptr2 = &num2;
	sum = *ptr1 + *ptr2; //adding the numbers
	printf("%ld\n", sum);
}
main()
{
	char num1[1000]={"127834"}, num2[1000]={"57987674"};
	int num=atoi(num1);
	int num3=atoi(num2);
	add1(num,num3);
	//calling the functions
}

