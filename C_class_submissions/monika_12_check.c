#include <stdio.h>
void check()
{
    int d,m,y,leap;
    int legit = 0;
    printf("Enter the date\n");
    scanf("%i.%i.%i",&d,&m,&y);
    if(y % 400 == 0 || (y % 100 != 0 && y % 4 == 0))
        {leap=1;}
    if (m<13)
    {
        if (m == 1 || (3 || ( 5 || ( 7 || ( 8 || ( 10 || ( 12 )))))))
            {if (d <=31)
                {legit=1;}}
        else if (m == 4 || ( 6 || ( 9 || ( 11 ) ) ) )
            {if (d <= 30)
                {legit = 1;}}
        else
            {
                        if (leap == 1)
                              {if (d <= 29)
                                    {legit = 1;}}
                        if (leap == 0)
                              {{if (d <= 28)
                                    legit = 1;}}
             }
    }
    if (legit==1)
        printf("It is a legitimate date!\n");
    else
        printf("It's not a legitimate date!");

}

void main()
{
	check();
}