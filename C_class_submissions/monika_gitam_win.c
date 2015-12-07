//AIM:to find the winner element where winner element is the element with k or more occurences
#include<stdio.h>
#include<stdlib.h>
//declaring the functions
void quicksort(int [10],int,int);
void findMaxRepeatingNumber(int [], int, int);
int main()
{
	//declaring and initialising the variables
  int arr[20],size,index,num;
  printf("Enter size of the array: ");
  scanf("%d",&size);
  printf("Enter %d elements: ",size);
  for(index=0;index<size;index++)
    scanf("%d",&arr[index]);
    printf("Enter the k value");
    scanf("%d",&num);
    //creating a dynamic array
    int *ptr;
    ptr=calloc(size,sizeof(int));
    //checking for the condition if size is less than sum
    if(size<num)
    {
    	printf("error\n");
    	size=num=0;
	}
  quicksort(arr,0,size-1); //calling the function quicksort
  printf("Sorted elements: "); //printing the sorted elements
  for(index=0;index<size;index++)
    printf(" %d",arr[index]);
    printf("\n");
findMaxRepeatingNumber(arr,size,num);// calling the function WinNum
free(ptr);
  return 0;
}
//a function quicksort to arrange the elements in ascending order
void quicksort(int arr[10],int first,int last)
{
    int pivot,index,temp,index1;
     if(first<last){
         pivot=first;
         index1=first;
         index=last;
         while(index1<index){
             while(arr[index1]<=arr[pivot]&&index1<last)
                 index1++;
             while(arr[index]>arr[pivot])
                 index--;
             if(index1<index){
                 temp=arr[index1];
                  arr[index1]=arr[index];
                  arr[index]=temp;
             }
         }
         temp=arr[pivot];
         arr[pivot]=arr[index];
         arr[index]=temp;
         //using recursion  to repeat the process
         quicksort(arr,first,index-1);
         quicksort(arr,index+1,last);
    }
}
//a function to find the winner element
findMaxRepeatingNumber(int array[], int size,int num)
{
	//finding the most recurring element in the array
    int most = 0; 
 int var = 0; 
 int var1 = 0; int index,index1;
 for ( index=0;index<size;index++) 
 { 
 var1 = 1; 
 for ( index1 = index+1;index1<size;index1++) 
 { 
 if (array[index] == array[index1]) 
 var1++; 
 } 
 if (var1>var) 
 { 
 var = var1; 
 most = array[index]; 
 } 
 } 
 //conditions to find the min cost
for(index=0;index<size;index++)
{
	if(array[index]==most-1)
	array[index]=most;
	else if(array[index]==most+1)
		 array[index]=most;		 
		 else if(array[index]>most)
		 array[index]=array[index]-1;
		 else if(array[index]<most)
		 array[index]=array[index]+1;
}
//printing the array
for(index=0;index<size;index++)
printf(" %d",array[index]);
printf("\n");
//finding the most recurring element in the above array
most = 0; 
var = 0; 
var1 = 0;
 for ( index=0;index<size;index++) 
 { 
 var1 = 1; 
 for ( index1 = index+1;index1<size;index1++) 
 { 
 if (array[index] == array[index1]) 
 var1++; 
 } 
 if (var1>var) 
 { 
 var = var1; 
 most = array[index]; 
 } 
 } 
 //ptinting the winner element
if(var>=num)
printf("the winner element is:%d",most);
else
findMaxRepeatingNumber( array, size, num);//using recursion to repeat the process
}






