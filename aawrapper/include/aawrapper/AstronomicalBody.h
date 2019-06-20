#pragma once

#include <aaplus/AARiseTransitSet.h>
#include <aaplus/AAElliptical.h>

class CAADate;

namespace AstronomicalAlgorithms {
	class AstronomicalBody {
		public:
            AstronomicalBody(double julianDate);
			void Initialize(double latitude, double longitude, CAAElliptical::EllipticalObject ellipticalObject, double geographicObserverLatitude);
			CAADate GetRise() const;
			CAADate GetSet() const;
			CAADate GetTransit() const;
		protected:
			CAARiseTransitSetDetails mRiseTransitSetDetails;
			double mJulianDate;
	};
} //namespace AstronomicalAlgorithms
