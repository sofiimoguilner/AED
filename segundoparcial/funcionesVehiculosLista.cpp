#include <iostream>
using namespace std;

/*Se requiere un sistema para gestionar un estacionamiento de vehículos. El estacionamiento cuenta
con diferentes secciones para diferentes tipos de vehículos (moto, autos, camiones). Se debe poder
registrar la entrada de vehículos y buscar vehículos específicos. 
Los tipos tienen un número al cual hacen referencia:
10: Moto
11: Auto
12: Camion
13: Bicicleta
14: Otros
Estructura de datos que debes utilizar:*/
struct Vehiculo
{
    int tipo;
    string patente;
};
struct NodoVehiculo
{
    Vehiculo vehiculo;
    NodoVehiculo* siguiente;
};
struct Seccion
{
    int seccion;
    Vehiculo vehiculo;
};


Seccion secciones[5];

/*Operaciones a implementar:
1. void inicializarEstacionamiento(Sección secciones[], int cantidad);
Inicializa todas las secciones del estacionamiento asegurando que estén sin vehículos. 
2. void registrarVehiculo(Sección secciones[], string patente, int tipoVehiculo);
Registra un vehículo en la sección correspondiente.
3. int cantidadVehiculos(Seccion secciones[], int tipoVehiculo, int cantidadSecciones);
Devuelve la cantidad de vehículos en una sección dada.*/

inicializarEstacionamiento(Sección secciones[], int cantidad)
{
    for(int i=0;i<5;i++)
    {
        secciones[i] = nullptr;
        secciones[i].vehiculo.tipo = 10+i;
    }
}


//agregar elementos a una lista y ver si ya esta iniciada o no 
NodoVehiculo* agregarVehiculo(NodoVehiculo* vehiculo,string patente, int tipoVehiculo)
{
    //abrir el lugar para un nuevo vehiculo 

    NodoVehiculo* NuevoVehiculo = new NodoVehiculo;
    NuevoVehiculo->vehiculo.patente = patente;
    NuevoVehiculo->vehiculo.tipo = tipoVehiculo;
    NuevoVehiculo->siguiente = nullptr;

    //verificar si lista esta vacia
    if(vehiculo==nullptr)
    {
        vehiculo = NuevoVehiculo;
    }else(vehiculo!=nullptr)
    {
        NodoVehiculo* actual = vehiculo;
        while(actual->siguiente !=nullptr) //necesario para encontrar el ultimo nodo
        {
            actual = actual->siguiente     //hasta que el lugar este vacio
        }
        actual->siguiente = NuevoVehiculo;
    }

    return vehiculo;
}

void registrarVehiculo(Seccion secciones[], string patente, int tipoVehiculo)
{
    for(int i=0;i<5;i++)
    {
       if( secciones[i].vehiculo.tipo = tipoVehiculo){
        secciones[i].vehiculo = agregarVehiculo(secciones[i].vehiculo,patente,tipoVehiculo)}
    }

    cout<<"no se encontro seccion del vehiculo";

}

int cantidadVehiculos(Seccion secciones[], int tipoVehiculo, int cantidadSecciones)
{
    int contador = 0;
    for(int i=0;i<5;i++)
    {
       if( secciones[i].vehiculo.tipo = tipoVehiculo)
       {NodoVehiculo* actual = secciones[i].vehiculo//puntero actual se inicializa con el valor secciones[i].vehiculo
       while(actual->siguiente != nullptr)
       {
        contador++;
        actual = actual->siguiente; //señala a la siguiente posicion
       } }

    }
    return contador;

}
