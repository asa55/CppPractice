
#include "../CppLibs/Eigen/eigen-3.3.7/Eigen/Dense"
#include <iostream>

int main()
{
    Eigen::MatrixXd A = Eigen::MatrixXd::Constant(5,2,1);
    std::cout
    << A.transpose()
    << std::endl;
}
