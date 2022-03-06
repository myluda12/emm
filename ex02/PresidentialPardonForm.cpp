#include "PresidentialPardonForm.hpp"

#include <fstream>

PresidentialPardonForm::PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm Constructor Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm",25,5)
{
    this->target = target;
    std::cout << "PresidentialPardonForm Constructor with parameter Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &rhs)
{
     name = rhs.name;    
     grade_ex = rhs.grade_ex;
     grade_sign = rhs.grade_sign;
     ifsign = rhs.ifsign;
    
    std::cout << "Copy Constructor PresidentialPardonForm IS Called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
    std::cout << "Shruberry operator has been called" << std::endl;

    if (this != &rhs)
    {
     name = rhs.name;    
     grade_ex = rhs.grade_ex;
     grade_sign = rhs.grade_sign;
     ifsign = rhs.ifsign;
    }
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor)
{
    std::cout << "PresidentialPardonForm EXECUTOR called" << std::endl;
    if (this->ifsign == false)
        throw NonSigned();
    std::cout << executor.getName() << "has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm Destructor Called" << std::endl;
}