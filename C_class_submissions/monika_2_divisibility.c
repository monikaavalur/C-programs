//aim: given a number find out whether the number is divisible by 11 or not
#include<stdio.h>
main()
{
	int n,a=0,b=0;
	printf("Enter the number");
	scanf("%d",&n);
	while(n!=0)
	{
		a=n%10+a;
		n=n/10;
		b=n%10+b;
		n=n/10;
	}
	if(b==a)
	printf("The number is divisible by 11");
	else
	printf("The number is not divisible by 11");
}
