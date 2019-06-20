#pragma once

#include <aawrapper/Planet.h>

class CAADate;

namespace AstronomicalAlgorithms {
	class Pluto : public Planet {
		public:
			Pluto(const CAADate& date, float latitude, float longitude);
	};
} //namespace AstronomicalAlgorithms
