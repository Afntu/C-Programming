#include <stdio.h>

void convertC2I(unsigned char a_8[], unsigned long int a_26[]){
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


void add(unsigned long int a[], unsigned long int b[], unsigned long int c[]){
	unsigned long int carry;

	c[0] = a[0]+b[0];
	c[1] = a[1]+b[1];
	c[2] = a[2]+b[2];
	c[3] = a[3]+b[3];
	c[4] = a[4]+b[4];

	
	//carry = c[4]>>23;	c[4] = c[4] & 0x7FFFFF;		c[0] = c[0]+carry;

	carry = c[0]>>26;	c[0] = c[0] & 0x3FFFFFF;	c[1] = c[1]+carry;
	carry = c[1]>>26;	c[1] = c[1] & 0x3FFFFFF;	c[2] = c[2]+carry;
	carry = c[2]>>26;	c[2] = c[2] & 0x3FFFFFF;	c[3] = c[3]+carry;
	carry = c[3]>>26;	c[3] = c[3] & 0x3FFFFFF;	c[4] = c[4]+carry;
	
	carry = c[4]>>23;	c[4] = c[4] & 0x7FFFFF;		c[0] = c[0]+carry;
	carry = c[0]>>26;	c[0] = c[0] & 0x3FFFFFF;	c[1] = c[1]+carry;

}


void mult(unsigned long int a[], unsigned long int b[], unsigned long int d[]){
	unsigned long int carry,c[8];
	unsigned long int t1,t2,t3,t4,t5,t6,t7;
	unsigned long int t11,t22,t33,t44,t55,t66,t77,t88;

	c[0] = a[0]*b[0];
	c[2] = a[1]*b[1];
	c[1] = (a[0]+a[1])*(b[0]+b[1])-c[0]-c[2];

	c[4] = a[2]*b[2];
	c[6] = a[3]*b[3];
	c[5] = (a[2]+a[3])*(b[2]+b[3])-c[4]-c[6];

	c[8] = a[4]*b[4];

	t1 = a[2]+a[4];	t2 = a[3];
	t3 = b[2]+b[4];	t4 = b[3];
	t5 = t1*t3;
	t7 = t2*t4;
	t6 = (t1+t2)*(t3+t4) - t5 - t7;

	t5 = t5 - c[4];
	t6 = t6 - c[5];
	t7 = t7 - c[6];

	t5 = t5 -  c[8];	
	
	c[6] = c[6] + t5;
	c[7] = t6;
	c[8] = c[8] + t7;

	t1 = a[0] + a[2];
	t2 = a[1] + a[3];
	t3 = a[4];

	t4 = b[0] + b[2];
	t5 = b[1] + b[3];
	t6 = b[4];

	t11 = t1*t4;
	t33 = t2*t5;
	t22 = (t1+t2)*(t4+t5) - t11 - t33;

	t55 = t3*t6;

	t1 = t1 + t3;
	t4 = t4 + t6;

	t66 = t1*t4;
	t88 = t2*t5;
	t77 = (t1+t2)*(t4+t5) - t66 - t88;


	t66 = t66 - t11;
	t77 = t77 - t22;
 	t88 = t88 - t33;
	t66 = t66 - t55;

	
	t33 = t33 + t66;
	t44 = t77;
	t55 = t55 + t88;

	t11 = t11 - c[0];
	t22 = t22 - c[1];
	t33 = t33 - c[2];

	t11 = t11 - c[4];
	t22 = t22 - c[5];
	t33 = t33 - c[6];
	t44 = t44 - c[7];
	t55 = t55 - c[8];


	c[2] = c[2] + t11;
	c[3] = t22;
	c[4] = c[4] + t33;
	c[5] = c[5] + t44;
	c[6] = c[6] + t55;


	c[5] = c[5] << 3; 	c[6] = c[6] << 3;	c[7] = c[7] << 3;
	c[8] = c[8] << 3;

	c[0] = c[0] + c[5];	c[1] = c[1] + c[6];	c[2] = c[2] + c[7];
	c[3] = c[3] + c[8];

	
	carry = c[0]>>26;	d[0] = c[0] & 0x3FFFFFF;	c[1] = c[1]+carry;
	carry = c[1]>>26;	d[1] = c[1] & 0x3FFFFFF;	c[2] = c[2]+carry;
	carry = c[2]>>26;	d[2] = c[2] & 0x3FFFFFF;	c[3] = c[3]+carry;
	carry = c[3]>>26;	d[3] = c[3] & 0x3FFFFFF;	c[4] = c[4]+carry;
	carry = c[4]>>23;	d[4] = c[4] & 0x7FFFFF;		d[0] = d[0]+carry;
	carry = d[0]>>26;	d[0] = d[0] & 0x3FFFFFF;	d[1] = d[1]+carry;
}


void convertI2C(unsigned long int a_26[], unsigned char a_8[]){
	a_8[0] = (unsigned long int) (a_26[0]&0xFF);
	a_8[1] = (unsigned long int) ((a_26[0]>>8)&0xFF);
	a_8[2] = (unsigned long int) ((a_26[0]>>16)&0xFF);
	a_8[3] = (unsigned long int) ((a_26[0]>>24)&0x03);
	
	a_8[3] = a_8[3] | ((unsigned long int) (a_26[1]&0x3F)<<2);
	a_8[4] = (unsigned long int) ((a_26[1]>>6)&0xFF);
	a_8[5] = (unsigned long int) ((a_26[1]>>14)&0xFF);
	a_8[6] = (unsigned long int) ((a_26[1]>>22)&0x0F);
	
	a_8[6] = a_8[6] | ((unsigned long int) (a_26[2]&0x0F)<<4);
	a_8[7] = (unsigned long int) ((a_26[2]>>4)&0xFF);
	a_8[8] = (unsigned long int) ((a_26[2]>>12)&0xFF);
	a_8[9] = (unsigned long int) ((a_26[2]>>20)&0x3F);
	
	a_8[9] = a_8[9] | ((unsigned long int) (a_26[3]&0x03)<<6);
	a_8[10] = (unsigned long int) ((a_26[3]>>2)&0xFF);
	a_8[11] = (unsigned long int) ((a_26[3]>>10)&0xFF);
	a_8[12] = (unsigned long int) ((a_26[3]>>18)&0xFF);
	
	a_8[13] = (unsigned long int) (a_26[4]&0xFF);
	a_8[14] = (unsigned long int) ((a_26[4]>>8)&0xFF);
	a_8[15] = (unsigned long int) ((a_26[4]>>16)&0xFF);
}

void convertI2C_mult(unsigned long int a_26[], unsigned char a_8[]){
	a_8[0] = (unsigned long int) (a_26[0]&0xFF);
	a_8[1] = (unsigned long int) ((a_26[0]>>8)&0xFF);
	a_8[2] = (unsigned long int) ((a_26[0]>>16)&0xFF);
	a_8[3] = (unsigned long int) ((a_26[0]>>24)&0x03);
	
	a_8[3] = a_8[3] | ((unsigned long int) (a_26[1]&0x3F)<<2);
	a_8[4] = (unsigned long int) ((a_26[1]>>6)&0xFF);
	a_8[5] = (unsigned long int) ((a_26[1]>>14)&0xFF);
	a_8[6] = (unsigned long int) ((a_26[1]>>22)&0x0F);
	
	a_8[6] = a_8[6] | ((unsigned long int) (a_26[2]&0x0F)<<4);
	a_8[7] = (unsigned long int) ((a_26[2]>>4)&0xFF);
	a_8[8] = (unsigned long int) ((a_26[2]>>12)&0xFF);
	a_8[9] = (unsigned long int) ((a_26[2]>>20)&0x3F);
	
	a_8[9] = a_8[9] | ((unsigned long int) (a_26[3]&0x03)<<6);
	a_8[10] = (unsigned long int) ((a_26[3]>>2)&0xFF);
	a_8[11] = (unsigned long int) ((a_26[3]>>10)&0xFF);
	a_8[12] = (unsigned long int) ((a_26[3]>>18)&0xFF);
	
	a_8[13] = (unsigned long int) (a_26[4]&0xFF);
	a_8[14] = (unsigned long int) ((a_26[4]>>8)&0xFF);
	a_8[15] = (unsigned long int) ((a_26[4]>>16)&0xFF);
	a_8[16] = (unsigned long int) ((a_26[4]>>24)&0x03);
	
	a_8[16] = a_8[16] | ((unsigned long int) (a_26[5]&0x3F)<<2);
	a_8[17] = (unsigned long int) ((a_26[5]>>6)&0xFF);
	a_8[18] = (unsigned long int) ((a_26[5]>>14)&0xFF);
	a_8[19] = (unsigned long int) ((a_26[5]>>22)&0x0F);
	
	a_8[19] = a_8[19] | ((unsigned long int) (a_26[6]&0x0F)<<4);
	a_8[20] = (unsigned long int) ((a_26[6]>>4)&0xFF);
	a_8[21] = (unsigned long int) ((a_26[6]>>12)&0xFF);
	a_8[22] = (unsigned long int) ((a_26[6]>>20)&0x3F);
	
	a_8[22] = a_8[22] | ((unsigned long int) (a_26[7]&0x03)<<6);
	a_8[23] = (unsigned long int) ((a_26[7]>>2)&0xFF);
	a_8[24] = (unsigned long int) ((a_26[7]>>10)&0xFF);
	a_8[25] = (unsigned long int) ((a_26[7]>>18)&0xFF);
	
	a_8[26] = (unsigned long int) (a_26[8]&0xFF);
	a_8[27] = (unsigned long int) ((a_26[8]>>8)&0xFF);
	a_8[28] = (unsigned long int) ((a_26[8]>>16)&0xFF);
	a_8[29] = (unsigned long int) ((a_26[8]>>24)&0x03);
	
	a_8[29] = a_8[29] | ((unsigned long int) (a_26[9]&0x3F)<<2);
	a_8[30] = (unsigned long int) ((a_26[9]>>6)&0xFF);
	a_8[31] = (unsigned long int) ((a_26[9]>>14)&0x3F);
}


int main(){
	  //127-bit inputs
	unsigned char a_8[16] ={44, 42, 237, 16, 199, 240, 233, 138, 218, 153, 138, 174, 45, 112, 138, 73}; 

	unsigned char b_8[16]= {74, 167, 251, 243, 158, 232, 148, 93, 204, 15, 150, 248, 63, 119, 14, 15};

	unsigned long int a_26[5], b_26[5];
	unsigned long int addr_26[5];
	unsigned long int multr_26[5];

	unsigned char 	addr_8[16], multr_8[16];
	unsigned char a2_8[16], b2_8[16];


	convertC2I(a_8, a_26);
	printf("\n a_26 = ");
	for(int i=0;i<5;i++)
		printf("%lu ",a_26[i]);
	printf("\n");

	convertC2I(b_8, b_26);
	printf("\n b_26 = ");
	for(int i=0;i<5;i++)
		printf("%lu ",b_26[i]);
	printf("\n");

	convertI2C(a_26, a2_8);
	printf("\n a2_8 = ");
	for(int i=0;i<16;i++)
		printf("%u ",a2_8[i]);
	printf("\n");

	convertI2C(b_26, b2_8);
	printf("\n b2_8 = ");
	for(int i=0;i<16;i++)
		printf("%u ",b2_8[i]);
	printf("\n");

	add(a_26, b_26, addr_26);
	printf("\n addr_26 = ");
	for(int i=0;i<5;i++)
		printf("%lu ",addr_26[i]);
	printf("\n");
	convertI2C(addr_26, addr_8);
	printf("\n addr_8 = ");
	for(int i=0;i<16;i++)
		printf("%u ",addr_8[i]);
	printf("\n");


	
	mult(a_26, b_26, multr_26);
	printf("\n multr_26 = ");
	for(int i=0;i<5;i++)
		printf("%lu ",multr_26[i]);
	printf("\n");
	convertI2C(multr_26, multr_8);
	printf("\n multr_8 = ");
	for(int i=0;i<16;i++)
		printf("%u ",multr_8[i]);
	printf("\n");


	return 0;
}
