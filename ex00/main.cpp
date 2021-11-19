#include "Converter.hpp"
#include <string>
#include <iostream>

int	main( int argc, char* argv[] )
{
	if ( argc != 2 )
	{	std::cout << "Usage:\n" << argv[ 0 ]
		          << " scalar_literal"	<< std::endl;
		return 1;
	}
	try
	{	Converter converter( argv[ 1 ] );
		try { std::cout << "double: " << ( double )converter << std::endl; }
		catch ( std::bad_cast ) { std::cout << "impossible" << std::endl; }
	}
	catch ( std::exception const & e )
	{	std::cout << e.what() << std::endl;
	}
}
