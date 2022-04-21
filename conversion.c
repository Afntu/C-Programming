#include<stdio.h>
int main()
{
	unsigned char a[11]={7, 70, 129, 150, 237, 128, 87, 217, 136, 130, 52};
	int i;
	
	for(i=0;i<11;i++)
        {
		printf("The %dth element of the array is %hhu\n",i,a[i]);
		//printf("\n");
	 }
	return 0;
}
