#include <stdio.h>

int binomialCoeff(int n, int r) {
  int dp[n + 1][r + 1];
  for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= r && j <= i; j++) {
      if(j == 0 || j == i)
        dp[i][j] = 1;
      else
        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
    }
  }
  return dp[n][r];
}

int main()
{
  int n, r;
  printf("Enter values of n and r: \n");
  scanf("%d", &n);
  scanf("%d", &r);
  if(r > n)
    printf("Invalid input\n");
  else
    printf("The value of %dC%d is %d\n", n, r, binomialCoeff(n, r));
  return 0;
}