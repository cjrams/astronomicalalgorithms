#include <aawrapper/Mars.h>
#include <aaplus/AAElliptical.h>
#include <aaplus/AADate.h>

namespace AstronomicalAlgorithms {

Mars::Mars(const CAADate& date, double latitude, double longitude)
	: AstronomicalBody(date.Julian())
{
    Initialize(latitude, longitude, CAAElliptical::EllipticalObject::MARS, -0.5667);
}

} //namespace AstronomicalAlgorithms

