#include <stdio.h>

int main (int argc, char* argv){
	int sum;
	int curr;

	sum = 0;

	for (curr = 0; curr < 1000; curr+=3){
		sum += curr;
	}

	for (curr = 0; curr < 1000; curr+=5){
		sum +=curr;
	}

	printf("%d\n", curr);

	return curr; 
}
