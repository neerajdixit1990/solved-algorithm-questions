#include<stdio.h>
#define COST_S 15
#define COST_T 20
int main()
{
    int cost[1002][1002],i,j,len_S,len_T;
    char *S,*T;
    while(1) {
             scanf("%s",S);
             len_S = strlen(S);
             if (len_S == 1 && S[0] == '#') {
                break;
             }
             scanf("%s",T);
             len_T = strlen(T);
             for (i=0;i<len_S;i++) {
                 for (j=0;j<len_T;j++) {
                     
                 }
             }
    }
    return 0;
}
