#include<stdio.h>

void inputmon_date()
{
	int mm,dd,yy;
	int flag = 0,leap;
	printf("Enter month: ");
	scanf("%d",&mm);
	printf("Enter the date: ");
	scanf("%d",&dd);
	
	printf("Enter the year:");
	scanf("%d",&yy);
	
   if(yy % 400 == 0 || (yy % 100 != 0 && yy % 4 == 0))
    leap=1;
     
    if (mm<13)
    {
	   if ((mm == 1 || mm ==3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12 ) && (dd<=31))
            flag=1;
			
        else if ((mm == 4 || mm == 6 || mm == 9 || mm == 11 ) && (dd<=30))
             flag = 1;
					
        else if(mm==2)
            {
               if ((leap == 1) && dd<=29)
                   flag = 1;
				                   
				  else if((leap == 0) && dd<=28)
                   flag=1;
			}
    }
    if (flag==1)
        printf("\nIt is a valid date!\n\n");
    else
        printf("\nIt is invalid date!\n\n");
}

	

int main()
{

	inputmon_date();
return 0;
}


