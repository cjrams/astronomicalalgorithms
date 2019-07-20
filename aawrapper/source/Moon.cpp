#include <aawrapper/Moon.h>
#include <aaplus/AAElliptical.h>
#include <aaplus/AADate.h>
#include <aaplus/AAMoon.h>
#include <aaplus/AANutation.h>
#include <aaplus/AACoordinateTransformation.h>

namespace AstronomicalAlgorithms {

Moon::Moon(const CAADate& date, float latitude, float longitude)
	: AstronomicalBody (date.Julian())
{
	mEvents = CAARiseTransitSet2::CalculateMoon(
            mJulianDate, mJulianDate + 1,
            -longitude, latitude);
}

} //namespace AstronomicalAlgorithms

