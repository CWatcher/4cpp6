#pragma once
#include <string>
#include <stdexcept>
#include <typeinfo>

class Converter {
public:
	Converter( std::string const & ) throw ( std::invalid_argument );
	Converter( Converter const & src );
	~Converter();

	Converter &	operator=( Converter const & rhs );

	operator double () const throw( std::bad_cast );

private:
	double		_d;
};
