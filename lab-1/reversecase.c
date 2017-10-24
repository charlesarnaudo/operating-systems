#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <fcntl.h> 
#include <unistd.h> 

/**
Note: The code at this linked was used as an examples on how to use pipes. 
	  https://www.cs.rutgers.edu/~pxk/416/notes/c-tutorials/pipe.html
**/

void reversecase(char *str) {
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] += 32;
		} else {
			str[i] -= 32;
		}
	}
}

int main() {
	int fd[2];
	int pid;
	char str[128];

	printf("Please enter a string to reverse the caser of: ");
	scanf("%s", str);
	
	pipe(fd);

	pid = fork();

	if (pid < 0) {
		printf("Could not create process");
		exit(0);
	} else if (pid == 0) {
		printf("Child process created, writing to process\n");
		close(fd[0]);
		reversecase(str);
		write(fd[0], str, (strlen(str) + 1));
		printf("%s\n", str);
		exit(0);
	} else {
		printf("Child working\n");
		wait(0);
		printf("Child finished\n");
	}
}