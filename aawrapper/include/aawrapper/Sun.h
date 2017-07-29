#pragma once

#include <aaplus/AARiseTransitSet.h>

class CAADate;

namespace AstronomicalAlgorithms {
	class Sun {
		public:
			Sun(const CAADate& date, float latitude, float longitude);
			CAADate GetRise() const;
			CAADate GetSet() const;
			CAADate GetTransit() const;
		private:
			CAARiseTransitSetDetails mRiseTransitSetDetails;
			double mJulianDate;
	};

}
