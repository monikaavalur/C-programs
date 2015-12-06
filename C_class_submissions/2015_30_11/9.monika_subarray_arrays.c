//9.Largest Contiguous Sum Array .
//Ex : 1, 2, 3, 5, -10, 20, 40 O / P : 20, 40 Sum : 60
 //Ex : 1 2 3 4 5 - 2 - 3 - 4 - 20 10 2 O / : P : 1 2 3 4 5 Sum : 15
#include<stdio.h>
#include <stdlib.h>
int maxSubArraySum(int arr[], int length, int *start, int *end)
{
    int temp = 0, temp2 = 0;
	int index, current_index = 0;
   for (index = 0; index < length; index++)
   {
	   temp2 = temp2 + arr[index];
     if (temp2<= 0)
      {
         temp2 = 0;
         current_index = index + 1;
     }
  else if (temp < temp2)
    {
       temp = temp2;
       *start = current_index;
       *end = index;
   }
   }
   printf("The sub array is:");
   for (index = *start; index <= *end; index++)
	   printf("%d,", arr[index]);

   printf("\n");
   return temp;
}

int main()
{
	int arr[] = { -1, -2 ,3, -4, 5, - 2 ,- 3, - 4, - 20, 10, 2 };
	int start = 0, end = 0;
	int size = sizeof(arr) / sizeof(arr[0]);
	printf(" The max sum is %d", maxSubArraySum(arr, size, &start, &end));
	getchar();
	return 0;
}