#include <aawrapper/Planet.h>
#include <aaplus/AAElliptical.h>
#include <aaplus/AADate.h>

namespace AstronomicalAlgorithms {

Planet::Planet(double julianDate)
    : mJulianDate(julianDate) {}

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

