*Given an integer array and length as inputs, write a function to find the max value and min value of the array.
 example: input array 2, 4, -6, 8, -2 and 5 as inputs, output is: max: 8, min: -6*/
 
 #include<stdio.h>
 #include<conio.h>

const int num=10;
 
 
 
 struct test
 {
 	int arr[10];
 	int len;
 	int max;
 	int min;
 	int op[2];
 }
 testDB[3]={   
 {{1,2,3,4,5,6},6,6,1,{-1,-1}},
 {{2,3,4,1,-9},5,4,-9,{-1,-1}},
 {{},0,0,0,{-1,-1}},
 
 };
 
 void max_min(struct test *inp);
 
 void testCases()
 {
 	int i;
 	for(i=0;i<3;i++)
 	{
 		max_min(&testDB[i]);
 		if(testDB[i].op[0]==testDB[i].max && testDB[i].op[1]==testDB[i].min)
 		printf("\n Passed! ");
 		
 		else
 		printf("\n Failed! ");
 	}
 }
 
 main()
 {
 	testCases();
 	getch();
 	
 }
 
 void max_min(struct test *inp)
 {
 	inp->op[0]=inp->op[1]=inp->arr[0];
  	int i=1;
  	while(i<inp->len)
 	{
 		if(inp->arr[i]>inp->op[0])
 		{
 		inp->op[0]=inp->arr[i];
 		}	
 		
 		else if(inp->arr[i]<inp->op[1])
 		{
 		inp->op[1]=inp->arr[i];
 		}	
 		i++;
 	}
 }
