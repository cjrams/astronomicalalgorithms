#include <aawrapper/AstronomicalBody.h>
#include <aaplus/AADate.h>
#include <aaplus/AADynamicalTime.h>

namespace AstronomicalAlgorithms {

	AstronomicalBody::AstronomicalBody(double julianDate)
    : mJulianDate(julianDate) {}

void AstronomicalBody::Initialize(double latitude, double longitude, CAARiseTransitSet2::Object object, double geographicObserverLatitude) {
	mEvents = CAARiseTransitSet2::Calculate(
			mJulianDate, mJulianDate + 1,
            object,
			-longitude, latitude,
			geographicObserverLatitude);
}

CAADate AstronomicalBody::GetRise() const {
	for (const auto& event : mEvents) {
		if (event.type == CAARiseTransitSetDetails2::Type::Rise) {
			return CAADate(CAADynamicalTime::TT2UTC(event.JD), true);
		}
	}
	return {};
}

CAADate AstronomicalBody::GetSet() const {
	for (const auto& event : mEvents) {
		if (event.type == CAARiseTransitSetDetails2::Type::Set) {
			return CAADate(CAADynamicalTime::TT2UTC(event.JD), true);
		}
	}
	return {};
}

CAADate AstronomicalBody::GetTransit() const {
	for (const auto& event : mEvents) {
		if (event.type == CAARiseTransitSetDetails2::Type::SouthernTransit) {
			return CAADate(CAADynamicalTime::TT2UTC(event.JD), true);
		}
	}
	return {};
}

} //namespace AstronomicalAlgorithms

