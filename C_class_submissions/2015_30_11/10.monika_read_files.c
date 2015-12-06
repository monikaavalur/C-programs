#include<stdio.h>
#include<stdlib.h>
int main()
{
     FILE *file_name; //assigning the file a name
     char string[200]; //creating a string
     int count=0, index, length;//declaring variables
     file_name = fopen("sample.txt", "r");//opening the file
     //checking whether the file exists!!
     if(file_name==NULL)
     {
     	printf("File not found");
     	return;
	 }
	 //inputting the number of lines to be displayed
     printf("\nHow many lines to read from the end: ");
	 scanf("%d", &length);
	 //loop to count the number of lines
     while(fgets(string, 200, file_name) != NULL)
     count++;
     index=0;
     //rewinding the file
     rewind(file_name);
     //loop to traverse to the nth line of the file
     while(index<count-length)
     {	
       fgets(string, 200, file_name);
       index++;
   }
    
    index=0;
    //printing the last lines of the file
    printf("\n last\n");
    while(index<length)
    {
    	fgets(string, 200, file_name);
    	printf("%s", string);
    	index++;
	}   
	     //closing the file
    fclose(file_name);
    
    return 0;
}

