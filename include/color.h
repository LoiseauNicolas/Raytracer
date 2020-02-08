#pragma once 

#include "geometry/array_1x3.h"


template<class T> class color_u	: public array_1x3<T>
{
	using type_t = T;

public:
	// color_u() : array_1x3<T>(0,0,0){}

	// color_u(type_t &r, type_t &g, type_t &b)
	// 	:array_1x3<type_t>(r,g,b){}

	constexpr color_u() : array_1x3<T>(){};

	constexpr color_u(const T &x, const T &y, const T &z)
	: array_1x3<T>(x,y,z){}

	constexpr color_u(const array_1x3<T> &a):array_1x3<T>(a){}

	// friend std::ostream& operator<<(std::ostream& os, const color_u<T> &col){
 //  	os<<"Scene: "<<" W: "<<s._width<<" H: "<<s._height<<" _d: "<<s._d;
	// 	os<<" Phi: "<<_phiR<<" Obs:"<<_observator_default<<std::endl;
 //  	return os;
 //  }


};
