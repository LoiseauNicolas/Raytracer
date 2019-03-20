#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>
#include <iostream>

#include "point.h"

class vector_t	
{
public:

	// http://olivier.buga.free.fr/sandy/bases.html
	double _x,_y,_z;

	vector_t(){};

	vector_t(const point_t& A, const point_t &B)
	:_x(B._x-A._x), _y(B._y-A._y), _z(B._z-A._z)
	{};	

	vector_t(const double& a, const double& b, const double& c)
	:_x(a), _y(b), _z(c)
	{};	


	double norm()
	{
		double ret = this->_x*this->_x + this->_y*this->_y + this->_z*this->_z;
		return sqrt(ret);
	}

	double normalize()
	{
		this->_x /= this->norm();
		this->_y /= this->norm();
		this->_z /= this->norm();
	}
	double dot(const vector_t& vec1 ,const  vector_t& vec2)
	{
		return vec1._x*vec2._x+vec1._y*vec2._y+vec1._z*vec2._z;
	}
};

#endif