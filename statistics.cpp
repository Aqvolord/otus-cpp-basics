#include <iostream>
#include <limits>

class IStatistics {
public:
	virtual void change(float next) = 0;
	virtual float getMeaning() const = 0;
	virtual const char* getName() const = 0;
	virtual ~IStatistics() {}
};


class Min : public IStatistics {
public:
	Min() : _min{ std::numeric_limits<float>::min() } {}

	void change(float num) override
	{
		if (num < _min)
			_min = num;
	}

	float getMeaning() const override { return _min; }
	const char* getName() const override { return "min"; }

private:
	float _min;
};

class Max : public IStatistics
{
public:
	void change(float num) override
	{
		if (num > _max)
			_max = num;
	}

	float getMeaning() const override { return _max; }
	const char* getName() const override { return "max"; }
private:
	float _max;
};

class Mean : public IStatistics
{
public:
private:
	float _mean;
};

class Std : public IStatistics
{
public:
private:
	float _stad;
};

class Pct90 : public IStatistics
{
public:
private:
	float _pct90;
};

class Pct50 : public IStatistics
{
public:
private:
	float _pct50;
};

int main() {

	const size_t statistics_count = 1;
	IStatistics* statistics[statistics_count];

	statistics[0] = new Min{};

	float val = 0;
	while (std::cin >> val) {
		for (size_t i = 0; i < statistics_count; ++i) {
			statistics[i]->change(val);
		}
	}

	// Handle invalid input data
	if (!std::cin.eof() && !std::cin.good()) {
		std::cerr << "Invalid input data\n";
		return 1;
	}

	// Print results if any
	for (size_t i = 0; i < statistics_count; ++i) {
		std::cout << statistics[i]->getName() << " = " << statistics[i]->getMeaning() << std::endl;
	}

	// Clear memory - delete all objects created by new
	for (size_t i = 0; i < statistics_count; ++i) {
		delete statistics[i];
	}

	return 0;
}