/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TextoPredictivo.cpp
 * Author: usuario
 * 
 * Created on 9 de noviembre de 2017, 17:36
 */

#include "TextoPredictivo.h"

TextoPredictivo::TextoPredictivo(Diccionario diccidioma):dicBase() {
}

TextoPredictivo::TextoPredictivo(const TextoPredictivo& orig): dicBase(orig.dicBase) {
}

TextoPredictivo::~TextoPredictivo() {
}
std::list<std::string> TextoPredictivo::sugerencia(std::string termino){
    Palabra palabrilla;
    palabrilla.SetTermino(termino);
    if(dicBase.busqueda(termino)==palabrilla){
        throw std::runtime_error("La palabra no esta en el diccionario");
    }else
        return palabrilla.sucesores();
    
}
void TextoPredictivo::entrena(std::string frase){
    dicBase.entrena(frase);
}

