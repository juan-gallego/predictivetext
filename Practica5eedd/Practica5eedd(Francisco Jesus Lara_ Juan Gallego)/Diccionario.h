/* 
 * @file:   Diccionario.h
 * @author: Poo
 *
 * @date 18 de septiembre de 2017, 21:49
 */

#ifndef DICCIONARIO_H
#define DICCIONARIO_H
#include "Palabra.h"

#include <algorithm>
#include <vector>
#include <list>
#include "AVL.h"

class Diccionario {
public:
    Diccionario();
    Diccionario(std::string NomFich);
    Diccionario(unsigned int pos,AVL<Palabra> arbol);
    Diccionario(const Diccionario& orig);
    virtual ~Diccionario();
   

  
    

    void insertar(std::string termino);
    void cargaPalabras(std::string NomFich);
    Palabra busqueda(std::string dato);
    void entrena(string &frase);
    void usaCorpus(string nom_fich_corpus);
    Palabra& GetPalabra(Palabra& pala);

private:
    int pos;
    AVL<Palabra> arbol;
    };

#endif /* DICCIONARIO_H */

