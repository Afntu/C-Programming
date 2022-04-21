//This program is not complete yet.



 #include<stdio.h>
void swap(int *i,int *j)
{
	int temp;
	temp=*i;
	*i=*j;
	*j=temp;
}
int maxi(int a,int max,int index)
{
	int i;
	for(i = 1;i < index;i++)
	{
		if(max<a[i])
		max = a[i];
	}
	return(max);
}
int mini(int a,int min,int index)
{
	int i;
	for(i = 1;i < index;i++)
	{
		if(min > a[i])
		min = a[i];
	}
	return(min);
}
int main()
{
	int i,n,m,max,min,num1,num2;
	index1 = 1,index2 = 1;
	printf("Enter the number of elements in the set\n");
	scanf("%d",&n);
	int a[n];
	int large[n],small[n];
	for(i=0;i<n;i++)
	{
		printf("Enter the %d th element of the array\n",i);
		scanf("%d",&a[i]);
	}
	max = a[0];
	for(i=1;i<n;i++)
	{
		if(max < a[i])
		max = a[i];
	}
	printf("The maximum value of the set is %d\n",max);
}
