#include <stdexcept>
#include <cstring>
#include <iostream>
#include "string.hpp"

namespace ecci {

    //construccion de un string a partir de un arreglo de caracteres
    string::string(const char* str)
    {
        if( str == NULL )
            str = "";

        m_length = strlen(str);
        m_buffer_length = m_length + 1;
        m_buffer = new char[m_buffer_length];
        strcpy(m_buffer,str);
    }


    //construccion de un string a partir de otro string
    string::string(const string& str)
    {
        m_length = str.m_length;
        m_buffer_length = m_length + 1;
        m_buffer = new char[m_buffer_length];
        strcpy(m_buffer,str.m_buffer);
    }

    //destruccion de arreglo de caracteres
    string::~string()
    {
        delete[] m_buffer;
    }

    //Imprime valor m_buffer
    void string::print(ostream &where) const {
        cout << m_buffer;
    }

    //Devuelve resultado de comparacion <
    bool string::comparemin(const ecci::object& y) const{
        ecci::string a = *(string*)this;
        const ecci::object* test = &y;
        ecci::string b = *(string*)test;
        return a < b;
    }

    //Devuelve resultado de comparacion >
    bool string::comparemay(const ecci::object& y) const{
        auto a = *(string*)this;
        const ecci::object* test = &y;
        auto b = *(string*)test;
        return a > b;
    }

    //asignacion de strings, sobrecargan de operador =
    const string& string::operator=(const string &str)
    {
        if( this != &str )
        {
            if(m_buffer_length < str.m_length+1 )
            {
                delete []m_buffer;
                m_buffer_length = str.m_length+1;
                m_buffer = new char[m_buffer_length];
            }
            m_length = str.m_length;
            strcpy(m_buffer,str.m_buffer);
        }
        return *this;
    }

    //suma y asigna, sobrecarga del operador +=
    const string& string::operator+=(const string& str)
    {
        if( this == &str ) //si ambos string son iguales
        {
            string string_copy(str);
            return *this += string_copy;
        }

        size_t new_length = this->m_length + str.m_length;
        if( new_length >= m_buffer_length )
        {
            m_buffer_length = 2*(new_length + 1);

            char *former = m_buffer;
            m_buffer = new char[m_buffer_length];
            strcpy(m_buffer,former);
            delete []former;
        }

        strcpy(m_buffer+length(),str.m_buffer);
        m_length = new_length;
        return *this;
    }

    //sobrecarga del []
    char& string::operator[](size_t index)
    {
        if( index < 0 || index >= m_length ) //si ocurre desbordamiento
            throw std::out_of_range("string index out of range");
        return m_buffer[index];
    }

    char string::operator[](size_t index) const
    {
        if( index < 0 || index >= m_length )
            throw std::out_of_range("string index out of range");
        return m_buffer[index];
    }

} // namespace

//sobrecarga del flujo de salida
std::ostream& operator<<(std::ostream& out, const ecci::string& str)
{
    return out << str.c_str();
}

//sobrecarga de flujo de entrada
std::istream& operator>>(std::istream& in, ecci::string& str)
{
    char buf[ ecci::string::MAX_LENGTH + 1 ];
    in >> buf;
    if(!in.fail())
        str = buf;
    return in;
}

//lectura de string
std::istream& getline(std::istream& in, ecci::string& str)
{
    char buf[ ecci::string::MAX_LENGTH + 1 ];
    in.getline(buf, ecci::string::MAX_LENGTH);
    if(!in.fail())
        str = buf;
    return in;
}

//sobrecarga de == (es equivalente)
bool operator==(const ecci::string& str1, const ecci::string& str2)
{
    //realizamos la compracion entre strenas de chars (por eso se usa c_str)
    return strcmp(str1.c_str(),str2.c_str()) == 0;
}

//sobrecarga de != (es diferente)
bool operator!=(const ecci::string& str1, const ecci::string& str2)
{
    return strcmp(str1.c_str(), str2.c_str()) != 0;
}

//sobrecarga de <
bool operator<(const ecci::string& str1, const ecci::string& str2)
{
    return strcmp(str1.c_str(), str2.c_str()) < 0;
}

//sobrecarga de <=
bool operator<=(const ecci::string& str1, const ecci::string& str2)
{
    return strcmp(str1.c_str(), str2.c_str()) <= 0;
}

//sobrecarga de >
bool operator>(const ecci::string& str1, const ecci::string& str2)
{
    return strcmp(str1.c_str(), str2.c_str()) > 0;
}

//sobrecarga de >=
bool operator>=(const ecci::string& str1, const ecci::string& str2)
{
    return strcmp(str1.c_str(), str2.c_str()) >= 0;
}


