#include <stdio.h>
#include <math.h>

#define TRUE 0
#define FALSE 1
#define INPUT 600851475143

long int find_largest_pf(long int);
long int is_prime(long int);

int main(int argc, char** argv){
	long int out; 

	out = find_largest_pf(INPUT);

	printf("%li\n", out);
}

long int is_prime (long int n){
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

long int find_largest_pf (long int num_in){
	long int curr; 

	curr = ((long int) sqrt(num_in))+1;

	while(curr > 0){
		if( num_in % curr == 0  &&  (is_prime(curr)) == TRUE){
			return curr;
		}
		curr -= 1;
	}

	printf("The input number is prime\n");
	return -1;

}
