#include <stdio.h>
#define LOWER_BOUND 1
#define UPPER_BOUND 100

int main (int argc, char** argv){
	int curr;
	int sum_of_squares;
	int square_of_sum; 

	int diff;

	sum_of_squares = square_of_sum = 0;

	for (curr = LOWER_BOUND; curr <= UPPER_BOUND; curr ++){
		sum_of_squares += curr * curr;
		square_of_sum += curr;
	}

	square_of_sum *= square_of_sum;

	diff = square_of_sum - sum_of_squares; 

	printf("%d - %d = %d \n", square_of_sum, sum_of_squares, diff);


	return 0;

}