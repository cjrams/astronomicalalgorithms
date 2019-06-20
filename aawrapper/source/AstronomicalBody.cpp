#include <aawrapper/AstronomicalBody.h>
#include <aaplus/AADate.h>

namespace AstronomicalAlgorithms {

	AstronomicalBody::AstronomicalBody(double julianDate)
    : mJulianDate(julianDate) {}

void AstronomicalBody::Initialize(double latitude, double longitude, CAAElliptical::EllipticalObject ellipticalObject, double geographicObserverLatitude) {
	auto details1 = CAAElliptical::Calculate(mJulianDate - 1, ellipticalObject, true);
	auto details2 = CAAElliptical::Calculate(mJulianDate, ellipticalObject, true);
	auto details3 = CAAElliptical::Calculate(mJulianDate + 1, ellipticalObject, true);
	mRiseTransitSetDetails = CAARiseTransitSet::Calculate(
			mJulianDate,
			details1.ApparentGeocentricRA, details1.ApparentGeocentricDeclination,
			details2.ApparentGeocentricRA, details2.ApparentGeocentricDeclination,
			details3.ApparentGeocentricRA, details3.ApparentGeocentricDeclination,
			-longitude, latitude,
			geographicObserverLatitude);
}

CAADate AstronomicalBody::GetRise() const {
	return CAADate((mJulianDate + (mRiseTransitSetDetails.Rise / 24.00)), true);
}

CAADate AstronomicalBody::GetSet() const {
	return CAADate((mJulianDate + (mRiseTransitSetDetails.Set / 24.00)), true);
}

CAADate AstronomicalBody::GetTransit() const {
	return CAADate((mJulianDate + (mRiseTransitSetDetails.Transit / 24.00)), true);
}

} //namespace AstronomicalAlgorithms

