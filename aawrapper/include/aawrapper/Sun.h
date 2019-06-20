#pragma once

#include <aawrapper/AstronomicalBody.h>

class CAADate;

namespace AstronomicalAlgorithms {
	class Sun : public AstronomicalBody {
		public:
			Sun(const CAADate& date, double latitude, double longitude);
	};
} //namespace AstronomicalAlgorithms
