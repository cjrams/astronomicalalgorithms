#include <aawrapper/Moon.h>
#include <aaplus/AAElliptical.h>
#include <aaplus/AADate.h>
#include <aaplus/AAMoon.h>
#include <aaplus/AANutation.h>
#include <aaplus/AACoordinateTransformation.h>

namespace AstronomicalAlgorithms {

Moon::Moon(const CAADate& date, float latitude, float longitude)
	: mJulianDate (date.Julian())
{
	auto lunarCoord = [](double juliadDate){
		return CAACoordinateTransformation::Ecliptic2Equatorial(
			CAAMoon::EclipticLongitude(juliadDate),
			CAAMoon::EclipticLatitude(juliadDate),
			CAANutation::TrueObliquityOfEcliptic(juliadDate));
	};

	auto lunarcoord1 = lunarCoord(mJulianDate - 1);
	auto lunarcoord2 = lunarCoord(mJulianDate);
	auto lunarcoord3 = lunarCoord(mJulianDate + 1);

	mRiseTransitSetDetails = CAARiseTransitSet::Calculate(
            mJulianDate,
            lunarcoord1.X, lunarcoord1.Y,
            lunarcoord2.X, lunarcoord2.Y,
            lunarcoord3.X, lunarcoord3.Y,
            -longitude, latitude,
            0.125);

}

CAADate Moon::GetRise() const {
	return CAADate((mJulianDate + (mRiseTransitSetDetails.Rise/ 24.00)), true);
}

CAADate Moon::GetSet() const {
	return CAADate((mJulianDate + (mRiseTransitSetDetails.Set / 24.00)), true);
}

CAADate Moon::GetTransit() const {
	return CAADate((mJulianDate + (mRiseTransitSetDetails.Transit / 24.00)), true);
}

} //namespace AstronomicalAlgorithms

