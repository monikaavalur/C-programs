#include<stdio.h>
main()
{
	area();
}
area()
{
	float l,r,area;
	printf("Enter the arc length and radius");
	scanf("%f %f",&l,&r);
	area=0.5*l*r;
	printf("The area of arc is:%f",area);
}