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
	float _max;
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
	int getOrdinal()const { return _ordinal; }
	const char* getName() const override { return "mean"; }
	
private:
	float _sum;
	int _ordinal;
	float _mean;
	
};

class Std : public IStatistics
{
public:
	void change(float num) override
	{

		
		//_sum2 += pow((num - _mean), 2);
		//_std = sqrt(_sum2 / 10);
	}

	float getMeaning() const override { return _std; }
 	const char* getName() const override { return "std"; }

private:
	//float _num;
	//
	//int _ordinal;
	float _std;
};
//
//class Pct90 : public IStatistics
//{
//public:
//	void change(float num) override
//	{
//
//	}
//
//	float getMeaning() const override { return _pct90; }
//	const char* getName() const override { return "pct90"; }
//
//private:
//	float _pct90;
//};
//
//class Pct50 : public IStatistics
//{
//public:
//	void change(float num) override
//	{
//
//	}
//
//	float getMeaning() const override { return _pct50; }
//	const char* getName() const override { return "pct50"; }
//
//private:
//	float _pct50;
//};

int main() {

	const size_t statistics_count = 4;
	IStatistics* statistics[statistics_count];

	statistics[0] = new Min{};
	statistics[1] = new Max{};
	statistics[2] = new Mean{};
	statistics[3] = new Std{};
	//statistics[4] = new Pct90{};
	//statistics[5] = new Pct50{};

	std::cout << "Enter a sequence of numbers: " << std::endl;
	float value, j = 0;
	while (std::cin >> value) {
		std::cout << ++j << std::endl;
		for (size_t i = 0; i < statistics_count; ++i) {
			statistics[i]->change(value);
			std::cout << j+10 << std::endl;
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