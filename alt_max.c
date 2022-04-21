// This algorithm is better than the algorithm we used for max.c


#include<stdio.h>
int main()
{
	int n,number,max,next_max,i;
	printf("Enter the value of n\n");
	scanf("%d",&n);
	if(n>0)
	{
		printf("Enter the first number in the list\n");
		scanf("%d",&number);
		next_max=max;
		max=number;
		for(i=2;i<=n;i++)
		{
			printf("Enter the %dth number in the list\n",i);
			scanf("%d",&number);
			if(max < number)
			max = number;
			else if(next_max < number)
			next_max=number;
	
		}
	printf("Maximum value of the given list is %d\n",max);
	printf("Next Maximum value of the given list is %d\n",next_max);		
	}	
}
