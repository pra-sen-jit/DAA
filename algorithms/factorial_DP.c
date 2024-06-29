#include <stdio.h>

unsigned long long fact(int n)
{
  unsigned long long fac[n + 1];
  fac[0] = 1;

  for(int i = 1; i <= n; i++)
  {
    fac[i] = fac[i - 1] * i;
  }
  return fac[n];
}

int main()
{
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);
  if(n < 0)
    printf("Factorial is not defined for negative numbers\n");
  else
    printf("Factorial of %d is %llu\n", n, fact(n));
  return 0;
}