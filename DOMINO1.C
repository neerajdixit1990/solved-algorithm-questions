#include<stdio.h>
#include<string.h>
void sort(int *a,int n)
{
     int i,j,temp;
     for(i=0;i<n;i++)
     {
         for(j=i+1;j<n;j++)
         {
             if(a[i]<a[j])
             {
                 temp=a[i];
                 a[i]=a[j];
                 a[j]=temp;
             }
         }
     }
}
int maxi(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int mini(int a,int b)
{
    if(a>b)
        return b;
    else
        return a;
}
int main()
{
    char input[120],t1,t2;
    int i,b_len,c_len,len,cb[102],bc[102],cnt_cb,cnt_bc,j,k,n,result,temp;
	scanf("%d",&n);
	b_len=0;
	c_len=0;
	cnt_cb=0;
	cnt_bc=0;
	result=0;
	for(k=0;k<n;k++)
	{
        scanf("%s",&input);
        len=strlen(input);
        t1=input[0];
        t2=input[len-1];
        if(t1=='B'&&t2=='B')
            b_len=b_len+len;
        else if(t1=='C'&&t2=='C')
            c_len=c_len+len;
        else if(t1=='B'&&t2=='C')
            bc[cnt_bc++]=len;
        else
			cb[cnt_cb++]=len;
	}
	sort(bc,cnt_bc);
	sort(cb,cnt_cb);

	if(cnt_bc==0&&cnt_cb==0)
		result=maxi(b_len,c_len);
	else if(cnt_bc==0)
		result=b_len+c_len+cb[0];
	else if(cnt_cb==0)
		result=b_len+c_len+bc[0];
	else
	{
		result=result+b_len+c_len;
		temp=mini(cnt_cb,cnt_bc);
		for(i=0;i<temp;i++)
			result=result+cb[i]+bc[i];
		if(cnt_cb>cnt_bc)
			result=result+cb[i];
		else if(cnt_cb<cnt_bc)
			result=result+bc[i];
	}
	printf("%d",result);
	return 0;
}
