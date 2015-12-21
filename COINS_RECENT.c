#include <stdio.h>
#include<stdlib.h>
long long int input[1000000020]={0,1,2,3,4,5,6,7,8,9,10,
                       11,13,13,14,15,17,17,19,19,21,
                       22,23,23,27,27,27,28,30,30,32,
                       32,35,36,36,36,41,41,41,41,44,
                       44,46,46,48,49,49,49,57,57,57,
                       57,57,57,60,60,63,63,63,63,68,
                       68,68,69,74,74,76,76,76,76,76,
                       76,87,87,87,87,87,87,87,87,92,
                       93,93,93,98,98,98,98,101,101,104,
                       104,104,104,104,104,119,119,119,120,120};
long long int stack_input[1000000000],stack_index[1000000000],top=-1,stack_sum[1000000000];
int main()
{
    long long int i;
    while(scanf("%lld",&data)!=EOF)
	{
        top=-1;
        stack_input[top+1]=data;
        stack_sum[top+1]=0;
        stack_index[++top]=1;
        while(top!=-1)
        {
            curr=stack[top];
            curr_index=stack[top];
            curr_sum=stack[top];
            top--;
            if(input[data]==0)
            {
                if(curr_index==1)
                {
                    if(input[(long long int)data/(long long int)2]==0)
                    {
                        stack_input[top+1]=(long long int)data/(long long int)2;
                        stack_sum[top+1]=curr_sum;
                        stack_index[++top]=1;
                    }
                    else
                    {   
                        curr_sum=curr_sum+input[(long long int)data/(long long int)2];
                        curr_index=curr_index+1;
                    }
                }
                if(curr_index==2)
                {
                    if(input[(long long int)data/(long long int)3]==0)
                    {
                        stack_input[top+1]=(long long int)data/(long long int)3;
                        stack_sum[top+1]=curr_sum;
                        stack[++top]=2;
                    }
                    else
                    {   
                        curr_sum=curr_sum+input[(long long int)data/(long long int)3];
                        curr_index=curr_index+1;
                    }
                }
                if(curr_index==3)
                {
                    if(input[(long long int)data/(long long int)4]==0)
                    {
                        stack_input[top+1]=(long long int)data/(long long int)4;
                        stack_sum[top+1]=curr_sum;
                        stack[++top]=3;
                    }
                    else
                        curr_sum=curr_sum+input[(long long int)data/(long long int)4];
                }
            }
            else
                result=input[data];
            
        }
