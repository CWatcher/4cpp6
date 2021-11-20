#include "Data.hpp"
#include <iostream>
#include <exception>

uintptr_t serialize(Data* ptr)
{	return reinterpret_cast< uintptr_t >( ptr );
}
Data* deserialize(uintptr_t raw)
{	return reinterpret_cast< Data* >( raw );
}

int	main()
{
	Data	b2( "b2", 2 );
	std::cout << b2;
	uintptr_t p = serialize( &b2 );
	Data&	b2ref = *deserialize( p );
	std::cout << b2ref;
	try
	{	b2ref.incrementGrade();
		b2ref.incrementGrade();
	}
	catch ( Data::GradeTooHighException const & e )
	{	std::cout << e.what() << ": " << e.grade << std::endl;
	}
	std::cout << b2ref;
}
