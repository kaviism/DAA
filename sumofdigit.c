#include<stdio.h>
int main()
{
int a,sum,b,c,i;
printf("enter a number :");
scanf("%d",&a);
for(i=0;i<=a;i++)
{
b=a%10;
a=a/10;
c=b;
sum+=c;
}
printf("%d",sum);
}
