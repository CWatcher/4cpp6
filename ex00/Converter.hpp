#pragma once
#include <string>
#include <stdexcept>
#include <typeinfo>

class Converter {
public:
	Converter( std::string ) throw ( std::invalid_argument );
		//TODO std::string const & (see "if ( s[ s.length() - 1 ] == 'f' )" )
	Converter( Converter const & src );
	~Converter();

	Converter &	operator=( Converter const & rhs );

	operator double () const throw( std::bad_cast );

private:
	union {
		char	c;
		int		i;
		float	f;
		double	d;
	}
		_data;
	enum { tNone, tChar, tInt, tFloat, tDouble }
		_type;

	bool try1Parse1Symbol();
	bool try2ParsePseudoLiterals();
	bool try3ParseNumber();
};
