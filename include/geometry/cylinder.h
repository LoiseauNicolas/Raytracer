#pragma once

#include <cmath>
#include <iostream>

#include "geometry/point.h"
#include "geometry/vector.h"
#include "geometry/ray.h"

template<class T>
class cylinder_u
{

	using type_t = T;

private:

	point_t<type_t> _origin;
	type_t _radius;
	point_t<type_t> _color_a; //! Ambiant color
	type_t _k_s; //! Specular coef
	type_t _k_d; //! Diff coef

public:

	cylinder_u(){};
	cylinder_u(
		const point_t<type_t> &p,
		const type_t &rad,
		const point_t<type_t>& color_a)
		:_origin(p), _radius(rad), _color_a(color_a){}

	bool intersect(ray_t<type_t> &ray, point_t<type_t> &inter)
	{
		type_t t=0;

		// type_t u2 = dot(inter, inter);
		// vector_t<type_t> A( this->_origin, ray.origin() );
		// type_t d = dot(ray.direction(), A);

		// type_t r2 = this->_radius*this->_radius;
		// vector_t<type_t> A( this->_origin, ray.origin() );
		// type_t a2 = dot(A, A);
		// type_t u2 = dot(ray.direction(), ray.direction());
		// type_t d = dot(ray.direction(), A);
		// type_t delta = d*d - u2*(a2-r2);

		// if(delta < 0){
  //           return false;
  //       }

  //       if(a2 < r2){
  //           t = (-d+sqrt(delta)/u2);
  //       }else if(d >= 0){
  //           return false;
  //       }else{
  //           t = (-d-sqrt(delta)/u2);
  //       }
  //       inter = A + t*ray.direction();
        return true;
	}

	void print(){std::cout<<"ok";}

	point_t<type_t> color_a(){return _color_a;}

};
#pragma once

// I NTERSECTION R AYON (A, u) C YLINDRE (O, r, Oz)
// u z 2 = u z .u z .
// d = u ⊥
// z .A z
// ∆ = r 2 .u z 2 − d 2
// si ∆ < 0 alors pas d’intersection
// l = u z .A z
// a 2 = A.A
// si l > 0 et a 2 √ > r 2 alors pas d’intersection
// t ± = (−l ± ∆)/u z 2
// intersections = A + t ± .u