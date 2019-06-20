#pragma once

#include <aawrapper/AstronomicalBody.h>

class CAADate;

namespace AstronomicalAlgorithms {
	class Pluto : public AstronomicalBody {
		public:
			Pluto(const CAADate& date, double latitude, double longitude);
	};
} //namespace AstronomicalAlgorithms
