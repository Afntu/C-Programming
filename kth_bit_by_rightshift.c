#include<stdio.h>
int right_shift(int a, int k)
{
    if(1 & (a>>k)) return 1;
    else return 0;
}

int main()
{
    int i, k, j;
    int a;
    printf("Enter the integer:");
    scanf("%d", &a);
    printf("Enter the bit between 0 to 31 you want: ");
    scanf("%d", &k);
    while(k>31 || k<0)
    {
        printf("Enter the bit between 0 to 31 which bit you want : ");
        scanf("%d", &k);
    }
    printf("The %d th bit is: %d",k, right_shift(a, k));
    return 0;
}
