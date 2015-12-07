//AIM:to find the length of the given array
#include<stdio.h>
#include<stdlib.h>
//function to find the length of the array
findLength()
{
	//declaring and initialising the variables
	int index=1,index1,size;
int *ptr;
//allocating memory dynamically
ptr=malloc(100*sizeof(int));
	int array[100]={1,2,3,4,10,11,12,13,14,15,16,17,18,20,19,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	while(array[index]!=0)//loop for repetition
	{
		index=2*index;// multiplying index with two for each iteration
		if(array[index]==0)//taking if condition and checking whether the element is zero
		{
			if(array[index-1]==0)//if the previous element is equal to zero
			{
				index=index/2;// reducing index to half it's value
				index1=index/4;// and reducing it again by half
				index=index+index1;// adding both the values
				if(array[index]<array[index-1])// checking if the element at that index is less than the //previous element
				{
					index=index-2; // if so reduce the index by two
					size=index+1;//size is index plus one
				}
			}
			}
			else if(array[index]<array[index-1])// checking if the element is less than the previous element
			{
			index=index-2;//if so reduce the index by two
			size=index+1;	// size is index plus one
			}
			else if(array[index]>array[index+1])// if the element in the index is greater the the next element
			{
				index=index-1;//decrement index by 1
				size=index+1;//size is size plus one
			}
	}
	//print the size
	printf("%d",size-1);
//freeing the memory
free(ptr);
}
main()
{
	//calling the function
	findLength();
}

