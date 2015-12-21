#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long int heap[1020];       // max heap
void insert(long long int n)
{
     long long int i,item;
     i=n;
     item=heap[n];
     while((i>1)&&(heap[i/2]<item))
     {
         heap[i]=heap[i/2];
         i=i/2;
     }
     heap[i]=item;
}
void adjust(long long int i,long long int n)
{
     long long int j,item;
     j=2*i;
     item=heap[i];
     while(j<=n)
     {
         if((j<n)&&(heap[j]<heap[j+1]))
             j++;
         if(item>=heap[j])
             break;
         heap[j/2]=heap[j];
         j=2*j;
     }
     heap[j/2]=item;
}
long long int delmax(long long int n)
{
    long long int ans;
    ans=heap[1];
    heap[1]=heap[n];
    adjust(1,n-1);
    return ans;
}
int main()
{
    long long int test_cases,stamps_borrow,i,j,no_of_friends,res,ans,count;
    scanf("%lld",&test_cases);
    for(i=1;i<=test_cases;i++)
    {
        res=0;
        ans=0;
        count=0;
        scanf("%lld",&stamps_borrow);
        scanf("%lld",&no_of_friends);
        for(j=1;j<=no_of_friends;j++)
        {   scanf("%lld",&heap[j]);
            res=res+heap[j];
        }
        if(res>=stamps_borrow)
        {
            for(j=1;j<=no_of_friends;j++)
                insert(j);
            for(j=no_of_friends;j>=1;j--)
            {
                ans=ans+delmax(j);
                count++;
                if(ans>=stamps_borrow)
                    break;
            }
            printf("Scenario #%d:",i);
            printf("\n%d",count);
			printf("\n\n");
		}
		else
		{
			printf("Scenario #%d:",i);
			printf("\nimpossible");
			printf("\n\n");
        }
    }
    return 0;
}
