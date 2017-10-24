#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// struct Point {
// 	int x;
// 	int y;
// }Point;
// 
// double res;
// 
// struct Point[size] getRand(int num) {
// 	
// }


int main() {
	printf("Enter the amount of points\n");
	//scanf("%d", &size);
	unsigned int rand_state = rand();
	double x = rand_r(&rand_state) / ((double)RAND_MAX + 1) * 2.0 - 1.0;
	printf("%d\n", x);

}