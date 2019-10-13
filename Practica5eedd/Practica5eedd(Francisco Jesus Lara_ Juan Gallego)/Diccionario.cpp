/* 
 * @file:   Diccionario.cpp
 * @author: Poo
 * 
 * @date 18 de septiembre de 2017, 21:49
 */

#include "Diccionario.h"
#include <stdexcept>
#include <fstream>
#include "Palabra.h"
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <list>
#include "AVL.h"
using namespace std;

Diccionario::Diccionario(){
}
Diccionario::~Diccionario() {

}

Diccionario::Diccionario(unsigned int pos,AVL<Palabra> arbol)
    :pos(pos),arbol() {
    
}

Diccionario::Diccionario(const Diccionario& orig) {
    pos=orig.pos;
    
}

Diccionario::Diccionario(std::string NomFich):arbol(){
   
    std::fstream fe;
    std::string linea;
    
    fe.open("listado-sin-acentos_v2.txt");
    if (fe.good()){
        while(!fe.eof()){
            getline(fe,linea);
            if(linea!=""){
                Palabra lin;
                lin.SetTermino(linea);
                arbol.inserta(lin);
                
                
            }
        }

        fe.close();
    }else{
        throw runtime_error("no se puede abrir el archivo");
    }
}

void Diccionario::cargaPalabras(std::string NomFich){
    std::fstream fe;
    std::string linea;
    
    fe.open("listado-sin-acentos_v2.txt");
    if (fe.good()){
        while(!fe.eof()){
            getline(fe,linea);
            if(linea!=""){
                Palabra lin;
                lin.SetTermino(linea);

                arbol.inserta(lin);
            }
        }

        fe.close();
    }else{
        throw runtime_error("no se puede abrir el archivo");
    }
}
Palabra  Diccionario::busqueda(string dato){
    Palabra pal;
    pal.SetTermino(dato);
    Palabra esta;
    if(arbol.buscar(pal,esta)){
        return esta;
    }else
        throw std::runtime_error("La palabra que buscas no esta en el diccionario");
    
}

void Diccionario::insertar(std::string termino){
Palabra esta;

Palabra pal(termino);
if(arbol.buscar(pal,esta)){
    arbol.inserta(pal);
}else
    throw std::runtime_error("No se puede insertar la palabra ya que ya esta en el diccionario");

}

void Diccionario::entrena(string &frase){
    Palabra esta;
    std::string comprueba = "zz";
    std::string palabra;
    std::stringstream ss;
    int total = 0;
    ss << frase;
    while (!ss.eof()) {
        ss >> palabra;
        if (palabra != "") {
            std::cout << ++total << " " << palabra << std::endl;

            Palabra pal(palabra);

            if(!arbol.buscar(pal,esta)) {

                arbol.inserta(pal);

            }
            if (comprueba != "zz") {
                Palabra pal2(palabra);
                arbol.buscar(pal2,esta);
                pal2.nuevoSucesor(pal2.GetTermino());

            }
            palabra=comprueba;
            comprueba="";
        }
    }
    std::cout << "total palabras: " << total << std::endl;

   }


void Diccionario::usaCorpus(string nom_fich_corpus){
    std::fstream fe;
    std::string linea;
    int total=0;
    fe.open("corpus_spanish.txt");
    if (fe.good()){
        while(!fe.eof()){
            getline(fe,linea);
            if(linea!=""){
                entrena(linea);
                cout <<"Total de frases :" << ++total << endl;
                
            }
        }
    fe.close();
    }else{
        throw runtime_error("no se puede abrir el archivo");
    }
}
//Palabra& Diccionario::GetPalabra(Palabra& pala){
//    return arbol[this->busqueda(pala.GetTermino())];
//}
