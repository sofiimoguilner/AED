#include <iostream>
using namespace std;

/*EJ 1 : hacer lista ordenada a partir de la interseccion de una pila y una cola*/

struct Nodo
{
    int dato;
    Nodo* sgte;
}

Nodo* listaOrdenada(Nodo* pila, Nodo* cola)
{
    Nodo* lista; //lista resultante, inicializa vacia
    Nodo aux;//ayuda a recorrer la cola 

    while(pila){
        aux = cola;
     while(aux){
      if(pila.datos == cola.datos)
      {
        insertarOrdenado(lista, pila.dato);
        aux = NULL;
      }
      else
      {
        aux =aux.sgte;
      }
      }
      pila = pila.sgte;
    }

};

void insertarOrdenado(Nodo*& lista, int valor)
{
    Nodo* Nuevo = new Nodo;
    Nuevo.datos = valor;
    Nodo aux;

    //insercion ordenada en lista enlazada (ordenamiento menor a mayor)

    if(!lista || lista.datos > valor)/*!lista , verifica que no esta nullen caso de que el valor de la lista 
    sea mayor al que ingresa a la funcion, el valor pasa a estar en el valor del nodo de la lista y el valor 
    de la lista se desplaza a la sig posicion*/
    {  Nuevo.sgte = lista;
       lista = Nuevo;
    } 
 //encontrar posicion adecuada 
    aux = lista; //aux comienza al principio de lista
 while (aux.sgte && aux.sgte.datos < valor) // hay sgte nodo y  no es NULL, con valor menor al ingresado
 {
    nuevo.sgte = aux.sgte;
    aux.sgte = nuevo; //se incierta en pos adecuada dsp del nodo aux
 }//el nuevo nodo quedaria enre aux y aux.sgte

}

/*EJ 2: vector de saldos, que tiene nro de cuentas, cant transacciones y saldo. Lista de transacciones 
(1 nodo 1 transaccion) cada nodo tiene nro de cuenta y monto
actualizar vector con lista. Debe acctualizarse el saldo y la cantidad de transacciones, hay 150 ctas*/

struct Saldos
{
    int nroCuenta;
    int cantT;
    int saldo;
};

struct Transaccion
{
   int NumCuenta;
   int Monto;
   Transaccion* sgte;
};

Saldos saldos[150];

void Acualizar(Saldo saldo[], Transaccion* lista)
{
    Transaccion* aux;
    aux = lista;
    
    while(aux)
    {
        for(int i=0; i<150; i++)
        {
            if(saldo[i].nroCuenta == aux->NumCuenta)
            {
               saldo[i].saldo += aux->Monto;
               saldo[i].cantT ++;
               i=150; //como encuentra la cta correspondiente esto hace que termine el for
            }
        }
        aux = aux->sgte;
    }

}
/*EJ 3: mostrar lo que improme el programa o funcion*/
//A
void proc(int v[], int len) {
    *v = 10; // Esto asigna el valor 10 al primer elemento del array.
}
int main() {
    int *p = NULL;
    int x = 30;
    p = new int[3]; // Reserva memoria para un array de 3 enteros.
    p[1] = x; // Asigna el valor 30 al segundo elemento del array.
    proc(p, 3); // Llama a la función proc, que asigna 10 al primer elemento del array.
    p[2] = *(p + 1) + x; // Asigna a p[2] el valor de p[1] + x, es decir, 30 + 30 = 60.
    for (int i = 0; i < 3; i++) {
        cout << *(p + i) << " " << endl; // Imprime los elementos del array.
    }
    delete[] p; // Libera la memoria asignada.
    return 0;
}
/*Entonces la salida del programa será: 10 30 60*/

//B
int main()
{
    int *p;
    int x=10;
    p =new int [10];//convierte en vector de 10 pos
    p[0]= 20;
    p[1]= 21;
    p[2]= *p;//20
    p[3]= *(p+1);//21
    p[4]=*p+*(p+1);//41
    cout<<*(p+4)<<endl;
    return 0;
}

//muestra por pantalla 41

/*EJ 4 Verdadero - Falso 
Manera correcta de mandar un parametro con referencia en un vector es int*vec[].
Falso. la manera de mandar un parametro por referencia en un vector es int *vec o int vec[];
  1.int *vec: puntero que apunta a la cima del array;
  2.int vec[]:indica tambien la cima del array pero hace mas evidente que es un array 
Apareo solo se usa en archivo. Falso, tambien se usa en otros contextos algoritmicos con la finalidad de
ordenamiento */
