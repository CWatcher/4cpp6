#include <iostream>
#include <exception>
#include <iomanip>

struct Data
{
	double		x;
	std::string	s;
};

uintptr_t serialize(Data* ptr)
{	return reinterpret_cast< uintptr_t >( ptr );
}
Data* deserialize(uintptr_t raw)
{	return reinterpret_cast< Data* >( raw );
}

int	main()
{
	std:: cout << std::setprecision(10);
	Data	data = { 12345.6789, "abcdefgh" };
	std::cout << "Data { x = " << data.x << ", s = " << data.s << " }"
	        << std::endl;
	uintptr_t p = serialize( &data );
	std::cout << "was serialized to uintptr_t, ...\n";
	Data&	dataRef = *deserialize( p );
	std::cout << "then deserialized to pointer to:\n";
	std::cout << "Data { x = "<< dataRef.x << ", s = " << dataRef.s << " }"
	          << std::endl;
}
