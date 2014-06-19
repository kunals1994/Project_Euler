/**
 *  Pythagorean triples can be generated, given 2 positive integers, x and y, where x > y.
 *	a = x^2 - y^2, b = 2 * x * y, c = x^2 + y^2
 *	a + b + c = 2 * x^2 + 2 * x * y
 *	a * b * c = 2 * x^5 * y - 2 * x * y^5
 *
 *	Since we're looking for a triplet with a sum of 1000, we can assume x and y both fall in the range [1,100].
 *	Given all this information, we can generate a relatively fast brute force solution, below. 
 */

#include <math.h>
#include <stdio.h>
#define TRUE 0
#define FALSE 1

int main (int argc, char** argv){
	for (int y = 1; y < 100; y++){
		for(int x = y + 1; x<100; x++){
			if (((2 * x * x) + (2 * x * y)) == 1000){
				printf("a * b * c =%10.0f\n", ((2 * pow(x, 5) * y) - (2 * x * pow(y, 5))));
				return 0;
			}
		}
	}
}