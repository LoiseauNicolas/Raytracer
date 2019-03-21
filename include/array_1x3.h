#ifndef _ARRAY_1X3
#define _ARRAY_1X3

template<typename T> class array_1x3
{
private:

	T _array[3];

public:
	array_1x3()
	: _array{T{}, T{}, T{}}{};
	array_1x3(const T &r, const T &g, const T &b)
	{
		_array[0]=r;_array[1]=g;_array[2]=b;
	};
	array_1x3(const array_1x3 &__)	
	: _array{__[0],__[1],__[2]}{};
	~array_1x3(){};


	// Gérer les débordements ? 
	template<typename TYPE> 
	T& operator[](TYPE e)
	{
		return _array[static_cast<size_t>(e)];
	}
	template<typename TYPE>
	const T operator[](TYPE e) const
	{
		return _array[static_cast<size_t>(e)];
	}

	array_1x3& operator*=(const array_1x3 &__)
	{
		_array[0] *= __[0];_array[1] *= __[1];_array[2] *= __[2];
		return *this;
	}

	array_1x3& operator*=(const T& __) 
	{
		_array[0] *= __;_array[1] *= __;_array[2] *= __;
		return *this;
	}


	array_1x3<T> operator*(const T& value) 
	{
		array_1x3<T> tmp(*this);
		tmp *= value;
		return tmp;
	}

	array_1x3<T> operator*(const array_1x3& __) 
	{
		array_1x3<T> tmp(*this);
		tmp *= __;
		return tmp; 
	}

	// Vérifier les divisions par 0 ? utile ? 
	array_1x3& operator/=(const array_1x3 &__)
	{
		_array[0] /= __[0];_array[1] /= __[1];_array[2] /= __[2];
		return *this;
	}

	array_1x3& operator+=(const array_1x3 &__)
	{
		_array[0] += __[0];_array[1] += __[1];_array[2] += __[2];
		return *this;
	}

	array_1x3& operator-=(const array_1x3 &__)
	{
		_array[0] -= __[0];_array[1] -= __[1];_array[2] -= __[2];
		return *this;
	}




	bool operator==(const array_1x3 &__)
	{
		if(_array[0]==__[0] & _array[1]==__[1] & _array[2]==__[2])
			return 1;
		else return 0;
	}	

	bool operator!=(const array_1x3 &__)
	{
		if(_array[0]==__[0] & _array[1]==__[1] & _array[2]==__[2])
			return 0;
		else return 1;
	}	

};

template<typename T>
array_1x3<T> operator*(const T &__val, array_1x3<T> __array)
{
	__array*=__val;
	return __array;
}

template<typename T>
std::ostream& operator<<(std::ostream & s, const array_1x3<T> &__)
{
    s << "["<<__[0]<<","<<__[1]<<","<<__[2]<<"]";
    return s;
} 

#endif