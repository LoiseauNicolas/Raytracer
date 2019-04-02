#include <stdio.h>
#include <opencv2/opencv.hpp>

#include "io_ocv.h"
#include "scene.h"
#include "raytracer.h"


using namespace std;

using type_t = float;
using scene = scene_t<type_t>;
using sphere = sphere_t<type_t>;
using point = point_t<type_t>;
using light_t = light_u<type_t>;

int main(int argc, char **argv) {

	scene scene;
	scene.add_object<sphere>(point{100,0,100},110.0,point_t<type_t>{1.,0,0});
	scene.add_object<sphere>(point{0,0,100},110.0,point_t<type_t>{0,1.,0});
	scene.add_light<light_t>(point{0,0,-100});

	raytracer rt;
	rt.render(scene);
	rt.output("name.png",scene);

}
