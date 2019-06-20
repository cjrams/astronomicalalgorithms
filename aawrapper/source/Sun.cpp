#include <aawrapper/Sun.h>
#include <aaplus/AAElliptical.h>
#include <aaplus/AADate.h>

namespace AstronomicalAlgorithms {

Sun::Sun(const CAADate& date, double latitude, double longitude)
	: AstronomicalBody (date.Julian())
{
	Initialize(latitude, longitude, CAAElliptical::EllipticalObject::SUN, -0.8333);
}

} //namespace AstronomicalAlgorithms

