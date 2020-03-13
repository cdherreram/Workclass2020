#include<iostream>
#include<cmath>

void sumaArmonica (int i, int N);

int main ( void )
{
  int i = 1, N = 1000;
  std::cout << "#N \t suma " << std::endl; 
  sumaArmonica(i,N);
  return 0;
}

void sumaArmonica (int i, int N){
  double suma = 0;
  //Se asume que i>0 y que i<=N de inicio
  for(i;i<=N;i++){
    suma = suma + pow(i,-1);
    std::cout << i << "\t" << suma << std::endl;
  }
}
