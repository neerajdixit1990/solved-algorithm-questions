#include<stdio.h>
main()
{
    int input,test_cases,answer,i;
    scanf("%d",&test_cases);
    for (i=0 ; i<test_cases ; i++)
    {
        scanf("%d",&input);
        if(input==0)
        {
            printf("0\n");
            continue;
        }
        answer=0;
        if(input&(input-1))
        {
            while(input)
            {
                if(input%2==1)
                    answer=answer+1;
                input=input/2;
            }
        }
        else
            answer=1;
        printf("%d\n",answer);
    }
    return 0;
}
