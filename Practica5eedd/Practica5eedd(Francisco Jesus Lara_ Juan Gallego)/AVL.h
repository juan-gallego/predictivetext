#ifndef AVL_H
#define AVL_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename U>
class Nodo{
  public:
          Nodo<U> *izq,*der;
    U dato;
    char bal;

    Nodo (U &ele):izq(0),der(0),bal(0) {
        dato=ele;
    }
};


template <typename T>
class AVL {
    Nodo<T> *raiz;
public:
    AVL(){
        raiz=0;
    }

    bool inserta(T &dato){
        return inserta(raiz,dato);
    }
    AVL(const AVL& orig):raiz(orig.raiz){
        raiz=0;       
     
                   
                    Copia(orig.raiz, raiz);
           
         
        

    }
        AVL<T>& operator=(const AVL& right){
        if(this==&right){
            return *this;
          
    }
        
        destruyeArbol(raiz);
        Copia(right.raiz,raiz);
     return *this;   
    }
    virtual ~AVL(){
        destruyeArbol(raiz);
    }
    void recorreInorden(){
         inorden(raiz,0);
    }
    bool buscar(T &ele,T &result);
    unsigned int numElementos(){
                Nodo<T> *p = raiz;
        int numE = 0;

        numElementos(p, 0, numE);
        return numE;
    }

    void Copia(Nodo<T>* orig,Nodo<T> *&r){
        if(orig){
             r=new Nodo<T>(orig->dato);
             Copia(orig->izq,r->izq);
             Copia(orig->der,r->der);
    }else{
            r=0;
        }
    }
void destruyeArbol(Nodo<T> *&p);
private:
    void rotDer(Nodo<T>* &nodo);
    void rotIzq(Nodo<T>* &nodo);
    int inserta(Nodo<T>* &c, T &dato);
    void inorden(Nodo<T> *p, int nivel);
    int altura(Nodo<T> *p,int nivel,int &max);
    Nodo<T>* buscaClave(T& ele,Nodo<T>* p);
    void numElementos (Nodo<T>* &p, int nivel, int numE);
    
    bool preorden(Nodo<T> *p,int nivel);
};    
    
    
template <typename T>
void AVL<T>::rotDer(Nodo<T>* &nodo){
    Nodo<T> *q=nodo, *l;
    nodo=l=q->izq;
    q->izq=l->der;
    l->der = q;
    q->bal--;
    if(l->bal>0){
        q->bal -=l->bal;
    }
    l->bal--;
    if(q->bal < 0){
        l->bal -= -q->bal;
    }
    
}

template <typename T>
void  AVL<T>::rotIzq(Nodo<T>* &nodo){
   Nodo<T> *q=nodo, *r;
   nodo= r=q->der;
   q->der=r->izq;
   r->izq= q;
   q->bal++;
   if(r->bal <0){
       q->bal +=-r->bal;
   }
   r->bal++;
   if(q->bal>0){
       r->bal += q->bal;
   }
}
template <typename T>
int  AVL<T>::inserta(Nodo<T>* &c, T &dato){
    Nodo<T> *p= c;
    int deltaH=0;
    if(!p){
        p=new Nodo<T>(dato);
        c= p;
        deltaH=1;
    }
    else if(dato > p->dato){
        if(inserta(p->der,dato)){
            p->bal--;
            if(p->bal==-1){
                deltaH=1;
            }
            else if(p->bal ==-2){
                if(p->der->bal==1){
                    rotDer(p->der);
                }
                rotIzq(c);
            }
        }
    }
    else if (dato<p->dato){
        if(inserta(p->izq,dato)){
            p->bal++;
            if(p->bal==1){
                deltaH=1;
            }
            else if(p->bal==2){
                if(p->izq->bal==-1){
                    rotIzq(p->izq);
                }
                rotDer(c);
            }
        }
    }
    return deltaH;
    
 }
template <typename T>
void AVL<T>::inorden(Nodo<T> *p, int nivel){

    if(p){
        inorden(p->izq, nivel+1);
        cout <<"Procesando inorden:" << p->dato;
        cout << "en el nivel:" << nivel <<endl;
        inorden(p->der, nivel+1);
        
          
    }
    
}
template<typename T>
Nodo<T>* AVL<T>::buscaClave(T& ele,Nodo<T>* p){
    if(!p)
        return 0;
    else if(ele < p->dato)
        return buscaClave(ele, p->izq);
    else if (ele > p->dato)
        return buscaClave(ele,p->der);
    else return p;
}
template <typename T>
bool AVL<T>::buscar(T &ele,T &result){
    Nodo<T> *p= buscaClave(ele,raiz);
    if (p){
        result = p->dato;
        return true;
    }
    return false;
}
template <typename T>
int AVL<T>::altura(Nodo<T> *p,int nivel,int &max){
    if(p){
        altura(p->izq,nivel+1,max);
        if(nivel>max)max=nivel;
        altura(p->der,nivel+1,max);
    }
    return nivel;
}

template <typename T>
void AVL<T>::numElementos(Nodo<T>* &p, int nivel, int elem) {
        
        if (p->izq)
            numElementos(p->izq, nivel + 1, elem); 
        if (p->der)
            numElementos(p->der, nivel + 1, elem);

        (elem)++;
    }

template <typename T>
void AVL<T>::destruyeArbol(Nodo<T> *&p){
    if(p){
        destruyeArbol(p->izq);
        destruyeArbol(p->der);
        delete p;
        p=0;
    }
}
template <typename T>
bool AVL<T>::preorden(Nodo<T>* p,int nivel){
    if(p){

        preorden(p->izq,nivel+1);
        preorden(p->der,nivel+1);
    }
    return true;
}


#endif /* AVL_H */

