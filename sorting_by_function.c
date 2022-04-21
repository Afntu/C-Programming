// This is a try, need to update it ,now it is not giving the correct result


#include<stdio.h>
int swap(int a, int b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
	return(a,b);
}
int main()
{
	int n,i,j;
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
				swap(a[i],a[j]);		
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("The %dth element of the sorted array is %d\n",i,a[i]);
		printf("\n");
	}
}
