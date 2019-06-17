#pragma once
#include <aaplus/AARiseTransitSet.h>

class CAADate;
namespace AstronomicalAlgorithms {
	class Moon {
		public:
			Moon(const CAADate& date, float latitude, float longitude);
			CAADate GetRise() const;
			CAADate GetSet() const;
			CAADate GetTransit() const;
		private:
			CAARiseTransitSetDetails mRiseTransitSetTime;
			double mJulianDate;
	};
} //namespace AstronomicalAlgorithms
