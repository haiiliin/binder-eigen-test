#include <pybind11/pybind11.h>

#include <algorithm>
#include <functional>
#include <map>
#include <memory>
#include <stdexcept>
#include <string>

using ModuleGetter = std::function<pybind11::module &(std::string const &)>;

void bind_unknown_unknown(std::function<pybind11::module &(std::string const &namespace_)> &M);
void bind_unknown_unknown_1(std::function<pybind11::module &(std::string const &namespace_)> &M);
void bind_bindereigen(std::function<pybind11::module &(std::string const &namespace_)> &M);

PYBIND11_MODULE(bindings, root_module) {
    root_module.doc() = "bindings module";

    std::map<std::string, pybind11::module> modules;
    ModuleGetter M = [&](std::string const &namespace_) -> pybind11::module & {
        auto it = modules.find(namespace_);
        if (it == modules.end())
            throw std::runtime_error("Attempt to access pybind11::module for namespace " + namespace_ +
                                     " before it was created!!!");
        return it->second;
    };

    modules[""] = root_module;

    static std::vector<std::string> const reserved_python_words{
        "nonlocal",
        "global",
    };

    auto mangle_namespace_name([](std::string const &ns) -> std::string {
        if (std::find(reserved_python_words.begin(), reserved_python_words.end(), ns) == reserved_python_words.end())
            return ns;
        return ns + '_';
    });

    std::vector<std::pair<std::string, std::string> > sub_modules{
        {"", "Eigen"},
        {"Eigen", "internal"},
        {"", "EigenTest"},
    };
    for (auto &p : sub_modules)
        modules[p.first.empty() ? p.second : p.first + "::" + p.second] =
            modules[p.first].def_submodule(mangle_namespace_name(p.second).c_str(),
                                           ("Bindings for " + p.first + "::" + p.second + " namespace").c_str());

    // pybind11::class_<std::shared_ptr<void>>(M(""), "_encapsulated_data_");

    bind_unknown_unknown(M);
    bind_unknown_unknown_1(M);
    bind_bindereigen(M);
}
