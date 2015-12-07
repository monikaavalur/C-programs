#include<stdio.h>
main()
{
	power();
}
power()
{
	int n,count=1,pow=1;
	printf("Enter the number of bits:");
	scanf("%d",&n);
	while(count<=n)
	{
		pow=pow*2;
		count++;
	}
	printf("The max numbers of numbers represented by %d bits=%d",n,pow);
}
