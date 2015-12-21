#include<stdio.h>
long long int half(long long int data)
{
    if(data%2==1)
        return((data+1)/2);
    else
        return(data/2);
}
long long int maximum(long long int N,long long int M,long long int K)
{
    if(N>M)
    {
        if(N>K)
            return N;
        else
            return K;
    }
    else
    {
        if(M>K)
            return M;
        else
            return K;
    }
}
int main()
{
    long long int test_cases,N,M,K,answer1,answer2,i,temp;
    scanf("%lld",&test_cases);
    for(i=1;i<=test_cases;i++)
    {
        scanf("%lld",&N);
        scanf("%lld",&M);
        scanf("%lld",&K);
        answer1=N*M*K-1;
        answer2=0;
        while(!(N==1&&M==1&&K==1))
        {
            answer2=answer2+1;
            temp=maximum(N,M,K);
            if(temp==N)
                N=half(N);
            else if(temp==M)
                M=half(M);
            else
                K=half(K);
        }
        printf("Case #%lld: %lld %lld\n",i,answer1,answer2);
    }
    return 0;
}
