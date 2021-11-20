#pragma once
#include <exception>
#include <iostream>
#include <string>

class Data {
public:
	class GradeTooHighException: public std::exception {
	public:
		GradeTooHighException( int grade );
		virtual char const * what() const throw();
		int	const		grade;
	};
	class GradeTooLowException: public std::exception {
	public:
		GradeTooLowException( int grade );
		virtual char const * what() const throw();
		int	const		grade;
	};
	Data( std::string const & name = "bureaucrat", int grade = 150 )
		throw ( GradeTooHighException, GradeTooLowException );
	Data( Data const & src )
		throw ( GradeTooHighException, GradeTooLowException );
	~Data();
	Data &	operator=( Data const & rhs )
		throw ( GradeTooHighException, GradeTooLowException );
	std::string		getName() const throw();
	int				getGrade() const throw();
	int				incrementGrade() throw ( GradeTooHighException );
	int				decrementGrade() throw ( GradeTooLowException );
private:
	std::string	const	_name;
	int					_grade;
	void			checkGrade( int grade ) const
		throw ( GradeTooHighException, GradeTooLowException );
};

std::ostream &	operator<<( std::ostream & o, Data const & i ) throw();
