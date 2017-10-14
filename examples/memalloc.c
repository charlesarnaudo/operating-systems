#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

int main() {
  char *mem;
  mem = malloc( 15 * sizeof(char));

  if (mem == NULL) {
    printf("Couldn't allocate memory");
  } else {
    strcpy(mem,"Wentworth");
  }
  printf("Dynamically allocated memory content : %s\n", mem );
  free(mem);

}
