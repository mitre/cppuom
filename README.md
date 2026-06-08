# cppuom

![Apache 2.0](https://img.shields.io/badge/license-Apache%20License%202.0-blue?style=for-the-badge)

![CMake](https://img.shields.io/badge/CMake-%23008FBA.svg?style=for-the-badge&logo=cmake&logoColor=white)
![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)

![Linux](https://img.shields.io/badge/-Linux-%2310B981?style=for-the-badge&logo=linux&logoColor=white)
![macos](https://img.shields.io/badge/MacOS-f0f0f0?logo=apple&logoColor=black&style=for-the-badge)

C++ header-only library for scientific units of measure compile-time enforcement.
This repo is a fork of [this abandoned repo](https://sourceforge.net/projects/tuoml/) on sourceforge.

## History of Use

Read more in the [history](./history.md) documentation.

## MITRE Disclosure

> This is the copyright work of The MITRE Corporation, and was produced for the U. S. Government under Contract Number 693KA8-22-C-00001, and is subject to Federal Aviation Administration Acquisition Management System Clause 3.5-13, Rights In Data-General (Oct. 2014), Alt. III and Alt. IV (Jan. 2009).  No other use other than that granted to the U. S. Government, or to those acting on behalf of the U. S. Government, under that Clause is authorized without the express written permission of The MITRE Corporation. For further information, please contact The MITRE Corporation, Contracts Management Office, 7515 Colshire Drive, McLean, VA  22102-7539, (703) 983-6000.
>
> (c) 2026 The MITRE Corporation. All Rights Reserved.
>
> Approved for Public Release; Distribution Unlimited. 15-1482

This project contains content developed by The MITRE Corporation. If this code is used in a deployment or embedded within another project, it is requested that you send an email to [opensource@mitre.org](mailto:opensource@mitre.org) in order to let us know where this software is being used.

## License

[Apache 2.0](https://github.com/mitre/FMACM/blob/master/LICENSE)

## Build

This is a header-only library. You can include it without building it.

We like the [C++ Package Manager (CPM)](https://github.com/cpm-cmake/cpm.cmake) for including external git repos. We do it like this:

```cmake
include(${PROJECT_SOURCE_DIR}/.cmake/get_cpm.cmake)
CPMAddPackage(
    NAME unitslib
    GIT_REPOSITORY https://github.com/mitre/cppuom.git
    GIT_TAG 2.2
    DOWNLOAD_ONLY TRUE
)
target_include_directories(some_target PRIVATE include)
```

If useful, the CMake also exposes to the PARENT scope the variable `CPPUOM_SOURCES`.

## Use

Review the [example code](./example.cpp) or the [tests](./test/tests.cpp).

---

~ Happy Developing ~
