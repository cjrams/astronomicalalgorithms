#pragma once

#include <aawrapper/Planet.h>

class CAADate;

namespace AstronomicalAlgorithms {
	class Mars : public Planet {
		public:
			Mars(const CAADate& date, float latitude, float longitude);
	};
} //namespace AstronomicalAlgorithms
