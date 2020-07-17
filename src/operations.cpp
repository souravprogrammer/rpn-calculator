#ifndef Operations
#define Operations
namespace rpn::check
{
/*This finction tells whether the parimeter is operator or not */
bool isoperator(char var)
{
    if(var == '+'||var == '-'||var =='*'||var=='/') {return true ;}
    return false ;
}
/*This function tells whether the perimeter is operants or not*/
bool isoperants(char var)
{
    if(var>='0'&&var<='9'||var=='.') {return true ;}
    return false ;
}
/*This function returns the intiger value according to parameter higher number means higher priority*/
static int pricideance(char var)
{
    switch(var)
    {
    case '/':
        return 2 ;
    case '*':
        return 2;
    case '+':
        return 1;
    case '-':
        return 1;

    }
}
/*this function tells the which has a higher pricideance */
bool highipricideance(char var, char expression)
{
    if(pricideance(var)==pricideance(expression))
    {
        return true ;
    }
    return (pricideance(var)>pricideance(expression)) ? true:false ;
}
}
#endif // Operations
