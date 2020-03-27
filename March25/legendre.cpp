// entre -1 y 1 en pasos de 0.01 con n=5
#include<iostream>
#include<cmath>

int main (void)
{
  int n = 5;
  const double XMIN = -1.0, XMAX = 1.0 , DX = 0.01 ;
  std::cout.precision(15);
  std::cout.setf(std::ios::scientific);
  
  for( double x = XMIN; x<= XMAX; x+=DX)
    {
      std::cout << x << "\t" << std::legendre(n,x) << "\n";
    }
  
  return 0;
}
