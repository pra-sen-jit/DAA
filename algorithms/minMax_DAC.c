#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int max, min;
void findMaxMin(int arr[], int low, int high)
{
  int max1, min1, max2, min2, mid;
  if(low == high)
    max = min = arr[low];
  else if(high == low + 1)
  {
    if(arr[low] > arr[high])
    {
      min = arr[high];
      max = arr[low];
    }
    else
    {
      min = arr[low];
      max = arr[high];
    }
  }
  else
  {
    mid = (low + high) / 2;
    findMaxMin(arr, low, mid);
    max1 = max;
    min1 = min;
    findMaxMin(arr, mid + 1, high);
    max2 = max;
    min2 = min;
    min = (min1 < min2) ? min1 : min2;
    max = (max1 > max2) ? max1 : max2;
  }
}

void printArray(int arr[], int size)
{
  for(int i = 0; i < size; i++)
    printf("%d\t", arr[i]);
  printf("\n");
}

int main()
{
  srand(time(NULL));
  clock_t start, end;
  double execTime;
  int i, n;
  printf("Enter the total number of integers : ");
  scanf("%d", &n);
  int arr[n];
  for(i = 0; i < n; i++)
    arr[i] = (int) rand() % 100 + 1;
  printf("Array of integers :\n");
  printArray(arr, n);
  start = clock();
  findMaxMin(arr, 0, n - 1);
  end = clock();
  printf("Minimum element = %d\n", min);
  printf("Maximum element = %d\n", max);
  execTime = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Execution time = %lf", execTime);
  return 0;
}