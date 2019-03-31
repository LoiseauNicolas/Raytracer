#pragma once

#include "geometry/array_1x3.h"

class pixel_t : public array_1x3<unsigned char>
{
public:

	pixel_t():array_1x3<unsigned char>(){};

	pixel_t(const unsigned char &r, const unsigned char &g,
		const unsigned char &b) :array_1x3<unsigned char>(r,g,b){};

};
