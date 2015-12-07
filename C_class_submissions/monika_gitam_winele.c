#include<stdio.h>
#include<stdlib.h>
int main()
{
//declaring and initaialising variables
  int array[20],size,index,key;
//creating a dynamic array
int *ptr;
  printf("Enter size of the array: ");
  scanf("%d",&size);
ptr=(int*)calloc(size,sizeof(int));
  printf("Enter %d elements: ",size);
  for(index=0;index<size;index++)
    scanf("%d",&array[index]);
    printf("Enter the key");
    scanf("%d",&key);
//calling the function to find the winner element
    find_winnerelement(array,key,size);
//freeing the memory
free(ptr);
  return 0;
}
find_winnerelement(int arr[],int key,int size)
{
//declaring and initialising variables
	int index,index1,var=0,winner_sum1=0,winner_sum2=0,winner_element1=0,winner_element2=0;
	for(index=0;index<size;index++) //for loop to repeat the following iteration
	{
		var=0;             //initialising the variables to zero
		winner_sum1=0;
		for(index1=index;var<key;index1++) //for loop to repeat the following iteration
		{
			if(var==key/2)// if this condition is satisfied assing the value to the variable winner_element1
			{
				winner_element1=arr[index1];
			}
			winner_sum1=winner_sum1+arr[index1];//calculating the sum of the elements
			var++;//incrementing the var
		}
		if(winner_sum2<winner_sum1) // if the condition is satisfied then assign win_sum1=win_sum2
		{
			winner_sum2=winner_sum1;
			winner_element2=winner_element1; //assinging the value of winner_element2 to winner_element1
		}
	}
//printing the winner element
	printf("the winner element is:%d",winner_element2);
}


