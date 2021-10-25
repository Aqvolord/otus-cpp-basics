#include "max.h"

void Max::change(float num)
{
	if (_max < num)
		_max = num;
}