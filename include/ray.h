#ifndef RAY_H
#define RAY_H

#include <cmath>
#include <iostream>

#include "point.h"
#include "vector.h"

template<typename T> class ray_t	
{
private: 
	vector_t _direction;
	point_t _origin;

public:
	ray_t(){};
	ray_t(const vector_t &dir, const point_t &ori)
	{
		_direction = dir;_origin = ori;
	};

	// setters et getters ? 
	point_t getOrigin()
	{
		return _origin;
	}

	vector_t<T> getDirection()
	{
		return _direction;
	}
};

#endif