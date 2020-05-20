#include <iostream>
#include <Eigen/Dense>
 
int main()
{
  Eigen::MatrixXd m(8,8);
  std::cout << m << std::endl;
  for(int i = 0; i<8;i++){
    for (int j= 0; j<8;j++){
	m(i,j)=i+j;
      }
    }
  std::cout << m << std::endl;
}
