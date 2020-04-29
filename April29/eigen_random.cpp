#include <iostream>
#include <eigen3/Eigen/Dense>

int main(void)
{
  int SEED = 5; 
  srand(SEED);
  double trace = 0;
  int tam = 80;
  Eigen::MatrixXd m = Eigen::MatrixXd::Random(tam,tam);
  for(int i = 0; i<tam;i++){
    trace += std::fabs(m(i,i));
  }
  std::cout << trace << std::endl;
       
  return 0; 
}
