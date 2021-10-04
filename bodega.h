#ifndef _BODEGA_
#define _BODEGA_ 0

#include <iostream>
#include "listadoble.h"
#include "stack.h"
#include "paletas.h"

using namespace std;

struct bodega {
    
    struct stack columnas;

    int  retirarProducto(int restar){
        if (columnas.isEmpty()==0){
            nodo* nodop = (nodo*) columnas.pop();
            paleta* paleta1 = (paleta*) nodop->data;
            while (restar!=0 & paleta1->cantproducto!=0){
                paleta1->cantproducto=paleta1->cantproducto-1;
                restar--;
            }
            if (restar>0){
                return 1+ retirarProducto(restar);
            }
            if (paleta1->cantproducto>0){
                nodop->data=paleta1;
                columnas.push(nodop);
            }
            if (restar==0){
                cout<<"Si se pudo realizar el pedido (Estado: completo)"<<endl;
                return 1;
            }
        }
        else{
            cout<<"No se pudo realizar el pedido (Estado: incompleto)"<<endl;
            return 0;
        }
        return 0;
    }

    int verCantProductos(){
        if (columnas.isEmpty()==0){
            int largo = columnas.stackList.getSize();
            int cantidad=0;
            nodo* array[largo];
            int cont = 0;
            while (largo!=0){
                nodo* puntero = (nodo*) columnas.pop();
                paleta* paleta1 = (paleta*) puntero->data;
                cantidad = cantidad + paleta1->cantproducto;
                array[cont++]=puntero;
                largo--;
            }
            while (cont!=0){
                nodo* puntero = array[cont--];
                columnas.push(puntero);
            }
            
            return cantidad;
        }
        else{
            return 0;
        }
    }
};

#endif