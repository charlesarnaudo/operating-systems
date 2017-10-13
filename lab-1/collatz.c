#include <stdio.h>
#include <unistd.h> 
#include <sys/types.h>
#include <sys/wait.h>

int collatz(int num) {
	if (num % 2 == 0) {
		return (num / 2);
	}
	return ((3 * num) + 1);

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

	if (pid == 0) {
		while (result != 0) {
			if(result % 2 == 0) {
 				result /= 2;
			} else {
 				result = (3 * result) + 1;
			}
			printf("%d\n",result);
			printf("Child finished\n");
		}
	} else {
		printf("Parent working\n");
		wait();
		printf("Parent finished");
	}

}

	// while (result != 1) {
	// if(result % 2 == 0) {
    //  		result /= 2;
    // } else {
    //  		result = (3 * result) + 1;
    // }
	// 	printf("%d", result);
	// 	printf("\n");
	// }

	// while (result != 1) {
	// 	printf("%d", pid);
	// 	if (pid == 0) {
	// 		result = collatz(num);
	// 		printf("%d", result);
	// 	// } else if (pid > 0) {
	// 	// 	printf("%d", pid);
	// 	// 	printf("Waiting on parent process\n");
	// 	// 	wait(&status);
	// 	} else {
	// 		printf("Child creation not successful\n");
	// 		return 0;
	// 	}
	// }

	