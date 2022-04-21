#include <math.h>
#include <stdio.h>
int main()
{
    int n,i,c=0;
    printf("Enter a number: \n");
    scanf("%d", &n);
    for (i = 2; i <=sqrt(n); i++) 
    {
        if (n % i == 0) 
        {
          c=1;	
            break;
        }
    }
    if(c==1)
     printf("%d is not a prime number\n", n); 
    if(c==0)
      printf("%d is a prime number\n", n);    
}
