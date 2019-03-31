#pragma once

#include <cmath>
#include <iostream>

#include "geometry/point.h"
#include "geometry/vector.h"
#include "geometry/ray.h"

template<class T>
class sphere_t
{

	using type_t = T;

private:

	point_t<type_t> _origin;
	type_t _radius;
	type_t _color_a; //! Ambiant color
	type_t _k_s; //! Specular coef
	type_t _k_d; //! Diff coef

public:

	sphere_t(){};
	sphere_t(const point_t<type_t> &p, const type_t &rad)
		:_origin(p), _radius(rad){}

	bool intersect(const ray_t<type_t> &ray, point_t<type_t> &inter)
	{
		type_t t=0;
		type_t r2 = _radius*_radius;
		vector_t<type_t> A(_origin, ray._origin);
		type_t a2 = dot(A, A);
		type_t u2 = dot(ray._direction, ray._direction);
		type_t d = dot(ray._direction, A);
		type_t delta = d*d - u2*(a2-r2);

		if(delta < 0){
            return false;
        }

        if(a2 < r2){
            t = (-d+sqrt(delta)/u2);
        }else if(d >= 0){
            return false;
        }else{
            t = (-d-sqrt(delta)/u2);
        }
        inter = A + t*ray._direction;
        return true;
	}

};
