#include <iostream>
#include <fstream>
#include "HojaTrabajo.cpp"

using namespace std;

int main(){
    lista* productos = new lista();

    nodo* insertar = new nodo(123,25,30,"Quitate perra");
    nodo* insertar1 = new nodo(343,100,150,"Dos");
    nodo* insertar2 = new nodo(245,15,12,"Tres");
    nodo* insertar3 = new nodo(90,56,40,"Cuatro");
    nodo* insertar4 = new nodo(120,30,25,"Cuatro");
    nodo* insertar5 = new nodo(10,20,25,"Cuatro");

    productos->insertarOrdenado(insertar);
    productos->insertarOrdenado(insertar1);
    productos->insertarOrdenado(insertar2);
    productos->insertarOrdenado(insertar3);
    productos->insertarOrdenado(insertar4);
    productos->insertarOrdenado(insertar5);

    productos->mostrar();

    cout<<"----------------"<<endl;

    lista* copia = productos->copiar();

    copia->mostrar();

    cout<<"----------------"<<endl;

    //productos->eliminar();

    //productos->mostrar();

    return 0;
}
