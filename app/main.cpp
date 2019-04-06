#include <stdio.h>
#include <opencv2/opencv.hpp>

#include "io_ocv.h"
#include "scene.h"
#include "raytracer.h"


using namespace std;

using type_t = float;
using scene = scene_t<type_t>;
using sphere = sphere_t<type_t>;
using cylinder = cylinder_u<type_t>;
using point = point_t<type_t>;
using light_t = light_u<type_t>;
using color_t = color_u<type_t>;

int main(int argc, char **argv) {

	scene scene;
	std::cout << scene << std::endl;

	scene.add_object<sphere>(point{0,0,3},0.1,color_t{0.5,0,0});
	// scene.add_object<sphere>(point{0,0,100},110.0,color_t{1.0,0,0});
	// scene.add_object<sphere>(point{0,10,110},110.0,color_t{0,0.5,0});
	// scene.add_object<sphere>(point{0,30,120},110.0,color_t{0,1.,0});
	// scene.add_object<sphere>(point{-50,50,130},110.0,color_t{0.5,1.,0});
	// scene.add_object<sphere>(point{-150,-150,140},110.0,color_t{1.0,1.,0.5});
	// scene.add_object<sphere>(point{90,-150,0},110.0,color_t{1.,1.,1.});
	// scene.add_object<cylinder>(point{0,0,100},110.0,point_t<type_t>{1.,1.,0});
	scene.add_light<light_t>(point{0,0,-100});

	raytracer rt;
	rt.render(scene);
	rt.output("name.png",scene);

}
