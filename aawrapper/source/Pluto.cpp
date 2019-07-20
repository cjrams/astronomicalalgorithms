#include <aawrapper/Pluto.h>
#include <aaplus/AAElliptical.h>
#include <aaplus/AADate.h>

namespace AstronomicalAlgorithms {

Pluto::Pluto(const CAADate& date, double latitude, double longitude)
	: AstronomicalBody(date.Julian())
{
    Initialize(latitude, longitude, CAARiseTransitSet2::Object::PLUTO, -0.5667);
}

} //namespace AstronomicalAlgorithms

