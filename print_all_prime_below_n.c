#include<math.h>
#include <stdio.h>
int main()
{
    int n,i,j,c=0;
    printf("Enter a number: \n");
    scanf("%d", &n);
    for (i = 2; i <=n; i++) 
    {
        for(j=2;j<=sqrt(i);j++)
        {
        	if (i % j == 0) 
        	{
          	c=1;	
            	break;
        	}
        }
        if(c==0)
      printf("%d\n", i);  
    }   
}
