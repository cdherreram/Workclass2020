#include<iostream>
#include<cmath>

typedef double REAL;

REAL sum1 (int N);
REAL sum2 (int N);
REAL sum3 (int N);

int main(void  )
{
  std::cout.precision(16);
  std::cout.setf(std::ios::scientific);
    for(int N = 10; N <= 100; N++){
      double suma3 = sum3(N);
      double suma1 = sum1(N);
      double suma2 = sum2(N);
      double delta1 = std::fabs((suma3-suma2)/suma3);
      double delta2 = std::fabs((suma3-suma1)/suma3);
      std::cout << N << "\t" <<delta1 << "\t" << delta2 << std::endl;
    }
    return 0;
}

REAL sum1 (int N)
{
  REAL sum = 0;
  int sign = -1;
  for ( int i = 1; i <= 2*N ; i++)
    {
      sum += sign*1.0*i/(i+1);
      sign *= -1;
    }
  return sum;
}

REAL sum2(int N)
{
  REAL sum = 0;
  REAL sumP = 0;
  REAL sumN = 0;
  for(int n = 1; n <= N; n++)
    {
      sumP +=2.0*n/(2*n+1);
      sumN +=((2.0*n)-1.0)/(2*n);
      sum = sumP- sumN;
    }
  return sum;
}

REAL sum3 (int N )
{
  REAL sum = 0;
  for (int n =1 ; n <= N; n++)
    {
      sum += 1.0/((2*n)*(2*n+1));
    }
  return sum;
}

