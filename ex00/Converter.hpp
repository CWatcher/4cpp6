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
	union {
		char	c;
		int		i;
		float	f;
		double	d;
	}
		_data;
	enum { tNone, tChar, tInt, tFloat, tDouble }
		_type;

	bool try1Parse1Symbol( std::string const & );
	bool try2ParsePseudoLiterals( std::string const & );
	bool try3ParseNumber( std::string );
};
