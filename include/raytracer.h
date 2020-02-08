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
				color_t pixel_color = launch_ray(ray, scene, screen_pt);
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
	static color_u<T> launch_ray(ray_t<T> & ray, scene_t<T>& scene, point_t<T> screen_pt){
		using sphere = sphere_t<T>;
		using color_t = color_u<T>;

		T curr_dist = std::numeric_limits<T>::max();
		int index=-1, i=0;
		sphere closestSphere;
		point_t<T> closestInter;

		T curr_dist_light = std::numeric_limits<T>::max();
		int index_light=-1, i_light=0;
		sphere closestSphere_tolight;
		point_t<T> closestInter_tolight;


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





			// screen_pt : point de l'image 
			// Direction entre le point de l'image et la position de la luz
			// PA
			vector_t<T> direction = vector_t<T>(closestInter,scene.lights()[0].position());
			direction.normalize();
			// rayon lumière (direction et position de la luz)
			ray_t<T> rayLight = ray_t<T>(direction, closestInter);

			///
			bool contactobject = false;
			for(auto obj: scene.objects()){
				point_t<T> contact_tolight;
				// Intersect
				if( obj.intersect(rayLight,contact_tolight) ){ 
					contactobject = true;
					break;
					/*if(distance(scene.lights()[0].position(),contact_tolight) < curr_dist_light){
						index_light = i_light;
						curr_dist_light = distance(scene.lights()[0].position(),contact_tolight);
						closestInter_tolight = contact_tolight;
					}*/
				}
				++i_light;
			}
			closestSphere_tolight = scene.objects()[i_light];
			// rayon entre la position de la lumière et le point touché
			// vector_t<T> lightVec = vector_t<T>(closestInter_tolight,
			// 	scene.lights()[0].position());
			// lightVec.normalize();
			double r = 0.5;
			// (closestSphere_tolight.origin()).norm();



			// vecteur centre sphere et 
			// vector_t<T> direction_centertopoint = vector_t<T>(closestSphere_tolight.origin(),closestInter_tolight);
			// ray_t<T> ray_centertopoint = ray_t<T>(direction_centertopoint, closestSphere_tolight.origin());
			// vector_t<T> _centertopoint = vector_t<T>(closestInter_tolight,
				// scene.lights()[0].position());
			// lightVec.normalize();
			// closestInter_tolight

			// vector_t<T> vector_center = ray_centertopoint.direction();
			// vector_center.normalize();
			vector_t<T> _centertopoint = vector_t<T>(closestInter_tolight, scene.lights()[0].position());
				// scene.lights()[0].position());

			// lightVec.normalize();
			// Calcul de l'angle de frappe du rayon
			// (closestSphere_tolight.origin()).norm() 
			double angle = dot(direction, _centertopoint);
			// std::cout << angle << std::endl;



			color_t finalColor = scene.objects()[index].color_a();


			// if(angle<0){
			// 	std::cout << angle << "  ";
			// 	// finale scene.light().luminosité * color_d (couleur diffuse (0 et 5)) * couleur couleur ambiante de l'objet * angle
			// 	return finalColor;
			// }else{
			finalColor = finalColor * 0.5 * 1.0 * angle;
			return finalColor;
			// }

		}


	}


	template<typename T>
	void output(const char * name, scene_t<T> scene){
		io::output_window_wait(name, scene.pixels(), scene.width(), scene.height());
		io::output_file(name, scene.pixels(), scene.width(), scene.height());

	}
};
