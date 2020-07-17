#ifndef _CALCULATOR_
#define _CALCULATOR_
#include<bits/stdc++.h>
#include"operations.cpp"
#include"notation.cpp"
namespace rpn
{
std::string postfix(std::string infix);
double convert(std::string expression);
double solve (double  ,double ,char );

namespace check
{
bool isoperator(char var);
bool isoperants(char var);
int pricideance(char var);
bool highipricideance(char var , char expression);
}
}
#endif // _CALCULATOR_
