#include<stdio.h>
void swap1(int i,int j)
{
	int temp;
	temp=i;
	i=j;
	j=temp;
}

void swap2(int *i,int *j)
{
	int temp;
	temp=*i;
	*i=*j;
	*j=temp;
}

int main()
{
	int a,b;
	printf("Enter Two integers\n");
	scanf("%d %d",&a,&b);
	printf("Before call value of two integers are %d %d\n",a,b);
	swap1(a,b);
	printf("After the fast call values are %d %d\n",a,b);
	swap2(&a,&b);
	printf("After the second call values are %d %d\n",a,b);
}
