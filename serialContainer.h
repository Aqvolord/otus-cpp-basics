#pragma once

#include <iostream>
#include <deque>
template<typename T>
class MyContainter
{
public:
	MyContainter(size_t size);

	~MyContainter();
	void MyContainter::push_back(T value);

	size_t size() const;

private:
	T* _data;
	size_t _size;
};


template<typename T>
MyContainter<T>::MyContainter(size_t size)
	: _size{ size }, _data{ new T(size) }
{}

template<typename T>
inline MyContainter<T>::~MyContainter()
{
	delete[] _data;
}

template<typename T>
size_t MyContainter<T>::size() const
{
	return _size;
}

//template<typename T>
//void MyContainter::push_back(T value)
//{
//	T* new_region = new T[m_size + 1]; // новая область памяти
//	for (size_t i = 0; i < m_size; ++i) {
//		new_region[i] = m_region[i]; // копирование элементов
//	}
//	new_region[m_size] = value; // добавление нового элемента
//	delete[] m_region; // удаление старой области
//	m_region = new_region; // сохранение новой в мембер
//	m_size += 1; // обновление информации о размере
//}