#pragma once

#include "pixel.h"

class raytracer{

public:

	raytracer(){}

	template<typename T>
	void render(scene_t<T>& scene){
		// 1 . Pour chaque pixels ( double boucle for )
		// 2 . Calculer la position du pixel, normaliser l'écran !
		// 3 . Calculer le rayon
		// 4 . Utiliser une fonction launch_ray qui prend un rayon et les objets
		// 5 . Pour tous les objets calculaer les intersections, retourner la plus
		// proche de l'écran
		// 6 . Utiliser cette couleur (entre 0-1) et la transformer en RGB

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
					// point_t<T>( scene(i,j)[0], scene(i,j)[1], scene(i,j)[2]) );

				ray_t<T> ray = ray_t<T>(direction, scene.observator());

				bool pixel_color = launch_ray(ray, scene);

				if(pixel_color == true)
					scene(i,j) = pixel_t(100, 10, 10);
				else
					scene(i,j) = pixel_t(0, 0, 0);
			}
		}
	}


	template<typename T>
	static bool launch_ray(ray_t<T> & ray, scene_t<T>& scene){
		bool intersection = false;
		T curr_dist = std::numeric_limits<T>::max();

		for(auto obj: scene.get_objects()){
			point_t<T> contact;
            // Intersect 
            if( obj.intersect(ray,contact) )
            {
            	// std::cout << " ok ";
            	if(distance(scene.observator(),contact) < curr_dist){
            		intersection = true;
            		// std::cout << " pkPas ";
            	}

            }
            	// std::cout<<"mouais";
            // obj.print();	
		}

		return intersection;
	}


	template<typename T>
	void output(const char * name, scene_t<T> scene){
		io::output_window_wait(name, scene.pixels(), scene.width(), scene.height());
		io::output_file(name, scene.pixels(), scene.width(), scene.height());

	}


};
				// unsigned char a = (unsigned char) 50;
				// unsigned char b = (unsigned char) 50;
				// unsigned char c = (unsigned char) 50;
				// scene(i,j) = pixel_t(a, b, c);
