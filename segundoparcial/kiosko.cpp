#include <iostream>
using namespace std;

/*Se requiere un sistema para gestionar las ventas de productos de un kiosko de la semana. El kiosko
vende distintos tipos de productos como golosinas, bebidas y artículos de librería. Se debe poder
registrar ventas y conocer los ingresos de dichas ventas de cada día.
Operaciones a implementar:
1.Devuelve la lista de ventas semanales con 5 nodos, uno para cada día. Donde cada día es
representado por un número del 1 al 5 y asegurandose que todos los días arranquen sin productos
vendidos.
2.Registra una venta de un producto en el día correspondiente. Da por hecho que ya está validado
previamente si el día esta entre 1 y 5.
3. Devuelve el día en el que se generó más ingresos por ventas.*/

struct Producto {
string nombre;
float precio;
int cantidad;
};
struct NodoProducto {
Producto producto;
NodoProducto* sgte;
};
struct NodoVentasDelDia {
NodoProducto* productosVendidos;
int dia; // 1..5
NodoVentasDelDia* sgte;
};
NodoVentasDelDia* ventasSemanal;

//1
NodoVentasDelDia* AgregarVentas(NodoVentasDelDia* venta, int dia, )
{
    NodoVentasDelDia NuevaVenta = new NodoVentasDelDia; //inicializo todo en NULL (enunciado)
    NuevaVenta.dia = dia;
    NuevaVenta.productosVendidos = nullptr;
    NuevaVenta.sgte = nullptr

    //veo si lista esta vacia

    if(venta == nullptr)
    {
        venta = NuevaVenta;
    }
    else
    {
        NodoVentasDelDia* actual = venta;

        while(actual != nullptr)
        {
            actual = actual->sgte;
        }

        actual->sgte = NuevaVenta;
    }
    return venta;
}


NodoVentasDelDia* dameVentasSemanalInicializado()
{
    //inicializo los dias de venta, asegurandome que esten vacios
    NodoVentasDelDia* ventas = nullptr;

    // relleno de ventas debe estar en NULL 

    for (int i = 0; i < 5; i++)
    {
        ventas= AgregarVentas(ventas,i+1);
    }

    return ventas;
    

};

//2

NodoProducto* AgregarVentaDeProducto(NodoProducto* producto, string nombre, int cantidad, float precio)
{
    NodoProducto productoNuevo = new NodoProducto;
    productoNuevo.producto.nombre = nombre;
    productoNuevo.producto.cantidad = cantidad;
    productoNuevo.producto.precio = precio;
    productoNuevo.sgte = nullptr;

    if(producto == nullptr)
    {
        producto = productoNuevo;
    }
    else
    {
        NodoProducto* actual = producto;
        while(actual!=nullptr)
        {
            actual = actual->sgte;
        }
        actual->sgte = productoNuevo;

    }
    return producto;
}
void registrarVenta(NodoVentasDelDia* ventasSemanal, int dia, string nombre, int cantidad, float precio)
{
    //necesito si o si el aux ya que este permitira que ventasSemanal apunte ctemte a la cima de la lista
    NodoVentasDelDia* aux = ventasSemanal;

    while (aux.dia!=dia) //busco el dia de venta, si no lo encuentra avanza
    {
        aux = aux->sgte
    }

    //una vez que encuentra el dia del producto lo agrega con la funcion
    aux->productosVendidos = AgregarVentaDeProducto(aux,nombre,cantidad,precio);

}

//3para sacar el dia mas exitoso de la semana, primero tengo qu sacar la cuenta del dia y despues la comparacion

int SumatoriaDeVenta(NodoProducto* ventas)
{
    int sumatoria = 0;

    while (ventas!=nullptr)
    {
        sumatoria +=ventas->producto.precio * ventas->producto.cantidad;
        ventas = ventas->sgte;
    }
    return sumatoria;

};
int dameDiaMasExitoso(NodoVentasDelDia* ventasSemanal)
{
    int maxVenta=0, dia=0;

    while (ventasSemanal!=nullptr)
    {
        int ventadeldia = SumatoriaDeVenta(ventasSemanal->productosVendidos);
        if (ventadeldia > maxVenta)
        {
            maxVenta = ventadeldia;
            dia = ventasSemanal->dia;
        } 
        ventasSemanal = ventasSemanal->sgte;
    }

    return dia;
    
};