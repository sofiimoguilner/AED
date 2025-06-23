#include <iostream>
#include <string.h>
#include <stdio.h>
define t 100 //cant de ofertas
using namespace std;

void interactuar ();

struct Sucursal
{
    int nroDeSucursal;
    int codigosOfertas[t];
    int cantOfertas; //ctas odertas hay verdaderamente cargadas  
};

struct Nodo
{
    Sucursal sucursal;
    Nodo* sgte;
};


Nodo* sucursales[5];

int main(){

}

char* getAccion(int n);
int getEspacioDeAccion();
void listar(Nodo* sucursales);
void insertar(Nodo* sucursales);
void eliminar(Nodo* sucursales);
void vaciar(Nodo* sucursales);

void interactuar(){

    char accion[10];
    int opcion;
    int espacio;
    cout<<"Ingrese su seleccion: 1- listar, 2- ..."<<endl;
    cin>>opcion;
    strcpy(accion,getAccion(opcion));
    espacio=getEspacioDeAccion();
    if(strcmp(accion,"Listar")==0){
        if (espacio==0){
            for(int i=0;i<5;i++){
                listar(sucursales[i]);
            }
        } else {
            listar(sucursales[espacio-1]);
        }
    } else if(strcmp(accion,"Insertar")==0){
        if (espacio==0){
            for(int i=0;i<5;i++){
                insertar(sucursales[i]);
            }
        } else {
            insertar(sucursales[espacio-1]);
        }
    } else if(strcmp(accion,"Eliminar")==0){
        if (espacio==0){
            for(int i=0;i<5;i++){
                eliminar(sucursales[i]);
            }
        } else {
            eliminar(sucursales[espacio-1]);
        }
    } else if(strcmp(accion,"Vaciar")==0){
        if (espacio==0){
            for(int i=0;i<5;i++){
                vaciar(sucursales[i]);
            }
        } else {
            vaciar(sucursales[espacio-1]);
        }
    }
    while (strcmp(accion,"Finalizar")!=0){
        cout<<"Ingrese su seleccion: 1- listar, 2- ..."<<endl;
        cin>>opcion;
        strcpy(accion,getAccion(opcion));
        espacio=getEspacioDeAccion();
        if(strcmp(accion,"Listar")==0){
        listar();
    } else if(strcmp(accion,"Insertar")==0){
        insertar();
    } else if(strcmp(accion,"Eliminar")==0){
        eliminar();
    } else if(strcmp(accion,"Vaciar")==0){
        vaciar();
    }
    }

}

void eliminar (Nodo* &sucursal){
    int pos;
    cout<<"Inidque cual oferta desea eliminar"<<endl;
    cin>>pos;
    eliminarNodo(sucursal,pos);
}

void insertar (Nodo* &sucursal){
    int oferta;
    cout<<"Ingrese el nro de oferta"<<endl;
    cin>>oferta;
    agregarNodo(sucursal,oferta);
}

void agregarNodo(Nodo& sucursal,int codigoOferta) //agrega oferta si hay espacio
{
    int pos = sucursal.sucursal.cantOfertas;

    if (pos < t)
    {
        sucursal.sucursal.codigosOferta[pos] = codigoOferta;
        sucursal.sucursal.cantOfertas ++;
        cout<< "Oferta agregada correctamente. "<<endl;
    }else cout<<"No hay espacio para agregar ofertas. "<<endl;

}

void eliminarNodo (Nodo& sucursal, int codigoOferta)//elimina oferta de la lista
{
    int pos = sucursal.sucursal.cantOfertas;

    for (int i=0; i<pos ; i ++)
    {
        if(codigoOferta = sucursal.sucursal.codigosOfertas[i])
        {
            sucursal.sucursal.codigosOfertas[i] = sucursal.sucursal.codigosOfertas[i+1];
            sucursal.sucursal.cantOfertas --;
            cout<<"Oferta eliminada correctamente. "<<endl;
        }
    }

}