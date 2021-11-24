#include "float.hpp"

using namespace std;

namespace ecci {

    //construccion de un flo a partir de un const float
    flo::flo(const float point) {
        m_float = point;
    }

    //destruccion de la float
    flo::~flo(){
        
    }

    //Imprime valor m_float
    void flo::print(ostream &where) const {
        cout << m_float;
    }

    //Devuelve resultado de comparacion <
    bool flo::comparemin(const ecci::object& y) const{
        flo a = *(flo*)this;
        const ecci::object* test = &y;
        flo b = *(flo*)test;
        return a < b;
    }

    //Devuelve resultado de comparacion >
    bool flo::comparemay(const ecci::object& y) const{
        flo a = *(flo*)this;
        const ecci::object* test = &y;
        flo b = *(flo*)test;
        return a > b;
    }

    //Funcion que devuelve el flotante dentro de la variable
    float flo::get_flo() const {
        return m_float;
    }

    //Metodo que se encarga de sumar dos float
    flo flo::operator+(const flo& point) {
        return flo(m_float + point.m_float);
    }
    //Metodo que se encarga de restar dos float
    flo flo::operator-(const flo& point) {
        return flo(m_float - point.m_float);
    }
    //Metodo que se encarga de multiplicar dos float
    flo flo::operator*(const flo& point) {
        return flo(m_float * point.m_float);
    }
    //Metodo que se encarga de dividir dos float
    flo flo::operator/(const flo& point) {
        return flo(m_float / point.m_float);
    }

} //namespace


//sobrecarga de flujo de salida
std::ostream& operator<<(ostream& out, const ecci::flo& point) {
    return out << point.get_flo();
}

//sobrecarga de flujo de entrada
std::istream& operator>>(istream& in, ecci::flo& point) {
    float temp;
    in >> temp;
    if(!in.fail()) {
        ecci::flo new_value(temp);
        point = new_value;
    }
    return in;
}

//sobrecarga del operador <
bool operator<(const ecci::flo& flo_0, const ecci::flo& flo_1) {
    return flo_0.get_flo() < flo_1.get_flo();
}

//sobrecarga del operador >
bool operator>(const ecci::flo& flo_0, const ecci::flo& flo_1) {
    return flo_0.get_flo() > flo_1.get_flo();
}

//sobrecarga del operador ==
bool operator==(const ecci::flo& flo_0, const ecci::flo& flo_1) {
    return flo_0.get_flo() == flo_1.get_flo();
}

//sobrecarga del operador !=
bool operator!=(const ecci::flo& flo_0, const ecci::flo& flo_1) {
    return flo_0.get_flo() != flo_1.get_flo();
}

//sobrecarga del operador <=
bool operator<=(const ecci::flo& flo_0, const ecci::flo& flo_1) {
    return flo_0.get_flo() <= flo_1.get_flo();
}

//sobrecarga del operador >=
bool operator>=(const ecci::flo& flo_0, const ecci::flo& flo_1) {
    return flo_0.get_flo() >= flo_1.get_flo();
}