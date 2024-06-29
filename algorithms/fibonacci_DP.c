#include <stdio.h>

int fib(int n)
{
  int F[n + 1];
  int i;
  F[0] = 0;
  F[1] = 1;
  for(i = 2; i <= n; i++)
  {
    F[i] = F[i - 1] + F[i - 2];
  }
  return F[n];
}

int main()
{
  int n;
  printf("Enter the value of n : ");
  scanf("%d", &n);
  printf("%dth term of fibonacci series is %d", n, fib(n));
  return 0;
}