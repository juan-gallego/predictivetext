/* 
 * @file:   main.cpp
 * @author: Poo
 *
 * @date 18 de septiembre de 2017, 21:48
 */

#include <cstdlib>
#include "Palabra.h"
#include "Diccionario.h"
#include <chrono>
#include <iostream>
#include <vector>
#include <list>
#include "AVL.h"
using namespace std;


int main(int argc, char** argv) {
  auto start = std::chrono::system_clock::now();
//    Diccionario dic("listado-general.txt");
//    Palabra p1;        
//    Palabra p2;
//    p1.SetTermino("aconsejar");
//    p2.SetTermino("elefante");
//    
//    
//
//
//    Diccionario dicc;
//    dicc.usaCorpus("corpus_spanish.txt");
//    Palabra pala("el");
    AVL<int> arbolito;
    int a[6]={5,2,8,7,6,9};
    arbolito.inserta(a[0]);
    arbolito.inserta(a[1]);
    arbolito.inserta(a[2]);
    arbolito.inserta(a[3]);
    arbolito.inserta(a[4]);
    
    arbolito.inserta(a[5]);
    AVL<int> arbolito2;
    arbolito2=arbolito;

    arbolito.recorreInorden();
    arbolito2.recorreInorden();
auto end = std::chrono::system_clock::now();
auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
cout << "Time spent (ms) : " << elapsed_ms << endl;
    
   return 0;
}

