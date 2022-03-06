#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureacrat;

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
        
        int  getSignG() const;
        int  getExecutionG() const;
        int  getifsign() const;
        void setifsign(bool);
        std::string getName() const;


	private:

        std::string name;
        int grade_ex;
        int grade_sign;
        bool ifsign;


};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif