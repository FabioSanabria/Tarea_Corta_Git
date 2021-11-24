// nodo_arbol_binario.h
// Definicion de la clase nodo_arbol_binario.
#ifndef NODO_ARBOL_BINARIO_H1
#define NODO_ARBOL_BINARIO_H1

#include "object.hpp"
using ecci::object;

// declaracion anticipada de la clase arbol_binario
class arbol_binario;

// definicion de la clase nodo_arbol_binario
class nodo_arbol_binario
{
   friend class arbol_binario;
   public:
      // constructor
      nodo_arbol_binario(object* d)
         : ptr_izquierdo(0), // apuntador al subarbol izquierdo
         m_dato(d), // datos del nodo del arbol
         ptr_derecho(0) // apuntador al subarbol derecho
      {
         // cuerpo vacio
      }

      // devuelve una copia del dato del nodo
      object* dato() const
      {
         return m_dato;
      }
      
   private:
      nodo_arbol_binario *ptr_izquierdo; // apuntador al subarbol izquierdo
      object* m_dato;
      nodo_arbol_binario *ptr_derecho; // apuntador al subarbol derecho
};

#endif
