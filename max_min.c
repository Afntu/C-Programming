#include<stdio.h>
int main()
{
	int n,number,min,max,i;
	printf("Enter the value of n\n");
	scanf("%d",&n);
	if(n>0)
	{
		printf("Enter the first number in the list\n");
		scanf("%d",&number);
		max=number;
		min=number;	// As minimum and maximum are same for a singleton set.
		for(i=2;i<=n;i++)
		{
			printf("Enter the %dth number in the list\n",i);
			scanf("%d",&number);
			if(max<number)
			max=number;
			if(min>number)
			min=number;
		}
	printf("Maximum value of the given list is %d\n",max);
	printf("Minimum value of the given list is %d\n",min);		
	}	
}
