#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <pthread.h>

// #include <sys/sysinfo.h>

// void printProcessors() {
//     printf("This system has %d processors\n", get_nprocs_conf());
// }


int cmpfnc(const void* a, const void* b) { 
    const char* aa = (const char*)a;
    const char* bb = (const char*)b;
    return strcmp(aa, bb);
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("No amount of threads specified\n");
        return(0);
    } else if (argc == 2) {
        printf("No input file specifed\n");
        return(0);
    }
    int nThreads = atoi(argv[1]);
    // printProcessors();
   
    // Open file, create pointer and find size
    FILE* fd = fopen(argv[2], "rw"); 
    int fp = open(argv[2], O_RDWR, (mode_t)0600); 
    fseek(fd, 0 , SEEK_END); 
    int filesize = ftell(fd);
    
    // Create memory map, find size of str in mmap
    char *map = mmap(0, filesize, PROT_READ | PROT_WRITE, MAP_SHARED, fp, 0);
    size_t strings_len = sizeof(map) / sizeof(char *); 

    printf("Sort starting....\n");
    
    // Determine chunk size
    int chunkSize = (int) (sizeof(map) / nThreads);
    if (chunkSize * nThreads < sizeof(map)) {
        ++chunkSize;
    }
    printf("%i\n", nThreads);
    for (int i = 0; i < nThreads; i++) {
        int start = i * chunkSize;
        int end = start + chunkSize - 1;
        if (i == nThreads - 1) {
            end =  - 1;
        }
        
        for (int i = start; i <= end; i++) {
            printf("%d", map[i]);
        }
            printf("\n");
}

    // Create threads
    pthread_t threads[nThreads];
    // for(int i = 0; i<nThreads; i++) {
    //     pthread_create (&threads[i], NULL , &thread_function, NULL);
    // } 


    qsort(map, strings_len, sizeof(char *), cmpfnc);
    // for (int i = 0; i < filesize; i++) {
    //     printf("%i\n", map[i]);
    // }
}