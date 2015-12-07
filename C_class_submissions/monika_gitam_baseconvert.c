//AIM:to convert the decimakl using base -2
#include<stdio.h>
#include<stdlib.h>
//function to convert a decimal number using base -2
convertBase(long int decimal)
{
	//declaring and initialising of variables
	 int binary[100],quotient,remainder,index=1,index1;
int *ptr,*ptr1; 
//allocating memory dynamically
ptr=malloc(sizeof(decimal)*sizeof(long int));
ptr1=malloc(100*sizeof(int));
	quotient=decimal;// assigning decimal to quotient
	while(quotient!=0)//  using while loop to repeat the process until quotient is not equal to zero
	{
		remainder=quotient%(-2);// finding the remainder when the decimal number is divided by -2
		quotient=quotient/(-2);//finding the quotient
		if(remainder==-1)//using if condition to modify the remainder if it is -1
		{
			quotient++;//if remainder is -1 incrementing the quotient
			remainder=-remainder; // assigning remainder to -remainder
			binary[index++]=remainder; //storing the remainder in the binary array
		}
		else
		binary[index++]=remainder; // if remainder is not equal to -1 storing the remainder in binary array
	}
	//printing the binary array
	for(index1=index-1;index1>0;index1--)
	printf("%d",binary[index1]);
//freeing the memory
free(ptr);
free(ptr1);
}
main()
{
	convertBase(25);//calling the above function
}
