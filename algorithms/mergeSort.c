#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int mid, int low, int high)
{
  int i, j, k;
  int n1 = mid - low + 1;
  int n2 = high - mid;
  int L[n1], R[n2];

  for (i = 0; i < n1; i++)
    L[i] = arr[low + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[mid + 1 + j];

  i = 0; j = 0; k = low;
  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
    }
    k++;
  }
  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }
  while (j < n2)
  {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int low, int high)
{
  if (low < high)
  {
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, mid, low, high);
  }
}

void printArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
    printf("%d\t", arr[i]);
  printf("\n");
}

int main()
{
  srand(time(NULL));
  clock_t start, end;
  double cputime;
  int n, i;
  printf("Enter the number of elements : ");
  scanf("%d", &n);
  int arr[n];
  for (i = 0; i < n; i++)
    arr[i] = (int) rand() % 9 + 1;
  printf("Original array :\n");
  printArray(arr, n);
  start = clock();
  mergeSort(arr, 0, n - 1);
  end = clock();
  printf("Sorted array :\n");
  printArray(arr, n);
  cputime = (double) (end - start) / CLOCKS_PER_SEC;
  printf("Time taken to execute the program = %f", cputime);
  return 0;
}