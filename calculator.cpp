/*----------------------------------------------------------------------------------------------------------

    This calculator only work with basic operators (+,-,*,/)
    This calculator is based on the Reverse Polish notation
    
    internet <souravsh1234567@gmail.com>
    
 -----------------------------------------------------------------------------------------------------------*/
#include"src/calculator.h"
int main()
{
    std::string expression;
    std::cout<<">>$ ";
    std::cin>>expression ; // Taking an mathamatical expression
    /*converting a mathamatical expression into a postfix notation and asigning into a expression*/
    expression = rpn::postfix(expression);

    /* solveing a mathamatical (which in the form of postfix) expration and returning a solved expression*/
    std::cout<<"Result : "<<rpn::convert(expression)<<std::endl ;
    return  0;
}

