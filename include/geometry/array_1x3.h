#pragma once

template<typename T>
class array_1x3
{
private:

	T _array[3];

public:

	constexpr array_1x3(): _array{T{},T{},T{}} {}

	constexpr array_1x3(const T &r, const T &g, const T &b): _array{r,g,b}{}

	constexpr array_1x3(const array_1x3 &a):  _array{a[0],a[1],a[2]}{}

	~array_1x3(){}

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

	array_1x3& operator*=(const array_1x3 &a)
	{
		_array[0] *= a[0];
		_array[1] *= a[1];
		_array[2] *= a[2];
		return *this;
	}

	array_1x3& operator*=(const T& a)
	{
		_array[0] *= a;
		_array[1] *= a;
		_array[2] *= a;
		return *this;
	}

	array_1x3<T> operator*(const T& value)
	{
		array_1x3<T> tmp(*this);
		tmp *= value;
		return tmp;
	}

	array_1x3<T> operator*(const array_1x3& a)
	{
		array_1x3<T> tmp(*this);
		tmp *= a;
		return tmp;
	}

	// Vérifier les divisions par 0 ? utile ?
	array_1x3& operator/=(const array_1x3 &a)
	{
		_array[0] /= a[0];
		_array[1] /= a[1];
		_array[2] /= a[2];
		return *this;
	}

	array_1x3& operator+=(const array_1x3 &a)
	{
		_array[0] += a[0];
		_array[1] += a[1];
		_array[2] += a[2];
		return *this;
	}

	array_1x3& operator-=(const array_1x3 &a)
	{
		_array[0] -= a[0];
		_array[1] -= a[1];
		_array[2] -= a[2];
		return *this;
	}

	bool operator==(const array_1x3 &a)
	{
		if(_array[0]==a[0] & _array[1]==a[1] & _array[2]==a[2])
			return 1;
		return 0;
	}

	bool operator!=(const array_1x3 &a)
	{
		if(_array[0]==a[0] & _array[1]==a[1] & _array[2]==a[2])
			return 0;
		return 1;
	}

};

template<typename T>
array_1x3<T> operator*(const T &__val, array_1x3<T> __array)
{
	__array*=__val;
	return __array;
}

template<typename T>
std::ostream& operator<<(std::ostream & s, const array_1x3<T> &a)
{
    s << "["<<a[0]<<","<<a[1]<<","<<a[2]<<"]";
    return s;
}
