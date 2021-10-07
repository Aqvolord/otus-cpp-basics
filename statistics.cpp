#include <iostream>
#include <limits>
#include <cmath>

class IStatistics
{
public:
	virtual void change(float num) = 0;
	virtual float getMeaning() const = 0;
	virtual const char* getName() const = 0;
	virtual ~IStatistics() {}
};

class Min : public IStatistics
{
public:
	Min() : _min{ std::numeric_limits<float>::max() } {}

	void change(float num) override
	{
		if (_min > num)
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
		if (_max < num)
			_max = num;
	}

	float getMeaning() const override { return _max; }
	const char* getName() const override { return "max"; }

private:
	float _max{};
};

class Mean : public IStatistics
{
public:
	void change(float num) override
	{
		_sum += num;
		_ordinal++;
		_mean = _sum / _ordinal;
	}

	float getMeaning() const override { return _mean; }
	const char* getName() const override { return "mean"; }
	int getOrdinal() const { return _ordinal; }

private:
	float _sum{};
	int _ordinal{};
	float _mean{};
};

class Std : public Mean
{
public:
	void change(float num) override
	{
		Mean::change(num);
		
		_sum += pow((num - Mean::getMeaning()), 2);
		_std = sqrt(_sum / (Mean::getOrdinal() - 1));
	}

	float getMeaning() const override { return _std; }
 	const char* getName() const override { return "std"; }

private:
	float _sum{};
	float _std{};
};

int main() {

	const size_t statistics_count = 4;
	IStatistics* statistics[statistics_count];

	statistics[0] = new Min{};
	statistics[1] = new Max{};
	statistics[2] = new Mean{};
	statistics[3] = new Std{};

	std::cout << "Enter a sequence of numbers: " << std::endl;
	float value;
	while (std::cin >> value) {
		for (size_t i = 0; i < statistics_count; ++i) {
			statistics[i]->change(value);
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