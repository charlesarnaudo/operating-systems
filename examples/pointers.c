#include<stdio.h>

int main() {
  int n = 20;
  int *pntr = n;
  int a = pntr;
  
  printf("Address of n: %x\n", &n);
  printf("Address of pntr: %x\n", a);
  return 0;
}
