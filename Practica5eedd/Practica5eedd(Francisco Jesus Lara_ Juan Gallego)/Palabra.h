/* 
 * @file:   Palabra.h
 * @author: Poo
 *
 * @date 18 de septiembre de 2017, 21:51
 */

#ifndef PALABRA_H
#define PALABRA_H
#include <iostream>
#include <string>
#include <fstream>
#include "Sucesor.h"
#include <list>
#include <functional>
#include <vector>
#include <iosfwd>
#include <sstream>
#include <queue>

class Palabra {
public:
    Palabra();
    Palabra(std::string termino);
    Palabra(const Palabra& orig);
    virtual ~Palabra();
    Palabra& operator=(const Palabra& right);
    bool operator>(const Palabra& right);
    bool operator<(const Palabra& right);
    bool operator==(const Palabra& right);
    std::string GetTermino() const;
    void SetTermino(std::string termino);
    void nuevoSucesor(string termino);
    list<std::string> sucesores();

private:
    std::string termino;
    list<Sucesor> siguientes;
    

};

#endif /* PALABRA_H */

