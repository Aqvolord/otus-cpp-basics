#include "min.h"

void Min::change(float num)
{
	if (_min > num)
		_min = num;
}