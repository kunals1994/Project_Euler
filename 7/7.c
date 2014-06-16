#include <stdio.h>
#include <math.h>


#define TRUE 0
#define FALSE 1

#define NTH_PRIME 10001

int is_prime(long int n);

int main (int argc, char** argv){
	long int curr = 0;
	long int potential_prime = 2;

	while (curr < NTH_PRIME){
		if(is_prime(potential_prime) == TRUE){
			curr +=1;
		}
		potential_prime += 1;
	}

	printf("%li\n", (potential_prime - 1));

	return 0;
}


/**
 * Prime-checking process from Problem # 3
**/
int is_prime (long int n){
        long int curr;
        long int sqrt_n;

        sqrt_n = ((long int)sqrt(n)) + 1;

        curr = 2;

        while(curr < sqrt_n){
                if (n % curr == 0){
                        return FALSE;
                }
                curr += 1;
        }
        return TRUE;
}

