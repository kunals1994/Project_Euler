#include "13.h"
#include <stdio.h>

#define FIRST_X_DIGITS 10

int main (int argc, char** argv){
	long sum = 0;
	long upper_bound;




	for (int digit = 0; digit < FIRST_X_DIGITS + NUM_TO_ADD_MAG; digit++){
		for (int curr_number = 0; curr_number < NUM_TO_ADD; curr_number++){
			sum += (numbers_in[curr_number][digit] - '0');
		}
		sum *= 10;
	}

	upper_bound = 1;

	for (int x = 0; x < FIRST_X_DIGITS; x++){upper_bound *= 10;}

	while(sum > upper_bound){

		sum /= 10;
	}

	printf("%ld\n", sum);

}

