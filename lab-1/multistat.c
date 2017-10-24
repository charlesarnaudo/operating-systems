#include <pthread.h>
#include<stdio.h>

struct Res
{
  double ave;
  int min;
  int max;
}Res;
int size = 0;

void *findAve(void *x)
{
  int *val_x = (int *) x;
  int sum = 0;
  for(int i = 0; i < size; i++)
  {
    sum += val_x[i];
  }
  
  Res.ave = (double)sum / size;

  pthread_exit(0);
}

void *findMax(void *x)
{
  int *val_x = (int *) x;
  int max = val_x[0];
  for(int i = 0; i < size; i++)
  {
    if(max - val_x[i] < 0)
    {
      max = val_x[i];
    }
  }
  Res.max = max;
  pthread_exit(0);
}

void *findMin(void *x)
{
  int *val_x = (int *) x;
  int min = val_x[0];
  for(int i = 0; i < size; i++)
  {
    if(min - val_x[i] > 0)
    {
      min = val_x[i];
    }
  }
  Res.min = min;
  pthread_exit(0);
}

int main()
{
  printf("Enter amount of numbers for data set\n");
  scanf("%d",&size);
  int nums[size];
  
  printf("enter numbers by pressing enter between entries\n");
  for(int i=0; i<size; i++)
  {
    scanf("\n%d",&nums[i]);
  }
  
  pthread_t findAve_thr;
  pthread_create(&findAve_thr, NULL, findAve, (void*)nums);
  
  pthread_t findMin_thr;
  pthread_create(&findMin_thr, NULL, findMin, (void*)nums);

  pthread_t findMax_thr;
  pthread_create(&findMax_thr, NULL, findMax, (void*)nums);


  pthread_join(findAve_thr,NULL);
  pthread_join(findMin_thr,NULL);
  pthread_join(findMax_thr,NULL);

  printf("\nThe Average is:%lf",Res.ave);
  printf("\nThe Min is:%d",Res.min);
  printf("\nThe Max is:%d\n",Res.max);
  
  return 0;
}