#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

//funciones de las que dispongo 
void insertarOrdenado();
Nodo* buscarEnLista();
void insertarSinRepetir();
void push();
void pop();
void queu(NodoCola&cola, ClienteEnCola cliente);

//archivo binario Cajas.dat, concalores iniciales de las cajas
struct CajaArchivo
{
    int nroDeCaja;
    int dineroEfectivo;
};

struct ClienteEnCola
{
    int nro_carrito;
    ClienteEnCola*sgte;
};
struct NodoCola
{
    ClienteEnCola*frente;
    ClienteEnCola*fin;
};



struct Ventas
{
    int efectivo=0;
    int importeTotal=0;
    int cant_credito=0;
    int cant_debito=0;
    int cant_promocion=0;
    Ventas* sgte_venta;
};


struct Caja
{
    int total_Apertura =0;
    int nro_de_caja;
    int tot_Efectivo=0;
    int valores_cobrados_ventas=0;
    Ventas* venta = nullptr;
    ClienteEnCola* cola_de_clientes = nullptr;
};

Caja cajas[40]= {NULL};// no hago noso si no directamente el vector pq es una estructura fija la inicializo vacia

void CajasHabilitadas(Caja cajas[],char* nombre_archivo)
{
    FILE* archivoCajas = fopen(nombre_archivo, "rb");

    CajaArchivo caja;

    while (fread(&caja,sizeof(CajaArchivo),1,archivoCajas))
    {
        int posicion= caja.nroDeCaja - 1;
        cajas[posicion].total_Apertura +=caja.dineroEfectivo;
    }
    fclose(archivoCajas);
};

void nuevoCliente(NodoCola& cola, ClienteEnCola cliente)
{
    queu(cola,cliente);
};

void atenderClientes(Caja cajas[], int nroCaja){

    ClienteEnCola *aux;
    Ventas importes;

    aux = unQueu(cajas[nroCaja-1].cola_de_clientes);
    importes = calcularImportes(aux->nro_carrito);

    cajas[nroCaja-1].valores_cobrados_ventas += importes.importeTotal;
    cajas[nroCaja-1].tot_Efectivo += importes.efectivo;
    cajas[nroCaja - 1].venta->cant_credito += importes.cant_credito;
    cajas[nroCaja - 1].venta->cant_debito += importes.cant_debito;
    cajas[nroCaja -1].venta->cant_promocion += importes.cant_promocion;
    cajas[nroCaja-1].venta->sgte_venta = nullptr;
};

void reasignarCaja(int cajaActual, int cajaNueva, Caja cajas[])
{
    ClienteEnCola*aux;
    aux = unQueu(cajas[cajaActual-1].cola_de_clientes);

    queu(cajas[cajaNueva-1].cola_de_clientes, aux);
}