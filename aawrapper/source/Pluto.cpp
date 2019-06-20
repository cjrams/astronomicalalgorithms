#include <aawrapper/Pluto.h>
#include <aaplus/AAElliptical.h>
#include <aaplus/AADate.h>

namespace AstronomicalAlgorithms {

Pluto::Pluto(const CAADate& date, float latitude, float longitude)
	: Planet(date.Julian())
{
    Initialize(latitude, longitude, CAAElliptical::EllipticalObject::PLUTO);
}

} //namespace AstronomicalAlgorithms

