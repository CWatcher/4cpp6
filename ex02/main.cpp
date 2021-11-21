#include <iostream>
#include <cstdlib>

class	Base {
public:
	virtual	~Base() {};
};

class	A: public Base {};
class	B: public Base {};
class	C: public Base {};

Base*	generate( void )
{
	std::cout << "Generated: ";

	switch ( rand() % 3 + 'A' )
	{
		case 'A':	std::cout << "A";
					return new A();
		case 'B':	std::cout << "B";
					return new B();
		case 'C':	std::cout << "C";
					return new C();
		default :	std::cout << "nothing";
					return NULL;
	}
}
void	identify( Base* p )
{
	if ( dynamic_cast< A* >( p ) )
		std::cout << "A";
	else if ( dynamic_cast< B* >( p ) )
		std::cout << "B";
	else if ( dynamic_cast< C* >( p ) )
		std::cout << "C";
}
void	identify( Base& baseChild )
{
	try
	{	( void ) dynamic_cast< A& >( baseChild );
		std::cout << "A";
		return;
	}
	catch( std::exception & ) {}
	try
	{	( void ) dynamic_cast< B& >( baseChild );
		std::cout << "B";
		return;
	}
	catch( std::exception & ) {}
	try
	{	( void ) dynamic_cast< C& >( baseChild );
		std::cout << "C";
		return;
	}
	catch( std::exception & ) {}
}

int		main()
{
	srand( time( NULL ) );
	for ( int i = 0; i < 9; i++ ) {
		Base *p = generate();
		std::cout << ". Identified from pointer: ";
		identify( p );
		std::cout << ". Identified from reference: ";
		identify( *p );
		std::cout << std::endl;
	}
}
