#include <stdio.h> 
int gcd(int a, int b) 
{  
  if (b == 0) 
        return a; 
    return gcd(b, a % b);  
} 
  
void main() 
{ 
	int a,b;
    printf("enter two number\n");
	scanf("%d%d",&a,&b); 
    printf("GCD of %d and %d is %d ", a, b, gcd(a, b)); 
}
