// ****************************************************************************
// NOTICE
//
// This work was produced for the U.S. Government under Contract 693KA8-22-C-00001
// and is subject to Federal Aviation Administration Acquisition Management System
// Clause 3.5-13, Rights In Data-General, Alt. III and Alt. IV (Oct. 1996).
//
// The contents of this document reflect the views of the author and The MITRE
// Corporation and do not necessarily reflect the views of the Federal Aviation
// Administration (FAA) or the Department of Transportation (DOT). Neither the FAA
// nor the DOT makes any warranty or guarantee, expressed or implied, concerning
// the content or accuracy of these views.
//
// For further information, please contact The MITRE Corporation, Contracts Management
// Office, 7515 Colshire Drive, McLean, VA 22102-7539, (703) 983-6000.
//
// (c) 2026 The MITRE Corporation. All Rights Reserved.
// ****************************************************************************

#include <gtest/gtest.h>

#include <cmath>
#include <set>

#include "scalar/Area.h"
#include "scalar/Length.h"
#include "scalar/Temperature.h"

namespace
{

constexpr double kTolerance = 1e-6;

template <typename To, typename From>
void ExpectRelativeConversion(From const & from, double expected)
{
  Units::Temperature const temperature(from);
  EXPECT_NEAR(To(temperature).value(), expected, kTolerance);
}

template <typename To, typename From>
void ExpectAbsoluteConversion(From const & from, double expected)
{
  Units::AbsTemperature const temperature(from);
  EXPECT_NEAR(To(temperature).value(), expected, kTolerance);
}

} // namespace

TEST(LengthUnits, SupportsComparisonsAndAreaMath)
{
  Units::Length const threeFeet = Units::FeetLength(3.0);
  Units::Length const threeMeters = Units::MetersLength(3.0);

  Units::Area const rectArea = threeFeet * threeMeters;
  Units::MetersLength const distance = sqrt(rectArea);

  EXPECT_NEAR(Units::MetersArea(rectArea).value(), 3.0 * 3.0 * 0.3048,
              kTolerance);
  EXPECT_NEAR(distance.value(), std::sqrt(3.0 * 3.0 * 0.3048), kTolerance);

  EXPECT_LT(threeFeet, threeMeters);
  EXPECT_EQ(threeFeet, Units::FeetLength(3.0));
}

TEST(LengthUnits, SupportsOrderedSetOperations)
{
  Units::Length const threeFeet = Units::FeetLength(3.0);
  Units::Length const threeMeters = Units::MetersLength(3.0);

  std::set<Units::Length> lengths{threeFeet, threeMeters};

  ASSERT_EQ(lengths.size(), 2U);
  EXPECT_NEAR(Units::FeetLength(*lengths.begin()).value(), 3.0, kTolerance);

  lengths.erase(Units::FeetLength(3.0));

  ASSERT_EQ(lengths.size(), 1U);
  EXPECT_EQ(*lengths.begin(), threeMeters);
  EXPECT_NEAR(Units::MetersLength(*lengths.begin()).value(), 3.0,
              kTolerance);
}

TEST(RelativeTemperatureUnits, ConvertsBetweenSupportedScales)
{
  ExpectRelativeConversion<Units::CelsiusTemperature>(
      Units::CelsiusTemperature(1.0), 1.0);
  ExpectRelativeConversion<Units::FahrenheitTemperature>(
      Units::CelsiusTemperature(0.0), 0.0);
  ExpectRelativeConversion<Units::KelvinTemperature>(
      Units::CelsiusTemperature(0.0), 0.0);
  ExpectRelativeConversion<Units::FahrenheitTemperature>(
      Units::CelsiusTemperature(100.0), 180.0);

  ExpectRelativeConversion<Units::CelsiusTemperature>(
      Units::FahrenheitTemperature(180.0), 100.0);
  ExpectRelativeConversion<Units::CelsiusTemperature>(
      Units::FahrenheitTemperature(0.0), 0.0);
  ExpectRelativeConversion<Units::FahrenheitTemperature>(
      Units::FahrenheitTemperature(1.0), 1.0);
  ExpectRelativeConversion<Units::RankineTemperature>(
      Units::FahrenheitTemperature(0.0), 0.0);

  ExpectRelativeConversion<Units::KelvinTemperature>(
      Units::KelvinTemperature(1.0), 1.0);
  ExpectRelativeConversion<Units::CelsiusTemperature>(
      Units::KelvinTemperature(273.15), 273.15);

  ExpectRelativeConversion<Units::RankineTemperature>(
      Units::RankineTemperature(1.0), 1.0);
  ExpectRelativeConversion<Units::FahrenheitTemperature>(
      Units::RankineTemperature(459.67), 459.67);
}

TEST(AbsoluteTemperatureUnits, ConvertsBetweenSupportedScales)
{
  ExpectAbsoluteConversion<Units::AbsCelsiusTemperature>(
      Units::AbsCelsiusTemperature(1.0), 1.0);
  ExpectAbsoluteConversion<Units::AbsFahrenheitTemperature>(
      Units::AbsCelsiusTemperature(0.0), 32.0);
  ExpectAbsoluteConversion<Units::AbsKelvinTemperature>(
      Units::AbsCelsiusTemperature(0.0), 273.15);
  ExpectAbsoluteConversion<Units::AbsFahrenheitTemperature>(
      Units::AbsCelsiusTemperature(100.0), 212.0);

  ExpectAbsoluteConversion<Units::AbsCelsiusTemperature>(
      Units::AbsFahrenheitTemperature(212.0), 100.0);
  ExpectAbsoluteConversion<Units::AbsCelsiusTemperature>(
      Units::AbsFahrenheitTemperature(32.0), 0.0);
  ExpectAbsoluteConversion<Units::AbsFahrenheitTemperature>(
      Units::AbsFahrenheitTemperature(1.0), 1.0);
  ExpectAbsoluteConversion<Units::AbsRankineTemperature>(
      Units::AbsFahrenheitTemperature(0.0), 459.67);

  ExpectAbsoluteConversion<Units::AbsKelvinTemperature>(
      Units::AbsKelvinTemperature(1.0), 1.0);
  ExpectAbsoluteConversion<Units::AbsCelsiusTemperature>(
      Units::AbsKelvinTemperature(273.15), 0.0);

  ExpectAbsoluteConversion<Units::AbsRankineTemperature>(
      Units::AbsRankineTemperature(1.0), 1.0);
  ExpectAbsoluteConversion<Units::AbsFahrenheitTemperature>(
      Units::AbsRankineTemperature(459.67), 0.0);
}
