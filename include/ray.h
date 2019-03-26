#ifndef RAY_H
#define RAY_H

#include <cmath>
#include <iostream>

#include "point.h"
#include "vector.h"

template<typename T> class ray_t	
{
private: 
	vector_t<T> _direction;
	point_t<T> _origin;

public:
	ray_t(){};
	ray_t(const vector_t<T> &dir, const point_t<T> &ori)
	{
		_direction = dir;_origin = ori;
	};

	// setters et getters ? 
	point_t<T> getOrigin()
	{
		return _origin;
	}

	vector_t<T> getDirection()
	{
		return _direction;
	}
};

#endif