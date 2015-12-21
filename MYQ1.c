#include<stdio.h>
int main()
{
    long long int test_cases,seat_no,i,row_number,seat_position;
    char pos1,pos2;
    scanf("%lld",&test_cases);
    for(i=0;i<test_cases;i++)
    {
        scanf("%lld",&seat_no);
        pos1=pos2=0;
        if(seat_no==1)
            printf("poor conductor\n");
        else
        {
            row_number=(seat_no-2)/5+1;
            seat_position=(seat_no-2)%5;            
            if(row_number%2==1)
            {
                if(seat_position==0||seat_position==4)
                    pos1='W';
                else if(seat_position==3)
                    pos1='M';
                else
                    pos1='A';
                if(seat_position<=1)
                    pos2='L';
                else
                    pos2='R';
            }
            else
            {
                if(seat_position==0||seat_position==4)
                    pos1='W';
                else if(seat_position==1)
                    pos1='M';
                else
                    pos1='A';
                if(seat_position>=3)
                    pos2='L';
                else
                    pos2='R';
            }
            printf("%lld ",row_number);
            printf("%c ",pos1);
            printf("%c\n",pos2);
        }
    }
    return 0;
}
