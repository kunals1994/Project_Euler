#include <stdio.h>

int main (int argc, char** argv){
	int sum = 0;
	int curr;
	int prev;
	int temp_curr;
	int temp;
 
	prev = 1;
	curr = 2; 

	while (curr < 4000000){
		sum += curr;
		temp_curr = curr; 

		while (curr %2 != 0 || temp_curr == curr){
			temp = curr;
			curr = prev + curr;
			prev = temp;
		}
	}

	printf("%d\n", sum);

	return sum;
}


