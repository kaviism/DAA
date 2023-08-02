#include <stdio.h>
int main()  
{
 int n,i,fact;
 printf("Enter an integer: ");
 scanf("%d",&n);
 fact=1;
 if(n<0)
   printf("Factorial of a negative number doesn't exist.");
 else
 {
  for (i=1;i<=n;++i) 
  {
   fact=fact*i;
  }
 printf("Factorial of %d=%d",n,fact);
 }
 return 0;
}