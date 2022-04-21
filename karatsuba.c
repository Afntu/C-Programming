#include <stdio.h>

void convertC2I(unsigned char a_8[], unsigned long int a_26[])
{
	a_26[0] = (unsigned long int) a_8[0];
	a_26[0] = a_26[0] |  (((unsigned long int) a_8[1])<<8);
	a_26[0] = a_26[0] |  (((unsigned long int) a_8[2])<<16);
	a_26[0] = a_26[0] |  (((unsigned long int) (a_8[3]&0x3))<<24);

	a_26[1] = (unsigned long int) (a_8[3]>>2);
	a_26[1] = a_26[1] |  (((unsigned long int) a_8[4])<<6);
	a_26[1] = a_26[1] |  (((unsigned long int) a_8[5])<<14);
	a_26[1] = a_26[1] |  (((unsigned long int) (a_8[6]&0xF))<<22);

	a_26[2] = (unsigned long int) (a_8[6]>>4);
	a_26[2] = a_26[2] |  (((unsigned long int) a_8[7])<<4);
	a_26[2] = a_26[2] |  (((unsigned long int) a_8[8])<<12);
	a_26[2] = a_26[2] |  (((unsigned long int) (a_8[9]&0x3F))<<20);

	a_26[3] = (unsigned long int) (a_8[9]>>6);
	a_26[3] = a_26[3] |  (((unsigned long int) a_8[10])<<2);
	a_26[3] = a_26[3] |  (((unsigned long int) a_8[11])<<10);
	a_26[3] = a_26[3] |  (((unsigned long int) a_8[12])<<18);

	a_26[4] = (unsigned long int) a_8[13];
	a_26[4] = a_26[4] |  (((unsigned long int) a_8[14])<<8);
	a_26[4] = a_26[4] |  (((unsigned long int) (a_8[15]&0x7F))<<16);
}


void add(unsigned long int a[], unsigned long int b[], unsigned long int c[])
{
	unsigned long int carry;

	c[0] = a[0]+b[0];
	c[1] = a[1]+b[1];
	c[2] = a[2]+b[2];
	c[3] = a[3]+b[3];
	c[4] = a[4]+b[4];

	carry = c[0]>>26;	c[0] = c[0] & 0x3FFFFFF;	c[1] = c[1]+carry;
	carry = c[1]>>26;	c[1] = c[1] & 0x3FFFFFF;	c[2] = c[2]+carry;
	carry = c[2]>>26;	c[2] = c[2] & 0x3FFFFFF;	c[3] = c[3]+carry;
	carry = c[3]>>26;	c[3] = c[3] & 0x3FFFFFF;	c[4] = c[4]+carry;
	carry = c[4]>>26;	c[4] = c[4] & 0x3FFFFFF;	c[5] = carry;

}


void mult(unsigned long int a[], unsigned long int b[], unsigned long int c[])
{
	unsigned long int carry;
	unsigned long int d1,d2,d3;
        //14 Multiplication
	c[0] = a[0]*b[0];
	d1 = a[1]*b[1];
	c[1] = (a[0]+a[1])*(b[0]+b[1])-c[0]-d1;
	
	d2=a[2]*b[2];
        c[2]=(a[0]+a[2])*(b[0]+b[2])-c[0]-d2+d1;
        
        d3=a[3]*b[3];
        c[3]=(a[1]+a[2])*(b[1]+b[2])+(a[0]+a[3])*(b[0]+b[3])-c[0]-d1-d2-d3;
        
        c[8] = a[4]*b[4];
        
        c[7]=((a[3]+a[4])*(b[3]+b[4]))-c[8]-d3;
        
        c[6]=((a[4]+a[2])*(b[4]+b[2]))-c[8]-d2+d3;
        
        
        c[5]=((a[3]+a[2])*(b[3]+b[2])) + ((a[1]+a[4])*(b[1]+b[4]))-d2-d3-d1-c[8];
        
        c[4]=(a[0]+a[1]+a[2]+a[3]+a[4])*(b[0]+b[1]+b[2]+b[3]+b[4])-c[0]-c[1]-c[2]-c[3]-c[5]-c[6]-c[7]-c[8];
        //c[4]=d2 + ((a[0]+a[4])*(b[0]+b[4])) - c[0] - c[8] + ((a[1]+a[3])*(b[1]+b[3])) - d1 - d3;
        	

	carry = c[0]>>26;	c[0] = c[0] & 0x3FFFFFF;	c[1] = c[1]+carry;
	carry = c[1]>>26;	c[1] = c[1] & 0x3FFFFFF;	c[2] = c[2]+carry;
	carry = c[2]>>26;	c[2] = c[2] & 0x3FFFFFF;	c[3] = c[3]+carry;
	carry = c[3]>>26;	c[3] = c[3] & 0x3FFFFFF;	c[4] = c[4]+carry;
	carry = c[4]>>26;	c[4] = c[4] & 0x3FFFFFF;	c[5] = c[5]+carry;
	carry = c[5]>>26;	c[5] = c[5] & 0x3FFFFFF;	c[6] = c[6]+carry;
	carry = c[6]>>26;	c[6] = c[6] & 0x3FFFFFF;	c[7] = c[7]+carry;
	carry = c[7]>>26;	c[7] = c[7] & 0x3FFFFFF;	c[8] = c[8]+carry;
	carry = c[8]>>26;	c[8] = c[8] & 0x3FFFFFF;	c[9] = carry;

}



int main()
{
	  //127-bit inputs
	unsigned char a_8[16] ={44, 42, 237, 16, 199, 240, 233, 138, 218, 153, 138, 174, 45, 112, 138, 73}; 

	unsigned char b_8[16]= {74, 167, 251, 243, 158, 232, 148, 93, 204, 15, 150, 248, 63, 119, 14, 15};

	unsigned long int a_26[5], b_26[5];
	unsigned long int addr_26[6];
	unsigned long int multr_26[10];

	convertC2I(a_8, a_26);
	convertC2I(b_8, b_26);

	printf("\n a_26 = ");
	for(int i=0;i<5;i++)
		printf("%lu ",a_26[i]);
	printf("\n");

	printf("\n b_26 = ");
	for(int i=0;i<5;i++)
		printf("%lu ",b_26[i]);
	printf("\n");


	add(a_26, b_26, addr_26);

	printf("\n addr_26 = ");
	for(int i=0;i<6;i++)
		printf("%lu ",addr_26[i]);
	printf("\n");
	
	mult(a_26, b_26, multr_26);

	printf("\n multr_26 = ");
	for(int i=0;i<10;i++)
		printf("%lu ",multr_26[i]);
	printf("\n");
	

	return 0;
}
