#include<stdio.h>
int main()
{
    int test_cases,i,j,no_problems,no_teams,result,input[12][12],con,flag,k;
    scanf("%d",&test_cases);
    for(i=1;i<=test_cases;i++)
    {
        result=0;
        scanf("%d%d",&no_teams,&no_problems);
        for(j=0;j<no_teams;j++)
            for(k=0;k<no_problems;k++)
                scanf("%d",&input[j][k]);
        flag=0;
		for(j=0;j<no_problems;j++)       // 1st condition
		{   con=0;
			for(k=0;k<no_teams;k++)
            {   
				if(input[k][j])
                {   
                    flag++;
                    con=1;
                    break;
                }
            }
            if(con==0)
                break;
        }
        if(flag==no_problems)
			result=result+4;

        flag=0;
        for(j=0;j<no_teams;j++)    // 2nd condition
        {   con=0;
            for(k=0;k<no_problems;k++)
            {
               if(input[j][k])
               {
                   flag++;
                   con=1;
                   break;
               } 
            }
            if(con==0)
                break;
        }
        if(flag==no_teams)
            result=result+2;
        
        flag=0;
        for(j=0;j<no_teams;j++)    // 3rd condition
        {   con=1;
            for(k=0;k<no_problems;k++)
               con=con&input[j][k]; 
			if(con==0)
				flag++;
        }
        if(flag==no_teams)
            result=result+1;
            
        printf("Case %d: %d\n",i,result);
    }
    return 0;
}
