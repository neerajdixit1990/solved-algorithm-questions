#include<stdio.h>
void merge(int a[], int low, int high, int mid)
{
int i, j, k, c[1002];
i=low;
j=mid+1;
k=low;
while((i<=mid)&&(j<=high))
{
if(a[i]<a[j])
{
c[k]=a[i];
k++;
i++;
}
else
{
c[k]=a[j];
k++;
j++;
}
}
while(i<=mid)
{
c[k]=a[i];
k++;
i++;
}
while(j<=high)
{
c[k]=a[j];
k++;
j++;
}
for(i=low;i<k;i++)
{
a[i]=c[i];
}
}
void mergesort(int a[], int low, int high)
{
int mid;
if(low<high)
{
mid=(low+high)/2;
mergesort(a,low,mid);
mergesort(a,mid+1,high);
merge(a,low,high,mid);
}
}
int main()
{
    int test_cases,no_of_participants,i,j,first[1002],second[1002];
    long long int sum;
    scanf("%d",&test_cases);
	for(i=1;i<=test_cases;i++)
    {
        sum=0;
        scanf("%d",&no_of_participants);
        for(j=0;j<no_of_participants;j++)
            scanf("%d",&first[j]);
        for(j=0;j<no_of_participants;j++)
            scanf("%d",&second[j]);
        mergesort(first,0,no_of_participants-1);
        mergesort(second,0,no_of_participants-1);
        for(j=0;j<no_of_participants;j++)
            sum=sum+(long long int)(first[j]*second[j]);
        printf("%lld\n",sum);
	}
	return 0;
}
