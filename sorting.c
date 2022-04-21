#include<stdio.h>
int main()
{
	int n,i,j,temp;
	printf("Enter the number of elements in the array which you want to sort\n");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		printf("Enter the %dth element of the array is\n",i);
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;	
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("The %dth element of the sorted array is %d\n",i,a[i]);
		printf("\n");
	}
}
