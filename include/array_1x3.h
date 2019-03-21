#ifndef _ARRAY_1X3
#define _ARRAY_1X3

template<typename T> class array_1x3
{
private:

	T _array[3];

public:
	array_1x3()
	: _array(T{}, T{}, T{}){};
	array_1x3(const T &r, const T &g, const T &b) 
	:_array(r,g,b){};
	array_1x3(const array_1x3 &__)	
	:_array(__[0],__[1],__[2]){};
	~array_1x3(){};

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




	template<typename TYPE>
	std::ostream& operator<<(std::ostream & s, const array_1x3<TYPE> &__)
	{
	    s << "["<<__[0]<<","<<__[1]<<","<<__[2]<<"]";
	    return s;
	} 
};


#endif