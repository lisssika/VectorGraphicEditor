#include "DoubleIsEqual.h"
#include <limits>

bool double_is_equal(double d1, double d2)
{
	return fabs(d1 - d2) < std::numeric_limits<double>::epsilon();
}
