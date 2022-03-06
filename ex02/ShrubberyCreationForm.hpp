#pragma once

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <fstream>


class Form;
class  ShrubberyCreationForm : public Form
{
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm &rhs);
        ShrubberyCreationForm(std::string);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);
        ~ShrubberyCreationForm();

    void execute(Bureaucrat const & executor);

    private :
        std::string target;
};