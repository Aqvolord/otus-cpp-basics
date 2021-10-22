#include "src/Include/min.h"

void Min::change(float num)
{
	if (_min > num)
		_min = num;
}