#include <iostream>
#include <eigen3/Eigen/Dense>
#include<eigen3/Eigen/StdVector>
#include <vector>

void print(std::vector<double> const &input)
{
  for (int i = 0; i < input.size(); i++) {
    std::cout << input.at(i) << ' ';
  }
}

int main(void)
{
  int SEED = 5; 
  srand(SEED);
  double trace = 0;
  int tam = 5;
  Eigen::MatrixXd m = Eigen::MatrixXd::Identity(tam,tam);
  for(int i = 0; i<tam;i++){
    trace += std::fabs(m(i,i));
  }

  std::cout << trace << std::endl;
  std::cout << m << std::endl << std::endl;
  Eigen::VectorXd k(tam);
  k = m.row(0);
  std::vector<double> v;
  v.resize(k.size());
  //v = Eigen::VectorXd::Map(&v[0],k.size());
  std::cout << v.size() << std::endl;
  print(v);
  
  //std::cout << v << std::endl;
  //std::cout << k.data() << std::endl;
       
  return 0; 
}
