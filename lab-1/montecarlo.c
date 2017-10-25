#include <pthread.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


double res;
int size;
int inCir;

void *numInCircle(void *x) {
  for (int i = 0; i < size; i++) {
    double x = (double)rand() / RAND_MAX;
    double y = (double)rand() / RAND_MAX;
    if ((x * x + y * y) <= 1) {
      inCir++;
    }
  }
}

int main() {
  srand(time(NULL));
  pthread_t monte;


  printf("Enter amount of points\n");
  scanf("%d", &size);

  pthread_create(&monte, NULL, &numInCircle, NULL);

  pthread_join(monte, NULL);

  double pi = (double)(4.0 * size) / inCir;
  printf("\napproximation of pi: %lf\n", pi);

  return 0;
}