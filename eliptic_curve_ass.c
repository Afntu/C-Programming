#include <stdio.h>
void point_double(unsigned long int x1,unsigned long int z1,unsigned long int p,unsigned long int q)
{
	unsigned long int P[2],Q[2],R[2],S[2],T[2],U[2],V[2],W[2]={1447112650,898208916};  //W=(A+2)/4 mod P
	add(x1,z1,P);
	negation(z1,R)
	add(x1,R,Q);
	mult(P,P,S)
	mult(Q,Q,T);
	mult(S,T,p);
	mult(x1,z1,V);
	negation(T,R);
	add(S,R,P);
	mult(W,P,R);
	add(T,R,Q);
	mult(P,Q,q);
}
void point_add(unsigned long int x1,unsigned long int z1,unsigned long int x2,unsigned long int z2,unsigned long int p,unsigned long int q)
{
	unsigned long int P[2],Q[2],R[2],S[2],T[2],U[2],V[2],W[2];
	V[0]=x1[0];	V[1]=x1[1];
	W[0]=z1[0];	W[1]=z1[1];
	add(x1,z1,P);
	negation(z1,R)
	add(x1,R,Q);
	add(x2,z2,S);
	negation(z2,R)
	add(x2,R,T);
	mult(P,T,R);
	mult(S,Q,U);
	add(R,U,P);
	negation(U,S);
	add(R,S,Q);
	mult(P,W,p);
	mult(Q,V,q);
}
void negation(unsigned long int a[],unsigned long int c[])
{
	unsigned long int b[2]={0x7FFFFFFF,0x3FFFFFFF};
	add(a,b,c);
}
void add(unsigned long int a[], unsigned long int b[], unsigned long int c[])
{
	unsigned long int carry;
	c[0]=a[0]+b[0];
	c[1]=a[1]+b[1];
	
	carry=c[0]>>31;	c[0]=c[0]&0x7FFFFFFF;	c[1]=c[1]+carry;
	carry=c[1]>>30;	c[1]=c[1]&0x3FFFFFFF;	c[0]=c[0]+carry;
	carry=c[0]>>31;	c[0]=c[0]&0x7FFFFFFF;	c[1]=c[1]+carry;
	carry=c[1]>>30;	c[1]=c[1]&0x3FFFFFFF;
}
void mult(unsigned long int a[], unsigned long int b[], unsigned long int d[])
{	
	unsigned long int carry,c[3];
	c[0] = a[0]*b[0];
	c[2] = a[1]*b[1];
	c[1] = (a[0]+a[1])*(b[0]+b[1])-c[0]-c[2];
	c[2]=c[2]<<1;
	c[0]=c[0]+c[2];
	
	carry=c[0]>>31;	d[0]=c[0]&0x7FFFFFFF;	c[1]=c[1]+carry;
	carry=c[1]>>30;	d[1]=c[1]&0x3FFFFFFF;	d[0]=d[0]+carry;
	carry=d[0]>>31;	d[0]=d[0]&0x7FFFFFFF;	d[1]=d[1]+carry;
	carry=d[1]>>30;	d[1]=d[1]&0x3FFFFFFF;		
}
void main()
{
	unsigned long int A[2]={1493483305,371610194},B[2]={1,0},X[2]={486145363,268485549},Z[2]={1,0},N[2];
	unsigned long int n;
	printf("Enter the vale of n:\n");
	scanf("%lu",&n);
	N[0]=(unsigned int)(n&0x7FFFFFFF);
	N[1]=(unsigned int)((n>>31)&0x3FFFFFFF);
	printf("%lu,%lu\n",N[0],N[1]);
	unsigned char m[64];
	int i,k;
	for(i=0;i<31;i++)
	{
		m[i]=(N[0]&1);
		N[0]=N[0]>>1;
	}
	while(N[1]!=0)
	{
		m[i]=(N[1]&1);
		i++;
		N[1]=N[1]>>1;
	}
	unsigned long int R_1[2],R_2[2],S_1[2],S_2[2];
	R_1[0]=X[0];	R_1[1]=X[1];
	R_2[0]=1;	R_2[1]=0;
	point_double(R_1,R_2,S_1,S_2);
	for(k=i-2;k>=0;k--)
	{
		
	
	
	
	
	
	
	
	
	
}
