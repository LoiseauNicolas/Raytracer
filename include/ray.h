#ifndef RAY_H
#define RAY_H

#include <cmath>
#include <iostream>

#include "point.h"
#include "vector.h"

class ray_t	
{
public:
	vector_t _direction;
	point_t _origin;

	ray_t(){};

	ray(const vector_t &dir, const point_t &ori)
	: _direction(dir), _origin(ori)
	{};

	// setters et getters ? 


	

};

#endif