Copyright © 2015 Lénaïc Bagnères, hnc@singularity.fr <br />
https://github.com/Lnc/gho/tree/master <br />
http://hnc.toile-libre.org/index.php?section=dev&page=gho <br />
https://www.lri.fr/~bagneres/index.php?section=dev&page=gho

# hopp

Generic Header-Only C Library

Apache License, Version 2.0

### System Requirement

Required:
- C99 compiler

Optional:
- CMake build system

### Installation

###### With CMake

```sh
mkdir build
cd build
cmake .. # -DCMAKE_INSTALL_PREFIX=/path/to/install # -DDEBUG=TRUE
make
# make doxygen
# make test
make install # su -c "make install" # sudo make install
```

###### Without CMake

This project is a header-only library, you can copy the include directory in /usr/local (for example) or in your project. (But you have to define some macros to enable optional parts.)

### Utilization

If you use CMake, add these lines in your CMakeLists.txt:
```cmake
# gho
message(STATUS "---")
find_package(gho REQUIRED)
# See /installation/path/lib/gho/gho-config.cmake for CMake variables
```
