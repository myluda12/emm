#include "Form.hpp"

Form::Form()
{
    std::cout << "Form Default Constructor called" << std::endl;
}

Form::Form  (std::string  name, int grade_sign, int grade_ex) : name(name)
{
    std::cout << "Param constructor called" << std::endl;
    this->grade_ex = grade_ex;
    this->grade_sign = grade_sign;
    ifsign = false;
    if (grade_sign > 150 || grade_ex > 150)
        throw GradeTooLowException();
    else if (grade_sign < 1 || grade_ex < 1)
        throw GradeTooHighException();
}

Form::Form(const Form &src) : name(src.name)
{
    std::cout << "Copy Constructor called" << std::endl;
    grade_sign = src.grade_sign;
    grade_ex = src.grade_ex;
    ifsign = src.ifsign;
    if (grade_sign > 150 || grade_ex > 150)
        throw GradeTooLowException();
    else if (grade_sign < 1 || grade_ex < 1)
        throw GradeTooHighException();
}

Form::~Form()
{
    std::cout << "Form Default Destructor called" << std::endl;
}

Form & Form::operator=(Form const &rhs)
{
    std::cout << "Form Assignment Operator" << std::endl;
    if (this != &rhs)
    {
        grade_sign = rhs.grade_sign;
        grade_ex = rhs.grade_ex;
        ifsign =  rhs.ifsign;
    }
    return *this;
}

std::string Form::getName() const
{
    return name;
}

int Form::getSignG() const
{
    return grade_sign;
}

int Form::getExecutionG() const
{
    return grade_ex;
}

int Form::getifsign() const
{
    return ifsign;
}

void Form::setifsign(bool in)
{
    this->ifsign = in;
}

std::ostream & operator<<(std::ostream & o, Form const & i)
{
    o << "Name :" << i.getName() << std::endl;
    o << "Grade : " << i.getSignG() << std::endl;
    o << "Exec : " << i.getExecutionG() << std::endl;
    o << "Status :" << (i.getifsign() ? "WELL SIGNED" : "NOT SIGNED BRO") << std::endl;
    return o;
}
const char * Form::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char * Form::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

const char * Form::NonSigned::what() const throw()
{
    return "Not signed succesfully";
}

void Form::beSigned(Bureaucrat &src)
{
    if (this->getSignG() < src.getGrade())
    {
        src.signForm((*this));
        throw GradeTooLowException();
    }
    else
    {
        this->ifsign = true;
        src.signForm((*this));
    }
}