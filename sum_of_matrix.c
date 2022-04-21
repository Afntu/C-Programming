#include<stdio.h>
void sum(int *a,int *b,int *c,int n)
{
	int i,j;
	for(i = 0;i < n;i++)
		for(j = 0;j < n;j++)
		{
			*(c+i*n+j) = *(a+i*n+j) + *(b+i*n+j);
		}
}
int main()
{
	int i,j,n;
	printf("Enter the order of the matrix\n");
	scanf("%d",&n);
	int a[n][n];int b[n][n];int c[n][n];
	
	// Printing the first Matrix 
	for(i = 0;i < n;i++)
		for(j = 0;j < n;j++)
		{
			printf("Enter the value of a(%d,%d) = \n",i,j);
			scanf("%d",&a[i][j]);
		}
	printf("\n");
	// Printing the 2nd Matrix 
	for(i = 0;i < n;i++)
		for(j = 0;j < n;j++)
		{
			printf("Enter the value of b(%d,%d) = \n",i,j);
			scanf("%d",&b[i][j]);
		}
	printf("\n");
	printf("The first matrix is\n");
	for(i = 0;i < n;i++)
	{
		for(j = 0;j < n;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	printf("The second matrix is\n");
	for(i = 0;i < n;i++)
	{
		for(j = 0;j < n;j++)
		{
			printf("%d\t",b[i][j]);
		}
		printf("\n");
	}
	printf("The sum of these two matrix are\n");
	sum(&a[0][0],&b[0][0],&c[0][0],n);
		printf("\n");
	for(i = 0;i < n;i++)
	{
		for(j = 0;j < n;j++)
		{
			printf("%d\t",c[i][j]);
		}
		printf("\n");
	}	
}
