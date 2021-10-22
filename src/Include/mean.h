#pragma once

#include "src/Include/statistics.h"

class Mean : public IStatistics
{
public:
	void change(float num) override;

	float getMeaning() const override { return _mean; }
	const char* getName() const override { return "mean"; }
	int getOrdinal() const { return _ordinal; }

private:
	float _sum{};
	int _ordinal{};
	float _mean{};
};