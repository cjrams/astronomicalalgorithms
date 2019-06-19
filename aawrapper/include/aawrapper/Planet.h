#pragma once

#include <aaplus/AARiseTransitSet.h>

class CAADate;

namespace AstronomicalAlgorithms {
	class Planet {
		public:
            Planet(double julianDate);
			CAADate GetRise() const;
			CAADate GetSet() const;
			CAADate GetTransit() const;
		protected:
			CAARiseTransitSetDetails mRiseTransitSetDetails;
			double mJulianDate;
	};
} //namespace AstronomicalAlgorithms
