#include <stdio.h>
#include <math.h>
int main()
{
 int num,temp,rem,count=0,sum=0;
 printf("Enter number:");
 scanf("%d",&num);
 temp=num;
 while(temp!=0) 
 {
 count=count+1;
 temp=temp/10;
 }
 temp=num;
 while(temp>0)
 {
 rem=temp%10;
 sum=sum+pow(rem,count);
 temp=temp/10;
 }
 if(num==sum)
 printf("\n%d is Armstrong Number\n",num);
 else
 printf("\n%d is not Armstrong Number\n",num);
 return 0;
}
