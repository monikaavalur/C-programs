//AIM:TO SORT AN ARRAY HAVING ONLY 0'S AND 1'S
#include<stdio.h>
//declaring variables in structure
struct test{
	int array[100], size;
};
//testcases
struct test testcases[3] = {
	{ { 0, 1, 1, 0, 1, 0, 1, 1 }, 8 },
	{ { 1, 1, 0, 0, 1, 1, 0, 1 }, 8 },
	{ { 1, 0, 1, 0, 0, 1, 0, 1 }, 8 }
};
//sorting by using quick sort method
sort1()
{
	int index;
	int index1, index2;
	for (index = 0; index<3; index++)
	{
		index1 = 0;
	index2 = testcases[index].size - 1;//initialise index2 as size-1
		while (index1<index2)
		{
			while (testcases[index].array[index1] == 0 &&index1<index2)
				index1++;                  //take a loop that repeats while the element in the array is zero 
			                               //and index1 is less than index2 increment index1 each time
			while (testcases[index].array[index2] == 1)
				index2--;             //take a loop that repeats while the element in the array is one and decrement index2 each time
			if (index1<index2)
			{
				testcases[index].array[index1] = 0;//if index1 is less than index2 replace the element in index1 by o
				                                    //and in index2 with 1
				testcases[index].array[index2] = 1;
			}
		}
		printf("quick sort:");
		for (index1 = 0; index1<testcases[index].size;index1++)
			printf("%d\n", testcases[index].array[index1]);//print array
	}
}
//sorting by using bubble sort
sort2()
{
	int temp, index;
	int index1, index2;
	for (index = 0; index<3; index++)
	{
		for (index1 = 0; index1<testcases[index].size; index1++)//take a loop for index1 
		{
			for (index2 = index1 + 1; index2<testcases[index].size; index2++)//loop for index2
			{
				if (testcases[index].array[index1] >= testcases[index].array[index2])//if the element in index1 is greater than the element in index2
				{
					//swap both the number by using a temporary variable
					temp = testcases[index].array[index1];
					testcases[index].array[index1] = testcases[index].array[index2];
					testcases[index].array[index2] = temp;
				}
			}//repeat the loops until the conditions are satisfied
		}
		printf("bubble sort:");
		for (index1 = 0; index1<testcases[index].size;index1++)
			printf("%d\n", testcases[index].array[index1]);//print the array
	}
}
//sorting by counting zero's
sort3()
{
	int count, size = 5, arr[100] = { 1, 3, 1, 1, 0 }, index = 0;
	for (count = 0; count<size; count++)
	{
		if (arr[count] >= 2)//if the elements in the array are greater than or equal to 2 than there's an error
		{
			printf("error\n");
			index = 0, size = 0;
		}
		else
			if (arr[count] == 0)
				index++;//otherwise traverse the array and every time u get a zero increment count
	}
	//print the array
	for (count = 0; count < index; count++)
		printf("0 ");
	for (count = 0; count < size - index; count++)
		printf("1 ");

}
//sorting by calculating the sum of the elements of the array
sort4()
{
	int array[100] = { 0, 1, 1, 0, 1, 0, 1, 3, 0, 1 };
	int size = 10;
	int sum;
	int index;
	for (index = 0; index<size; index++)
	{
		if (array[index] >= 2)//if the elements in the array are greater than 2 then error
		{
			printf("error\n");
			index = 0, size = 0, sum = 0;
		}
		else
			sum += array[index];//else add all the elements of the array
	}
	//print the array
	for (index = 0; index<size - sum; index++)
	{
		printf("0");
	}
	for (index = 0; index<sum; index++)
	{
		printf("1");
	}
}




main()
{
	//calling the functions

	sort1();
	sort2();
	sort3();
	sort4();
}



