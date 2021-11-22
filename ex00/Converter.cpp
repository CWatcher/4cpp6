#include "Converter.hpp"
#include <sstream>
#include <cstring>
#include <cmath>
#include <limits>

bool Converter::try1Parse1Symbol( std::string const & s )
{
	if ( s.length() != 1 )
		return false;

	if ( isdigit( s[0] ) )
	{	_type = tInt;
		_data.i = s[0] - '0';
	}
	else
	{	_type = tChar;
		_data.c = s[0];
	}

	return true;
}
bool Converter::try2ParsePseudoLiterals( std::string const & s )
{
	if ( s == "-inf" )
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
		return false;

	return true;
}
bool Converter::try3ParseNumber( std::string s )
{
	std::stringstream	ss( s );
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
	if ( ss.fail() || (    ss.peek() != std::stringstream::traits_type::eof()
	                    && ss.peek() != '\0' ) )
	{	_data.d = NAN;
		_type = tNone;
		return false;
	}

	return true;
}

Converter::Converter( std::string const & s ) throw ( std::invalid_argument )
{
	if (    !try1Parse1Symbol( s )
	     && !try2ParsePseudoLiterals( s )
		 && !try3ParseNumber( s )
	   )
		throw std::invalid_argument(
			"Argument is not a char, int, float or double");
}
Converter::Converter( const Converter & src )
:	_data( src._data ), _type( src._type )
{}
Converter::~Converter()
{}

Converter &	Converter::operator=( Converter const & rhs )
{
	_data = rhs._data;
	return *this;
}

template< typename T > char	castToChar( T x ) throw( std::bad_cast, std::range_error )
{
	if (    x < std::numeric_limits< char >::min()
	     || x > std::numeric_limits< char >::max()
	   )
		throw std::bad_cast();

	char	c = static_cast< char >( x );

	if ( !isprint( c ) )
		throw std::range_error( "non-displayable" );

	return c;
}

Converter::operator char () const throw( std::bad_cast, std::range_error )
{
	switch ( _type )
	{	case tChar	: return _data.c;
		case tInt	: return castToChar ( _data.i );
		case tFloat	: return castToChar ( _data.f );
		case tDouble: return castToChar ( _data.d );
		default		: throw std::bad_cast();
	}
}

Converter::operator double () const throw( std::bad_cast )
{
	switch ( _type )
	{	case tChar	: return static_cast< double >( _data.c );
		case tInt	: return static_cast< double >( _data.i );
		case tFloat	: return static_cast< double >( _data.f );
		case tDouble: return static_cast< double >( _data.d );
		default		: throw std::bad_cast();
	}

}
