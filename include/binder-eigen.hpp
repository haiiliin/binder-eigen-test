/// @file   include/binder-eigen.hpp
/// @brief  Binder test file for Eigen library
/// @author Hailin Wang

#ifndef BINDER_EIGEN_HPP
#define BINDER_EIGEN_HPP

#include <Eigen/Dense>

namespace EigenTest {

template <typename T>
void foo_eigen_argument_function(const Eigen::Matrix<T, 3, 3> &m) {}
template void foo_eigen_argument_function<float>(const Eigen::Matrix<float, 3, 3> &);
template void foo_eigen_argument_function<double>(const Eigen::Matrix<double, 3, 3> &);

template <typename T>
Eigen::Matrix<T, 3, 3> foo_eigen_return_function() {
    return Eigen::Matrix<T, 3, 3>::Identity();
}
template Eigen::Matrix<float, 3, 3> foo_eigen_return_function<float>();
template Eigen::Matrix<double, 3, 3> foo_eigen_return_function<double>();

template <typename T>
Eigen::Matrix<T, 3, 3> foo_eigen_argument_and_return_function(const Eigen::Matrix<T, 3, 3> &m) {
    return m;
}
template Eigen::Matrix<float, 3, 3> foo_eigen_argument_and_return_function<float>(const Eigen::Matrix<float, 3, 3> &);
template Eigen::Matrix<double, 3, 3> foo_eigen_argument_and_return_function<double>(
    const Eigen::Matrix<double, 3, 3> &);

template <typename T>
class Bar {
   public:
    Eigen::Matrix<T, 3, 3> eigen_property;
    void foo_eigen_argument_method(const Eigen::Matrix<T, 3, 3> &m) {}
    Eigen::Matrix<T, 3, 3> foo_eigen_return_method() { return Eigen::Matrix<T, 3, 3>::Identity(); }
    Eigen::Matrix<T, 3, 3> foo_eigen_argument_and_return_method(const Eigen::Matrix<T, 3, 3> &m) { return m; }

    static void foo_eigen_argument_method_static(const Eigen::Matrix<T, 3, 3> &m) {}
    static Eigen::Matrix<T, 3, 3> foo_eigen_return_method_static() { return Eigen::Matrix<T, 3, 3>::Identity(); }
    static Eigen::Matrix<T, 3, 3> foo_eigen_argument_and_return_method_static(const Eigen::Matrix<T, 3, 3> &m) {
        return m;
    }
};

template class Bar<float>;
template class Bar<double>;

}  // namespace EigenTest

#endif  // BINDER_EIGEN_HPP
