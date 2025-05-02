#include <iostream>
using namespace std;

/*Estás trabajando en un sistema para administrar la cola de pedidos en un restaurante de comida
rápida. Los clientes hacen pedidos en función de su urgencia, y debes implementar un sistema que
permita agregar pedidos a la cola de acuerdo a su urgencia.

1. Inicializa todas las colas de pedidos,estableciendo los punteros de cola de cada nivel de complejidad en NULL*/

struct Pedido {
int numeroPedido;
string descripcion;
int urgencia;
};

struct NodoPedido {
Pedido pedido;
NodoPedido* sgte;
};

struct ColaPedidos {
NodoPedido* frente;
NodoPedido* fin;

};

ColaPedidos colas[5];

//1 
void inicializarColas(ColaPedidos colas[], int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        colas[i].frente = colas[i].fin = nullptr;
    }
    
};
//2. Agregaun pedido a la cola de acuerdo a su urgencia y urgencia. Los parámetros urgencia siempre están
//en el rango de 1 a 5.
void agregarPedido(ColaPedidos colas[], int numeroPedido, string descripcion, int urgencia)
{
    NodoPedido* nuevoPedido = new NodoPedido;
    nuevoPedido->pedido.numeroPedido = numeroPedido;
    nuevoPedido->pedido.urgencia = urgencia;
    nuevoPedido->pedido.descripcion = descripcion;
    nuevoPedido->sgte = nullptr;

    //colas
    if(urgencia >=1 && urgencia <= 5)
    {
        if(colas[urgencia-1].frente == nullptr)
        {
            colas[urgencia-1].frente = nuevoPedido;
            colas[urgencia-1].fin = nuevoPedido;
        }
        else
        {
            colas[urgencia-1].fin->sgte = nuevoPedido;
            colas[urgencia-1].fin = nuevoPedido;  
        }
    }
    cout<<"urgencia no en el rango"<<endl;
}; 
//3.Retorna el pedido más urgente de lacola de pedidos.
Pedido pedidoMasUrgente(ColaPedidos colas[], int cantidad)
{
    Pedidos pedidoMasUrgente;
    pedidoMasUrgente.urgencia = 6;
    for (int i = 0; i < cantidad; i++)
    {
        if(colas[i].frente!=nullptr) //verifico cola llena
        {
            pedidoMasUrgente = colas[i].frente->pedido;
            NodoPedido* p = colas[i].frente; //el NodoPedido 
            //contiene un puntero que me va a servir para apuntar al sgte lugar en la cola
        }
        else colas[i].fin = nullptr; 
        
        delete p;
        return pedidoMasUrgente;
    }

    return pedidoMasUrgente;
    
}; 

//Verifica si todas las colas están vacías. Retorna 1 si todas las colas están vacías, 
//de lo contrario, retorna 0.
int colaVacia(ColaPedidos colas[], int cantidad)
{ 
    for (int i = 0; i < cantidad; i++)
    {
        if(colas[i].frente != nullptr) //al menos una cola NO esta vacia
        {
            return 0;
        }

    }
    return 1;
    
}; 