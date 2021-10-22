#pragma once

class IStatistics
{
public:
	virtual void change(float num) = 0;
	virtual float getMeaning() const = 0;
	virtual const char* getName() const = 0;
	virtual ~IStatistics() {}
};
