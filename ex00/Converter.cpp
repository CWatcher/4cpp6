#include "Converter.hpp"
#include <sstream>
#include <cstring>
#include <cmath>

#include <iostream>

Converter::Converter( std::string s ) throw ( std::invalid_argument )
{
	if ( s.length() == 1 )
	{	if ( isdigit( s[0] ) )
		{	_type = tInt;
			_data.i = s[0] - '0';
		}
		else if ( isprint( s[0] ))
		{	_type = tChar;
			_data.c = s[0];
		}
	}
	else if ( s == "-inf" )
	{	_type = tDouble;
		_data.d = -INFINITY;
	}
	else if ( s == "+inf" )
	{	_type = tDouble;
		_data.d = INFINITY;
	}
	else if ( s == "nan" )
	{	_type = tDouble;
		_data.d = NAN;
	}
	else if ( s == "-inff" )
	{	_type = tFloat;
		_data.f = -INFINITY;
	}
	else if ( s == "+inff" )
	{	_type = tFloat;
		_data.f = INFINITY;
	}
	else if ( s == "nanf" )
	{	_type = tFloat;
		_data.f = NAN;
	}
	else
	{	std::stringstream	ss( s );
		if ( s.end()[-1] == 'f' )
		{	s.end()[-1] = '\0';
			ss.str(s);
			_type = tFloat;
			ss >> _data.f;
		}
		else if ( s.find( '.' ) != std::string::npos )
		{	_type = tDouble;
			ss >> _data.d;
		}
		else
		{	_type = tInt;
			ss >> _data.i;
		}
		if ( ss.fail() )
		{	_data.d = NAN;
			_type = tNone;
			throw std::invalid_argument(
				"Argument is not a char, int, float or double");
		}
	}
}
Converter::Converter( const Converter & src )
:	_data( src._data )
{}
Converter::~Converter()
{}

Converter &	Converter::operator=( Converter const & rhs )
{
	_data = rhs._data;
	return *this;
}

Converter::operator double () const throw( std::bad_cast )
{
	switch ( _type )
	{	case tChar	: throw std::bad_cast();
		case tInt	: return static_cast< double >( _data.i );
		case tFloat	: return static_cast< double >( _data.f );
		case tDouble: return static_cast< double >( _data.d );
		default		: throw std::bad_cast();
	}

}
