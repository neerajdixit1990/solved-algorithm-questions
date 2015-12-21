#include<stdio.h>
#include<string.h>
int main()
{
    char input[210],mat[21][102];
    int no_col,r,c,i,len;
    while(1)
    {
        scanf("%d",&no_col);
        if(no_col==0)
            break;
        scanf("%s",input);
        len=strlen(input);
        r=0;
        c=0;
        for(i=0;i<len;)
        {
            while((c<no_col)&&(i<len))
            {
                mat[r][c]=input[i++];
                c++;
            }
            r++;
            c--;
            if(i>=len)
                break;
            while((c>=0)&&(i<len))
            {
                mat[r][c]=input[i++];
                c--;
            }
			r++;
			c++;
        }
		for(i=0;i<no_col;i++)
		{
			for(c=0;c<r;c++)
                printf("%c",mat[c][i]);
        }
        printf("\n");
    }
    return 0;
}
