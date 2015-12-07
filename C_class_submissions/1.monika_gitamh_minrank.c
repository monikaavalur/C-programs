//AIM: GIVEN AN UNSIGNED NUMBER AS INPUT,FIND THE INDEX OF THE NUMBER IN ALL PERMUTATIONS OF THE NUMBER

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//finding factorial of the number
 int factorial( int number) 
{
	int index, fact = 1;
	if (number <= 1)  
	{
		return 1;  //if the number is less than or equal 1 returning 1
	}
	else
		for (index = 1; index <= number; index++)
			fact = fact *index;    //taking a loop and multiplying fact with index everytime after incrementing index
	return fact;   //Returning fact to the function where factorial is called
}
//finding the smallest value of permutation 
int find_small(char* str, int index1, int index2)
{
	int count = 0, index;
	for (index = index1 + 1; index <= index2; ++index)
		if (str[index]<str[index1])   //by taking a loop we are comparing two adjacent digits and if
			                          //the if condition is satisfied incrementing count
		++count;
	return count; //Returning count to the function where this function is called

}
//finding rank of the number
int find_rank(char* str)
{
	int length = strlen(str);//finding length of the string
	int mul = factorial(length);//calling the function factorial and storing the
	                            //value returned by the function in a variable mul
	int rank = 1;
	int count;
	int index;
	for (index = 0; index<length; ++index) 
	{
		mul /= length - index;                   //subtracting the length by index and storing in mul
		                                         //and dividing it for every iteration
		count = find_small(str, index, length - 1);//calling the function find_small and assigning the
		                                           //value returned by the function to count
		rank += count*mul;//finding the rank by multiplying count with mul and adding the values for 
		                  //every iteration
	}
	return rank; //returning rand to the main 
}
int main()
{
	char str[] = "456";
	int length = strlen(str);
	int *ptr;
	ptr = malloc(length*sizeof(char));//assigning memory to the string
	printf("%d\n", find_rank(str));//calling function find_rank and also printing the rank
	free(ptr);//freeing memory
	return 0;
}



