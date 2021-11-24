#include "object.hpp"

namespace ecci
{

    object::object()
    {
        //ctor
    }

    object::~object()
    {
        //dtor
    }

    //Metodo que permite imprimir el valor que contiene el objeto
    void object::print(ostream &where) const
    {
    }

    bool object::comparemin(const ecci::object &y) const
    {
        return true;
    }

    bool object::comparemay(const ecci::object &) const
    {
        return true;
    }

}

//Sobrecarga del operador << para lograr las impresiones de diferentes objetos
ostream &operator<<(ostream &out, const ecci::object &o)
{
    o.print(out);
    return out;
}

bool operator<(const ecci::object &x, const ecci::object &y) { return x.comparemin(y); }
bool operator>(const ecci::object &x, const ecci::object &y) { return x.comparemay(y); }