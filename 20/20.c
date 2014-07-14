/*Incomplete*/


#include <stdio.h>
#include <stdlib.h>

int digit_sum(long long int);
int digit_sum_times_x(int,int);

int main (int argc, char** argv){
	if(argc < 2){
		printf("Usage %s integer\n", argv[0]);
		return 1;
	}

	int n_input = atoi(argv[1]);
	long long int curr_sum = 1; 

	for (int curr = 2; curr <= n_input; curr++){
		curr_sum *= curr;
		printf("digit_sum(%d!) = %d\n", curr, digit_sum(curr));
	}

	return 0;
}

int digit_sum_times_x(int d_sum, int x){
	while((x % 10) == 0){
		x /= 10;
	}

	if(x == 1){
		return d_sum;
	}

	return digit_sum(d_sum * digit_sum(x));
}

int digit_sum(long long int n){
	while (n % 10 == 0){
		n /= 10;
	}

	if(n == 1){
		return 1;
	}

	return digit_sum(n - 1) + 1;
}
