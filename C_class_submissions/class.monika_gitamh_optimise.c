//AIM: GIVEN AN ARRAY TO MULTIPLY THE NUMBERS EXCEPT THE REFERENCED NUMBER
#include<stdio.h>
//declaring varaibles using structures
struct test{
	int array[100];
	int size;
};
//testcases
struct test testcases[1] = {
	{ { 1, 2, 3, 4, 5 }, 5 },
};
//function to perform the given task
optimise()
{
	int index,index1;
	int array1[100], mul=1;
	for (index = 0; index<1; index++) //taking the loop for testcases
	{
		for (index1 = 0; index1<testcases[index].size;index1++)//traversing the array
		{
			mul *= testcases[index].array[index1];//multiply the elements of array with mul for each iteration
		}                                         //and store it in mul
		for (index1 = 0; index1<testcases[index].size; index1++)
		{
			array1[index1] = mul / testcases[index].array[index1];//divide the mul with the successive elements
		}
		for (index1 = 0;index1<testcases[index].size;index1++)
		{
			printf("%d\n", array1[index1]);//print the final array
		}

	}
}
main()
{
	optimise();
}
