#include <iostream>
#include "lib/bodega.h"
#include "lib/montacarga.h"
#include "lib/nodo.h"
#include "lib/listadoble.h"
#include "lib/stack.h"
#include "lib/paletas.h"
#include "lib/queue.h"
#include "lib/pedidounico.h"

using namespace std;

int main() {

    //-------------------------------------------ARROZ--------------------------------------------
    struct paleta arroz1 = {25};
    struct paleta arroz2 = {25};
    struct paleta arroz3 = {25};
    struct paleta arroz4 = {25};
    struct paleta arroz5 = {25};
    struct paleta arroz6 = {25};
    struct nodo a1;
    a1.data = &arroz1;
    struct nodo a2;
    a2.data = &arroz2;
    struct nodo a3;
    a3.data = &arroz3;
    struct nodo a4;
    a4.data = &arroz4;
    struct nodo a5;
    a5.data = &arroz5;
    struct nodo a6;
    a6.data = &arroz6;
    struct stack columnaarroz;
    columnaarroz.push(&a1);
    columnaarroz.push(&a2);
    columnaarroz.push(&a3);
    columnaarroz.push(&a4);
    columnaarroz.push(&a5);
    columnaarroz.push(&a6);

    struct bodega bodegaarroz;
    bodegaarroz.columnas = columnaarroz;

    //-------------------------------------------FRIJOLES--------------------------------------------
    struct paleta frijoles1 = {40};
    struct paleta frijoles2 = {40};
    struct paleta frijoles3 = {40};
    struct paleta frijoles4 = {40};
    struct paleta frijoles5 = {40};
    struct nodo f1;
    f1.data = &frijoles1;
    struct nodo f2;
    f2.data = &frijoles2;
    struct nodo f3;
    f3.data = &frijoles3;
    struct nodo f4;
    f4.data = &frijoles4;
    struct nodo f5;
    f5.data = &frijoles5;
    struct stack columnafrijoles;
    columnafrijoles.push(&f1);
    columnafrijoles.push(&f2);
    columnafrijoles.push(&f3);
    columnafrijoles.push(&f4);
    columnafrijoles.push(&f5);

    struct bodega bodegafrijoles;
    bodegafrijoles.columnas = columnafrijoles;
    
    //-------------------------------------------PEDIDOS--------------------------------------------
    int time1 = bodegaarroz.retirarProducto(30);
    int time2 = bodegafrijoles.retirarProducto(60);
    int time3 = bodegaarroz.retirarProducto(15);
    int time4 = bodegafrijoles.retirarProducto(10);
    cout<<endl;
    cout<<bodegaarroz.verCantProductos()<<" Productos restantes"<<endl;
    cout<<bodegafrijoles.verCantProductos()<<" Productos restantes"<<endl;
    cout<<endl;

    struct pedidounico pedido1;
    pedido1.cantidad = 50;
    pedido1.nombrebodega = bodegaarroz;
    struct pedidounico pedido2;
    pedido2.cantidad = 40;
    pedido2.nombrebodega = bodegafrijoles;

    struct nodo nodop1;
    nodop1.data = &pedido1;
    struct nodo nodop2;
    nodop2.data = &pedido2;

    struct queue colapedidos1;
    colapedidos1.enqueue(&nodop1);
    colapedidos1.enqueue(&nodop2);

    struct queue colapedidos2;

    struct montacarga montac1;
    struct montacarga montac2;
    montac1.tiempo= 1000;
    montac2.tiempo= 2000;
    montac1.colapedidos = colapedidos1;
    montac1.traerProductos();
    montac2.traerProductos();
    
}