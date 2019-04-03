#pragma once

#include "geometry/sphere.h"
#include "geometry/cylinder.h"
#include "pixel.h"
#include "geometry/point.h"
#include "light.h"

template <typename T> class scene_t
{
	using light_t = light_u<T>;

private:
	std::vector<sphere_t<T>> _objects;
	std::vector<pixel_t> _pixels;
	std::vector<light_t> _lights;


	size_t _width;
	size_t _height;

	point_t<T> _observator;


	static constexpr size_t _width_default = 800;//1024;
	static constexpr size_t _height_default = 600;//768;
	static const point_t<T> _observator_default;

public:

	scene_t(): _width(_width_default), _height(_height_default),
		_observator(_observator_default) {
		_pixels.resize(_width*_height);
	};

	pixel_t& operator()(const int i, const int j){
		assert(i*_width+j < _width*_height);
		return _pixels[i*_width+j];
	}

	template<class O, typename... ARGS>
	void add_object(ARGS... args){
		_objects.emplace_back(O(std::forward<ARGS>(args)...));
	}

	template<class L, typename... ARGS>
	void add_light(ARGS... args){
		_lights.emplace_back(L(std::forward<ARGS>(args)...));
	}

	std::vector<sphere_t<T>>& objects() { return _objects; }
	std::vector<light_t>& lights() { return _lights; }

	size_t width() const {return _width;}
	size_t height() const {return _height;}
	point_t<T>& observator() {return _observator;}
	std::vector<pixel_t>& pixels() {return _pixels;}

};

// TODO  La distance de l'observateur est cruciale !
// Elle represente un objectif d'appareil photo et sa focale.
// Cours de Pascal Mignot :
// http://mathinfo.univ-reims.fr/image/siPipeline/Documents/2005-Initiation.pdf
// Page 18. On peut calculer cette distance en fonction de l'angle
// d'ouverture
// Trop proche et les objets sont distordus et trop loin et les objects
// sur les cotes sont distordus.
template<typename T>
const point_t<T> scene_t<T>::_observator_default = point_t<T>{0,0,-100};
