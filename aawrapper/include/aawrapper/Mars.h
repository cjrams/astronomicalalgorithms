#pragma once

#include <aawrapper/AstronomicalBody.h>

class CAADate;

namespace AstronomicalAlgorithms {
	class Mars : public AstronomicalBody {
		public:
			Mars(const CAADate& date, double latitude, double longitude);
	};
} //namespace AstronomicalAlgorithms
