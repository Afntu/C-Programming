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
	int i,j,n;
	printf("Enter how many rows of Pascal triangle you want to print\n");
	scanf("%d",&n);
	printf("\n");
	printf("Here is your Pascal Triangle !!!\n");
	for(i = 0;i <= n;i++)
	{
		for(j = 0;j <= i;j++)
		{
			printf("%d\t",fact(i)/(fact(i-j)*fact(j)));
		}
		printf("\n");
	}
}
