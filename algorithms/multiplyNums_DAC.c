// Multiplying two integers using Divide-and-Conquer

#include <stdio.h>
#include <math.h>
#include <time.h>

long long multiply(long long a, long long b)
{
  if(a < 10 || b < 10)
    return a * b;
  int n = 0;
  long long temp = a;
  while(temp > 0)
  {
    n++;
    temp /= 10;
  }
  long long power, aL, aR, bL, bR, A, B, C, D;
  power = pow(10, n / 2);
  aL = a / power;
  aR = a % power;
  bL = b / power;
  bR = b % power;

  A = multiply(aL, bL);
  B = multiply(aL, bR);
  C = multiply(aR, bL);
  D = multiply(aR, bR);

  return (A * power * power) + ((B + C) * power) + D;
}

int main()
{
  clock_t start, end;
  double execTime;
  long long a, b, result;
  printf("Enter two numbers : ");
  scanf("%lld %lld", &a, &b);

  start = clock();
  result = multiply(a, b);
  end = clock();

  execTime = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Product of given numbers = %lld\n", result);
  printf("Execution time of the program = %f", execTime);

  return 0;
}