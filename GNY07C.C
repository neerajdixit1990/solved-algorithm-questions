#include<stdio.h>
#include<string.h>
void copy(char *inter,int ptr,char codes[29][7],int offset)
{
     int i;
     for(i=ptr;i<ptr+5;i++)
		 inter[i]=codes[offset][i-ptr];
}
int main()
{
    int test_cases,output[21][21],i,j,k,r,ru,rl,cl,cr,row,col,len,ptr,dec;
    char codes[29][7],input[102],inter[450],temp;
    strcpy(codes[0],"00000\0");
    strcpy(codes[1],"00001\0");
    strcpy(codes[2],"00010\0");
    strcpy(codes[3],"00011\0");
    strcpy(codes[4],"00100\0");
    strcpy(codes[5],"00101\0");
    strcpy(codes[6],"00110\0");
    strcpy(codes[7],"00111\0");
    strcpy(codes[8],"01000\0");
    strcpy(codes[9],"01001\0");
    strcpy(codes[10],"01010\0");
    strcpy(codes[11],"01011\0");
    strcpy(codes[12],"01100\0");
    strcpy(codes[13],"01101\0");
    strcpy(codes[14],"01110\0");
    strcpy(codes[15],"01111\0");
    strcpy(codes[16],"10000\0");
    strcpy(codes[17],"10001\0");
    strcpy(codes[18],"10010\0");
    strcpy(codes[19],"10011\0");
    strcpy(codes[20],"10100\0");
    strcpy(codes[21],"10101\0");
    strcpy(codes[22],"10110\0");
    strcpy(codes[23],"10111\0");
    strcpy(codes[24],"11000\0");
	strcpy(codes[25],"11001\0");
	strcpy(codes[26],"11010\0");
	scanf("%d",&test_cases);
	for(k=0;k<test_cases;k++)
	{
		scanf("%d",&row);
		scanf("%d",&col);
		scanf("%c",&temp);
		if(temp==' ')
			gets(input);
		ptr=0;
		len=strlen(input);
		j=row*col+11;
		for(i=0;i<j;i++)
			inter[i]='0';
		for(i=0;i<len;i++)
		{
			if(input[i]==' ')
				copy(inter,ptr,codes,0);
			else
				copy(inter,ptr,codes,input[i]-64);
			ptr=ptr+5;
		}
		len=ptr;
		for(i=0;i<row;i++)
			for(j=0;j<col;j++)
				output[i][j]=0;
        i=0;
        dec=0;
        ru=0;
        rl=row-1;
        cl=0;
        cr=col-1;
        while(i<len)
        {
            if(dec==0)
            {
                for(r=cl;r<=cr;r++)
					output[ru][r]=inter[i++]-48;
                ru++;
            }
            else if(dec==1)
            {
                 for(r=ru;r<=rl;r++)
					output[r][cr]=inter[i++]-48;
				 cr--;
			}
			else if(dec==2)
			{
				 for(r=cr;r>=cl;r--)
					output[rl][r]=inter[i++]-48;
				rl--;
			}
			else if(dec==3)
			{
				 for(r=rl;r>=ru;r--)
					output[r][cl]=inter[i++]-48;
                 cl++;
            }
            dec=(dec+1)%4;
        }
        printf("%d ",k+1);
        for(i=0;i<row;i++)
            for(j=0;j<col;j++)
				printf("%d",output[i][j]);
        printf("\n");
    }
    return 0;
}
