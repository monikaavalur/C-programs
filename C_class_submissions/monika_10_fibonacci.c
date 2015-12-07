#include<stdio.h>
 fibonacci()
 {
    int i,range=40;
    long int arr[40];
    arr[0]=0;
    arr[1]=1;
    for(i=2;i<range;i++){
         arr[i] = arr[i-1] + arr[i-2];
    }
    printf("Fibonacci series is: ");
    for(i=0;i<range;i++)
         printf("%ld ",arr[i]);
}
main()
{
	fibonacci();
}