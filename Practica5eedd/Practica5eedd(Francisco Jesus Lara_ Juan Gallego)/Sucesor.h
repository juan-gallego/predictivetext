/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sucesor.h
 * Author: usuario
 *
 * Created on 20 de octubre de 2017, 20:54
 */

#ifndef SUCESOR_H
#define SUCESOR_H
#include <iostream>
#include <string>

using namespace std;

class Sucesor {
public:
    Sucesor();
    Sucesor(std::string termino);
    Sucesor(const Sucesor& orig);
    int GetNumOcurrencias() const;
    void SetNumOcurrencias(int numOcurrencias);
    string GetTermino() const ;
    void SetTermino(string termino);
    void IncrementarOcu();
    virtual ~Sucesor();
    bool operator<(const Sucesor& right) const;

private:
    string termino;
    int numOcurrencias;
    

};

#endif /* SUCESOR_H */

