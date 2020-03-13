#include<iostream>
#include<cmath>

double myExpMinus( double x);

int main ( void )
{
  std::cout.precision(16);
  std::cout.setf(std::ios::scientific);
  double x = 0.1;
  for ( double x = 0.0; x <= 10.12312; x+= 0.1){
    std::cout << x << "\t" << myExpMinus(x) << "\t" << std::exp(-x) << "\n";
  }
}

double myExpMinus( double x)
{
  double term = 1;
  double sum = 1;
  double eps = 1.0e-08;
  double i = 1;

  while (std::fabs(term/sum)> eps)
    {
      term = -term*x/i;
      sum = sum + term;
      i+=1;
    }
  return sum;
}
