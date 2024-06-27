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

void bind_unknown_unknown_1(std::function<pybind11::module &(std::string const &namespace_)> &M) {
    {  // Eigen::internal::constructor_without_unaligned_array_assert file: line:
        pybind11::class_<Eigen::internal::constructor_without_unaligned_array_assert,
                         std::shared_ptr<Eigen::internal::constructor_without_unaligned_array_assert>>
            cl(M("Eigen::internal"), "constructor_without_unaligned_array_assert", "");
        cl.def(pybind11::init([]() { return new Eigen::internal::constructor_without_unaligned_array_assert(); }));
        cl.def(pybind11::init([](Eigen::internal::constructor_without_unaligned_array_assert const &o) {
            return new Eigen::internal::constructor_without_unaligned_array_assert(o);
        }));
    }
}
