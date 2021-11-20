#include "Data.hpp"

Data::GradeTooHighException::GradeTooHighException( int grade )
:	grade( grade )
{}
Data::GradeTooLowException::GradeTooLowException( int grade )
:	grade( grade )
{}

char const *	Data::GradeTooHighException::what() const throw()
{	return "Grade is too high";
}
char const *	Data::GradeTooLowException::what() const throw()
{	return "Grade is too low";
}

void	Data::checkGrade( int grade ) const
	throw ( GradeTooHighException, GradeTooLowException )
{
	if ( grade < 1 )
		throw Data::GradeTooHighException( grade );
	if ( grade > 150 )
		throw Data::GradeTooLowException( grade );
}

Data::Data( std::string const & name, int grade )
	throw ( GradeTooHighException, GradeTooLowException )
:	_name( name ), _grade( grade )
{
	checkGrade( _grade );
}
Data::Data( const Data & src )
	throw ( GradeTooHighException, GradeTooLowException )
:	_name( src._name ), _grade( src._grade )
{
	checkGrade( _grade );
}
Data::~Data()
{}

Data &	Data::operator=( Data const & rhs )
		throw ( GradeTooHighException, GradeTooLowException )
{
	checkGrade( rhs._grade );
	_grade = rhs._grade;
	return *this;
}
std::ostream &	operator<<( std::ostream & o, Data const & i ) throw()
{
	o << "name = " << i.getName() << ", ";
	o << "grade = " << i.getGrade() << std::endl;
	return o;
}

std::string		Data::getName() const throw()
{	return _name;
}
int				Data::getGrade() const throw()
{	return _grade;
}

int				Data::incrementGrade() throw ( GradeTooHighException )
{
	checkGrade( _grade - 1 );
	return --_grade;
}
int				Data::decrementGrade() throw ( GradeTooLowException )
{
	checkGrade( _grade + 1 );
	return ++_grade;
}
