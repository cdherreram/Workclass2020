#include<iostream>
#include<cmath>

double discriminante ( double a, double b, double c);
double raizPositiva1 ( double a, double b, double c, double disc);
double raizPositiva2 ( double a, double b, double c, double disc);
double raizNegativa1 ( double a, double b, double c, double disc);
double raizNegativa2 ( double a, double b, double c, double disc);


int main (void)
{
  std::cout.precision(16);
  std::cout.setf(std::ios::scientific);
  double a = 1, b = 1;
  double c;
  double disc;
  for ( int n = 2; n<30; ++n ){
    c = 1*pow(10,-n);
    disc = discriminante (a, b,c);
    std::cout << raizPositiva1(a,b,c,disc) << "\t" << raizPositiva2(a,b,c,disc) << "\t" << raizNegativa1(a,b,c,disc) << "\t" << raizNegativa2(a,b,c,disc) << std::endl;
  }
}

double discriminante ( double a, double b, double c)
{
  return b*b-4*a*c;
}

double raizPositiva1 ( double a, double b, double c, double disc)
{
  return (-b + std::sqrt(disc) ) / (2*a);
}

double raizPositiva2 ( double a, double b, double c, double disc)
{
  return (-2.0*c)/(b+std::sqrt(disc));
}

double raizNegativa1 ( double a, double b, double c, double disc)
{
    return (-b - std::sqrt(disc) ) / (2*a);
}

double raizNegativa2 ( double a, double b, double c, double disc)
{
  return (-2.0*c)/(b-std::sqrt(disc)); 
}
