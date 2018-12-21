#include<stdio.h>
void TOH(int n,char source,char temp,char dest)
{
   if(n==1)
   printf("Move disk from %c to %c\n",source,dest);
   else
   {
      TOH(n-1,source,dest,temp);
      printf("Move disk from %c to %c\n",source,dest);
      TOH(n-1,temp,source,dest);
   }
}
 void main()
 {
   int n=3;
   TOH(n,'A','B','C');
 }
      
