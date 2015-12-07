#include<math.h>
int convert(int binary)
{ int decimal=0,i=0,b;
   while(binary>0)
  { b=binary%10;
    binary/=10;
    decimal=decimal+b*pow(2,i);
    ++i;
  }
 printf("%c",decimal);
}
void read()
{
  int n,i;
    printf("enter the number of characters: ");
    scanf("%d",&n);
    printf("enter the binary sequence to convert to ASCII: ");
  int seq[n];
    for(i=0;i<n;i++)
     { scanf("%d",&seq[i]); }
    printf("\t \n ASCII EQUIVALENT: ");  
    for(i=0;i<n;i++)
     { convert(seq[i]);   }
}
int main()
{  read();
   getch();
}
