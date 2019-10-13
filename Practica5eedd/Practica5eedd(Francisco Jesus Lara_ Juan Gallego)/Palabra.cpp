
#include <list>


#include "Palabra.h"
Palabra::Palabra(){
    
}
Palabra::Palabra(std::string termino):termino(termino),siguientes() {
}

Palabra::Palabra(const Palabra& orig)
        :termino(orig.termino),siguientes(orig.siguientes) {
}

Palabra::~Palabra() {
}


    std::string Palabra::GetTermino() const {
        return this->termino;
    }

    void Palabra::SetTermino(std::string termino) {
        this->termino = termino;
    }
    
    Palabra& Palabra::operator=(const Palabra& right){
    if(this==&right)
        return *this;
    termino=right.termino;
    siguientes=right.siguientes;
    
    return *this;
}
        bool Palabra::operator>(const Palabra& right){
                 if(this->termino>right.termino)
        return true; 
 else{
         return false;
 }
            
        }
    bool Palabra::operator<(const Palabra& right){
               if(this->termino<right.termino)
        return true; 
 else{
         return false;
 }
        
    }
    bool Palabra::operator==(const Palabra& right){
        if(this->termino==right.termino)
            return true;
    else{
            return false;
    }
    }
void Palabra::nuevoSucesor(string termino){

    bool repetido = false;
    std::list<Sucesor>::iterator it;
    it = siguientes.begin();
    while (it!=siguientes.end()) {

        if (it->GetTermino() == termino) {

            it->IncrementarOcu();
            repetido = true;

        }

        it++;
    }

    if (repetido == false) {
        Sucesor sucesor(termino);
        siguientes.push_back(sucesor);
        
    }
}
//  
//    bool encontrado = false;
//    int ocurrencia = 1;
//    std::list<Sucesor>::iterator it = siguientes.begin();
//    for (unsigned int i = 0; i < siguientes.size(); i++) {
//        if (it->GetTermino() == termino) {
//            ocurrencia = it->GetNumOcurrencias() + 1;
//            it->SetNumOcurrencias(ocurrencia);
//            encontrado = true;
//            i = siguientes.size();
//        }
//        it++;
//    }
//    if (encontrado == false) {
//        Sucesor s(termino);
//        siguientes.push_back(s);
//    }
//}
 
list<std::string> Palabra::sucesores(){



    std::priority_queue<Sucesor> cola;
    std::list<Sucesor>::iterator it;
    while(it!=siguientes.end()){
        
        cola.push(*it);
    it++;
    }
    std::list<string> lista;
    int contador = 0 ;
    while(!cola.empty() && contador<10){
        lista.push_back(cola.top().GetTermino());
        cola.pop();
        contador ++;
    }

    return lista;

}

//    int contador = 0;
//    std::priority_queue<Sucesor> pq;
//    std::list<std::string> l;
//    ;
//    std::string cadena;
//    std::stringstream ss;
//    auto it = siguientes.begin();
//    for (unsigned int i = 0; i < siguientes.size(); i++) {
//        pq.push(*it);
//        it++;
//        contador++;
//    }
//
//    for (int i = 0; i < 10; i++) {
//
//        ss << "Ocurrencia:" << pq.top().GetNumOcurrencias() << " Palabra->" << pq.top().GetTermino();
//        getline(ss, cadena);
//        l.push_back(cadena);
//        ss.clear();
//        cadena.clear();
//        pq.pop();
//        if (i == contador) {
//            i = 10;
//        }
//return l;
//    }