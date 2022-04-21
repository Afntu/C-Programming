//convert to hexadecimal
#include<stdio.h>
int main()
{
	unsigned int a;
	unsigned int b;
	unsigned char c[16];
	int i;
	
	a=23847238;
	b=0x16be146;
	print("%u\n",a-b);
	for(i=0;i<16;i++)
		{
		 c[i]=(unsigned char) (a & 15);
		 a=a>>4;
		}
        for(i=15;i>=0;i--)
        	printf("%hhu",c[i]);
        printf("\n");
        
        return 0;			
}
