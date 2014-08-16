#include <stdio.h>
#include <stdlib.h>

int is_amicable(int);
int divisor_sum(int);

int main(int argc, char** argv){
	/*int sum = 0;
	for(int i = 1; i < 10000; i++){
		if(is_amicable(i)){
			sum += i;
		}
	}
	printf("The sum of all amicable numbers below 10000 is %d\n", sum);*/

	printf("%d\n", divisor_sum(220));
}

int is_amicable(int int_in){
	return divisor_sum(divisor_sum(int_in)) == int_in;
}

int divisor_sum(int int_in){
	int ret = 0;
	int* poss = malloc(sizeof(int) * (int_in - 1));
	for (int curr = 1; curr < int_in; curr++){
		printf("%d\n", ret);
		if(!poss[curr - 1]){
			if (int_in % curr == 0){
				ret += curr;
			}else{
				for (int inner = curr; inner < int_in; inner++){
					poss[inner - 1] = 1;
				}
			}
		}
	}
	free(poss);

	return ret;
}