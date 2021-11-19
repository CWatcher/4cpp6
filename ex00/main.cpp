#include <iostream>

int	main( int argc, char* argv[] )
{
	if ( argc != 2 )
	{	std::cout << "Usage:\n" << argv[ 0 ]
		          << " scalar_literal"	<< std::endl;
		return 1;
	}
	std::cout << std::endl;
}
