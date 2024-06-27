#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <binder-eigen.hpp>  // EigenTest::Bar
#include <binder-eigen.hpp>  // EigenTest::foo_eigen_argument_and_return_function
#include <binder-eigen.hpp>  // EigenTest::foo_eigen_argument_function
#include <binder-eigen.hpp>  // EigenTest::foo_eigen_return_function
#include <functional>
#include <sstream>  // __str__
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
#define BINDER_PYBIND11_TYPE_CASTER
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>, false)
PYBIND11_DECLARE_HOLDER_TYPE(T, T *, false)
PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_bindereigen(std::function<pybind11::module &(std::string const &namespace_)> &M) {
    // EigenTest::foo_eigen_argument_function(const class Eigen::Matrix<float, 3, 3, 0, 3, 3> &) file:binder-eigen.hpp
    // line:
    M("EigenTest")
        .def("foo_eigen_argument_function",
             (void (*)(const class Eigen::Matrix<float, 3, 3, 0, 3, 3> &)) &
                 EigenTest::foo_eigen_argument_function<float>,
             "C++: EigenTest::foo_eigen_argument_function(const class Eigen::Matrix<float, 3, 3, 0, 3, 3> &) --> void",
             pybind11::arg("m"));

    // EigenTest::foo_eigen_argument_function(const class Eigen::Matrix<double, 3, 3, 0, 3, 3> &) file:binder-eigen.hpp
    // line:
    M("EigenTest")
        .def("foo_eigen_argument_function",
             (void (*)(const class Eigen::Matrix<double, 3, 3, 0, 3, 3> &)) &
                 EigenTest::foo_eigen_argument_function<double>,
             "C++: EigenTest::foo_eigen_argument_function(const class Eigen::Matrix<double, 3, 3, 0, 3, 3> &) --> void",
             pybind11::arg("m"));

    // EigenTest::foo_eigen_return_function() file:binder-eigen.hpp line:
    M("EigenTest")
        .def("foo_eigen_return_function",
             (class Eigen::Matrix<float, 3, 3, 0, 3, 3>(*)()) & EigenTest::foo_eigen_return_function<float>,
             "C++: EigenTest::foo_eigen_return_function() --> class Eigen::Matrix<float, 3, 3, 0, 3, 3>");

    // EigenTest::foo_eigen_return_function() file:binder-eigen.hpp line:
    M("EigenTest")
        .def("foo_eigen_return_function",
             (class Eigen::Matrix<double, 3, 3, 0, 3, 3>(*)()) & EigenTest::foo_eigen_return_function<double>,
             "C++: EigenTest::foo_eigen_return_function() --> class Eigen::Matrix<double, 3, 3, 0, 3, 3>");

    // EigenTest::foo_eigen_argument_and_return_function(const class Eigen::Matrix<float, 3, 3, 0, 3, 3> &)
    // file:binder-eigen.hpp line:
    M("EigenTest")
        .def("foo_eigen_argument_and_return_function",
             (class Eigen::Matrix<float, 3, 3, 0, 3, 3>(*)(const class Eigen::Matrix<float, 3, 3, 0, 3, 3> &)) &
                 EigenTest::foo_eigen_argument_and_return_function<float>,
             "C++: EigenTest::foo_eigen_argument_and_return_function(const class Eigen::Matrix<float, 3, 3, 0, 3, 3> "
             "&) --> class Eigen::Matrix<float, 3, 3, 0, 3, 3>",
             pybind11::arg("m"));

    // EigenTest::foo_eigen_argument_and_return_function(const class Eigen::Matrix<double, 3, 3, 0, 3, 3> &)
    // file:binder-eigen.hpp line:
    M("EigenTest")
        .def("foo_eigen_argument_and_return_function",
             (class Eigen::Matrix<double, 3, 3, 0, 3, 3>(*)(const class Eigen::Matrix<double, 3, 3, 0, 3, 3> &)) &
                 EigenTest::foo_eigen_argument_and_return_function<double>,
             "C++: EigenTest::foo_eigen_argument_and_return_function(const class Eigen::Matrix<double, 3, 3, 0, 3, 3> "
             "&) --> class Eigen::Matrix<double, 3, 3, 0, 3, 3>",
             pybind11::arg("m"));

    {  // EigenTest::Bar file:binder-eigen.hpp line:
        pybind11::class_<EigenTest::Bar<float>, std::shared_ptr<EigenTest::Bar<float>>> cl(M("EigenTest"),
                                                                                           "Bar_float_t", "");
        cl.def(pybind11::init([]() { return new EigenTest::Bar<float>(); }));
        cl.def_readwrite("eigen_property", &EigenTest::Bar<float>::eigen_property);
        cl.def("foo_eigen_argument_method",
               (void(EigenTest::Bar<float>::*)(const class Eigen::Matrix<float, 3, 3, 0, 3, 3> &)) &
                   EigenTest::Bar<float>::foo_eigen_argument_method,
               "C++: EigenTest::Bar<float>::foo_eigen_argument_method(const class Eigen::Matrix<float, 3, 3, 0, 3, 3> "
               "&) --> void",
               pybind11::arg("m"));
        cl.def("foo_eigen_return_method",
               (class Eigen::Matrix<float, 3, 3, 0, 3, 3>(EigenTest::Bar<float>::*)()) &
                   EigenTest::Bar<float>::foo_eigen_return_method,
               "C++: EigenTest::Bar<float>::foo_eigen_return_method() --> class Eigen::Matrix<float, 3, 3, 0, 3, 3>");
        cl.def("foo_eigen_argument_and_return_method",
               (class Eigen::Matrix<float, 3, 3, 0, 3, 3>(EigenTest::Bar<float>::*)(
                   const class Eigen::Matrix<float, 3, 3, 0, 3, 3> &)) &
                   EigenTest::Bar<float>::foo_eigen_argument_and_return_method,
               "C++: EigenTest::Bar<float>::foo_eigen_argument_and_return_method(const class Eigen::Matrix<float, 3, "
               "3, 0, 3, 3> &) --> class Eigen::Matrix<float, 3, 3, 0, 3, 3>",
               pybind11::arg("m"));
        cl.def_static("foo_eigen_argument_method_static",
                      (void (*)(const class Eigen::Matrix<float, 3, 3, 0, 3, 3> &)) &
                          EigenTest::Bar<float>::foo_eigen_argument_method_static,
                      "C++: EigenTest::Bar<float>::foo_eigen_argument_method_static(const class Eigen::Matrix<float, "
                      "3, 3, 0, 3, 3> &) --> void",
                      pybind11::arg("m"));
        cl.def_static(
            "foo_eigen_return_method_static",
            (class Eigen::Matrix<float, 3, 3, 0, 3, 3>(*)()) & EigenTest::Bar<float>::foo_eigen_return_method_static,
            "C++: EigenTest::Bar<float>::foo_eigen_return_method_static() --> class Eigen::Matrix<float, 3, 3, 0, 3, "
            "3>");
        cl.def_static(
            "foo_eigen_argument_and_return_method_static",
            (class Eigen::Matrix<float, 3, 3, 0, 3, 3>(*)(const class Eigen::Matrix<float, 3, 3, 0, 3, 3> &)) &
                EigenTest::Bar<float>::foo_eigen_argument_and_return_method_static,
            "C++: EigenTest::Bar<float>::foo_eigen_argument_and_return_method_static(const class Eigen::Matrix<float, "
            "3, 3, 0, 3, 3> &) --> class Eigen::Matrix<float, 3, 3, 0, 3, 3>",
            pybind11::arg("m"));
    }
    {  // EigenTest::Bar file:binder-eigen.hpp line:
        pybind11::class_<EigenTest::Bar<double>, std::shared_ptr<EigenTest::Bar<double>>> cl(M("EigenTest"),
                                                                                             "Bar_double_t", "");
        cl.def(pybind11::init([]() { return new EigenTest::Bar<double>(); }));
        cl.def_readwrite("eigen_property", &EigenTest::Bar<double>::eigen_property);
        cl.def("foo_eigen_argument_method",
               (void(EigenTest::Bar<double>::*)(const class Eigen::Matrix<double, 3, 3, 0, 3, 3> &)) &
                   EigenTest::Bar<double>::foo_eigen_argument_method,
               "C++: EigenTest::Bar<double>::foo_eigen_argument_method(const class Eigen::Matrix<double, 3, 3, 0, 3, "
               "3> &) --> void",
               pybind11::arg("m"));
        cl.def("foo_eigen_return_method",
               (class Eigen::Matrix<double, 3, 3, 0, 3, 3>(EigenTest::Bar<double>::*)()) &
                   EigenTest::Bar<double>::foo_eigen_return_method,
               "C++: EigenTest::Bar<double>::foo_eigen_return_method() --> class Eigen::Matrix<double, 3, 3, 0, 3, 3>");
        cl.def("foo_eigen_argument_and_return_method",
               (class Eigen::Matrix<double, 3, 3, 0, 3, 3>(EigenTest::Bar<double>::*)(
                   const class Eigen::Matrix<double, 3, 3, 0, 3, 3> &)) &
                   EigenTest::Bar<double>::foo_eigen_argument_and_return_method,
               "C++: EigenTest::Bar<double>::foo_eigen_argument_and_return_method(const class Eigen::Matrix<double, 3, "
               "3, 0, 3, 3> &) --> class Eigen::Matrix<double, 3, 3, 0, 3, 3>",
               pybind11::arg("m"));
        cl.def_static("foo_eigen_argument_method_static",
                      (void (*)(const class Eigen::Matrix<double, 3, 3, 0, 3, 3> &)) &
                          EigenTest::Bar<double>::foo_eigen_argument_method_static,
                      "C++: EigenTest::Bar<double>::foo_eigen_argument_method_static(const class Eigen::Matrix<double, "
                      "3, 3, 0, 3, 3> &) --> void",
                      pybind11::arg("m"));
        cl.def_static(
            "foo_eigen_return_method_static",
            (class Eigen::Matrix<double, 3, 3, 0, 3, 3>(*)()) & EigenTest::Bar<double>::foo_eigen_return_method_static,
            "C++: EigenTest::Bar<double>::foo_eigen_return_method_static() --> class Eigen::Matrix<double, 3, 3, 0, 3, "
            "3>");
        cl.def_static(
            "foo_eigen_argument_and_return_method_static",
            (class Eigen::Matrix<double, 3, 3, 0, 3, 3>(*)(const class Eigen::Matrix<double, 3, 3, 0, 3, 3> &)) &
                EigenTest::Bar<double>::foo_eigen_argument_and_return_method_static,
            "C++: EigenTest::Bar<double>::foo_eigen_argument_and_return_method_static(const class "
            "Eigen::Matrix<double, 3, 3, 0, 3, 3> &) --> class Eigen::Matrix<double, 3, 3, 0, 3, 3>",
            pybind11::arg("m"));
    }
}
