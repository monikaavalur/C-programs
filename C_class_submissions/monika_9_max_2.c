//Program to write a function which takes an array as input and finds out the two largest values of the array
#include <stdio.h>
#include<conio.h>

const int num=20;

struct large
{
	int arr[20];
	int len;
	int max1;
	int max2;
	int op[2];
}

test[3]={
{1,2,-7,4,-3,4},
{{},6,5,2,1,10},
{45,-23,90,-12,15},
};

void max_2(struct large *i);

void testcases()
{
	int i;
	for(i=0;i<3;i++)
	{
	if(test[i].op[0]==test[i].max1 && test[i].op[1]==test[i].max2)
 		printf("\n Passed! ");
 		
 		else
 		printf("\n Failed! ");
 	}
 }
 main()
 {
 	testcases();
 	getch();
 }
 void max_2(struct large *i)
 {
 	i->op[0]=i->op[1]=i->arr[0];
  	int j=1;
  	while(j<i->len)
 	{
 		if(i->arr[j]>i->op[0])
 		{
 		i->op[0]=i->arr[j];
 		}	
 		
 		else if(i->arr[j]>i->op[1])
 		{
 		i->op[1]=i->arr[j];
 		}	
 		j++;
 	}
 }

