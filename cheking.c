#include<stdio.h>
 
int main()
{
	int x = 23,*ptr1,*ptr2,*ptr3;
	ptr1 = &x;
	ptr2 = &ptr1;
	ptr3 = &ptr2;
	printf("*ptr = %d\n",*ptr1);
	printf("&x = %ls\n",&x);
	printf("x = %d\n",x);
	printf("ptr = %p\n", ptr1);
	printf("ptr1 = %p\n", ptr1);
	printf("ptr2 = %p\n", ptr2);
	printf("ptr3 = %p\n", ptr3);
	printf("*(*(*(ptr))) = %d\n", *(*(*(ptr3))));
	printf("*(&ptr) = %p\n",*(&ptr1));
	printf("&(*ptr) = %p",&(*ptr1));	
}
