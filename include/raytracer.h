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

		for(int i=0 ; i<scene.height() ; ++i){
			for(int j=0; j<scene.width(); ++j){
				unsigned char a = (unsigned char)i;
				unsigned char b = (unsigned char)j;
				unsigned char c = (unsigned char) ((i+j)/2);
				scene(i,j) = pixel_t(a, b, c);
			}
		}
	}

	template<typename T>
	void output(const char * name, scene_t<T> scene){
		io::output_window_wait(name, scene.pixels(), scene.width(), scene.height());
		io::output_file(name, scene.pixels(), scene.width(), scene.height());

	}


};
