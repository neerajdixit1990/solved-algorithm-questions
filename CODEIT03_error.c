#include<stdio.h>
int main()
{
    int test_cases,day,month,year,i,offset,temp,days_array[13]={0,31,28,31,30,31,30,31,31,30,31,30,31},j;
    scanf("%d",&test_cases);
    for(i=0;i<test_cases;i++)
    {
        offset=0;
        scanf("%d",&day);
        scanf("%d",&month);
        scanf("%d",&year);
        temp=(year-2012)/4;
        temp=temp*5;         // year offset
        
        j=(year-2012)/4*4+2012;
        for(;j<year;j++)
        {   if(j%4==0)
                temp=temp+1;
            temp=temp+1;
        }
        offset=offset+temp;
        
        temp=0;              // month offset
        for(j=1;j<month;j++)
            temp=temp+days_array[j];
        if(year%4==0&&j>2)
            temp=temp+1;
        offset=offset+temp;
        
        offset=offset+day-1;        //day offset
        
        offset=offset%7;
        if(offset==0)
            printf("Sunday\n");
        else if(offset==1)
             printf("Monday\n");
        else if(offset==2)
             printf("Tuesday\n");
        else if(offset==3)
             printf("Wednesday\n");
        else if(offset==4)
             printf("Thursday\n");
        else if(offset==5)
             printf("Friday\n");
        else if(offset==6)    
             printf("Saturday\n");
    }
    return 0;
}
