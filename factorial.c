#include<stdio.h>
int fact(int i)
{
	int m=1;
	if(i > 1)
	m=i*fact(i-1);
	return m;
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
		a=fact(n);
		printf("Factorial(%d)=%d\n",n,a);
	}
}
