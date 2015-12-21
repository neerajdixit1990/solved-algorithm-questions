#include<stdio.h>
#include<stdlib.h>
long long int merge(long long int *a,long long int low,long long int high,long long int mid)
{
	long long int i,j,k,*c,count;
	c=(long long int *)malloc(sizeof(long long int)*(high-low+6));
	i=low;
	j=(long long int)mid+(long long int)1;
	k=0;
    count=0;
    while((i<=mid)&&(j<=high))
    {
        if(a[i]<=a[j])
        {
			c[k]=a[i];
			k=(long long int)k+(long long int)1;
			i=(long long int)i+(long long int)1;
		}
		else
		{
			count=(long long int)count+(long long int)mid-(long long int)i+(long long int)1;
			c[k]=a[j];
			k=(long long int)k+(long long int)1;
			j=(long long int)j+(long long int)1;
		}
	}
	while(i<=mid)
	{
		c[k]=a[i];
		k=(long long int)k+(long long int)1;
		i=(long long int)i+(long long int)1;
	}
	while(j<=high)
	{
		c[k]=a[j];
		k=(long long int)k+(long long int)1;
		j=(long long int)j+(long long int)1;
	}
	for(i=0;i<k;i++)
		a[(long long int)i+(long long int)low]=c[i];
	return((long long int)count);
}
long long int mergesort(long long int *a,long long int low,long long int high)
{
    long long int mid,d,b,c;
    if(low<high)
    {
        mid=(long long int)((long long int)low+(long long int)high)/(long long int)2;
        d=mergesort(a,low,mid);
        b=mergesort(a,mid+1,high);
        c=merge(a,low,high,mid);
        return((long long int)d+(long long int)b+(long long int)c);
    }
    return(0);
}
int main()
{
	long long int n,a[200010],i,ans,test_cases,j;
	scanf("%lld",&test_cases);
	for(i=0;i<test_cases;i++)
	{
        scanf("%lld",&n);
        for(j=0;j<n;j=(long long int)j+(long long int)1)
            scanf("%lld",&a[j]);
        ans=mergesort(a,0,n-1);
        printf("%lld\n",ans);
    }
    return 0;
}
