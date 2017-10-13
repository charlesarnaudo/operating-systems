#include <stdio.h>
#include <unistd.h> 
#include <sys/types.h>
#include <sys/wait.h>

int collatz(int num) {
	if (num % 2 == 0) {
		num = num / 2;
		return (num);
	} else {
		num = (3 * num) + 1;
		return (num);
	}
}

int main() {
	int num, pid, status;
	int result = 0;

	printf("Enter a number to perform the collatz conjecture on: ");
	num = scanf("%d", &num);

	if (num < 0) {
		printf("Please enter a number greater than 0\n");
		return 0;
	} 

	pid = fork();

	if (pid < 0) {
		printf("Child process could not be created\n");
		return 0;
	} else if (pid == 0) {
		result = num;
		do {
			result = collatz(result);
			printf("%d \n", result);
		} while (result != 1);
	} else {
		printf("Child working\n");
		wait(0);
		printf("Child finished\n");
	}
}