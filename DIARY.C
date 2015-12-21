#include<stdio.h>
int main()
{
	int test_cases,i,j,count[27],max,max_cnt,index,key,temp,rem[3],k;
    char input[1020],output[1020];
    scanf("%d",&test_cases);
    for(i=0;i<test_cases;i++)
    {
        for(j=0;j<27;j++)
            count[j]=0;
        fflush(stdin);
        gets(input);
		max=0;
        max_cnt=0;
        for(j=0;input[j]!='\0';j++)
            if(input[j]!=' ')
                count[input[j]-65]++;
        for(j=0;j<26;j++)
        {
            if(count[j]>max)
            {
                max=count[j];
                index=j;
                max_cnt=1;
            }
			else if(count[j]==max)
				max_cnt++;
		}
		if(max_cnt>2)
			printf("NOT POSSIBLE\n");
		else
		{
			if(max_cnt==2)
			{
				k=0;
				for(j=0;j<26;j++)
					if(count[j]==max)
						rem[k++]=j;
				if((rem[0]+rem[1])%2==1)
					printf("NOT POSSIBLE\n");
				else
				{
					if(((rem[0]+rem[1])/2)!=4)
						printf("NOT POSSIBLE\n");
					else
					{
						key=rem[1]-4;
						if(key<0)
							key=key+26;
						for(j=0;input[j]!='\0';j++)
						{
							if(input[j]==' ')
								output[j]=input[j];
							else
							{
								temp=input[j]-65-key;
								if(temp<0)
									temp=temp+26;
								output[j]=temp+65;
							}
						}
						output[j]='\0';
						printf("%d ",key);
						for(j=0;input[j]!='\0';j++)
							printf("%c",output[j]);
						printf("\n");
					}
				}
			}
			else
			{
				key=index-4;
				if(key<0)
					key=key+26;
				for(j=0;input[j]!='\0';j++)
				{
					if(input[j]==' ')
						output[j]=input[j];
					else
					{
						temp=input[j]-65-key;
						if(temp<0)
							temp=temp+26;
						output[j]=temp+65;
					}
				}
				output[j]='\0';
				printf("%d ",key);
				for(j=0;input[j]!='\0';j++)
					printf("%c",output[j]);
				printf("\n");
			}
		}
	}
	return 0;
}
