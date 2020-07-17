#ifndef Notation
#define Notation
#include"calculator.h"
namespace rpn {using namespace rpn::check ;

 double solve(double first , double second , char expression)
{
        if(expression =='+')
        return first+second ;
        if(expression == '-')
        return first- second ;
        if(expression == '*')
        return first*second;
        if(expression== '/')
        return ((double)first/second);
}
/*This function will convert the expretion into a postfix expression*/
std::string postfix(std::string infix)
{
    void spacer(std::string &postfix);
    std::string postfix;
    std::stack <char> operant ;
    for(int i=0;i<infix.length();i++)
    {

        if(rpn::check::isoperants(infix[i]))
        {
            postfix+=infix[i];
        }
        if(rpn::check::isoperator(infix[i]))
        {
            postfix+=' '; //inserted ...
            while(!operant.empty() && operant.top()!='(' &&rpn::check:: highipricideance(operant.top(),infix[i]))
            {
                postfix+=operant.top();
                operant.pop();
            }
            operant.push(infix[i]);
        }
        if(infix[i] == '(')
        {
            operant.push(infix[i]);
        }
        if(infix[i] == ')')
        {
            while(!operant.empty() && operant.top()!='(')
            {
                postfix+=operant.top();
                operant.pop();
            }
            operant.pop();
        }
    }
    while(!operant.empty())
    {
        postfix+=operant.top();
        operant.pop();
    }
    spacer(postfix);
    return postfix ;
}
double convert(std::string expression)
{
    std::stack<char> s;
    std::stack<double> num;
    for(int i=0;i<expression.length();i++)
    {
        if(isoperator(expression[i]))
        {
            double first,second,store ;
            second = num.top();
            num.pop();
            first = num.top();
            num.pop();
            store = solve(first,second,expression[i]);

            num.push(store);
        }
        else
        {
            if(expression[i]==' ')
            {
                double varialbe;
                char buffer[6],*b;
                for(int z=0;z<6;z++)
                    buffer[z]='A';
                int stak_size=s.size();
                for(int z = stak_size-1;z>=0;z--)
                {
                    buffer[z]=s.top();
                    varialbe =std::strtod(buffer,&b);
                    s.pop();
                }
                num.push(varialbe);
                continue;
            }else
            {

                s.push(expression[i]);
            }
        }
    }
  return num.top();
}
  void spacer(std::string &postfix)
{
    int len = postfix.length();
    for(int i=0 ;i<len;i++)
    {
        if(isoperator(postfix[i]))
        {
            if(postfix[i-1] != ' '&&!isoperator(postfix[i-1]))
            {
               postfix.insert(i," ");
               i+=2;//break;
               len = postfix.length();
            }
        }
    }
    std::string temp;
    len = postfix.length();
    for(int i=0;i<=len;i++)
    {
        if(isoperator(postfix[i-1])&&isoperator(postfix[i+1]))
        {}
       else { temp+=postfix[i];}
    }
    postfix= temp;
}
}
#endif // Notation
