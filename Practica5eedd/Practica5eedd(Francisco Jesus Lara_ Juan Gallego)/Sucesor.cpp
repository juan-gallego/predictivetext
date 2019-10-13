/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sucesor.cpp
 * Author: usuario
 * 
 * Created on 20 de octubre de 2017, 20:54
 */

#include "Sucesor.h"

Sucesor::Sucesor():termino(""),numOcurrencias(0) {
}
Sucesor::Sucesor(std::string termino):termino(termino){
    numOcurrencias=1;
    
}
Sucesor::Sucesor(const Sucesor& orig):termino(orig.termino), numOcurrencias(orig.numOcurrencias) {
}
int Sucesor::GetNumOcurrencias() const {
        return numOcurrencias;
    }

    void Sucesor::SetNumOcurrencias(int numOcurrencias) {
        this->numOcurrencias = numOcurrencias;
    }

    std::string Sucesor::GetTermino() const {
        return termino;
    }

    void Sucesor::SetTermino(std::string termino) {
        this->termino = termino;
    }
void Sucesor::IncrementarOcu(){
    numOcurrencias++;
}
Sucesor::~Sucesor() {
}
 bool Sucesor::operator<(const Sucesor& right) const {
     if(this->numOcurrencias<right.numOcurrencias)
        return right.numOcurrencias > this->numOcurrencias; 
 else{
         return this->numOcurrencias > right.numOcurrencias;
 }
    }
