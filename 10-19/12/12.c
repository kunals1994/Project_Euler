#include <stdio.h>
#include <math.h>

int num_divisors(long int);

int main (int argc, char** argv){
	long int curr_natural = 1;
	long int triangle = curr_natural;

	while(num_divisors(triangle) < 500){
		curr_natural += 1;
		triangle += curr_natural;
	}

	printf("%ld\n", triangle);

}

int num_divisors(long int n){
	long int sq_n = sqrt(n);
	int count = 0;
	if(sq_n * sq_n == n){
		count += 1;
	}
	for (int curr = 1; curr < sq_n; curr++){
		if(n % curr == 0){
			count +=2;
		}
	}

	return count;
}