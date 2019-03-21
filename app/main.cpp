#include <stdio.h>
#include <opencv2/opencv.hpp>

#include "io_ocv.h"
#include "pixel.h"

#include "array_1x3.h"
#include "point.h"

#include "ray.h"

// #include "sphere.h"

using namespace std;

int main(int argc, char **argv) {

	std::cout << "Première image" << std::endl;

	// array_1x3<int> a(1,2,3);
	// array_1x3<int> c(1,2,3);
	// array_1x3<int> b(2,3,4);

	// cout << a << "  " << b << endl;
	
	// cout << a*2 << "  " << c*c*2 << endl;

	// point_t<int> p1(0,0,0);
	// point_t<int> p2(5,5,0);

	// cout << distance(p2,p1) << endl;


	int width = 255, height = 255;
	// std::vector<pixel_t> image(width*height);
	std::vector<pixel_t> image;
	for(int i=0 ; i<width ; ++i)
	{
		for(int j=0; j<height; ++j)
		{
			unsigned char a = (unsigned char)i;
			unsigned char b = (unsigned char)j;
			unsigned char c = (unsigned char) ((i+j)/2);
			pixel_t *p = new pixel_t(a, b, c);
			image.push_back (*p);
		}
	}

	// sphere_t *s = new sphere_t();
	// std::cout << s->_origin.getX();

	io::output_window_wait("bonjour.png", image, width, height);
	io::output_file("bonjour.png", image, width, height);


}