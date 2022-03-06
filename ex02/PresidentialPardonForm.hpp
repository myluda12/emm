#pragma once

#include "Form.hpp"
#include "Bureaucrat.hpp"


class Form;
class  PresidentialPardonForm : public Form
{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &rhs);
        PresidentialPardonForm(std::string);
        PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);
        ~PresidentialPardonForm();

    void execute(Bureaucrat const & executor);

    private :
        std::string target;
};