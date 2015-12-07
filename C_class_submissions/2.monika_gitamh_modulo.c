//AIM: GIVEN THREE UNSIGNED NUMBERS AS INPUT X,Y,Z FIND OUT X TO THE POWER Y MODULO Z
#include<stdio.h>
#include<math.h>
//function to compute power(x,y)modz
void compute(int x, int y, int z)
{
	int array[20];
	int var1 = y;
	int index = 0, product = 1, length;
	int var2 = pow(x, 2);  //finding x^2 and storing the value in variable
	while (y != 0)
	{
		array[index++] = y % 2;  //dividing the number y into individual digits
		y = y / 2;
	}
	length = index + 1;//assigning index+1 value to length
	if (x%z == 0)  
	{
		printf("0");
	}

	if (var1 % 2 == 0) //check if y is even and if y is even 
	{
		for (index = 0; index<length; index++)
		{
			if (array[index] == 1) //then take a loop and check ehether the value stored in array is 1
			{
				product *= var2%z; //if it one the perform var2%z and store the value in product
				                   //and keep multiplying it for every iteration
			}
		}
		printf("%d", product); //print product
	}
	else
	{
		printf("%d", product*(x%z));
	}
}
int main()
{
	int x, y, z;
	printf("Enter x,y,z values: ");
	scanf_s("%d%d%d", &x, &y, &z);
	compute(x, y, z);

}
