#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
    std::cout << "ShruberryCreation Constructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("Shruberry",145,137)
{
    this->target = target;
    std::cout << "ShruberryCreation Constructor with parameter Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &rhs)
{
     name = rhs.name;    
     grade_ex = rhs.grade_ex;
     grade_sign = rhs.grade_sign;
     ifsign = rhs.ifsign;
    
    std::cout << "Copy Constructor ShruberryCreation IS Called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
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

void ShrubberyCreationForm::execute(Bureaucrat const &executor)
{   
    std::cout <<  "ShrubberyCreationForm EXECUTE function called";

    if (this->ifsign == false)
        throw NonSigned(); 

    std::ofstream file(executor.getName() + "_shrubbery");

    file << " \n";
    file << "                     / / /\n";
    file << "                   /        /  /     //    /\n";
    file << "                /                 /         /  /\n";
    file << "                                /\n";
    file << "                               /                //\n";
    file << "               /          /            /              /\n";
    file << "               /            '/,        /               /\n";
    file << "               /              'b      *\n";
    file << "                /              '$    //                //\n";
    file << "               /    /           $:   /:               /\n";
    file << "             //      /  //      */  @):        /   / /\n";
    file << "                          /     :@,@):   ,/**:'   /\n";
    file << "              /      /,         :@@*: //**'      /   /\n";
    file << "                       '/o/    /:( @'/@*'  /\n";
    file << "               /  /       bq,//:,@@*'   ,*      /  /\n";
    file << "                          ,p$q8,:@)'  /p*'      /\n";
    file << "                   /     '  / '@@Pp@@*'    /  /\n";
    file << "                    /  / //    Y7'.'     /  /\n";
    file << "                              :@):.\n";
    file << "                             .:@:'.\n";
    file << "                           .::(@:.\n";

    file.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShruberryCreation Distructor Called" << std::endl;
}