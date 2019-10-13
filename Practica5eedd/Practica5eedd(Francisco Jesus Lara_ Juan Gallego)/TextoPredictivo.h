/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TextoPredictivo.h
 * Author: usuario
 *
 * Created on 9 de noviembre de 2017, 17:36
 */

#ifndef TEXTOPREDICTIVO_H
#define TEXTOPREDICTIVO_H
#include "Diccionario.h"
#include <string>
#include <list>


class TextoPredictivo {
public:
    TextoPredictivo(Diccionario diccidioma);
    TextoPredictivo(const TextoPredictivo& orig);
    virtual ~TextoPredictivo();
    std::list<std::string> sugerencia(std::string termino);
    void entrena(std::string frase);
private:
    Diccionario dicBase;
};

#endif /* TEXTOPREDICTIVO_H */

