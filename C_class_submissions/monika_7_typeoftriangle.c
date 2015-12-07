#include <stdio.h>
#include <math.h>

type_of_tri()
{
double x1=1, y1=5, x2=4, y2=7,x3=6,y3=7, x,y,z;
x = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
y = sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
z = sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
printf("The distance between the two points is ""%5.2f \n", x);
printf("The distance between two points is ""%5.2f \n",y);
printf("The distance between two points is ""%5.2f \n",z);
	 if((x==y) && (y==z))
  {
  printf("\nThe triangle is equilateral");
  } 
  else if((x==z) || (y==z) || (x==y))
  {
  printf("\nThe triangle is isoseles");
  }
  else
  {
  printf("\nThe triangle is scalene");
  }

}
 main()
 {
 	type_of_tri();
 }