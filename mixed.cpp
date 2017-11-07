#include "mixed.h"

mixed::mixed()
{

}

mixed::mixed(int whole)
{
    value.num = whole;
    value.denom = 1;
}

mixed::mixed(int n, int d)
{
    value = n/d;
}

mixed::mixed(int whole, int n = 0, int d = 1)
{

}

mixed::mixed(const fraction &other)
{
    value = other;
}

mixed& mixed::operator=(int x)
{
    value = x;
    return *this;
}

mixed& mixed::operator=(double d)
{
    value = d;
    return *this
}


mixed& mixed::operator=(const fraction &other)
{
    value = other;
    return *this;
}

mixed& mixed::operator=(const mixed &other)
{
    if(&other != this)
    {
        value = other;
    }
    return *this;
}


mixed operator+(const mixed &x, const mixed &y)
{
    return x.value + y.value;
}
