#include <stdio.h>
#include<stdlib.h>
long long int input[102]={0,1,2,3,4,5,6,7,8,9,10,
                       11,13,13,14,15,17,17,19,19,21,
                       22,23,23,27,27,27,28,30,30,32,
                       32,35,36,36,36,41,41,41,41,44,
                       44,46,46,48,49,49,49,57,57,57,
                       57,57,57,60,60,63,63,63,63,68,
                       68,68,69,74,74,76,76,76,76,76,
                       76,87,87,87,87,87,87,87,87,92,
                       93,93,93,98,98,98,98,101,101,104,
                       104,104,104,104,104,119,119,119,120,120};
long long int find_max(long long int data)
{
	long long int first,second,third;
	if(data<100/*59999997*/)
	{
		if(input[(long long int)(data/2)]==0)
			input[(long long int)(data/2)]=find_max((long long int)(data/2));
		first=input[(long long int)(data/2)];

		if(input[(long long int)(data/3)]==0)
			input[(long long int)(data/3)]=find_max((long long int)(data/3));
		second=input[(long long int)(data/3)];

		if(input[(long long int)(data/4)]==0)
			input[(long long int)(data/4)]=find_max((long long int)(data/4));
		third=input[(long long int)(data/4)];
	}
	else
	{
		first=find_max((long long int)(data/2));
		second=find_max((long long int)(data/3));
		third=find_max((long long int)(data/4));
		first=first+second+third;
		if(first>data)  
			return first;
		else
			return data;
	}
	first=first+second+third;
	if(first>data)
	{
		input[data]=first;
		return first;
	}
	else
	{
		input[data]=data;
		return data;
	}
}
int main()
{
	long long int ans=-1,data,i;
	//input=(long long int *)calloc(1,sizeof(long long int)*102/*59999999*/);
	/*for(i=1;i<=11;i++)
		input[i]=i;
	input[12]=13;
	input[13]=13;
	input[14]=13;
	input[15]=13;
	input[16]=13;
	input[17]=13;
	input[18]=13;
	input[19]=13;
	input[20]=13;
	input[21]=13;
	input[22]=13;
	input[23]=13;
	input[24]=13;
	input[25]=13;
	input[26]=13;
	input[27]=13;*/
	while(scanf("%lld",&data)!=EOF)
	{
		if(data!=0)
		{
			if(data>=100)/*59999997*/
				ans=find_max(data);
			else if(input[data]==0)
				ans=find_max(data);
			else
				ans=input[data];
		}
		else
			ans=0;
		printf("%lld\n",ans);
	}
	return 0;
}
