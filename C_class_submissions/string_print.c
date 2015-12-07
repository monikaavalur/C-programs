//AIM:to print the string
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	 
	int length;
	int index = 0;
	char str[100]="GITAM UNIVERSITY";
	length = strlen(str);//find the length of the string
	int *ptr = malloc(length*sizeof(char));//allocate memory dynamically
	if (ptr == NULL)
	{
		printf("Error");//if length is 0 then error
	}
	else
	{
		while (index <= length)
		{
			printf("%c", str[index]); //take a loop and print the string
			index++;
		}
		printf("\n");
	}
	free(ptr);
	return 0;

}