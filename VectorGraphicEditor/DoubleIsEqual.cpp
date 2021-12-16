#include "DoubleIsEqual.h"

bool double_is_equal(double d1, double d2, double epsilon )
{
	return fabs(d1 - d2) < epsilon;
}
