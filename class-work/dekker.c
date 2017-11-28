#include <pthread.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef int bool;
#define true 1
#define false 0

void *d1_add(void *x) {
	int *test = (int *) x;

	bool enter = true;
	bool turn = true;
	while (enter) {
		if (!turn) {
			enter = false;
			while (!turn) {
				printf("%s\n", "Waiting for p2 to fininsh...");
				sleep(100);
			}
		}
		printf("%s\n", "P1 - CRITICAL SECTION, accessing memory");
		test = 2;
		turn = false;
		printf("%s\n", "Exiting critical section");
	}
}

void *d2_add(void *x) {
	int *test = (int *) x;

	bool enter = true;
	bool turn = false;
	while (enter) {
		if (!turn) {
			enter = false;
			while (!turn) {
				printf("%s\n", "Waiting for p1 to fininsh...");
				sleep(100);
			}
		}
		printf("%s\n", "P2 - CRITICAL SECTION, accessing memory");
		test = 5;
		turn = false;
		printf("%s\n", "Exiting critical section");
	}
}

int main() {
	pthread_t d1;
	pthread_t d2;

	int test = 0; //values to test on

	printf("%s\n", "Creating threads");

	bool flag = true;
	while(flag) {
		pthread_create(&d1, NULL, &d1_add, (void*)test);
		pthread_create(&d2, NULL, &d2_add, (void*)test);
		printf("%s\n", "Executing threads..." );
		pthread_join(d1, NULL);
		pthread_join(d2, NULL);
		flag = false;
	}

	printf("%s\n", "Both threads executed" );
	return 0;
}