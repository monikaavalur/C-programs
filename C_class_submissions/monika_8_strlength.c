#include<stdio.h>
str_len()
{
	char str[100];
	int i=0,length;
	printf("Enter a string:");
	gets(str);
	while(str[i]!='\0')
	i++;
	length=i;
	printf("The length of the string is:%d",length);
}
main()
{
	str_len();
}
