#include <iostream>
#include <stdlib.h>

using namespace std;

struct nodo{
public:
    int codProd;
    int stock;
    int stockMin;
    string codProv;
    nodo* siguiente;

    nodo(int codProd, int stock, int stockMin, string codProv){
        this -> codProd = codProd;
        this -> stock = stock;
        this -> stockMin = stockMin;
        this -> siguiente = NULL;
    }
};

struct lista{
public:
    nodo* inicio;
    nodo* fin;

    lista(){
        inicio = NULL;
        fin = NULL;
    }

    bool listaVacia(){
        if(inicio == NULL){
            return true;
        }else{
            return false;
        }
    }

    void insertarOrdenado(nodo* pull){
        if(listaVacia()){
            inicio = fin = pull;
        }else{
            if(pull->codProd < inicio ->codProd){
                insertarInicio(pull);
            }else if(pull->codProd > fin->codProd){
                insertarFin(pull);
            }else{
                insertarMedio(pull);
            }
        }
    }

    void insertarInicio(nodo* pull){
        pull -> siguiente = inicio;
        inicio = pull;
    }

    void insertarFin(nodo* pull){
        fin -> siguiente = pull;
        fin = pull;
    }

    void insertarMedio(nodo* pull){
        nodo* aux;
        nodo* aux2;

        aux = inicio;

        while(aux -> codProd < pull -> codProd){
                if(aux->siguiente->codProd < pull->codProd){
                    aux = aux->siguiente;
                }else{
                    break;
                }
        }

        aux2 = aux -> siguiente;
        aux -> siguiente = pull;
        pull -> siguiente = aux2;
    }

    lista* copiar(){
        nodo* aux = inicio;
        lista* copia = new lista();

        while(aux != NULL){
            if(aux->stock <= aux->stockMin){
                copia->insertarOrdenado(aux);
            }
            aux = aux -> siguiente;
        }

        return copia;
    }



    void mostrar(){
        nodo* temp = inicio;
        while(temp!=NULL){
            cout<<"codigo Producto: "<<temp->codProd<<endl;
            temp = temp->siguiente;
        }
    }
};
