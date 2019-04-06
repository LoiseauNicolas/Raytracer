#pragma once

#include "pixel.h"

class raytracer{
public:

	raytracer(){}

	template<typename T>
	void render(scene_t<T>& scene){

		const float delta = (2.0*scene.r()) / std::min(scene.height(),
			scene.width());

		for(int i=0 ; i<scene.height() ; ++i){
			for(int j=0; j<scene.width(); ++j){

				float xdir = ((-scene.width()/2.) + j)*delta;
				float ydir = ((scene.height()/2.) - i)*delta;
				float zdir = 1.;
				point_t<T> screen_pt = point_t<T>( xdir, ydir, zdir );

				vector_t<T> direction = vector_t<T>(scene.observator(),screen_pt);

				ray_t<T> ray = ray_t<T>(direction, scene.observator());

				// TODO: Retourner une couleur ici
				color_u<T> pixel_color = launch_ray(ray, scene);
				// Utiliser la couleur retournee precedemment:
				// La transformer de 0-1 vers 0-255
				scene(i,j) = pixel_t(
					pixel_color[0]*255, pixel_color[1]*255, pixel_color[2]*255);



				// Teste d'ajout de lumière
				// for(auto light: scene.lights()){

				// 	float xdir = (j*step_x-scene.width()/2);
				// 	float ydir = (i*step_y-scene.height()/2);
				// 	float zdir = 1.;

				// 	point_t<T> cont;
				// 	vector_t<T> dir = vector_t<T>
				// 		(light.position(),
				// 		point_t<T>( xdir, ydir, zdir ));

				// 	ray_t<T> ray = ray_t<T>(dir, light.position());
				// 	int p = 0, index =0;
				// 	T curr_dist = std::numeric_limits<T>::max();
				// 	for(auto obj: scene.objects()){
				// 		if( obj.intersect(ray,cont) ){
				// 			if(distance(scene.observator(),cont) < curr_dist){
				// 				index = p;
				// 			}
				// 		}
				// 	}
				// 	pixel_t tmp = pixel_t(0,0,1.0);
				// 	if(index != -1)
				// 		scene(i,j) =pixel_t(
				// 			tmp[0]*255, tmp[1]*255, tmp[2]*255);

				// }

			}
		}
	}


	template<typename T>
	static color_u<T> launch_ray(ray_t<T> & ray, scene_t<T>& scene){


		// float rr = pow(float(scene.width()),2)+pow(float(scene.height()),2);
		// float r = 0.5 * sqrt( float(rr) );
		// std::cout << r << " " << 0.5 * sqrt(rr) << std::endl;

		T curr_dist = std::numeric_limits<T>::max();
		// T curr_dist = 0;
		int index = -1;
		int i = 0;

		// TODO : Cours mignot ... vecteur prend le pas sur l'autre.

		for(auto obj: scene.objects()){
			point_t<T> contact;
			// Intersect
			if( obj.intersect(ray,contact) ){
				if(distance(scene.observator(),contact) < curr_dist){
					index = i;
					curr_dist = distance(scene.observator(),contact);
				}
			}
			++i;
		}
		// TODO retourner la couleur du fond si curr_dist == max
		// Autrement retourner la couleur de l'objet:
		// - Ajouter une couleur de fond dans l'objet scene : rgb entre 0-1
		if(index == -1)
			return scene.background();

		return scene.objects()[index].color_a();
	}


	template<typename T>
	void output(const char * name, scene_t<T> scene){
		io::output_window_wait(name, scene.pixels(), scene.width(), scene.height());
		io::output_file(name, scene.pixels(), scene.width(), scene.height());

	}
};
