#include <aawrapper/Mars.h>
#include <aaplus/AAElliptical.h>
#include <aaplus/AADate.h>

namespace AstronomicalAlgorithms {

Mars::Mars(const CAADate& date, float latitude, float longitude)
	: Planet(date.Julian())
{
    Initialize(latitude, longitude, CAAElliptical::EllipticalObject::MARS);
}

} //namespace AstronomicalAlgorithms

