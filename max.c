#include<stdio.h>
int main()
{
	int i,n,max;
	printf("Enter the number of elements in the set\n");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		printf("Enter the %d th element of the array\n",i);
		scanf("%d",&a[i]);
	}
	max=a[0];
	for(i=1;i<n;i++)
	{
		if(max<a[i])
		max=a[i];
	}
	printf("The maximum value of the set is %d\n",max);
}
