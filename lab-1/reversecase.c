#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>

char reversecase(char *str) {

}

int main() {
	int fd[2];
	int pid;
	char parent[100]; child[100], string[100];

	printf("Enter string to reverse case on: ");
    scanf("%s", string);
  
	pipe(fd);
	pid = fork();

	if (pid == -1) {
		printf("Child process could not be created\n");
		return 0;
	} else if (pid == -0) {
		close(fd[0]);
		printf("Child side closed\n");
		pid = getpid();
		printf("Child(%d): Recieved Message\n\nChild(%d): Toggling Case and Sending to Parent\n",pid, pid);

		
		write(fd[1], input, (strlen(string)+1));
        exit(0);
	} else {
		close(fd[1]);
		printf("Parent process pipe closed\n");
	}
}