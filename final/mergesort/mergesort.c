#include <stdio.h>
#include <sys/sysinfo.h>

void printProcessors() {
    printf("This system has %d processors\n", get_nprocs_conf());
}

int main() {
    printProcessors();
}
