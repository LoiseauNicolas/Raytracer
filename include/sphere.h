#pragma once

#include <cmath>
#include <iostream>

#include "point.h"
#include "vector.h"
#include "ray.h"

template<class T>
class sphere_t
{

private:

	point_t<T> _origin;
	T _radius;
	T _color_a; //! Ambiant color
	T _k_s; //! Specular coef
	T _k_d; //! Diff coef

public:

	sphere_t(){};
	sphere_t(const point_t<T> &p, const double &rad):_origin(p), _radius(rad)
	{};

	bool intersect(const ray_t<T> &ray, point_t<T> &inter)
	{
		double t=0;
		double r2 = _radius*_radius;
		vector_t<T> A(_origin, ray._origin);
		double a2 = dot(A, A);
		double u2 = dot(ray._direction, ray._direction);
		double d = dot(ray._direction, A);
		double delta = d*d - u2*(a2-r2);

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
