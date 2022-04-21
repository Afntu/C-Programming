#include<stdio.h>
#include<stdlib.h>
void sum(int **a,int **b,int **c,int n)
{
	int i,j;
	for(i = 0;i < n;i++)
		for(j = 0;j < n;j++)
			c[i][j] = a[i][j] + b[i][j];
}
	
int main()
{

	int i,j,n;
	printf("Enter the order of the matrix\n");
	scanf("%d",&n);
	
	int **a, **b, **c;

	a = (int**)malloc(n*sizeof(int*));
	b = (int**)malloc(n*sizeof(int*));
	c = (int**)malloc(n*sizeof(int*));
	for(int i1=0; i1<n; i1++)
	{
		a[i1] = (int*)malloc(n*sizeof(int));
		b[i1] = (int*)malloc(n*sizeof(int));
		c[i1] = (int*)malloc(n*sizeof(int));
	}
		
	// Printing the first Matrix 
	for(i = 0;i < n;i++)
		for(j = 0;j < n;j++){
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
	for(i = 0;i < n;i++){
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
	sum(a,b,c,n);
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
