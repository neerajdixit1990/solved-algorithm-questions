#include<stdio.h>
#include<string.h>
int main()
{
    long long int M,N,temp3,output[24],i,K,P;
    output[20]='\0';
    double temp,t=0.500000000000;
    while(1)
    {
        scanf("%lld",&M);
        scanf("%lld",&N);
        if(M==-1)
            break;
        for(i=0;i<20;i++)
            output[i]='-';
        temp=(double)M*(double)20;
        temp=temp/N;
        temp3=temp;
        if((temp-temp3)>=t)
            temp3=(long long int)temp3+(long long int)1;
        K=temp3;
        
        temp=(double)M*(double)100;
        temp=temp/N;
        temp3=temp;
        if((temp-temp3)>=t)
            temp3=(long long int)temp3+(long long int)1;
        P=temp3;
    
        i=0;
        while(i<K)
            output[i++]='*';
        if(P==100)
        {
            output[8]='1';
            output[9]='0';
            output[10]='0';
            output[11]='%';
        }
        else if(P>=10)
        {
             output[9]=(long long int)P/(long long int)10+48;
             output[10]=(long long int)P%(long long int)10+48;
             output[11]='%';
        }
        else
        {
            output[9]=P+48;
            output[10]='%';
        }
        for(i=0;i<20;i++)
            printf("%c",output[i]);
        printf("\n");
    }
    return 0;
}
