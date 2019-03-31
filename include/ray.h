#pragma once

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
	ray_t(){}

	ray_t(
		const vector_t<T> &dir, const point_t<T> &ori)
		: _direction(dir), _origin(ori){}

	// setters et getters ?
	point_t<T> origin() { return _origin;}
	vector_t<T> direction() { return _direction;}

	void set_origin(const point_t<T>& origin){ _origin = origin;}
	void set_direction(const vector_t<T>& direction){ _direction = direction;}

};
