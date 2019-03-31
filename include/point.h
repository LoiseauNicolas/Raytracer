#pragma once

#include <cmath>
#include <iostream>

#include "array_1x3.h"

template <typename T> class point_t	: public array_1x3<T>
{
// private:

public:
	// Constructeurs
	constexpr point_t() : array_1x3<T>(){};

	constexpr point_t(const T &x, const T &y, const T &z) : array_1x3<T>(x,y,z){};

	constexpr point_t(const array_1x3<T> &a):array_1x3<T>(a){};

	T distance(const point_t &a) const
	{
        return sqrt((a[0]-*this->_array[0])*(a[0]-*this->_array[0])+
                    (a[1]-*this->_array[1])*(a[1]-*this->_array[1])+
                    (a[2]-*this->_array[2])*(a[2]-*this->_array[2]));
	}

};

template<typename T>
T distance(const point_t<T> &p_1, const point_t<T> &p_2)
{
	return sqrt((p_1[0]-p_2[0])*(p_1[0]-p_2[0])+
                (p_1[1]-p_2[1])*(p_1[1]-p_2[1])+
                (p_1[2]-p_2[2])*(p_1[2]-p_2[2]));
}
