#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
    std::cout << "Bureacrat Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src )
{
    std::cout << "Copy Bureaucrat Constructor called " << std::endl;
    Name = src.Name;
    Grade = src.Grade;
    if (Grade < 1)
        throw GradeTooLowException();
    if (Grade > 150)
        throw GradeTooHighException();

}

Bureaucrat::Bureaucrat(std::string const name, int grade)
{
    Name = name;
    Grade = grade;
    if (Grade < 1)
        throw GradeTooLowException();
    if (Grade > 150)
        throw GradeTooHighException();
}

Bureaucrat & Bureaucrat::operator=( Bureaucrat const & rhs )
{
    std::cout << "Bureaucrat assignement opperator called" << std::endl;
    if (this != &rhs)
    {
        Name = rhs.Name;
        Grade = rhs.Grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destractor called" << std::endl;
}

std::string Bureaucrat::getName() const
{
    return Name;
}

int Bureaucrat::getGrade() const
{
    return Grade;
}

void Bureaucrat::decrement()
{
    if (Grade > 150)
        throw GradeTooHighException();
    Grade--;
}

void Bureaucrat::increment()
{
    if (Grade < 1)
        throw GradeTooLowException();
    Grade++;
}

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
    o << i.getName() << " ,bureaucrate grade " << i.getGrade() << std::endl;
    return o;
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}
