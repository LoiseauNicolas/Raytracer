#pragma once

#include "pixel.h"
#include "color.h"

class raytracer{

public:

	raytracer(){}

	template<typename T>
	void render(scene_t<T>& scene){
		using color_t = color_u<T>;

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
				color_t pixel_color = launch_ray(ray, scene);
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
		using sphere = sphere_t<T>;
		using color_t = color_u<T>;


		T curr_dist = std::numeric_limits<T>::max();
		int index=-1, i=0;
		sphere closestSphere;
		point_t<T> closestInter;



		// TODO : Cours mignot ... vecteur prend le pas sur l'autre.

		for(auto obj: scene.objects()){
			point_t<T> contact;
			// Intersect
			if( obj.intersect(ray,contact) ){
				if(distance(scene.observator(),contact) < curr_dist){
					index = i;
					curr_dist = distance(scene.observator(),contact);
					closestInter = contact;
				}
			}
			++i;
		}
		closestSphere = scene.objects()[i];
		// TODO retourner la couleur du fond si curr_dist == max
		// Autrement retourner la couleur de l'objet:
		// - Ajouter une couleur de fond dans l'objet scene : rgb entre 0-1
		if(index == -1)
			return scene.background();
		else{

			// N = normal à la surface de l'objet closest au point P
			// vector_t<T> V = vector_t<T>(scene.lights()[0].position(),
				// closest.origin());
			vector_t<T> lightVec = vector_t<T>(closestInter,
				scene.lights()[0].position());
			lightVec.normalize();

			color_t finalColor;

			

			return scene.objects()[index].color_a();
		}


	}


	template<typename T>
	void output(const char * name, scene_t<T> scene){
		io::output_window_wait(name, scene.pixels(), scene.width(), scene.height());
		io::output_file(name, scene.pixels(), scene.width(), scene.height());

	}
};
