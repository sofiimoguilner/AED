#include <iostream>
using namespace std;


//hacer un struct para hacer un arrary de colas 
struct Mesa
{
    int nro;
    int factura;
    bool ocupado = false; //false->mesa libre

};

struct MesaCola
{
    Mesa mesa;
    int pedido;
    NodoCola* inicio;
    NodoCola* final;
    

};

struct NodoCola
{
    NodoCola* siguiente;
}

void ColaMesa(int nro, Mesa m[]); // buscar si la mesa esta libre


int main()
{
    FILE* ArchivoMesas = fopen("ArchivoMesas.dat", "wb");

    int opcion; 






    fseek(ArchivoMesas, 0, SEEK_SET);
    fwrite(array, sizeof(Mesa), 10, ArchivoMesas);
    fclose(ArchivoMesas);
    return 0;
}

void ColaMesa(int nro, MesaCola m[])
{
    
}


