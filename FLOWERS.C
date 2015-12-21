#include<stdio.h>
#include<string.h>
int main()
{
	char input[1020],remember1,remember2;
    int i,flag,len;
    while(1)
    {
        fflush(stdin);
        gets(input);
        if(input[0]=='*')
            break;
        remember1='$';
        //remember2='$';
        flag=0;
        len=strlen(input);
        for(i=0;i<len;)
        {
            if(input[i]==' '&&i<(len-1))
            {   
                if(remember1=='$')
                {   
                    remember1=input[i+1];
                    if(input[i+1]>='a'&&input[i+1]<='z')
                        remember2=remember1-32;
                    else if(input[i+1]>='A'&&input[i+1]<='Z')
                        remember2=remember1+32;
                }
                if(remember1!=input[i+1]&&remember2!=input[i+1])
                {   
                    flag=1;
                    break;
                }
			}
			else if(remember1=='$')
			{
				remember1=input[i];
				if(input[i]>='a'&&input[i]<='z')
					remember2=remember1-32;
				else if(input[i]>='A'&&input[i]<='Z')
					remember2=remember1+32;
			}
            i++;
        }
        if(flag==0)
            printf("Y\n");
        else
            printf("N\n");
    }
    return 0;
}
