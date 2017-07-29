#include <aawrapper/Sun.h>
#include <aaplus/AAElliptical.h>
#include <aaplus/AADate.h>

namespace AstronomicalAlgorithms {

Sun::Sun(const CAADate& date, float latitude, float longitude)
	: mJulianDate (date.Julian())
{
	auto SunDetails1 = CAAElliptical::Calculate(mJulianDate - 1, CAAElliptical::SUN, true);
	auto SunDetails2 = CAAElliptical::Calculate(mJulianDate, CAAElliptical::SUN, true);
	auto SunDetails3 = CAAElliptical::Calculate(mJulianDate + 1, CAAElliptical::SUN, true);
	mRiseTransitSetDetails = CAARiseTransitSet::Calculate(
			mJulianDate,
			SunDetails1.ApparentGeocentricRA,
			SunDetails1.ApparentGeocentricDeclination,
			SunDetails2.ApparentGeocentricRA,
			SunDetails2.ApparentGeocentricDeclination,
			SunDetails3.ApparentGeocentricRA,
			SunDetails3.ApparentGeocentricDeclination,
			-longitude,
			latitude,
			-0.8333);
}

CAADate Sun::GetRise() const {
	return CAADate((mJulianDate + (mRiseTransitSetDetails.Rise / 24.00)), true);
}

CAADate Sun::GetSet() const {
	return CAADate((mJulianDate + (mRiseTransitSetDetails.Set / 24.00)), true);
}

CAADate Sun::GetTransit() const {
	return CAADate((mJulianDate + (mRiseTransitSetDetails.Transit / 24.00)), true);
}

} //namespace

