#include <iostream>
#include <eigen3/Eigen/Dense>

int main()
{
  Eigen::MatrixXd A = Eigen::MatrixXd::Random(100,100);
  Eigen::VectorXd b = Eigen::VectorXd::Random(100);
  //std::cout << "Here is the matrix A:\n" << A << std::endl;
  //std::cout << "Here is the vector b:\n" << b << std::endl;
  Eigen::VectorXd x = A.fullPivHouseholderQr().solve(b);
  //std::cout << "The solution is:\n" << x << std::endl;
  std::cout << "Verification:\n" << (A*x - b).norm() << std::endl;
}
