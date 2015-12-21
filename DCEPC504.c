#include<stdio.h>
int main()
{
    long long int test_cases,generation,k,family_tree[700],offset;
    int status,i;
    scanf("%lld",&test_cases);
    while(test_cases--)
    {
        scanf("%lld",&generation);
        scanf("%lld",&k);
        status=0;
        offset=1;      i=1;
        while(i<generation)
        {
            offset=(long long int)offset*(long long int)2;
            i++;
        }
       // printf("%lld\t",offset);
        offset=(long long int)k+(long long int)offset-(long long int)1;
        family_tree[i]=(long long int)offset;
        while(offset!=1)
        {
            family_tree[++i]=(long long int)offset/(long long int)2;
            offset=(long long int)family_tree[i];
        }
        while(i>0)
        {
            offset=(long long int)family_tree[i-1];
            if(status==1)
            {
                if(offset==((long long int)family_tree[i]*(long long int)2)+1)
                    status=0;
            }
            else if(status==0)
            {
                if(offset==((long long int)family_tree[i]*(long long int)2)+1)
                    status=1;
            }
            i--;
        }
        if(status==1)
            printf("Female\n");
        else
            printf("Male\n");
    }
    return 0;
}
