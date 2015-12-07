//AIM:TO PERFORM ADDITION FROM LEFT TO RIGHT
#include<stdio.h>
#include<stdlib.h>
//function to perform addition from left to right
addition()
{
	long int num1[100] = { 56574 }, num2[100] = { 36247 };
	int *ptr = malloc(sizeof(num1)*sizeof(long int));
	int index = 0;
	int length = 1;
	while (index<length)// repeat the loop for index less than length of the array
	{
		num1[index] = num1[index] + num2[index];//adding the elements of the array 
		if (num1[index] > 9)//during addition if the num is greater than 9
		{
			if (num1[index - 1] == 9) // if the previous index is equal to 9
			{
				num1[index - 1] = 0;//than make it to 0
				num1[index - 2] += 1;//and add the previous elment with 1
			}
			else if (num1[index] < 9)//else if the previous element is less than 9
			{
				num1[index - 1] = num1[index - 1] + 1;//than increment it by 1
			}
		}
		index++;//increment the index and return for next iteration
	}
	for (index = 0; index < length; index++){
		printf("%d", num1[index]);//print the array
	}
	free(ptr);
}

main()
{
	addition();
}
