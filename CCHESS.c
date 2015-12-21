#include<stdio.h>
int last_x,last_y,arr[8][8];
dist(int a,int b,int c,int d)
{
    int ret=0;
    ret = a*c + b*d;
    if (arr[c][d] != 0)
       arr[c][d] = ret+arr[a][b];
}
int calculate_distance(int x,int y)
{
    int result = 0;
    if (x == last_x && y == last_y)
        return 1;

//-----------------------------------------------------    
    if ((x-1)>=0 && (y-2)>=0){
       dist(x,y,x-1,y-2);
       result = calculate_distance(x-1,y-2);
    }
//-----------------------------------------------------    
    if (result == 0 && (x-2)>=0 && (y-1)>=0) {
       dist(x,y,x-2,y-1);
       result = calculate_distance(x-2,y-1);
    }
//-----------------------------------------------------    
    if (result == 0 && (x-2)>=0 && (y+1)<=7){
       dist(x,y,x-2,y+1);
       result = calculate_distance(x-2,y+1);
    }
//-----------------------------------------------------    
    if (result == 0 && (x-1)>=0 && (y+2)<=7){
       dist(x,y,x-1,y+2);
       result = calculate_distance(x-1,y+2);
    }
//-----------------------------------------------------
    if (result == 0 && (x+1)<=7 && (y+2)<=7){
       dist(x,y,x+1,y+2);
       result = calculate_distance(x+1,y+2);
    }
//-----------------------------------------------------
    if (result == 0 && (x+2)<=7 && (y+1)<=7){
       dist(x,y,x+2,y+1);
       result = calculate_distance(x+2,y+1);
    }
//-----------------------------------------------------
    if (result == 0 && (x+2)<=7 && (y-1)>=0){
       dist(x,y,x+2,y-1);
       result = calculate_distance(x+2,y-1);
    }
//-----------------------------------------------------
    if (result == 0 && (x+1)<=7 && (y-2)>=0){
       dist(x,y,x+1,y-2);
       result = calculate_distance(x+1,y-2);
    }
//-----------------------------------------------------
    return result;  
}
int main()
{
    int start_x,start_y,i,result = 0,j;
    for(i=0 ; i<8 ; i++) {
        for(j=0 ; j<8 ; j++)    
            arr[i][j] = 0;
    }
    scanf("%d",&start_x);
    scanf("%d",&start_y);
    scanf("%d",&last_x);
    scanf("%d",&last_y);
    result = calculate_distance(start_x,start_y);
    if(result == 0)
        printf("-1\n");
    else
        printf("%d\n",arr[last_x][last_y]);    
    return 0;
}
