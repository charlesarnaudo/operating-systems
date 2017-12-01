#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/sysinfo.h>

void printProcessors() {
    printf("This system has %d processors\n", get_nprocs_conf());
}

void createmmap(const char *filepath) {
    int fd = open(filepath, O_RDWR, (mode_t)0600);
    if (fd == -1) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }        
    struct stat fileInfo = {0};
    if (fstat(fd, &fileInfo) == -1) {
        perror("Error getting the file size");
        exit(EXIT_FAILURE);
    }
    if (fileInfo.st_size == 0) {
        fprintf(stderr, "Error: File is empty, nothing to do\n");
        exit(EXIT_FAILURE);
    }
    printf("File size is %ji\n", (intmax_t)fileInfo.st_size);
    
    char *map = mmap(0, fileInfo.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
} 

int main() {
    printProcessors();
    printf("How many threads would you like to sort with?\n");
    FILE* fd = fopen("data_128", "rw");
    int fp = open("data_128", O_RDWR, (mode_t)0600);    
    fseek(fd, 0 , SEEK_END);
    int filesize = ftell(fd);
    char *map = mmap(0, filesize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    printf("%d", map[1]);
    

}
