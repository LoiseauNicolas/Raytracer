#pragma once

#include "sphere.h"
#include "pixel.h"
#include "point.h"

template <typename T> class scene_t
{
private:
	std::vector<sphere_t<T>> _objects;
	std::vector<pixel_t> _pixels;

	size_t _width;
	size_t _height;

	point_t<T> _observator;

	static constexpr size_t _width_default = 1024;
	static constexpr size_t _height_default = 768;
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

	size_t width() const {return _width;}
	size_t height() const {return _height;}
	std::vector<pixel_t>& pixels() {return _pixels;}

};

template<typename T>
const point_t<T> scene_t<T>::_observator_default = point_t<T>{0,0,-5};
