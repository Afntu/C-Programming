#include<stdio.h>
int add(int a[],int n)
{
	int i,s=0;
	for(i=0;i<n;i++)
	s=s+a[i];
	return s;
}
int main()
{
	int i,n,sum;
	printf("Enter the size of array\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter the array elements\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	sum=add(a,n);
	printf("Sum of the array is %d\n",sum);
}
