#include<stdio.h>
void swap(int *i,int *j)
{
	int temp;
	temp = *i;
	*i = *j;
	*j = temp;
}
int main()
{
	int n,number,max,next_max,i;
	printf("Enter the value of n\n");
	scanf("%d",&n);
	if(n > 0)
	{
		printf("Enter the 0th number in the list\n");
		scanf("%d",&max);                             // storing first number in max variable.
		printf("Enter the 1st number in the list\n");
		scanf("%d",&next_max);			       //  storing second number in the next_max vaeiable.
		if(max < next_max)
		swap(&max , &next_max);
		for(i = 2;i < n;i++)
		{
			printf("Enter the %dth number in the list\n",i);
			scanf("%d",&number);
			if(max < number)
			{
				next_max = max;
				max = number;
			}
			else if(next_max < number)
			next_max = number;
		}
	printf("Maximum value of the given list is %d\n",max);
	printf("Next Maximum value of the given list is %d\n",next_max);		
	}	
}
