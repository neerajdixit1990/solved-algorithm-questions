#include<stdio.h>
long long int count[6];
int assign(char *colour,char *colour_sec,long long int curr,long long int input)
{
     char i='A';
     int flag=0;
     if(curr==input)
         flag=1;             // success
     else
     {    
          for(i='A';i<='D';i=i+1)  // 'i' present colour 
          {
              if((colour_sec[(long long int)curr-(long long int)1]!=i&&colour[curr]!=i)&&count[i-65]!=0)
              {
                  colour_sec[curr]=i;
                  flag=assign(colour,colour_sec,curr+1,input);
                  if(flag==1)
                      break;
                  else
                      continue;
              }
          }
     }
     return flag;
}
int main()
{
    long long int input,factor,i;
    char colour[50020],colour_sec[50020];
    scanf("%lld",&input);
    count[0]=count[1]=count[2]=count[3]=input;
    factor=(long long int)input*(long long int)2;
    for(i=0;i<factor;i=i+1)
    {   
        scanf("%c",&colour[i]);
        count[colour[i]-65]=count[colour[i]-65]-1;
    }
    colour_sec[0]=((colour[0]-64)%4)+65;
    count[((colour[0]-64)%4)+65]=count[((colour[0]-64)%4)+65]-1;
    assign(colour,colour_sec,1,factor);
    return 0;
}
