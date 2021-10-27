#include <iostream>
#include <deque>

class serialContainer
{
public:
    serialContainer(int count, const int& size)
    {
        for (count; count < size; ++count)
            _container.push_back(count);
        _printContainer(_container);
    }

    ~serialContainer() { }

    void SizeContainer()
    {
        std::cout << _container.size() << std::endl;
    }

    void DeleteElements()
    {
        _container.erase(_container.begin() + 2);
        _container.erase(_container.begin() + 3);
        _container.erase(_container.begin() + 4);

        _printContainer(_container);
    }

    void AddingElements()
    {
        _container.push_front(10);
        _printContainer(_container);

        _container.insert(_container.begin() + 4, 20);
        _printContainer(_container);
    
        _container.push_back(30);
        _printContainer(_container);
	}

private:
    std::deque<int> _container;
    
    void _printContainer(const std::deque<int>& container)
    {
        for (auto count : container) {
            std::cout << ' ' << count;
        }
        std::cout << '\n';
    }
};
