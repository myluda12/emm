#include "RobotomyRequestForm.hpp"

#include <fstream>

RobotomyRequestForm::RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm Constructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm",72,45)
{
    this->target = target;
    std::cout << "RobotomyRequestForm Constructor with parameter Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &rhs)
{
     name = rhs.name;    
     grade_ex = rhs.grade_ex;
     grade_sign = rhs.grade_sign;
     ifsign = rhs.ifsign;
    
    std::cout << "Copy Constructor RobotomyRequestForm IS Called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
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

void RobotomyRequestForm::execute(Bureaucrat const &executor)
{
    std::cout << "RobotomyRequestForm EXECUTOR called" << std::endl;
    if (this->ifsign == false)
        throw NonSigned();
    if ((rand() % 2) + 1 == 2)
        std::cout << executor.getName() << " has been robotomized successfully" << std::endl;
    else
        std::cout << executor.getName() << " the robotomy failed." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm Distructor Called" << std::endl;
}