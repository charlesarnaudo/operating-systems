#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int size = 0;

void* fibonacci(void *x) {
	int *fibo_store = (int *) x;

	for (int i = 2; i < size; i++) {
		fibo_store[i] = fibo_store[i - 1] + fibo_store[i - 2];
	}

	return(NULL);
}

int main() {
	while (size <= 1) {
		printf("How many fibonacci numbers would you like to generate? (Greater than 1) \n");
		scanf("%d", &size);
	}

	int fibo_store[size];
	fibo_store[0] = 0;
	fibo_store[1] = 1;

	pthread_t fibonacci_thread;
	pthread_create(&fibonacci_thread, NULL, fibonacci, (void*)fibo_store);
	pthread_join(fibonacci_thread, NULL);

	for (int i = 0; i < size; i++) {
		printf("%d ", fibo_store[i]);
	}

}