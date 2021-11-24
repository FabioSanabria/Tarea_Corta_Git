// main.cpp
// Programa de prueba de la clase arbol_binario.
#include <iostream>
#include "integer.hpp"
#include "float.hpp"
#include "string.hpp"
using ecci::flo;
using ecci::integer;
using ecci::object;
using ecci::string;
using std::cin;
using std::cout;
using std::endl;
//using std::fixed;

//#include <iomanip>
//using std::setprecision;

#include "arbol_binario.hpp" // definicion de la clase arbol_binario

int main()
{

    //Arbol de integer

    arbol_binario arbol_integers; // crea un Arbol de valores integer
    object *valor_integer;
    object *valores_int[10];
    //Valores que se le asignan al arbol
    valores_int[0] = new integer(1);
    valores_int[1] = new integer(1);
    valores_int[2] = new integer(2);
    valores_int[3] = new integer(5);
    valores_int[4] = new integer(14);
    valores_int[5] = new integer(42);
    valores_int[6] = new integer(132);
    valores_int[7] = new integer(429);
    valores_int[8] = new integer(1430);
    valores_int[9] = new integer(4862);
    for (int i = 0; i < 10; i++)
    {   
        valor_integer = valores_int[i];
        arbol_integers.inserte(valor_integer);
    }

    cout << "\nArbol integer:\n";
    arbol_integers.recorra_inorden();
    cout << endl;

    for (int i = 0; i < 10; i++) // Se hace de esta manera ya que con el delete[] valores nos da un warning
    {
        delete valores_int[i];
    }

    //Arbol de string

    arbol_binario arbol_strings; // crea un Arbol de valores string
    object *valor_string;
    object *valores_string[10];
     //Valores que se le asignan al arbol
    valores_string[0] = new ecci::string("La");
    valores_string[1] = new ecci::string("concision,");
    valores_string[2] = new ecci::string("amenidad");
    valores_string[3] = new ecci::string("y");
    valores_string[4] = new ecci::string("eficacia");
    valores_string[5] = new ecci::string("didactica");
    valores_string[6] = new ecci::string("caracteristicas");
    valores_string[7] = new ecci::string("de");
    valores_string[8] = new ecci::string("Isaac");
    valores_string[9] = new ecci::string("Asimov");
    for (int i = 0; i < 10; i++)
    {
        valor_string = valores_string[i];
        arbol_strings.inserte(valor_string);
    }

    cout << "\nArbol string:\n";
    arbol_strings.recorra_inorden();
    cout << endl;

    for (int i = 0; i < 10; i++) // Se hace de esta manera ya que con el delete[] valores nos da un warning
    {
        delete valores_string[i];
    }

    //Arbol de float


     //Valores que se le asignan al arbol
    arbol_binario arbol_floats; // crea un Arbol de valores float
    object *valor_float;
    object *valores_float[10];
    valores_float[0] = new flo(1.0);
    valores_float[1] = new flo(1.1);
    valores_float[2] = new flo(2.1);
    valores_float[3] = new flo(1.211);
    valores_float[4] = new flo(12.21);
    valores_float[5] = new flo(32.11);
    valores_float[6] = new flo(132.21);
    valores_float[7] = new flo(111.11);
    valores_float[8] = new flo(312.21);
    valores_float[9] = new flo(132.11);
    for (int i = 0; i < 10; i++)
    {
        valor_float = valores_float[i];
        arbol_floats.inserte(valor_float);
    }

    cout << "\nArbol float:\n";
    arbol_floats.recorra_inorden();
    cout << endl;

    for (int i = 0; i < 10; i++) // Se hace de esta manera ya que con el delete[] valores nos da un warning
    {
        delete valores_float[i];
    }

    return 0;
}
