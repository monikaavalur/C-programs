#include<stdio.h>
int inputyear()
{
	int year;
	
	printf("Please enter a year (example: 1999) : ");
	scanf("%d", &year);
	printf("%d\n",year);
	
}

	int inputdate()
{
	int date;
	printf("Enter the date:");
	scanf("%d",&date);
	if(date>31)
	{
		printf("The date is invalid");
	}
	else
	printf("%d\n",date);
}

void inputmonth()
{
	int n;
   printf("Month No:-> ");
   scanf("%d",&n);
   switch(n)
   {
	case 1:
	       printf("January\n");
	       break;
	case 2:
	       printf("February\n");
	       break;
	case 3:
	       printf("March\n");
	       break;
	case 4:
	       printf("April\n");
	       break;
	case 5:
	       printf("MAy\n");
	       break;
	case 6:
	       printf("June\n");
	       break;
	case 7:
	       printf("July\n");
	       break;
	case 8:
	       printf("August\n");
	       break;
	case 9:
	       printf("September\n");
	       break;
	case 10:
	       printf("October\n");
	       break;
	case 11:
	       printf("November\n");
	       break;
	case 12:
	       printf("December\n");
	       break;
	default:
	       printf("invalid Month number\nPlease try again ....\n");
	       break;
      }
}

int main()
{
	inputyear();
	inputdate();
	inputmonth();
}