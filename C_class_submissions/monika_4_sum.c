//AIM:To write a c program to find the sum of even digits and odd digits in a given number
#include<stdio.h>
main()
{
	compute();
}
compute()
{

	int n,evensum=0,oddsum=0;
	printf("Enter the number:");
	scanf("%d",&n);
	while(n>0)
	{
		if((n%10)%2==0)
		{
			evensum=evensum+(n%10);
		}
		else
		{
			oddsum=oddsum+(n%10);
		}
		n=n/10;
	}
		printf("The sum of odd numbers is:%d and sum of even numbers is:%d",oddsum,evensum);
	}