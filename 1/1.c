#include <stdio.h>

int main (int argc, char** argv){
	int sum;
	int curr;

	sum = 0;

	curr = 0;
	while (curr < 1000){
		sum += curr;
		curr += 3;
	}

	curr = 0;
	while (curr < 1000){
		sum += curr;
		curr +=5;
	}

	printf ("%d\n", sum);
	return curr; 
}
