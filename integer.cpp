#include <iostream>
#include "integer.hpp"

namespace ecci {

    //construccion de un integer a partir de un const int
    integer::integer(const int inter) {
        m_integer = inter;

    }

    //destruccion de la integer
    integer::~integer(){

    }

    //Devuelve el entero dentro de la variable
    int integer::get_dato() const{
        return m_integer;
    }

    //Imprime el valor que contiene la variable
    void integer::print(ostream &where) const {
        cout << m_integer;
    }

    //Devuelve resultado de comparacion <
    bool integer::comparemin(const ecci::object& y) const{
        integer a = *(integer*)this;
        const ecci::object* temp = &y;
        integer b = *(integer*)temp;
        return a < b;
    }

    //Devuelve resultado de comparacion >
    bool integer::comparemay(const ecci::object& y) const{
        integer a = *(integer*)this;
        const ecci::object* temp = &y;
        integer b = *(integer*)temp;
        return a > b;
    }


    //Funcion que suma dos variables integer
    integer integer::operator+(const integer& inter) {
        return integer(m_integer + inter.m_integer);
    }
    //Funcion que resta dos variables integer
    integer integer::operator-(const integer& inter) {
        return integer(m_integer - inter.m_integer);
    }
    //Funcion que multiplica dos variables integer
    integer integer::operator*(const integer& inter) {
        return integer(m_integer * inter.m_integer);
    }
    //Funcion que divide dos variables integer
    integer integer::operator/(const integer& inter) {
        return integer(m_integer / inter.m_integer);
    }

} //namespace

//sobrecarga de flujo de salida
std::ostream& operator<<(ostream& out, const ecci::integer& inter) {
    return out << inter.get_dato();
}

//sobrecarga de flujo de entrada
std::istream& operator>>(istream& in, ecci::integer& inter) {
    int temp;
    in >> temp;
    if(!in.fail()) {
        //ecci::integer new_value(temp);
        inter.set_int(temp);
    }
    return in;
}

//sobrecarga del operador <
bool operator<(const ecci::integer& inter_0, const ecci::integer& inter_1) {
    return inter_0.get_dato() < inter_1.get_dato();
}

//sobrecarga del operador >
bool operator>(const ecci::integer& inter_0, const ecci::integer& inter_1) {
    return inter_0.get_dato() > inter_1.get_dato();
}

//sobrecarga del operador ==
bool operator==(const ecci::integer& inter_0, const ecci::integer& inter_1) {
    return inter_0.get_dato() == inter_1.get_dato();
}

//sobrecarga del operador !=
bool operator!=(const ecci::integer& inter_0, const ecci::integer& inter_1) {
    return inter_0.get_dato() != inter_1.get_dato();
}

//sobrecarga del operador <=
bool operator<=(const ecci::integer& inter_0, const ecci::integer& inter_1) {
    return inter_0.get_dato() <= inter_1.get_dato();
}

//sobrecarga del operador >=
bool operator>=(const ecci::integer& inter_0, const ecci::integer& inter_1) {
    return inter_0.get_dato() >= inter_1.get_dato();
}