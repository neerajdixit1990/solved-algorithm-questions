#include<stdio.h>
int main()
{
    int test_cases,i,century_number[4]={0,5,3,1},century,month_number[12]={6,2,2,5,0,3,5,1,4,6,2,4},offset,year_number;
    int day,month,year;
    scanf("%d",&test_cases);
    for(i=0;i<test_cases;i++)
    {
        offset=0;
        scanf("%d",&day);
        scanf("%d",&month);
        scanf("%d",&year);
        century=(year/100)-20;
        century=century_number[century%4];                 // century number                                         
        offset=offset+century;
        
        year_number=year%100;
        year_number=year_number/4;
        year_number=year_number+year%100;
        offset=offset+year_number;
        
        offset=offset+month_number[month-1];              // month number
        if(year%4==0&&(month==1||month==2))
            offset=offset-1;
        offset=offset+day;
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
