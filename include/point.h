#ifndef point_h
#define point_h

#include <cmath>
#include <iostream>

#include "array_1x3.h"

template <typename T> class point_t	: public array_1x3<T>
{
// private:

public:
	// Constructeurs
	point_t() : array_1x3<T>(){};
	point_t(const T &x, const T &y, const T &z) : array_1x3<T>(x,y,z){};
	point_t(const array_1x3<T> &__):array_1x3<T>(__){};

	T distance(const point_t &__) const
	{
        return sqrt((__[0]-*this->_array[0])*(__[0]-*this->_array[0])+
                    (__[1]-*this->_array[1])*(__[1]-*this->_array[1])+
                    (__[2]-*this->_array[2])*(__[2]-*this->_array[2]));
	}

};

template<typename T>
T distance(const point_t<T> &_1, const point_t<T> &_2)
{
	return sqrt((_1[0]-_2[0])*(_1[0]-_2[0])+
                (_1[1]-_2[1])*(_1[1]-_2[1])+
                (_1[2]-_2[2])*(_1[2]-_2[2]));
}


#endif










	// // Constructeurs
	// point_t() : _x(0),_y(0),_z(0){};
	// point_t(double x, double y, double z) : _x(x),_y(y),_z(z){};

	// //getteurs et setteurs
	// void setX(double x){this->_x=x;};
	// void setY(double y){this->_y=y;};
	// void setZ(double z){this->_z=z;};
	// double getX() const { return this->_x;};
	// double getY() const { return this->_y;};
	// double getZ() const { return this->_z;};

	// // Autres méthodes
	// double distance(const point_t &P) const
	// {
	// 	double dx = this->_x - P._x;
	// 	double dy = this->_y - P._y;
	// 	return sqrt(dx*dx + dy*dy);
	// }
	// // Point milieu(const Point &P) const;

	// // void saisir();
	// void afficher() const
	// {
	// 	std::cout << "x : " << this->_x << std::endl;
	// 	std::cout << "y : " << this->_y << std::endl;
	// 	std::cout << "z : " << this->_z << std::endl;
	// }
