#pragma once

#include "src/Include/mean.h"

#include <cmath>

class Std : public Mean
{
public:
	void change(float num) override;

	float getMeaning() const override { return _std; }
	const char* getName() const override { return "std"; }

private:
	float _sum{};
	float _std{};
};