#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{

	public:

		Form();
		Form( Form const & src );
        Form(std::string, int, int);
		~Form();
		Form &		operator=( Form const & rhs );


        class GradeTooHighException : public std::exception
        {
            virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            virtual const char *what() const throw();
        };
        class NonSigned : public std::exception
        {
            virtual const char *what() const throw();
        };
        
        int  getSignG() const;
        virtual void execute(Bureaucrat const & executor) = 0;
        int  getExecutionG() const;
        int  getifsign() const;
        void setifsign(bool);
        std::string getName() const;
        void beSigned(Bureaucrat &);


	protected:

        std::string name;
        int grade_ex;
        int grade_sign;
        bool ifsign;


};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif