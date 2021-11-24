#include "arbol_binario.hpp"
#include "object.hpp"
#include <string>
using ecci::object;
using namespace std;

// Constructor
arbol_binario::arbol_binario()
{
    m_ptr_raiz = 0; // indica que al principio el arbol esta vacio
}

/**
 * Destructor
 * 
 * Llama al metodo destruir_arbol
 */
arbol_binario::~arbol_binario()
{
    destruir_arbol(this->m_ptr_raiz);
}

/**
 * funcion utilitaria llamada por el destructor
 */
void arbol_binario::destruir_arbol(nodo_arbol_binario *ptr)
{
    if (ptr != nullptr)
    {
        destruir_arbol(ptr->ptr_izquierdo);
        destruir_arbol(ptr->ptr_derecho);
        delete ptr;
    }
}

/**
 * inserta el nodo en el arbol_binario
 */
void arbol_binario::inserte(object *valor)
{
    auxiliar_inserte(&m_ptr_raiz, valor);
}

/**
 * funcion utilitaria llamada por inserte; recibe un apuntador
 * a un apuntador, para que la funcion pueda modificar el valor del apuntador
 */
void arbol_binario::auxiliar_inserte(nodo_arbol_binario **ptr, object *valor)
{
    // el subárbol está vacío; crea nuevo nodo_arbol_binario que contiene el valor
    if (*ptr == 0)
        *ptr = new nodo_arbol_binario(valor);
    else // el subárbol no está vacío
    {
        // los m_dato a insertar son menores que los m_dato en el nodo actual
        if (*valor < *(*ptr)->m_dato)
            auxiliar_inserte(&((*ptr)->ptr_izquierdo), valor);
        else
        {
            // los m_dato a insertar son mayores que los m_dato en el nodo actual
            if (*valor > *(*ptr)->m_dato)
                auxiliar_inserte(&((*ptr)->ptr_derecho), valor);
            else // se ignora el valor de m_dato duplicado
                cout << *valor << " dup" << endl;
        } // fin de else
    }     // fin de else
}

/**
 * borra el nodo en el arbol_binario
 */
void arbol_binario::borre(const object *valor)
{
    auxiliar_borre(&m_ptr_raiz, valor);
}

/**
 * función utilitaria llamada por borre; recibe un apuntador
 * a un apuntador, para que la funcion pueda modificar el valor del apuntador
 */
void arbol_binario::auxiliar_borre(nodo_arbol_binario **ptr, const object *valor)
{
    nodo_arbol_binario *aux;

    // el subarbol está vacio, no se encontró el nodo
    if (*ptr == 0)
    {
        return;
    }
    // los m_dato a borrar son mayores que los m_dato en el nodo actual
    if (valor > (*ptr)->m_dato)
    {
        auxiliar_borre(&((*ptr)->ptr_derecho), valor);
    }
    // los m_dato a borrar son menores que los m_dato en el nodo actual
    else if (valor < (*ptr)->m_dato)
    {
        auxiliar_borre(&((*ptr)->ptr_izquierdo), valor);
    }
    // los m_dato a borrar son iguales que los m_dato en el nodo actual
    else if (valor == (*ptr)->m_dato)
    {
        aux = *ptr;
        if ((*ptr)->ptr_izquierdo == 0)
        {
            *ptr = (*ptr)->ptr_derecho;
        }
        else if ((*ptr)->ptr_derecho == 0)
        {
            *ptr = (*ptr)->ptr_izquierdo;
        }
        else
        {
            reemplace(&(*ptr)->ptr_izquierdo, &aux);
        }
        delete aux;
    }
}

/**
 * funcion utilitaria llamada por borre; recibe dos apuntadores
 * a un apuntador, para que la funcion pueda modificar el valor del apuntador
 */
void arbol_binario::reemplace(nodo_arbol_binario **ptr, nodo_arbol_binario **aux)
{
    if ((*ptr)->ptr_derecho == 0)
    {
        (*aux)->m_dato = (*ptr)->m_dato;
        *aux = *ptr;
        *ptr = (*ptr)->ptr_izquierdo;
    }
    else
    {
        reemplace(&((*ptr)->ptr_derecho), aux);
    }
}

/**
 * empieza el recorrido preorden del arbol_binario
 */
void arbol_binario::recorra_preorden() const
{
    auxiliar_preorden(m_ptr_raiz);
}

/**
 * funcion utilitaria para realizar el recorrido preorden del arbol_binario
 */
void arbol_binario::auxiliar_preorden(nodo_arbol_binario *ptr) const
{
    if (ptr != 0)
    {
        cout << *ptr->m_dato << ' ';           // procesa el nodo
        auxiliar_preorden(ptr->ptr_izquierdo); // recorre el subárbol izquierdo
        auxiliar_preorden(ptr->ptr_derecho);   // recorre el subárbol derecho
    }                                          // fin de if
}

/**
 * empieza el recorrido inorden del arbol_binario
 */
void arbol_binario::recorra_inorden() const
{
    auxiliar_inorden(m_ptr_raiz);
}

/**
 * funcion utilitaria para realizar el recorrido inorden del arbol_binario
 */
void arbol_binario::auxiliar_inorden(nodo_arbol_binario *ptr) const
{
    if (ptr != 0)
    {
        auxiliar_inorden(ptr->ptr_izquierdo); // recorre el subárbol izquierdo
        cout << *ptr->m_dato << ' ';          // procesa el nodo
        auxiliar_inorden(ptr->ptr_derecho);   // recorre el subárbol derecho
    }                                         // fin de if
}

/**
 * empieza el recorrido postorden del arbol_binario
 */
void arbol_binario::recorra_postorden() const
{
    auxiliar_postorden(m_ptr_raiz);
}

/**
 * funcion utilitaria para realizar el recorrido postorden del arbol_binario
 */
void arbol_binario::auxiliar_postorden(nodo_arbol_binario *ptr) const
{
    if (ptr != 0)
    {
        auxiliar_postorden(ptr->ptr_izquierdo); // recorre el subárbol izquierdo
        auxiliar_postorden(ptr->ptr_derecho);   // recorre el subárbol derecho
        cout << *ptr->m_dato << ' ';            // procesa el nodo
    }                                           // fin de if
}
