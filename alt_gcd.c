#include<stdio.h>					
int gcd (int a, int b) 
{
	if(a%b == 0)
		return b;				// by this step we use the concept of gcd(i,j)=gcd(j,r) ,where i=jb+r.
	else
		return gcd(b, a%b);
}
int main()
{
	int a1,b1,a,b,c;
	printf("Enter two integers \n");
	scanf("%d%d",&a,&b);
	if(a==0||b==0)
	printf("Enter two non zero integers\n");
	if(a<0)
	a1=-a;
	else
	a1=a;
	if(b<0)
	b1=-b;
	else
	b1=b;
	c=gcd(a1,b1);
	printf("GCD(%d,%d)=%d\n",a,b,c);
}
