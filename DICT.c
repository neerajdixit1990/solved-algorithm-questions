#include<stdio.h>
#include<string.h>
void join(char dict[30][30],int low,int mid, int high)
{
    char aux[30][30];
    int i,j,dec,k;
    i=low;
    j=mid+1;
    k=low;
    while((i<=mid)&&(j<=high))
    {
        dec=strcmp(dict[i],dict[j]);
        if(dec<0)                  //a[i]<a[j]
        {
            strcpy(aux[k],dict[i]);                       //c[k]=a[i];
            k++;
            i++;
        }
        else
        {
            strcpy(aux[k],dict[j]);                       //c[k]=a[j];
            k++;
            j++;
        }
    }
    while(i<=mid)
    {
        strcpy(aux[k],dict[i]);                           //c[k]=a[i];
        k++;
        i++;
    }
    while(j<=high)
    {
        strcpy(aux[k],dict[j]);                           //c[k]=a[j];
        k++;
        j++;
    }
    for(i=low;i<k;i++)
        strcpy(dict[i],aux[i]);                           //a[i]=c[i];    
}
void mergesort(char dict[30][30],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(high+low)/2;
        mergesort(dict,0,mid);
        mergesort(dict,mid+1,high);
        join(dict,low,mid,high);
    }   
}
int main()
{
    char dict[30][30],input[30],*ptr;
    int N,K,i,j,count,low,high,dec,mid,flag;
    scanf("%d",&N);
    for(i=0;i<N;i++)
        scanf("%s",dict[i]);
    mergesort(dict,0,N-1);  // sort dictionary    
    
    scanf("%d",&K);
    for(i=1;i<=K;i++)
    {
        scanf("%s",input);
        count=0;
        flag=0;
        printf("Case #%d:\n",i);
        low=0;
        high=N-1;
        while(low<high)
        {
            mid=(low+high)/2;
            if(input[0]>dict[mid][0])
                low=mid+1;
            else if(input[0]<dict[mid][0])
                high=mid-1;
            else
            {   flag=1;
                break;
            }
        }
        if(flag==1)
        {   while(dict[mid][0]==dict[mid-1][0])
                mid--;
            for(j=mid;j<N;j++)        
            {
                if(strlen(dict[j])!=strlen(input))
                {
                    ptr=strstr(dict[j],input);
                    if(ptr!=NULL)
                    {   
                        printf("%s\n",dict[j]);
                        count++;
                    }
                }
            }
            if(count==0)
                printf("No match.\n");
        }
        else
            printf("No match.\n");
    }
    return 0;
}
