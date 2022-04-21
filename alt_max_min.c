#include<stdio.h>
void swap(int *i,int *j)
{
	int temp;
	temp=*i;
	*i=*j;
	*j=temp;
}
int main()
{
	int n,m,max,min,i,num1,num2;
	printf("Give n:\n");
	scanf("%d",&n);
	printf("n=%d\n",n);
	scanf("%d",&max);
	min=max;
	m=n-1;
	if(n%2==0)
	{
		scanf("%d",&min);
		if(max<min)
		swap(&max,&min);
		m=m-1;
	}
	for(i=1;i<m/2;i++)
	{
		scanf("%d%d",&num1,&num2);
		if(num1<num2)
		swap(&num1,&num2);
		if(num1>max)
		max=num1;
		if(num2<min)
		min=num2;
	}
}
