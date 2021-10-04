#ifndef _MONTACARGA_
#define  _MONTACARGA_ 0 

#include <iostream>
#include "pedidos.h"
#include "bodega.h"
#include "pedidounico.h"
#include "nodo.h"
#include "queue.h"

using namespace std;

struct montacarga {
    int tiempo = 0;
    struct queue colapedidos;

    void traerProductos(){
        if (colapedidos.isEmpty()==0){
            while (colapedidos.isEmpty()==0){
                struct nodo* punternoactual = (nodo*) colapedidos.dequeue();
                struct nodo actual = *punternoactual;
                struct pedidounico* datospedido = (pedidounico*) actual.data;
                int cantidad = datospedido->cantidad;
                struct bodega nombreb = datospedido->nombrebodega;
                int time = nombreb.retirarProducto(cantidad);
                cout<<"Se realizo en :"<<(tiempo*time)/1000<<" segundos"<<endl;
            }
        }
        else{
            cout<<"No hay pedidos en cola"<<endl;
        }
    }
};

#endif