#include "Converter.hpp"
#include <sstream>
#include <cmath>

Converter::Converter( std::string const & s ) throw ( std::invalid_argument )
{
	if ( s == "+inf" )
		_d = INFINITY;
	else
	{	std::stringstream	ss( s );
		ss >> _d;
		if ( ss.fail() )
			throw std::invalid_argument(
				"Argument is not a char, int, float or double");
	}
}
Converter::Converter( const Converter & src )
:	_d( src._d )
{}
Converter::~Converter()
{}

Converter &	Converter::operator=( Converter const & rhs )
{
	_d = rhs._d;
	return *this;
}

Converter::operator double () const throw( std::bad_cast )
{
	return _d;
}
