#include <iostream>
#include <Eigen/Dense>
 
int main()
{
  srand(0);
  Eigen::MatrixXd A = Eigen::MatrixXd::Random(20,20);
  Eigen::SelfAdjointEigenSolver<Eigen::MatrixXd> eigensolver(A);
  if (eigensolver.info() != Eigen::Success) abort();
  std::cout << "The eigenvalues of A are:\n" << eigensolver.eigenvalues() << std::endl;
}
