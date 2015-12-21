/*	NAME: NEERAJ DIXIT
    	CLASS: BE    DIV: H       ROLL. NO: 25
    	Assignment No. 1
    	PROB STAT: Write a program to sort numbers by using Merge Sort	*/

#include<stdio.h>
void join(int *a,int start,int middle,int end)
{
	int i,j,temp[200],k=0,flag=0;
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
void merge(int *a,int start,int end)
{
	int middle;
	middle=(start+end)/2;
	if(start<end)
	{
		merge(a,start,middle);
		merge(a,middle+1,end);
		join(a,start,middle,end);
	}
}
int main()
{
	int a[200],i,j,n;
	printf("\nEnter the number of elements to be sorted:\t");
	scanf("%d",&n);
	printf("\nEnter the elements:\t");
	for(i=0;i<n;i++)
		scanf("%d",a+i);
	merge(a,0,n-1);
	printf("\nThe numbers after sorting by Merge Sort are:\t");
	for(i=0;i<n;i++)
		printf(" %d",*(a+i));
	scanf("%d",&i);
	return 0;
}
/*	OUTPUT:
Enter the number of elements to be sorted:      10

Enter the elements:     24 36 15 10 48 97 61 43 21 0

The numbers after sorting by Merge Sort are:     0 10 15 21 24 36 43 48 61 97	*/
