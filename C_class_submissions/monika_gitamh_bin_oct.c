#include<stdio.h>
#define MAX 1000
BinarytoOctal()
{ 
	char binary[MAX] = { "100001010101010" }, octal[MAX];
	long int i = 0, j = 0;
	while (binary[i]){
		binary[i] = binary[i] - 48;
		++i;
	}
	--i;
	while (i - 2 >= 0)
	{
		octal[j++] = binary[i - 2] * 4 + binary[i - 1] * 2 + binary[i];
		i = i - 3;
	}
	if (i == 1)
		octal[j] = binary[i - 1] * 2 + binary[i];
	else if (i == 0)
		octal[j] = binary[i];
	else
		--j;
	while (j >= 0){
		printf("%d", octal[j--]);
}
}
main()
{
	BinarytoOctal();
}
