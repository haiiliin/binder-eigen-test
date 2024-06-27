#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <functional>
#include <sstream>  // __str__
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
#define BINDER_PYBIND11_TYPE_CASTER
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>, false)
PYBIND11_DECLARE_HOLDER_TYPE(T, T *, false)
PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_unknown_unknown(std::function<pybind11::module &(std::string const &namespace_)> &M) {
    {  // Eigen::Matrix file: line:
        pybind11::class_<Eigen::Matrix<float, 3, 3, 0, 3, 3>, std::shared_ptr<Eigen::Matrix<float, 3, 3, 0, 3, 3>>> cl(
            M("Eigen"), "Matrix_float_3_3_0_3_3_t", "");
        cl.def(pybind11::init([]() { return new Eigen::Matrix<float, 3, 3, 0, 3, 3>(); }));
        cl.def(pybind11::init<struct Eigen::internal::constructor_without_unaligned_array_assert>(), pybind11::arg(""));

        cl.def(pybind11::init<const float &, const float &, const float &>(), pybind11::arg("x"), pybind11::arg("y"),
               pybind11::arg("z"));

        cl.def(pybind11::init<const float &, const float &, const float &, const float &>(), pybind11::arg("x"),
               pybind11::arg("y"), pybind11::arg("z"), pybind11::arg("w"));

        cl.def(pybind11::init(
            [](Eigen::Matrix<float, 3, 3, 0, 3, 3> const &o) { return new Eigen::Matrix<float, 3, 3, 0, 3, 3>(o); }));

        pybind11::enum_<Eigen::Matrix<float, 3, 3, 0, 3, 3>::CompileTimeTraits>(cl, "CompileTimeTraits",
                                                                                pybind11::arithmetic(), "")
            .value("RowsAtCompileTime", Eigen::Matrix<float, 3, 3, 0, 3, 3>::RowsAtCompileTime)
            .value("ColsAtCompileTime", Eigen::Matrix<float, 3, 3, 0, 3, 3>::ColsAtCompileTime)
            .value("Flags", Eigen::Matrix<float, 3, 3, 0, 3, 3>::Flags)
            .value("SizeAtCompileTime", Eigen::Matrix<float, 3, 3, 0, 3, 3>::SizeAtCompileTime)
            .value("MaxSizeAtCompileTime", Eigen::Matrix<float, 3, 3, 0, 3, 3>::MaxSizeAtCompileTime)
            .value("IsVectorAtCompileTime", Eigen::Matrix<float, 3, 3, 0, 3, 3>::IsVectorAtCompileTime)
            .export_values();

        cl.def("assign",
               (class Eigen::Matrix<float, 3, 3, 0, 3, 3> &
                (Eigen::Matrix<float, 3, 3, 0, 3, 3>::*)(const class Eigen::Matrix<float, 3, 3, 0, 3, 3> &) const) &
                   Eigen::Matrix<float, 3, 3, 0, 3, 3>::operator=,
               "C++: Eigen::Matrix<float, 3, 3, 0, 3, 3>::operator=(const class Eigen::Matrix<float, 3, 3, 0, 3, 3> &) "
               "const --> class Eigen::Matrix<float, 3, 3, 0, 3, 3> &",
               pybind11::return_value_policy::automatic, pybind11::arg("other"));
        cl.def(
            "innerStride",
            (long(Eigen::Matrix<float, 3, 3, 0, 3, 3>::*)() const) & Eigen::Matrix<float, 3, 3, 0, 3, 3>::innerStride,
            "C++: Eigen::Matrix<float, 3, 3, 0, 3, 3>::innerStride() const --> long");
        cl.def(
            "outerStride",
            (long(Eigen::Matrix<float, 3, 3, 0, 3, 3>::*)() const) & Eigen::Matrix<float, 3, 3, 0, 3, 3>::outerStride,
            "C++: Eigen::Matrix<float, 3, 3, 0, 3, 3>::outerStride() const --> long");
    }
    {  // Eigen::Matrix file: line:
        pybind11::class_<Eigen::Matrix<double, 3, 3, 0, 3, 3>, std::shared_ptr<Eigen::Matrix<double, 3, 3, 0, 3, 3>>>
            cl(M("Eigen"), "Matrix_double_3_3_0_3_3_t", "");
        cl.def(pybind11::init([]() { return new Eigen::Matrix<double, 3, 3, 0, 3, 3>(); }));
        cl.def(pybind11::init<struct Eigen::internal::constructor_without_unaligned_array_assert>(), pybind11::arg(""));

        cl.def(pybind11::init<const double &, const double &, const double &>(), pybind11::arg("x"), pybind11::arg("y"),
               pybind11::arg("z"));

        cl.def(pybind11::init<const double &, const double &, const double &, const double &>(), pybind11::arg("x"),
               pybind11::arg("y"), pybind11::arg("z"), pybind11::arg("w"));

        cl.def(pybind11::init(
            [](Eigen::Matrix<double, 3, 3, 0, 3, 3> const &o) { return new Eigen::Matrix<double, 3, 3, 0, 3, 3>(o); }));

        pybind11::enum_<Eigen::Matrix<double, 3, 3, 0, 3, 3>::CompileTimeTraits>(cl, "CompileTimeTraits",
                                                                                 pybind11::arithmetic(), "")
            .value("RowsAtCompileTime", Eigen::Matrix<double, 3, 3, 0, 3, 3>::RowsAtCompileTime)
            .value("ColsAtCompileTime", Eigen::Matrix<double, 3, 3, 0, 3, 3>::ColsAtCompileTime)
            .value("Flags", Eigen::Matrix<double, 3, 3, 0, 3, 3>::Flags)
            .value("SizeAtCompileTime", Eigen::Matrix<double, 3, 3, 0, 3, 3>::SizeAtCompileTime)
            .value("MaxSizeAtCompileTime", Eigen::Matrix<double, 3, 3, 0, 3, 3>::MaxSizeAtCompileTime)
            .value("IsVectorAtCompileTime", Eigen::Matrix<double, 3, 3, 0, 3, 3>::IsVectorAtCompileTime)
            .export_values();

        cl.def("assign",
               (class Eigen::Matrix<double, 3, 3, 0, 3, 3> &
                (Eigen::Matrix<double, 3, 3, 0, 3, 3>::*)(const class Eigen::Matrix<double, 3, 3, 0, 3, 3> &) const) &
                   Eigen::Matrix<double, 3, 3, 0, 3, 3>::operator=,
               "C++: Eigen::Matrix<double, 3, 3, 0, 3, 3>::operator=(const class Eigen::Matrix<double, 3, 3, 0, 3, 3> "
               "&) const --> class Eigen::Matrix<double, 3, 3, 0, 3, 3> &",
               pybind11::return_value_policy::automatic, pybind11::arg("other"));
        cl.def(
            "innerStride",
            (long(Eigen::Matrix<double, 3, 3, 0, 3, 3>::*)() const) & Eigen::Matrix<double, 3, 3, 0, 3, 3>::innerStride,
            "C++: Eigen::Matrix<double, 3, 3, 0, 3, 3>::innerStride() const --> long");
        cl.def(
            "outerStride",
            (long(Eigen::Matrix<double, 3, 3, 0, 3, 3>::*)() const) & Eigen::Matrix<double, 3, 3, 0, 3, 3>::outerStride,
            "C++: Eigen::Matrix<double, 3, 3, 0, 3, 3>::outerStride() const --> long");
    }
}
