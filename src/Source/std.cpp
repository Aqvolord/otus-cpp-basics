#include "std.h"

void Std::change(float num)
{
	Mean::change(num);

	_sum += pow((num - Mean::getMeaning()), 2);
	_std = sqrt(_sum / (Mean::getOrdinal() - 1));
}