#pragma once

#include "src/Include/statistics.h"

#include <limits>

class Max : public IStatistics
{
public:
	Max() : _max{ std::numeric_limits<float>::lowest() } {}

	void change(float num) override;

	float getMeaning() const override { return _max; }
	const char* getName() const override { return "max"; }

private:
	float _max;
};