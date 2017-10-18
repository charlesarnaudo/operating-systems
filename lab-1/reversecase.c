#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <fcntl.h> 
#include <unistd.h> 

/**
Note: The code at this linked was used as an examples pipes. 
	  https://www.cs.rutgers.edu/~pxk/416/notes/c-tutorials/pipe.html
**/

// char reversecase(char *str) {
// 	char str[100] = str;
// 
// }

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
		printf("Child process created");
		// reversecase()
	} else {
		printf("Child working\n");
		wait(0);
		printf("Child finished\n");
	}
//
//	char buf[1025];
//	char *data = "hello... this is sample data";
//
//	pipe(fd);
//	write(fd[1], data, strlen(data));
//	if ((int n = read(fd[0], buf, 1024)) >= 0) {
//		buf[n] = 0;	/* terminate the string */
//		printf("read %d bytes from the pipe: \"%s\"\n", n, buf);
//	}	
//	else
//		perror("read");
//	exit(0);

//	int fd[2];
//	int pid;
//	char parent[100]; child[100], string[100];
//
//	printf("Enter string to reverse case on: ");
//    scanf("%s", string);
//  
//	pipe(fd);
//	pid = fork();
//
//	if (pid == -1) {
//		printf("Child process could not be created\n");
//		return 0;
//	} else if (pid == -0) {
//		close(fd[0]);
//		printf("Child side closed\n");
//		pid = getpid();
//		printf("Child(%d): Recieved Message\n\nChild(%d): Toggling Case and Sending to Parent\n",pid, pid);
//
//		
//		write(fd[1], input, (strlen(string)+1));
//        exit(0);
//	} else {
//		close(fd[1]);
//		printf("Parent process pipe closed\n");
//	}
}