#pragma once

#include "Bureaucrat.hpp"
#include "Form.hpp"

class Form;
class  RobotomyRequestForm : public Form
{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &rhs);
        RobotomyRequestForm(std::string);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);
        ~RobotomyRequestForm();

    void execute(Bureaucrat const & executor);

    private :
        std::string target;
};