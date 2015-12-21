#include<stdio.h>
void sub(int *first_hour,int *first_min,int *second_hour,int *second_min,int *ans_hour,int *ans_min)
{
    int temp1,temp2;
    temp1=*first_hour;
    temp2=*first_min;
    if(*second_min>*first_min)
    {
        temp1=*first_hour-1;
        temp2=*first_min+60;
    }
    *ans_min=temp2-*second_min;
    *ans_hour=temp1-*second_hour;
}
void add(int *first_hour,int *first_min,int *second_hour,int *second_min,int *ans_hour,int *ans_min)
{
     int temp1,temp2;
     *ans_min=*first_min+*second_min;
     *ans_hour=*first_hour+*second_hour;
     if(*ans_min>=60)
     {
         *ans_hour=*ans_hour+(*ans_min/60);
         *ans_min=*ans_min%60;
     }
}
void print(int *a,int *b,int *c,int *d)
{
     if((*a/10)==0)
         printf("0");
     printf("%d:",*a);
     if((*b/10)==0)
         printf("0");
     printf("%d",*b);
     printf("\n");
     if((*c/10)==0)
         printf("0");
     printf("%d:",*c);
     if((*d/10)==0)
         printf("0");
     printf("%d",*d); 
}
int main()
{
    int test_cases,i,team,time_hour,time_min,bal,last_hour,last_min;
    int team1_min=0,team1_hour=0,team2_min=0,team2_hour=0,temp1,temp2,temp3,temp4;
    char input[11];
    bal=0;
	last_min=last_hour=0;
	scanf("%d",&test_cases);
	for(i=0;i<test_cases;i++)
	{
		scanf("%d",&team);
		scanf("%s",input);
		time_hour=(input[0]-48)*10+input[1]-48;
		time_min=(input[3]-48)*10+input[4]-48;
		if(bal>0)
		{
			sub(&time_hour,&time_min,&last_hour,&last_min,&temp1,&temp2);
			add(&team1_hour,&team1_min,&temp1,&temp2,&temp3,&temp4);
			team1_hour=temp3;
			team1_min=temp4;
		}
		else if(bal<0)
		{
			sub(&time_hour,&time_min,&last_hour,&last_min,&temp1,&temp2);
			add(&team2_hour,&team2_min,&temp1,&temp2,&temp3,&temp4);
			team2_hour=temp3;
			team2_min=temp4;
		}
		last_hour=time_hour;
		last_min=time_min;
		if(team==1)
			bal++;
		else if(team==2)
			bal--;
	}
	time_hour=48;
	time_min=0;
	if(bal>0)
	{
		sub(&time_hour,&time_min,&last_hour,&last_min,&temp1,&temp2);
		add(&team1_hour,&team1_min,&temp1,&temp2,&temp3,&temp4);
		team1_hour=temp3;
		team1_min=temp4;
	}
	else if(bal<0)
	{
		sub(&time_hour,&time_min,&last_hour,&last_min,&temp1,&temp2);
		add(&team2_hour,&team2_min,&temp1,&temp2,&temp3,&temp4);
		team2_hour=temp3;
		team2_min=temp4;
	}
	print(&team1_hour,&team1_min,&team2_hour,&team2_min);
	return 0;
}
