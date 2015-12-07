//AIM:TO MULTIPLY TWO NUMBERS USING BITWISE OPERATORS
#include<stdio.h>
//declaring variables using structures
struct test{
	unsigned long int num1, num2;
};
//testcases
struct test testcases[3] =
{
	{ 63746282, 3893488 },
	{ -1, 345 },
	{ 1234, 67 }
};
//function to multiply using bitwise operators
multiply()
{
	int index;
	int product = 0;
	for (index = 0; index<3; index++)//loop for testcases
	{
		while (testcases[index].num2 != 0)//the loop repeats till num2 is not equal to zero
		{
			if (testcases[index].num2 & 01) // performing and operation 
			{
				product = product + testcases[index].num1;//adding product to num1 for every iteration
			}
			testcases[index].num1 <<= 1;//left shifting num1 by 1
			testcases[index].num2 >>= 1;//right shifting num2 by 1
		}
		printf("%d\n", product);//print product
	}
}

main()
{
	multiply();//calling multiply
}
