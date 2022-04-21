#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Initialise */
void CalcNumber(unsigned long number);
int isPrime(unsigned long number);

/* Functions*/

void CalcNumber(unsigned long number)
{
    unsigned long i = 1;
    unsigned long prime = 0;

    while(i != number)
    {
        i++;
        if(isPrime(i))
        {
            printf("prime: %lu\n", i);
            prime += i;
        }
    }

int isPrime(unsigned long number)
{
      int i, nb, count, test,limit;
      test = count = 0;
      nb = number;
      limit = sqrt(nb) + 1;

      if(nb == 2)
      {
          return 1;
      }

      if (nb % 2 == 0)
              test = 1;
      else{
          for (i = 3 ; i < limit && ! test; i+=2, count++)
            if (nb % i == 0)
              test = 1;
      }
      if (!test)
              return 1;
      else
              return 0;
}

int main(void)
{
    unsigned long number;

    printf("Enter a number: \n");
    scanf("%ul", &number );
    CalcNumber(number);
    return EXIT_SUCCESS;
}
