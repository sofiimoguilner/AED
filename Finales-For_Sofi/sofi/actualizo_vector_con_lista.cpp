#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

struct Saldo
{
    int nro_cuenta;
    int cant_transacciones;
    int saldo;
};



struct NodoTransaccion
{
    int nro_cuenta;
    int monto;
    NodoTransaccion* sgte;
};


void vectorActualizado(Saldo saldos[], NodoTransaccion* transaccion)
{
    NodoTransaccion* aux = transaccion;

    while (aux!=NULL)
    {
        for (int i = 0; i < 150; i++)
        {
            if(aux->nro_cuenta == saldos[i].nro_cuenta)
            {
                saldos[i].saldo = saldos[i].saldo + aux->monto;
                saldos[i].cant_transacciones = saldos[i].cant_transacciones + 1;
            };
        }

        aux = aux->sgte;
        
    }
    
}
