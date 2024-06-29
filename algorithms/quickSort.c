#include <stdio.h>
#include <time.h>

void swap(int *a, int *b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int low, int high)
{
  int pivot = arr[high];
  int i = low - 1;

  for(int j = low; j <= high; j++)
  {
    if(arr[j] < pivot)
    {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return i + 1;
}

void quickSort(int arr[], int low, int high)
{
  if(low < high)
  {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
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
  clock_t start, end;
  double cpu_time_used;

  int arr[] = {4, 6, 2, 8, 3, 0, 4, 7, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  printf("Original array : \n");
  printArray(arr, n);

  start = clock();
  quickSort(arr, 0, n - 1);
  end = clock();

  printf("Array after sorting : \n");
  printArray(arr, n);
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time taken to execute the program is = %f", cpu_time_used);
  return 0;
}