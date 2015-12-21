#include<stdio.h>
int main()
{
	int N,M,final_ans=30000,i,j,flag,first,second,third;
    int input[102][102],op[102]={0},last_bus_no;
    scanf("%d%d",&N,&M);
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
            scanf("%d",&input[i][j]);
    }
    for(i=0;i<M;i++)
    {
        op[0]=input[0][i];
        last_bus_no=i;
        for(j=1;j<N;j++)
        {
            first=(last_bus_no<1?30000:input[j][last_bus_no-1]);
            third=(last_bus_no>=(M-1)?30000:input[j][last_bus_no+1]);
            second=input[j][last_bus_no];
            if(first>second)
            {
				if(third>second)
					 flag=0;
                else
					 flag=1;
            }
            else
            {
				if(first>third)
					 flag=1;
                else
					 flag=-1;
            }
            op[j]=op[j-1]+input[j][last_bus_no+flag];
            last_bus_no=last_bus_no+flag;
        }
		if(op[N-1]<final_ans)
            final_ans=op[N-1];
    }
    printf("%d",final_ans);
    return 0;
}
