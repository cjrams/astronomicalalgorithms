#pragma once
#include <aawrapper/AstronomicalBody.h>

class CAADate;

namespace AstronomicalAlgorithms {
	class Moon : public AstronomicalBody {
		public:
			Moon(const CAADate& date, float latitude, float longitude);
	};
} //namespace AstronomicalAlgorithms
