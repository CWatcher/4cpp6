#include "Converter.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>

int	main( int argc, char* argv[] )
{
	if ( argc != 2 )
	{	std::cout << "Usage:\n" << argv[ 0 ]
		          << " scalar_literal"	<< std::endl;
		return 1;
	}
	std::cout << std::setprecision( 100 );
	try
	{	Converter converter( argv[ 1 ] );

		try
		{	std::cout << "char  : ";
			char c = ( char )converter;
			std::cout << "'" << c << "'" << std::endl;
		}
		catch ( std::bad_cast & )
		{	std::cout << "impossible" << std::endl; }
		catch ( std::range_error const & e )
		{	std::cout << e.what() << std::endl; }

		try
		{	std::cout << "int   : " << ( int )converter << std::endl; }
		catch ( std::bad_cast & )
		{	std::cout << "impossible" << std::endl; }

		std::string	pointZero[] = {"", ".0"};

		try
		{	std::cout << "float : ";
			float x = ( float )converter;
			std::cout << x << pointZero[ round( x ) == x ] << "f" << std::endl;
		}
		catch ( std::bad_cast & )
		{	std::cout << "impossible" << std::endl; }

		try
		{	std::cout << "double: ";
			double x = ( double )converter;
			std::cout << x << pointZero[ round( x ) == x ] << std::endl;
		}
		catch ( std::bad_cast & )
		{	std::cout << "impossible" << std::endl; }
	}
	catch ( std::exception const & e )
	{	std::cout << e.what() << std::endl;
	}
}
