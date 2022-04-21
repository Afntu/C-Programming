#include<stdio.h>
#include<stdlib.h>

void checking(int *p , int i)
{
	if(i % 2 == 0)
		p[i] = 0;
	else
		p[i] = 1;
	printf("Value of p[%d] inside the function is = %d\n",i,p[i]);
	printf("Address of p[%d] inside the function is = %p\n",i,&p[i]);		
}

int main()
{
	int *p,i,n;
	printf("Enter how many points you want to checks\n");
	scanf("%d",&n);
	p = (int*)malloc(n*sizeof(int));
	for(int i = 0;i<n;i++)
	{
		checking(&p[i],i);
		printf("Value of p[%d] outside the function is = %d\n",i,p[i]);
		printf("Address of p[%d] outside the function is = %p\n",i,&p[i]); 
	} 
	
	return 0;	
}
