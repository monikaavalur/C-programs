xxxx//AIM:given a number write a function to return the sum of all digits to the main program
#include<stdio.h>
main()
{
	int n,sum;
	printf("Enter the number");
	scanf("%d",&n);
	sum=totsum(n);
	printf("\n sum=%d",sum);
}
totsum(int a)
{
	int c=0,r;
	while(a>0)
	{
		r=a%10;
		a=a/10;
		c=c+r;
	}
	return(c);
}
