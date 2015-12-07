#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10000
//function to multiply two numbers
char * multiply(char array1[],char array2[]){
	//declaring and initialising the variables
    static char mul[MAX];
    char array3[MAX];
    char temp[MAX];
    int length1,length2;
    int index1,index2,index3=0,var1=0,var2;
    long int var3=0;
    long sum = 0;
int len1=0,len2=0;
    //finding the length of the string
while(array1[len1]!='\0'){
len++;}
    length1=len1-1;
while(array2[len2]!='\0'){
len2++;}
        length2=len2-1;
        //using loop to subtract each element in the array1 with 48(ascii value)
        for(index1=0;index1<=length1;index1++)
		{
                array1[index1] = array1[index1] - 48;
        }
//using loop to subtract each element in the array2 with 48(ascii value)
        for(index1=0;index1<=length2;index1++)
		{
                array2[index1] = array2[index1] - 48;

        }
//using for loops to do the following iteration
    for(index1=length2;index1>=0;index1--)
	{
         var3=0;
         for(index2=length1;index2>=0;index2--)
		{
             temp[index3++] = (array2[index1]*array1[index2] + var3)%10;//multiplying the elements in both the arrays 
                                                                      //and adding it to the quotient(var3) and storing the 
             var3 = (array2[index1]*array1[index2]+var3)/10;  //the remainder in temporary array
         }
         temp[index3++] = var3;//storing the quotient in temporary array
         var1++; //incrementing var1
         for(var2 = 0;var2<var1;var2++)// using loop to perform following iteration
		 {
             temp[index3++] = 0;
         }
    }
    index3=0;//initialising index3 to 0
    var3=0;//initialisng var3 to 0
    for(index1=0;index1<length1+length2+2;index1++)//using loop iteration to perform the following iteration
	{
         sum =0;//initialising sum to 0
         var2=0;//and var2 to 0
         for(index2=1;index2<=length2+1;index2++)//using loop iteration to perform the following iteration
		 {
             if(index1 <= length1+index2)
			 {
                 sum = sum + temp[var2+index1];//if the above condition is satisfied then perform the operation

             }
             var2 += index2 + length1 + 1;
         }
         array3[index3++] = (sum+var3) %10;
         var3 = (sum+var3)/10;
    }
    array3[index3] = var3;
    index2=0;
    for(index1=index3-1;index1>=0;index1--)
	{
         mul[index2++]=array3[index1] + 48;
    }
    mul[index2]='\0';
    return mul;//returning the mul to main 
}
int main()
{
//declaring variables
    char array1[MAX];
     char array2[MAX];
    char *array3;
    int length1,length2;
    int index;
    int *ptr1,*ptr2,*ptr3;
    //allocating memory dynamically
    ptr1=malloc(10000*sizeof(char));
    ptr2=malloc(10000*sizeof(char));
    ptr3=malloc(10000*sizeof(char));
    //asking the uer to enter the numbers
    printf("Enter the first number : ");
    scanf("%s",array1);
    printf("Enter the second number : ");
    scanf("%s",array2);
    printf("Multiplication of two numbers : ");
    array3 = multiply(array1,array2);
    printf("%s",array3);
    //freeing the memory
    free(ptr1);
    free(ptr2);
    free(ptr3);
    return 0;
}
