// 0/1 Knapsack problem using Dynamic Programming
// (Bottom-up approach)

#include <stdio.h>

int max(int a, int b)
{
  return (a > b) ? a : b;
}

int knapSack(int W, int wt[], int val[], int n)
{
  int i, w;
  int K[n + 1][W + 1];
  for(i = 0; i <= n; i++)
  {
    for(w = 0; w <= W; w++)
    {
      if(i == 0 || w == 0)
        K[i][w] = 0;
      else if(wt[i - 1] <= w)
        K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
      else  K[i][w] = K[i - 1][w];
    }
  }
  return K[n][W];
}

int main()
{
  int profit[] = {10, 40, 30, 50};
  int weight[] = {5, 4, 6, 3};
  int W = 10;
  int n = sizeof(profit) / sizeof(profit[0]);
  printf("%d", knapSack(W, weight, profit, n));
  return 0;
}