#include<iostream>
#include<cmath>
#include<tuple>

std::tuple<int, double> sumBad( double x, double eps);

int main (void)
{
  double x = 0.01;
  double eps = 1e-08;
  int contador;
  double sum;
  double err;
  
  while ( x < 0.5)
    {
      std::tie(contador, sum) < sumBad ( x, eps);
      err = fabs(sum-sin(x))/sin(x);
      std::cout << x << "\t" << contador << "\t" << sum << "\t" << err << std::endl;
      x+=0.01;
    }
  return 0;
}

std::tuple<int, double> sumBad( double x, double eps)
{
  double term = x;
  double error = eps;
  double sum = 0;
  int i = 3;
  int contador = 0;

  while ( fabs(term/sum) >= error){
    sum = sum + term;
    term = term*(-x*x)/i;
    i += 2;

    contador++;
  }
  return std::make_tuple(contador, sum);
}

  //double sumGood( double x )
