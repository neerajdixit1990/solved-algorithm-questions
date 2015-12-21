#include<stdio.h>
int main()
{
    long long int N,sx,sy,line_distance,vertices[102][2],i,temp;
    double point_dis[102];
    scanf("%lld %lld %lld",&N,&sx,&sy);
    for(i=0;i<N;i++)
    {
        scanf("%lld %lld",&vertices[i][0],&vertices[i][1]);
        temp = vertices[i][0]*vertices[i][0] + vertices[i][1]*vertices[i][1];
        point_dis[i] = sqrt((double)temp);
    }
    return 0;
}
