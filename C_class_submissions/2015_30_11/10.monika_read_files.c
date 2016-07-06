#include<stdio.h>
#include<stdlib.h>
void printLines()
{
     char ch,ch1;
     FILE *fp,*out,*fp1;
     int length=0,length1=0,n,lines;
     long count,last,last1;
     
     printf("Enter the number of lnes:");
     scanf("%d",&n);
     lines=n-1;
     
     out=fopen("output.txt","w");
     fp=fopen("sample.txt","rb");
     if(out==NULL||fp==NULL)
     {
                            printf("Error can't open\n");
                            exit(0);
                            }
                            fseek(fp,0,SEEK_END);
                            last=ftell(fp);
                            for(count=1;count<=last;count++)
                            {
                                                            fseek(fp,-count,SEEK_END);
                                                            ch=getc(fp);
                                                            if(ch=='\n')
                                                            length++;
                                                            if(length==n+1)
                                                            break;
                                                            if(ch!=EOF&&ch!='r')
                                                            putc(ch,out);
                                                            }
                                                            fclose(out);
                                                            fclose(fp);
                                                            
                                                            printf("\n");
                                                            out=fopen("output.txt","r");
                                                            if(out==NULL)
                                                            {
                                                                         printf("Error can't open\n");
                                                                         exit(0);
                                                                         }
                                                                         fseek(out,0,SEEK_END);
                                                                         last1=ftell(out);
                                                                         for(count=1;count<=last;count++)
                                                                         {
                                                                                                         fseek(out,-count,SEEK_END);
                                                                                                         ch1=getc(out);
                                                                                                         if(ch1=='\n')
                                                                                                         length1++;
                                                                                                         if(length1==n+lines)
                                                                                                         break;
                                                                                                         if(ch1!=EOF&&ch1!='\r')
                                                                                                         putchar(ch1);
                                                                                                         }
                                                                                                         fclose(out);
                                                                                                         }
                                                                                                         
                                                            
main()
{
      printLines();
      }     
     
