#include <aawrapper/Planet.h>
#include <aaplus/AADate.h>

namespace AstronomicalAlgorithms {

Planet::Planet(double julianDate)
    : mJulianDate(julianDate) {}

void Planet::Initialize(float latitude, float longitude, CAAElliptical::EllipticalObject ellipticalObject) {
	auto details1 = CAAElliptical::Calculate(mJulianDate - 1, ellipticalObject, true);
	auto details2 = CAAElliptical::Calculate(mJulianDate, ellipticalObject, true);
	auto details3 = CAAElliptical::Calculate(mJulianDate + 1, ellipticalObject, true);
	mRiseTransitSetDetails = CAARiseTransitSet::Calculate(
			mJulianDate,
			details1.ApparentGeocentricRA, details1.ApparentGeocentricDeclination,
			details2.ApparentGeocentricRA, details2.ApparentGeocentricDeclination,
			details3.ApparentGeocentricRA, details3.ApparentGeocentricDeclination,
			-longitude, latitude,
			-0.5667);
}

CAADate Planet::GetRise() const {
	return CAADate((mJulianDate + (mRiseTransitSetDetails.Rise / 24.00)), true);
}

CAADate Planet::GetSet() const {
	return CAADate((mJulianDate + (mRiseTransitSetDetails.Set / 24.00)), true);
}

CAADate Planet::GetTransit() const {
	return CAADate((mJulianDate + (mRiseTransitSetDetails.Transit / 24.00)), true);
}

} //namespace AstronomicalAlgorithms

