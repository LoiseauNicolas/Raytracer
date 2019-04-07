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

	scene.add_object<sphere>(point{0,0,4},			1.0,color_t{0.5,0,0});
	scene.add_object<sphere>(point{0.0,-0.4,4},		1.0,color_t{0,0.5,0});
	scene.add_object<sphere>(point{-0.4,0.0,4},		1.0,color_t{0,0,0.5});
	scene.add_object<sphere>(point{0.6,0.6,4},		1.0,color_t{0.5,0.5,0});
	scene.add_object<sphere>(point{-0.6,-0.6,5},	1.0,color_t{0,0.5,0.5});
	scene.add_object<sphere>(point{0.7,-0.7,4},		1.0,color_t{0.5,0.5,0.5});
	scene.add_object<sphere>(point{2,-2,0},			1.0,color_t{1.,1.,1.});
	// scene.add_object<cylinder>(point{0,0,100},110.0,point_t<type_t>{1.,1.,0});
	scene.add_light<light_t>(point{0,0,-1});

	raytracer rt;
	rt.render(scene);
	rt.output("name.png",scene);

}
