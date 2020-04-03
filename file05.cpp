
#include <iostream>
#include <exception>

class derived_exception
: public std::exception 
{
    virtual const char* what() const throw() 
    {
        return "My derived exception";
    }
} myderivedexception;

int main () 
{
    try 
    {
        throw myderivedexception;
    }
    catch (std::exception& e) 
    {
        std::cout << e.what() << '\n';
    }
}
