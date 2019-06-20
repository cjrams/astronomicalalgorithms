#pragma once

#include <aaplus/AARiseTransitSet.h>
#include <aaplus/AAElliptical.h>

class CAADate;

namespace AstronomicalAlgorithms {
	class Planet {
		public:
            Planet(double julianDate);
			void Initialize(float latitude, float longitude, CAAElliptical::EllipticalObject ellipticalObject);
			CAADate GetRise() const;
			CAADate GetSet() const;
			CAADate GetTransit() const;
		protected:
			CAARiseTransitSetDetails mRiseTransitSetDetails;
			double mJulianDate;
	};
} //namespace AstronomicalAlgorithms
