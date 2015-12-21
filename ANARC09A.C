#include<stdio.h>
#include<string.h>
int main()
{
    char input[2010],stack[2010],first,second;
    int top=-1,len,i,count,test_case=1;
    while(1)
    {
        scanf("%s",input);
        if(input[0]=='-')
            break;
        len=strlen(input);
        top=-1;
        count=0;
        for(i=0;i<len;i++)
        {
            if(input[i]=='{')
                stack[++top]=input[i];
            else if(input[i]=='}')
            {
                if(top==-1)
                    stack[++top]=input[i];
                else
                {
                    if(stack[top]=='{')
                        top--;
                    else
                        stack[++top]=input[i];
                }
            }
        }
        while(top!=-1)
        {
            first=stack[top];
            top--;
            second=stack[top];
            top--;
            if(first=='{'&&second=='{')
                count++;
            else if(first=='}'&&second=='}')
                count++;
            else if(first=='{'&&second=='}')
                count=count+2;
        }
		printf("%d. %d\n",test_case,count);
        test_case++;
    }
    return 0;
}
