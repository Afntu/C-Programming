#include<stdio.h>
#include<stdlib.h>


int main(){
    int n, c=0, m, i, *r, j;
    printf("Enter the integer to convert into binary: ");
    scanf("%d", &n);
    m = n;
    while(m>0){
        m = m/2;
        c++;
    }
    m = n;
    j = c;
    r = (int *)malloc(c * (sizeof(int)));
    while(n>0){
        r[c] = n%2;
        n = n/2;
        c--;
    }
    printf("The binary representation of %d is: ",m);
    for(i=1; i<=j;i++) printf("%d", r[i]);
    
    return 0;
}

