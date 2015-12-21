#include<stdio.h>
int main()
{
    char curr,first[9],second[9],input[9];
    int no_swaps,i;
    scanf("%s",input);
    curr=input[0];
    scanf("%d",&no_swaps);
    for(i=0;i<no_swaps;i++)
    {
        scanf("%s",first);
        scanf("%s",second);
        if(curr==first[0])
            curr=second[0];
		else if(curr==second[0])
             curr=first[0];
    }
    if(curr=='l')
        printf("left");
    else if(curr=='c')
         printf("center");
    else if(curr=='r')
        printf("right");
    else
        printf("\n");
    return 0;
}
