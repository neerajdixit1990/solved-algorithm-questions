#include<stdio.h>
/*void join(float *a,int start,int middle,int end)
{
	int i,j,temp[1020],k=0,flag=0;
	i=start;
	j=middle+1;
	for(;flag==0;)
	{
		if(a[i]<a[j])
			temp[k++]=a[i++];
		else if(a[i]>a[j])
			temp[k++]=a[j++];
		else if(i==j)
			j++;
		if(i>middle)
		{	for(;j<=end;)
				temp[k++]=a[j++];
			flag=1;
		}
		if(j>end)
		{	for(;i<=middle;)
				temp[k++]=a[i++];
			flag=1;
		}
	}
	for(i=0;i<k;i++)
		a[start+i]=temp[i];
}
void merge(float *a,int start,int end)
{
	int middle;
	middle=(start+end)/2;
	if(start<end)
	{
		merge(a,start,middle);
		merge(a,middle+1,end);
		join(a,start,middle,end);
	}
}*/
void sort(float *a,int n)
{
     int i,j;
     float temp;
     for(i=0;i<n;i++)
     {   for(j=i+1;j<n;j++)
         {
             if(a[i]>a[j])
             {
                 temp=a[i];
                 a[i]=a[j];
                 a[j]=temp;
             }
         }
     }
}
int main()
{
	int i,j,test_cases,n;
	float a[1020],temp,b;
	char input[47];
	scanf("%d",&test_cases);
	for(i=0;i<test_cases;i++)
	{	
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%s",input);
            scanf("%f",&a[j]);
        }
	    //merge(a,0,n-1);
	    sort(a,n);
	    temp=-1;
	    for(j=1;j<n;j++)
	        if((a[j]-a[j-1])>temp)
	            temp=a[j]-a[j-1];
         b=(float)360-a[n-1]+a[0];
         if(b>temp)
             temp=b;
         temp=(float)360-temp;
         temp=temp*(float)12;
         temp=ceilf(temp);
         printf("%.0f\n",temp);
    }
	return 0;
}
