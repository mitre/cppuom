cmake_minimum_required(VERSION 3.15)
project(cppuom VERSION 2.2 LANGUAGES CXX)

option(BUILD_EXAMPLE "Build the cppuom example executable" OFF)

set(CPPUOM_HEADERS
   include/scalar/Acceleration.h
   include/scalar/Angle.h
   include/scalar/Angle.i
   include/scalar/AngularAcceleration.h
   include/scalar/AngularSpeed.h
   include/scalar/Area.h
   include/scalar/Current.h
   include/scalar/Density.h
   include/scalar/Force.h
   include/scalar/Format.h
   include/scalar/Format.i
   include/scalar/Frequency.h
   include/scalar/Inertia.h
   include/scalar/Length.h
   include/scalar/MagneticField.h
   include/scalar/MagneticFlux.h
   include/scalar/MagneticFluxDensity.h
   include/scalar/Mass.h
   include/scalar/MassFlowRate.h
   include/scalar/Power.h
   include/scalar/Pressure.h
   include/scalar/ProductUnitFormat.h
   include/scalar/ProductUnitFormat.i
   include/scalar/RatioUnitFormat.h
   include/scalar/RatioUnitFormat.i
   include/scalar/SignedAngle.h
   include/scalar/SignedAngle.i
   include/scalar/SpecificUnit.h
   include/scalar/SpecificUnit.i
   include/scalar/Speed.h
   include/scalar/Temperature.h
   include/scalar/Temperature.i
   include/scalar/Time.h
   include/scalar/Torque.h
   include/scalar/Unit.h
   include/scalar/Unit.i
   include/scalar/UnsignedAngle.h
   include/scalar/UnsignedAngle.i
   include/scalar/Voltage.h
   include/scalar/Volume.h
   include/system/units_config.h
)

add_library(cppuom INTERFACE)
add_library(mitre::cppuom ALIAS cppuom)

target_sources(cppuom INTERFACE ${CPPUOM_HEADERS})
target_include_directories(cppuom INTERFACE
   $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
   $<INSTALL_INTERFACE:include>
)

if (BUILD_EXAMPLE)
   add_executable(cppuom-example example.cpp)
   target_link_libraries(cppuom-example PRIVATE mitre::cppuom)
   set_target_properties(cppuom-example PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
endif()

include(CTest)

if(BUILD_TESTING)
   include(.cpm/get_cpm.cmake)

   CPMAddPackage(
      NAME googletest
      GITHUB_REPOSITORY google/googletest
      VERSION 1.15.2
      OPTIONS
      "INSTALL_GTEST OFF"
      "GTEST_FORCE_SHARED_CRT ON"
      "BUILD_GMOCK OFF"
   )

   add_executable(cppuom-tests test/tests.cpp)
   target_link_libraries(cppuom-tests PRIVATE mitre::cppuom GTest::gtest_main)
   set_target_properties(cppuom-tests PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

   include(GoogleTest)
   gtest_discover_tests(cppuom-tests)
endif()
