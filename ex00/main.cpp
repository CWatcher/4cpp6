#include <string>
#include <iostream>
#include <sstream>

template< typename T > T convertString( std::string const & s )
{
	std::stringstream	ss( s );
	T	out;
	ss >> out;
	std::cout << std::endl;
	std::cout << ss.fail() << std::endl;
	return out;
}

int	main( int argc, char* argv[] )
{
	if ( argc != 2 )
	{	std::cout << "Usage:\n" << argv[ 0 ]
		          << " scalar_literal"	<< std::endl;
		return 1;
	}
	std::string			s( argv[ 1 ] );

	std::cout << convertString< char >( s ) << std::endl;
	std::cout << convertString< int >( s ) << std::endl;
	std::cout << convertString< float >( s ) << std::endl;
	std::cout << convertString< double >( s ) << std::endl;
}
