//AIM:Given a date print the date in text

#include<stdio.h>
#include<stdlib.h>
convert_date(int date, int month, int year)
{
	int *ptr1, *ptr2, *ptr3;
	//allocation of memory dynamically
	ptr1 = malloc(sizeof(date)*sizeof(int));
	ptr2 = malloc(sizeof(month)*sizeof(int));
	ptr3 = malloc(sizeof(year)*sizeof(int));
	//checking whether the date entered is correct or not
	int leap, legit = 0;
	//checking whether the year is leap year or not. if it is a leap year assigning leap=1
	if (year % 400 == 0 || year % 100 != 0 && year % 4 == 0)
	{
		leap = 1;
	}
	//checking if the month entered is less than 13
	if (month<13)
	{
		// checking the months having date's upto 31
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)

		{
			//if the date lies between 0 to 32 the assigning legit=1
			if (date>0 && date <= 31)
			{
				legit = 1;
			}
		}
		//checking for months having dates's upto 30
		else if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			//if date lies between 0 to 31 the assign legit=1
			if (date>0 && date <= 30)
			{
				legit = 1;
			}
		}
		else
		{
			//if leap =1 then feb has 29 day's so checking whether the date's lie between 0 to 30
			if (leap == 1)
			{
				if (date>0 && date <= 29)
				{
					//if yes the assign legit =1
					legit = 1;
				}
			}
			//if it's not a leap year the check whether the date's 
			//lie between 0 to 29 and if  it is yes the assign legit=1
			if (leap == 0)
			{
				{
					if (date>0 && date <= 28)
						legit = 1;
				}
			}
		}
	}
	if (legit == 1)
		//if legit=1 the it's legitimate date proceed for conversion
	{
		printf("It is a legitimate date!\n");
		{
			///conversion of date...assigning arrays
			char *one[] = { " ", "first", "second", "third", "fouth", "fifth", "sixth", "seventh", "eight", "nineth",
				"tenth", "eleventh", "twelveth", "thirteenth", "fourteenth", "fifteenth", "sixteenth",
				"seventeenth", "eighteenth", "twentieth" };
			char *ones[] = { " ", "one", "two", "three", "four", "five", "six"
				"seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen",
				"fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
			char *tens[] = { " ", " ", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
			// checking whether the date is greater than 20
			if (date >= 20)
			{
				int var = date / 10;  // dividing the date by 10 and storing the quotient in a variable
				printf("%s\t", tens[var]);
				date = date % 10;  // storing remainder in date
				printf("%s\t\n", one[date]);
			}
			// if date is less than 20
			else
			{
				printf("%s\t\n", one[date - 1]);
			}
		}
		//conversion of month by using switch cases
		switch (month)
		{
		case 1:
			printf("January\t\n");
			break;
		case 2:
			printf("February\t\n");
			break;
		case 3:
			printf("March\t\n");
			break;
		case 4:
			printf("April\t\n");
			break;
		case 5:
			printf("MAy\t\n");
			break;
		case 6:
			printf("June\t\n");
			break;
		case 7:
			printf("July\t\n");
			break;
		case 8:
			printf("August\t\n");
			break;
		case 9:
			printf("September\t\n");
			break;
		case 10:
			printf("October\t\n");
			break;
		case 11:
			printf("November\t\n");
			break;
		case 12:
			printf("December\t\n");
			break;
		default:
			printf("invalid Month number\nPlease try again ....\t\n");
			break;
		}
		printf("of\n");
		//conversion of year
		//assigning array's
		char *one[] = { " ", "first", "second", "third", "fouth", "fifth", "sixth", "seventh", "eight", "nineth",
			"tenth", "eleventh", "twelveth", "thirteenth", "fourteenth", "fifteenth", "sixteenth",
			"seventeenth", "eighteenth", "twentieth" };
		char *ones[] = { " ", "one", "two", "three", "four", "five", "six",
			"seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen",
			"fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
		char *tens[] = { " ", " ", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
		//if year is less than 0 the year is invalid
		if (year<0)
		{
			printf("invalid");
		}
		//if year is greater tha 2000 let us say 2015 the we should print two thousand fifteen
		else if (year >= 2000)
		{
			int var = year / 1000;  //dividing year by 1000 and storing quotient in a variable
			// for 2015 it is 2
			printf("%s", ones[var]); // printing two thousand
			printf("thousand\t");
			year = year % 1000; //storing the reamainder in year for 2015 remainder is 15
			{
				if (year == 0) //if remainder is 0
				{
					printf(" ");  //printf space and exit
					year = 0;
				}
				else if (year<100)
				{
					if (year >= 20)
					{
						int var = year / 10;  //if remainder is greater the or equal to 20 print find
						//quotient and print tens value 
						printf("%s", tens[var]);
						year = year % 10;// find remiander and print as ones value 
						printf("%s", ones[year]);
					}
					else if (year < 20)  //else if remainder is less than 20 print as ones value
					{
						printf("%s", ones[year]);
					}

				}
				//similarly checking for remainder greater than or equal to 100
				else if (year >= 100)
				{
					int var = year / 100;
					printf("%s", ones[var]);
					printf("hundred\t");
					year = year % 100;
					if (year)
					{
						printf("and\t");
						if (year >= 20)
						{
							int var = year / 10;
							printf("%s", tens[var]);
							year = year % 10;
							printf("%s", ones[year]);
						}
						else
						{
							if (year<20)
								printf("%s", ones[year]);
						}
					}
				}
			}
		}
		//similarly checking for year less than 2000
		else if (year < 2000)
		{
			int var = year / 100;
			printf("%s\t", ones[var]);
			year = year % 100;
			{
				if (year == 0)
				{
					printf(" ");
					year = 0;
				}
				else if (year<100)
				{
					int var = year / 10;
					printf("%s", tens[var]);
					year = year % 10;
					printf("%s", ones[year]);
				}
				else if (year >= 100)
				{
					int var = year / 100;
					printf("%s", ones[var]);
					printf("hundred\t");
					year = year % 100;
					if (year)
					{
						printf("and\t");
						if (year >= 20)
						{
							int var = year / 10;
							printf("%s", tens[var]);
							year = year % 10;
							printf("%s", ones[year]);
						}
						else
						{
							if (year<20)
								printf("%s", ones[year]);
						}
					}
				}
			}
		}
	}
	// else the date is invalid
	else
	{
		printf("It's not a legitimate date!\n");

	}
	//freeing memory
	free(ptr1);
	free(ptr2);
	free(ptr3);
}
int main()
{
	int date, month, year;
	printf("Enter a date");    // enter the date
	scanf_s("%d/%d/%d", &date, &month, &year);
	convert_date(date, month, year); //calling a function

}








