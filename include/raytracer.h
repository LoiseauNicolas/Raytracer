#pragma once

#include "pixel.h"

class raytracer{

public:

	raytracer(){}

	template<typename T>
	void render(scene_t<T>& scene){

    float step_x = (float)scene.height()/(float)scene.height();
    float step_y = (float)scene.width()/(float)scene.width();


		for(int i=0 ; i<scene.height() ; ++i){
			for(int j=0; j<scene.width(); ++j){

				float xdir = (j*step_x-scene.width()/2);
                float ydir = (i*step_y-scene.height()/2);
                float zdir = 1.;

				vector_t<T> direction = vector_t<T>
					(scene.observator(),
					point_t<T>( xdir, ydir, zdir ));

				ray_t<T> ray = ray_t<T>(direction, scene.observator());

				// TODO: Retourner une couleur ici
				point_t<T> pixel_color = launch_ray(ray, scene);
				// Utiliser la couleur retournee precedemment:
				// La transformer de 0-1 vers 0-255
				scene(i,j) = pixel_t(
					pixel_color[0]*255, pixel_color[1]*255, pixel_color[2]*255);
			}
		}
	}


	template<typename T>
	static point_t<T> launch_ray(ray_t<T> & ray, scene_t<T>& scene){

		T curr_dist = std::numeric_limits<T>::max();
		int index = -1;
		int i = 0;

		for(auto obj: scene.objects()){
			point_t<T> contact;
      // Intersect
      if( obj.intersect(ray,contact) ){
      	if(distance(scene.observator(),contact) < curr_dist){
					index = i;
      	}
      }
			++i;
		}
		// TODO retourner la couleur du fond si curr_dist == max
		// Autrement retourner la couleur de l'objet:
		// - Ajouter une couleur de fond dans l'objet scene : rgb entre 0-1
		if(index == -1)
			return point_t<T>{0,0,0};
		return scene.objects()[index].color_a();
	}


	template<typename T>
	void output(const char * name, scene_t<T> scene){
		io::output_window_wait(name, scene.pixels(), scene.width(), scene.height());
		io::output_file(name, scene.pixels(), scene.width(), scene.height());

	}
};
