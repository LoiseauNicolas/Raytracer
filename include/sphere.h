#ifndef SPHERE_H
#define SPHERE_H

#include <cmath>
#include <iostream>

#include "point.h"
#include "vector.h"
#include "ray.h"

class sphere_t	
{
public:
	point_t _origin;
	double _radius;
	

	sphere_t(){};
	sphere_t(const point_t &p, const double &rad):_origin(p), _radius(rad)
	{};

	bool intersect(const ray_t &ray, point_t &inter)
	{
		double t=0;
		double r2 = _radius*_radius;
		vector_t A(_origin, ray._origin);
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

#endif