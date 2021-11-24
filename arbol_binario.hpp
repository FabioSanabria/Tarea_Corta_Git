// arbol_binario.h
// Definicion de la clase arbol_binario.
#ifndef ARBOL_H
#define ARBOL_H

#include <iostream>
#include "object.hpp"
using ecci::object;
using std::cout;
using std::endl;

#include "nodo_arbol_binario.hpp"

// definicion de la clase arbol_binario
class arbol_binario
{
   public:
      arbol_binario(); // constructor
      virtual ~arbol_binario();
      void inserte(object*);
      void borre(const object*);
      void recorra_preorden() const;
      void recorra_inorden() const;
      void recorra_postorden() const;
      
   private:
      nodo_arbol_binario *m_ptr_raiz;

      // funciones utilitarias
      void destruir_arbol(nodo_arbol_binario *);
      void auxiliar_inserte(nodo_arbol_binario **, object*);
      void auxiliar_borre(nodo_arbol_binario **, const object*);
      void reemplace(nodo_arbol_binario **, nodo_arbol_binario **);
      void auxiliar_preorden(nodo_arbol_binario *) const;
      void auxiliar_inorden(nodo_arbol_binario *) const;
      void auxiliar_postorden(nodo_arbol_binario *) const;
};

#endif
