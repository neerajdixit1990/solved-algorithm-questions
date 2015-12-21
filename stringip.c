#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main()
{
 
char inputstr[128];
char *cptr = &inputstr[0];
size_t thesize = 128;
 
while(1)
{
if(feof(stdin) != 0)
{ break; }
 
getline(&cptr, &thesize, stdin);
 
printf("input string is : %s\n", inputstr);
}
 
getc(stdin);
return 0;
 
}
