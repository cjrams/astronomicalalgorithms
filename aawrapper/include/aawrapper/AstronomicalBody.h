#pragma once

#include <aaplus/AARiseTransitSet2.h>
#include <aaplus/AAElliptical.h>

class CAADate;

namespace AstronomicalAlgorithms {
	class AstronomicalBody {
		public:
            AstronomicalBody(double julianDate);
			void Initialize(double latitude, double longitude, CAARiseTransitSet2::Object object, double geographicObserverLatitude);
			CAADate GetRise() const;
			CAADate GetSet() const;
			CAADate GetTransit() const;
		protected:
			std::vector<CAARiseTransitSetDetails2> mEvents;
			double mJulianDate;
	};
} //namespace AstronomicalAlgorithms
