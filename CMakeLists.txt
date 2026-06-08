cmake_minimum_required(VERSION 4.0)
project(cppuom)

set(SOURCE_FILES
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

if (NOT CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
   set(CPPUOM_SOURCES ${SOURCE_FILES} PARENT_SCOPE)
endif()

if (BUILD_EXAMPLE)
   add_executable(cppuom-example example.cpp)
   target_include_directories(cppuom-example PRIVATE include)
   set_target_properties(cppuom-example PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
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
      "BUILD_GMOCK ON"
   )

   add_executable(cppuom-tests test/tests.cpp)
   target_include_directories(cppuom-tests PRIVATE include)
   target_link_libraries(cppuom-tests PRIVATE GTest::gtest_main)
   set_target_properties(cppuom-tests PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

   include(GoogleTest)
   gtest_discover_tests(cppuom-tests)
endif()
