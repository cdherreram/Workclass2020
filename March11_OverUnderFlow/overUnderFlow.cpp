#include<iostream>
#include<cmath>
#include<cstdlib>

int main ( int argc, char **argv) //automatiza para indicar desde consola el numero N
{
  std::cout.precision(16); std::cout.setf(std::ios::scientific);
  double under = 1.0, over = 1.0;
  
  const int N = std::atoi(argv[1]); //funcion atoi convierte string en integer, atof convierte string en double

  std::cout << "N \t under  \t\t\t\t  over" << std::endl;
  for(int i = 0; i<N; i++){
    under /= 2.;
    over *= 2.;
    std::cout << i << "\t" <<  under << "\t\t\t\t" << over << std::endl;
  }
}
