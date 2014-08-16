#include <stdio.h>
#include <math.h>


#define TRUE 0
#define FALSE 1

#define BELOW_NUM 2000000

int is_prime(long int n);

int main (int argc, char** argv){
	long int curr = 2;
	long int sum = 0;

        while(curr < BELOW_NUM){
                if(is_prime(curr) == TRUE){
                        sum += curr; 
                }
                curr += 1;
        }

        printf("The sum of all prime numbers below %d is %li\n", BELOW_NUM, sum);
}


/**
 * Prime-checking process from Problem # 3
**/
int is_prime (long int n){
        long int curr;
        long int sqrt_n;

        sqrt_n = ((long int)sqrt(n)) + 1;

        curr = 2;

        while(curr < sqrt_n && curr < n){
                if (n % curr == 0){
                        return FALSE;
                }
                curr += 1;
        }
        return TRUE;
}
