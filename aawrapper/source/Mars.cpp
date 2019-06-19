#include <aawrapper/Mars.h>
#include <aaplus/AAElliptical.h>
#include <aaplus/AADate.h>

namespace AstronomicalAlgorithms {

Mars::Mars(const CAADate& date, float latitude, float longitude)
	: Planet(date.Julian())
{
	auto details1 = CAAElliptical::Calculate(mJulianDate - 1, CAAElliptical::EllipticalObject::MARS, true);
	auto details2 = CAAElliptical::Calculate(mJulianDate, CAAElliptical::EllipticalObject::MARS, true);
	auto details3 = CAAElliptical::Calculate(mJulianDate + 1, CAAElliptical::EllipticalObject::MARS, true);
	mRiseTransitSetDetails = CAARiseTransitSet::Calculate(
		mJulianDate,
		details1.ApparentGeocentricRA, details1.ApparentGeocentricDeclination,
		details2.ApparentGeocentricRA, details2.ApparentGeocentricDeclination,
		details3.ApparentGeocentricRA, details3.ApparentGeocentricDeclination,
		-longitude, latitude,
		-0.5667);
}

} //namespace AstronomicalAlgorithms

