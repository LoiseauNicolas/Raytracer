#pragma once

#include "geometry/array_1x3.h"
#include "geometry/point.h"

template<typename T> class light_u
{
	using type_t = T;
	using point_ = point_t<type_t>;

private:
	point_ position_;

public:
	light_u(){};
	light_u(point_ pos):position_(pos){};


	point_ position(){return position_;}

};