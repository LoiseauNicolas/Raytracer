#ifndef pixel_h
#define pixel_h

class pixel_t	
{
public:

	unsigned char _r, _g, _b;

	/** pixel par default	*/
	pixel_t():_r(0),_g(0),_b(0){};

	pixel_t(const unsigned char &r,const unsigned char &g, const unsigned char &b)
	:_r(r),_g(g),_b(b)
	{};

	
};

#endif