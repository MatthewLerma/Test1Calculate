#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
//#include "mixed.h"
#include "toRPN.h"
#include <vector>
#include "fraction.h"
struct term
{
    fraction coef,power;
};

class expression
{
    public:
        expression();
        expression(const expression &other);
        ~expression();                                             //Deconstructor

        expression& operator=(const expression &other);/*
        expression& operator<<(const string &input);
        bool goodExpression();
        expression& derivative(unsigned int x = 1);
        fraction evaluateAt(const fraction &value);

        friend
        ostream& operator<<(ostream &out, const expression &exp);

        friend
        istream& operator>>(istream &in, expression &exp);
*/
    private:
        string expressionToStore;
        toRPN expressionInRPN;
        vector<term> terms;
        void copy(const expression &other);
       // void expression::Destroy();
};

#endif // EXPRESSION_H
