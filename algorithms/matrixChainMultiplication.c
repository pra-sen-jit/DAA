// Finding the minimum number of element (or scalar) multiplications
// needed for Matrix Chain Multiplication

#include <stdio.h>
#include <limits.h>
#include <time.h>

int MatrixChainOrder(int p[], int i, int j)
{
  if(i == j)
    return 0;
  int k, count, min = INT_MAX;

  for(k = i; k < j; k++)
  {
    count = MatrixChainOrder(p, i, k) + MatrixChainOrder(p, k + 1, j) + p[i - 1] * p[k] * p[j];
    if(count < min)
      min = count;
  }
  return min;
}

int main()
{
  clock_t start, end;
  double execTime;
  int n, i;
  printf("Enter the size of array : ");
  scanf("%d", &n);
  int arr[n];

  printf("Enter the elements :\n");
  for(i = 0; i < n; i++)
    scanf("%d", &arr[i]);
  
  start = clock();
  printf("Minimum number of multiplications is %d\n", MatrixChainOrder(arr, 1, n - 1));
  end = clock();

  execTime = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Execution time of the program = %f", execTime);
  return 0;
}