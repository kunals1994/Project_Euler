#include <stdio.h>

int is_amicable(int);
int divisor_sum(int);

int main(int argc, char** argv){
	int sum = 0;
	for(int i = 1; i <= 10000; i++){
		if (is_amicable(i)){
			sum += i;
		}
	}
	printf("The sum of all amicable numbers below 10000 is %d\n", sum);

}

int is_amicable(int int_in){
	int divis_sum = divisor_sum(int_in);
	return (divis_sum != int_in) && (divisor_sum(divis_sum) == int_in);
}

int divisor_sum(int int_in){
	int ret = 0;

	for (int curr = 1; curr < int_in; curr++){
		if (int_in % curr == 0){
			ret += curr;
		}
	}

	return ret;
}