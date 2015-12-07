//AIM:C program to generate permutations
#include<stdio.h>
#include<string.h>
//swaping the numbers
void swap(char *num1, char *num2)
{
	//swaping the numbers by taking a temporary variable
	char temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
//generating permutations
void permute(char *num, int index, int size)
{
	int index1;
	if (index == size)
	{
		printf("%s\n", num); //if both the index and size are same print number
	}
	else{
		for (index1 = index; index1 <= size; index1++)
		{ //otherwise take a loop and call the functions swap and permute for iteration till condition is satisfied
			swap((num + index), (num + index1));
			permute(num, index + 1, index1);
			swap((num + index), (num + index1));
		}
	}
}
int main()
{
	char num[] = "12345678";
	permute(num, 0, 7);//call the function
	getchar();
	return 0;

}