

/*Se le pide que haga un sistema donde la fábrica pueda registrar la producción de sillas. Por cada silla se sabe su
código, tipo de madera, fecha de producción, y el código de la línea de producción (De 1 a 10). Por cada línea de
producción sabemos su nombre y su capacidad máxima de producción diaria.
Sabemos que la fábrica puede producir un máximo de 500 sillas, y hay solo 10 líneas de producción.
1. Defini las estructuras necesarias para resolver el problema
2. Insertar líneas de producción: Agregar líneas de producción con su nombre y capacidad máxima de
producción diaria.
3. Insertar sillas: Agregar sillas con su código, tipo de madera, fecha de producción y código de línea de
producción.
4. Mostrar todos las sillas ordenadas por fecha de producción
5. Retornar la línea de producción con mayor capacidad: Identificar la línea de producción con la mayor
capacidad de producción diaria.
6. Retornar la silla más reciente: Identificar la silla producida más recientemente.
7. Retornar el día con más producción: Determinar el día en que se produjo el mayor número de sillas.
8. Retornar la línea de producción con más sillas producidas: Identificar la línea de producción con más sillas
registradas.*/

#include <iostream>

using namespace std;

#define t 10
#define T 500

struct sillas
{
    int codigo, cantP;
    string madera;
    int dia, mes, anio;
    produccion p;

};

struct produccion
{
    string nombre;
    int max;
};

void LineasProduccion (produccion [], int);
void InsertarSillas(sillas []);
void OrdenarSillas(sillas [], int );
void MaxProduccion(produccion [], int);
void DiaMax(sillas [], int );


int main()
{
    sillas s;
    produccion p;
    int tam;

    LineasProduccion (p,t);

    cout<<"Cantidad de tipos de sillas: ";
    cin>>tam;

    InsertarSillas(s,tam);  
    OrdenarSillas(s,tam);

    DiaMax(s,tam);

    return 0;


}

void LineasProduccion (produccion n[], int t)
{
    for(int i=0;i<t;i++)
    {
        cout<<"Nombre de linea de produccion "<<i<<endl;
        cin>>n[i].nombre;

        cout<<"Capacidad maxima de linea de produccion "<<i<<endl;
        cin>>n[i].max;

        if(n[i].max < T)
        {
            cout<<"supera maximo permitido, volver a ingresar valor: ";
            cin>>n[i].max;
        }

    }
    MaxProduccion(n,t);
}

void InsertarSillas(sillas s[], int tam)
{
   

    cout<<"Cantidad de tipos de sillas: ";
    cin>>tam;

    for (int i = 0; i < tam; i++)
    {
        cout<<"ingrese codigo: "<<endl;
        cin>>s[i].codigo;
        cout<<"ingrese tipo de madera: "<<endl;
        cin>>s[i].madera;
        cout<<"fecha de produccion"<<endl;
        cout<<"anio: ";
        cin>>s[i].anio;
        cout<<"mes: ";
        cin>>s[i].mes;
        cout<<"dia: ";
        cin>>s[i].dia;

        cout<<"linea de produccion: "<<endl;
        cin>>s[i].p.nombre;

        s[i].cantP = s[i].p.max;

    }
    
}

//ordeno las sillas de la mas nueva a la mas vieja y las muestro

void OrdenarSillas(sillas s[], int tam)
{
    int aux;
    for (int i=0; i<tam;i++)
    {
        if((s[i].anio < s[i+1].anio || s[i].anio == s[i+1].anio && s[i].mes < s[i+1].mes )|| (s[i].anio == s[i+1].anio && s[i].mes == s[i+1].mes & s[i].dia < s[i+1].dia))
        {
            aux=s[i];
            s[i]=s[i+1];
            s[i+1]=aux;
        }
    }
  for (int i=0; i<tam;i++)
 {
    cout<<"Lista de Sillas"<<endl;

    for(int i=0;i<tam;:i++)
    {
        cout<<"Silla "<<i<<endl;
        cout<<"Codigo: "<<s[i].codigo<<" Madera: "<<s[i].madera<<" Linea de produccion "<<s[i].p<<" Fecha de Produccion: "<<s[i].dia<<"/"<<s[i].mes<<"/"<<s[i].anio<<endl;
    }
 }
 cout<<endl;
 cout<<endl;
 cout<<"silla mas nueva: "<<s[0].codigo;
}

void MaxProduccion(produccion p[], int t)
{
    int max=0;
    string nombre;
    
    for(int i=0;i<t;i++)
    {
        if(p[i].max >= max)
        {
            max=p[i].max;
            nombre=p[i].nombre;
        }
    }

    cout<<"Produccion con maxima capacidad "<<nombre<<" con una capacidad de "<<max;
}

void DiaMax(sillas s[], int tam)
{
    int maxD = 0;
    int acumulo = 0;
    int diaMax = 0; // Variable para almacenar el día con más producción
    int mesMax = 0; // Variable para almacenar el mes con más producción
    int anioMax = 0; // Variable para almacenar el año con más producción

    for (int i = 0; i < tam - 1; i++) {
        if ((s[i].anio == s[i+1].anio) && (s[i].mes == s[i+1].mes) && (s[i].dia == s[i+1].dia)) {
            acumulo += s[i].cantP + s[i+1].cantP;
        } else {
            if (acumulo > maxD) {
                maxD = acumulo;
                diaMax = s[i].dia;
                mesMax = s[i].mes;
                anioMax = s[i].anio;
            }
            acumulo = 0;
        }
    }

    // Verifica si el último conjunto de días tiene la producción máxima
    if (acumulo > maxD) {
        maxD = acumulo;
        diaMax = s[tam-1].dia;
        mesMax = s[tam-1].mes;
        anioMax = s[tam-1].anio;
    }

    cout << "El día con más producción es: " << diaMax << "/" << mesMax << "/" << anioMax << ", con " << maxD << " sillas producidas." << endl;
}