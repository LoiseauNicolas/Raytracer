#ifndef pixel_h
#define pixel_h

#include "array_1x3.h"

class pixel_t : public array_1x3<unsigned char>
{
public:

	pixel_t():array_1x3<unsigned char>(){};
	pixel_t(const unsigned char &r, const unsigned char &g, const unsigned char &b)
	:array_1x3<unsigned char>(r,g,b){};

	
};

#endif


	// unsigned char _r, _g, _b;

	// pixel_t():_r(0),_g(0),_b(0){};

	// pixel_t(const unsigned char &r,const unsigned char &g, const unsigned char &b)
	// :_r(r),_g(g),_b(b)
	// {};