#include<stdio.h>
int fact(int i)
{
	if(i==1)
	return 1;
	else
	return(i*fact(i-1));
}
int main()
{
	int n,a;
	printf("Enter the value of the integer\n");
	scanf("%d",&n);
	if(n<0)
	{
		printf("Enter only non negative integers\n");
		
	}
	if(n==0)
	printf("Factorial(%d) = 1\n",n);
	if(n>0)
	{
		printf("Factorial(%d)=%d\n",n,fact(n));
	}
}
