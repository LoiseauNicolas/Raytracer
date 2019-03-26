#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>
#include <iostream>

#include "point.h"

template <typename T> class vector_t : public array_1x3<T>
{
public:

	// http://olivier.buga.free.fr/sandy/bases.html
	// double _x,_y,_z;

	vector_t():array_1x3<T>(){};

	vector_t(const point_t<T>& A, const point_t<T>& B)
	:array_1x3<T>(B[0]-A[0], B[1]-A[1], B[2]-A[2])
	{};	

	vector_t(const double& a, const double& b, const double& c)
	:array_1x3<T>(a, b, c)
	{};	


	double norm()
	{
		double ret = (*this)[0]*(*this)[0] + (*this)[1]*(*this)[1] + (*this)[2	]*(*this)[2];
		return sqrt(ret);
	}

	double normalize()
	{
		*this /= this->norm();
		// this->_x /= this->norm();
		// this->_y /= this->norm();
		// this->_z /= this->norm();
	}
};

template<typename T>
double dot(const vector_t<T>& vec1 ,const  vector_t<T>& vec2)
{
	return vec1[0]*vec2[0]+vec1[1]*vec2[1]+vec1[2]*vec2[2];
}

#endif