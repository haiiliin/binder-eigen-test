bindings:
	binder \
		--root-module bindings \
		--prefix bindings \
		--include-pybind11-stl \
		--annotate-includes \
		--skip-line-number \
		--suppress-errors \
		--config binder.config \
		  binder_includes.hpp \
		-- \
		-std=c++11 \
		-Iinclude \
		-Ieigen
