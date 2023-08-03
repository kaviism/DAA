#include<stdio.h>
int main()
{
	int a,i,j,c=1;
	printf("enter a row:");
	scanf("%d",&a);
	for(i=1;i<=a;i++)
	{
		for(j=1;j<=a-i;j++)
		{
			printf(" ");
		}
		for(j=0;j<=i;j++)
		{
		if(j==0)
		c;
		
		else
		c=c*(i-j+1)/j;
		printf(" ",c);
		}
	}
}
