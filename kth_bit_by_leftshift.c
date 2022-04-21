#include <stdio.h>
int left_shift(int a, int k)
{
    if(a & (1<<k)) 
    return 1;
    else return 0;
}

int main()
{
    int i, k, j;
    int a;
    printf("Enter the number:");
    scanf("%d", &a);
    printf("Enter a bit between 0 to 31 : ");
    scanf("%d", &k);
    while(k>31 || k<0)
    {
        printf("Please enter the bit between 0 to 31 you want: ");
        scanf("%d", &k);
    }
    printf("The %dth bit is: %d",k,left_shift(a, k));
    return 0;
}
