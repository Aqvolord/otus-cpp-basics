#include "mean.h"

void Mean::change(float num)
{
	_sum += num;
	_ordinal++;
	_mean = _sum / _ordinal;
}
