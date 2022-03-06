#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{

	public:

		Bureaucrat();
		Bureaucrat( Bureaucrat const & src );
        Bureaucrat(std::string const name, int grade);
		~Bureaucrat();
		Bureaucrat &		operator=( Bureaucrat const & rhs );


        class GradeTooHighException : public std::exception
        {
            virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            virtual const char *what() const throw();
        };

        void decrement();
        void increment();
        
        std::string getName() const ;
        int getGrade() const;

        void signForm(Form &);

	private:
        std::string Name;
        int Grade;


};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ******************************************************** CLAPTRAP_H */