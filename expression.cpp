#include "expression.h"

expression::expression()
{
}

expression::expression(const expression &other)
{
    copy(other);
}

expression::~expression()
{
    //Destroy();
}

expression& expression::operator=(const expression &other)
{
    if(this != &other)
        copy(other);
    return *this;
}

void expression::copy(const expression &other)
{
    for (unsigned int i = 0; i < other.terms.size();++i)
    {
        terms[i] = other.terms[i];
    }
}
/*
expression& expression::operator<<(const string &input)
{

}

bool goodExpression()
{

}

fraction evaluateAt(const fraction &value)
{

}

ostream& operator<<(ostream &out, const expression &exp)
{

}

istream& operator>>(istream &in, expression &exp)
{

}
*/
/*
expression& expression::derivative(unsigned int x)
{
    for(unsigned int i = 0; i < terms.size(); ++i)
        for(unsigned int j = 1; j <= x; ++j)
        {
            terms[i].coef = terms[i].coef * terms[i].power;
            terms[i].power = terms[i].power - 1;
        }
    return ;
}


void expression::Destroy()
{
    for(unsigned int i = 0; i < terms.size(); ++i)
        terms[i] = '\0';
    delete [] terms;
    terms = NULL;
}
*/
