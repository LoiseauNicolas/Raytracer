#pragma once

#include <iostream>
#include "geometry/sphere.h"
#include "geometry/cylinder.h"
#include "pixel.h"
#include "geometry/point.h"
#include "light.h"
#include "color.h"

template <typename T> class scene_t
{
	using light_t = light_u<T>;
	using color_t = color_u<T>;

private:
	std::vector<sphere_t<T>> _objects;
	std::vector<pixel_t> _pixels;
	std::vector<light_t> _lights;

	int64_t _width;
	int64_t _height;

	point_t<T> _observator;
	color_t _background;


	static constexpr T _phiD = 40;
	static constexpr T _phiR = _phiD*M_PI/180;
	static constexpr T _r = 1.0;
	static constexpr T _d = _r/_phiR;
	static constexpr int64_t _width_default = 800;//1024;
	static constexpr int64_t _height_default = 600;//768;
	static const point_t<T> _observator_default;
	static color_t _backgroung_default;

public:

	scene_t(): _width(_width_default), _height(_height_default),
		_observator(_observator_default), _background(_backgroung_default) {
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

	T r() const {return _r;}
	int64_t width() const {return _width;}
	int64_t height() const {return _height;}
	color_t background() const {return _background;}

	point_t<T>& observator() {return _observator;}
	std::vector<pixel_t>& pixels() {return _pixels;}


  friend std::ostream& operator<<(std::ostream& os, const scene_t<T> &s){
  	os<<"Scene: "<<" W: "<<s._width<<" H: "<<s._height<<" _d: "<<s._d;
		os<<" Phi: "<<_phiR<<" Obs:"<<_observator_default<<std::endl;
  	return os;
  }
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
const point_t<T> scene_t<T>::_observator_default = point_t<T>{0,0,
	-scene_t<T>::_d};

template<typename T>
color_u<T> scene_t<T>::_backgroung_default = color_u<T>{0.8,0.8,0.8};
