#include<iostream>

//Se compila con -fopenmp
//se usa export OMP_NUM_THREADS=2 para usar con 2 procesadores
int main(void){
#pragma omp paralell
{
  std::cout << "Hello world\n";
}
  return 0;
}
