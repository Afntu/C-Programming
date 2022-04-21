#include<stdio.h>
int main()
{
	int a,b;
	printf("Enter the two integers a,b : ");
	scanf("%d%d",&a,&b);
	printf("Bitwise AND of this two integer is=%d\n",a&b);
	printf("Bitwise OR of this two integer is=%d\n",a|b);
	printf("Bitwise XOR of this two integer is=%d\n",a^b);
	printf("Bitwise NOT of first integer is=%d\n",~a);
	return 0;
}
