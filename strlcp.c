#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
   int test_cases,i,l;
   int stack[20],top=-1;
   long long int len,k,first,second,j,no_oper,count,t,a;
   char *input,temp,input_func[21],op;
   input=(char *)malloc(sizeof(char)*100020);
   scanf("%d",&test_cases);
   for(i=0;i<test_cases;i++)
   {
      scanf("%s",input);
      len=strlen(input);
      scanf("%lld",&no_oper);
      for(k=0;k<no_oper;k=k+1)
      {
         //fflush(stdin);
         gets(input_func);
         l=strlen(input_func);
         op=input_func[0];
         for(j=2;input_func[j]!=' ';j=j+1)
         {   top++;
                stack[top]=(input_func[j]-48);
            }
         a=1;
         first=0;
         while(top!=-1)
         {
            t=(long long int)((long long int)stack[top]*a);
            top--;
            first=first+t;
            a=10*a;
         }
         if(op=='Q')
         {
            count=0;
            first=first-1;

            j=j+1;
            for(;j<l;j=j+1)
            {   top++;
                    stack[top]=(input_func[j]-48);
                }
            a=1;
            second=0;
            while(top!=-1)
            {
               t=(long long int)((long long int)stack[top]*a);
               top--;
               second=second+t;
               a=10*a;
            }

            second=second-1;
            while(input[first]==input[second])
            {
               count=count+1;
               first=first+1;
               second=second+1;
            }
            printf("%lld\n",count);
         }
         else
         {
            temp=input_func[j+1];
            if(op=='R')
               input[first-1]=temp;
            else
            {
               input[len+1]='\0';
               for(j=len-1;j>=first;j=j-1)
                  input[j+1]=input[j];
               input[j+1]=temp;
               len=len+1;
            }
         }
      }
   }
   return 0;
}
