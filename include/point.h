#ifndef point_h
#define point_h

#include <cmath>
#include <iostream>

class point_t	
{
public:
	double _x,_y,_z;

	// Constructeurs
	point_t() : _x(0),_y(0),_z(0){};
	point_t(double x, double y, double z) : _x(x),_y(y),_z(z){};

	//getteurs et setteurs
	void setX(double x){this->_x=x;};
	void setY(double y){this->_y=y;};
	void setZ(double z){this->_z=z;};
	double getX() const { return this->_x;};
	double getY() const { return this->_y;};
	double getZ() const { return this->_z;};

	// Autres méthodes
	double distance(const point_t &P) const
	{
		double dx = this->_x - P._x;
		double dy = this->_y - P._y;
		return sqrt(dx*dx + dy*dy);
	}
	// Point milieu(const Point &P) const;

	// void saisir();
	void afficher() const
	{
		std::cout << "x : " << this->_x << std::endl;
		std::cout << "y : " << this->_y << std::endl;
		std::cout << "z : " << this->_z << std::endl;
	}

};

#endif