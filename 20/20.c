#include <stdio.h>
#include <stdlib.h>
#define BASE 10

int digit_sum(int);
int digit_sum_times_x(int,int);

int main (int argc, char** argv){
	if(argc < 2){
		printf("Usage %s integer\n", argv[0]);
		return 1;
	}

	int n_input = atoi(argv[1]);

	int digit_sum = 1;
	for (int curr = 1; curr <= n_input; curr++){
		digit_sum = digit_sum_times_x(digit_sum, curr);
	}

	printf("%d\n", digit_sum);

	return 0;
}

int digit_sum_times_x(int d_sum, int x){
	while((x % 10) == 0){
		x /= 10;
	}
	return digit_sum(d_sum * digit_sum(x));
}

int digit_sum(int n){
	int digit_sum = 0;
	while(n > 0){
		digit_sum += n % 10;
		n /= 10;
	}

	return digit_sum;
}
