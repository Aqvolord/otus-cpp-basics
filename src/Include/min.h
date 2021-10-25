#pragma once

#include "statistics.h"

#include <limits>

class Min : public IStatistics
{
public:
	Min() : _min{ std::numeric_limits<float>::max() } {}

	void change(float num) override;

	float getMeaning() const override { return _min; }
	const char* getName() const override { return "min"; }

private:
	float _min;
};