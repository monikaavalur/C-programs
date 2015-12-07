//AIM:To generate a number which when multiplied by 2 results in the same number
#include<stdio.h>
#include<stdlib.h>
mul()
{
	//declaring and initialising variables
	int arr[6],mul,num,arr1[6],index=0,index1=5,temp,index3,index2=5;
	int *ptr,*ptr1,count=0;
	//creating an array dynamically
	ptr=(int*)calloc(6,sizeof(int));
	ptr1=(int*)calloc(6,sizeof(int));
	for(index=0;index<399999;index++)//for loop for generating numbers
	{
        count=0;		
        num=100000+index;//generating the number
        //spliting the digits of the number and storing them in an array
		do{
			arr[index1]=num%10;
			num/=10;
			index1--;
		}while(num!=0); 
		//arranging the numbers in ascending order
	for (index3=0;index3<6;++index3)
    {
        for (index1=index3+1;index1<6;++index1)
        {
            if (arr[index3] >arr[index1])
            {
                temp=arr[index3];
                arr[index3] = arr[index1];
                arr[index1] = temp;
            }
        }
  }
  num=100000+index;
		mul=num*2;//multiplying the number with 2 and storing the value in mul
		//spliting the digits of the number and storing them in an array
  do{
			arr1[index2]=mul%10;
			mul/=10;
			index2--;
		}while(mul!=0);
		//arranging the elements of the array in ascending order
for (index3=0;index3<6;++index3)
    {
        for (index2=index3+1;index2<6;++index2)
        {
            if (arr1[index3] > arr1[index2])
            {
                temp =  arr1[index3];
                arr1[index3] = arr1[index2];
                arr1[index2] = temp;
            }
        }
}
//comparing the two arrays... if both arrays have same elements incrementing count
count=0;
for(index2=0;index2<6;index2++)
{
	if(arr1[index2]==arr[index2])
		count++;
}
	 	for (index3=0;index3<6;++index3)
	 	{
	 	if(arr[index3]!=6)
	 	{
	 		if(arr[6]==8)
	 		count--;
		 }
   }
 //printing the number
if(count==6)
{
if(num%2==0)
printf("%d\n",num);
}
}
//freeing memory
	free(ptr);
	free(ptr1);
}

main()
{
	mul();
}







