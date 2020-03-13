#include<iostream>
#include<cmath>

bool esPrimo(int a);

int main ( void ){
  int a = 500, b = 12100; //rango para encontrar los numeros primos
  int suma = 0, contador = 0;
  std::cout << "La cantidad de primos que hay entre " << a << " y " << b << " es ";
  for(a; a<=b;a++) {
    if (esPrimo(a)==true) suma = suma + a, contador++;
  }
  std::cout << contador << "\n";
  std::cout << "La suma de estos primos es " << suma << std::endl;
}

//funcion que determina si un numero es primo o no
bool esPrimo(int a)
{
  int contador = 0;
  for(int i = 1 ; i <= sqrt(a) ; i++ )
    {
      if(a%i==0) contador++;
      
      if(contador>2) return false;
    }
  return true;
}
