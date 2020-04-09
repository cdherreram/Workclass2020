#include<iostream>
#include<cmath>
//#include<array> //usar librerias mas seguras
                //también se puede usar valgrind
                // también desde el compilador -fsanitize=address

double f(int & c);

int main (void)
{
  int a = 6;
  int b = a;
  b = 8;

  f(b);

  int array[5] = {-1};
  array[5] = -8;
  array[15] = -8;

  std::cout << array[5] << "\n";
  
  return 0;
}

double f(int & c){
  c = 2*c;
  return std::sin(c);
}
