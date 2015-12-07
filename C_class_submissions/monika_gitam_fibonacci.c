#include<stdio.h>
fibonacci(int num,int arr[])
{
	int array[100],index,array1[100]={0};
	array[0]=1;
	array[1]=1;
	for(index=2;index<40;index++)
	{
		array[index]=array[index-1]+array[index-2];
	}
	for(index=0;array[index]<=num;index++)
	printf(" %d",array[index]);
	printf("\n");
	index--;
	array1[index-2]=array1[index-1]=1;
	for(index=0;array[index]<=num;index++)
	{
	//printf(" %d",array1[index]);
	arr[index]+=array1[index];
	if(arr[index]==2)
	arr[index]=1;
	}
	index--;
	num=num%array[index];	
	if(num==0)
	return arr;
	else
	fibonacci(num,arr);
}
main()
{
	int array[40]={0};
	int num=334;
	fibonacci(num,array);
	int i;
	for(i=0;i<12;i++){
	printf(" %d",array[i]);
}
}




