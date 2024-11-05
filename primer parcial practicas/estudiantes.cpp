/*Se le pide que haga un sistema donde la universidad pueda registrar los estudiantes de la facultad. Por cada
estudiante se sabe su nombre, fecha_nacimiento, año ingreso, código de barrio (De 1 a 20). Por cada barrio
sabemos el nombre y su distancia a la facultad y su código.
Sabemos que la facultad acepta máximo 200 estudiantes, y hay solo 20 barrios aceptados.
1. Defini las estructuras necesarias para resolver el problema
2. Insertar barrios: Agregar barrios con su nombre y distancia a la facultad.
3. Insertar estudiantes: Agregar estudiantes con su nombre, fecha de nacimiento, año de ingreso y código de
barrio.
4. Mostrar todos los barrios ordenados por distancia a la facultad
5. Retornar el barrio más lejano a la facultad: Identificar el barrio con la mayor distancia a la facultad.
6. Retornar el estudiante más joven: Identificar al estudiante más joven registrado.
7. Retornar el año de ingreso que más estudiantes tuvo: Determinar el año en que se inscribió el mayor número
de estudiantes.
8. Retornar el barrio con más estudiantes: Identificar el barrio con más estudiantes registrados.
9. Mostrar todos los barrios ordenados por distancia a la facultad y cantidad de estudiantes asignados.*/

#include <iostream>
using namespace std;
#define t 20
#define T 200

struct Estudiante
{
    string nombre;

    int dia;
    int mes;
    int anio;

    int ingreso;
    int barrio;
};

struct Barrio
{
    
    int nro;
    string nombre;
    float distancia;
    int contador = 0;
};

void cargarBarrio(Barrio[], int);
void MostrarBarrio(Barrio [], int);

void MasJoven(Estudiante [],int);
void CargarEstudiante(Estudiante [], int, Barrio[], int);

void MasE(Barrio [], int);//barrio con mayor estudiantes

int main()
{ 
    Estudiante e[T];
    Barrio c[t];

    cargarBarrio(c,t);
    CargarEstudiante(e,T,c,t); //adentro esta la funcion MasJoven y MasE

    MostrarBarrio(c,t);//ordenamiento de mayor a menor distancia 

    


    return 0;
};

//Agregar barrios con su nombre y distancia a la facultad
void cargarBarrio(Barrio p[ ], int t)
{
    

    for(int i=0 ; i<t ; i++)
    {
        cout<<"numero de barrio "<<i+1<<endl;
        p[i].nro = i+1;

        cout<<"Agregar nombre:"<<endl;
        cin>>p[i].nombre;

        cout<<"Agregar distancia";
        cin>>p[i].distancia;
    }

    
}

//Mostrar todos los barrios ordenados por distancia a la facultad(mayor a menor) y devolver el que tenga mayor distancia.
void MostrarBarrio(Barrio p[], int t)
{
    float aux; 

    for(int i=0; i<t; i++)
    {
        for (int j=0;j<t-1; j++)
        {
            if(p[j].distancia<p[i+1].distancia)
            {
                aux=p[j].distancia;
                p[j].distancia=p[i+1].distancia;
                p[i+1].distancia=aux;
            }
        }
    }
    for (int i=0;i<t;i++)
    {
        cout<<"Barrio "<<p[i].nro<<"-"<<p[i].nombre<<" DISTANCIA "<<p[i].distancia<<endl;
    }
    cout<<"El bario a mayor distancia de la facultad es el barrio 1"<<endl;
    cout<<p[0].nro<<"-"<<p[0].nombre<<"-"<<p[0].distancia;
};

//Agregar estudiantes con su nombre, fecha de nacimiento, año de ingreso y código de barrio.
void CargarEstudiante(Estudiante e[], int T, Barrio b[], int t)
{
    int i=0;
    string rta;
    do
    {
        cout<<"Desea cargar estudiante? (S/N)"<<endl;
        cin>>rta;

        i++;
        if (i<T)
        {
            cout<<"Nombre: ";
            cin>>e[i].nombre;
            endl;

            cout<<"Fecha de nacimiento:"<<endl
            cout<<"Dia: ";cin>>e[i].dia;
            endl
            cout<<"Mes: ";cin>>e[i].mes;
            endl
            cout<<"Anio: ";cin>>e[i].anio;
            endl

            cout<<"Anio de ingreso: ";cin>>e[i].ingreso;
            endl

            cout<<"Codigo de barrio (1-20): ";cin>>e[i].barrio;

            for(int j=0;j<t;j++)
            {
                if(e[i].barrio == b[j].nro)
                {
                    b[j].contador++;
                }
            }



        } else cout<<"No hay mas espacio"<<endl;

    }while (rta=="S" || rta=="s");

    cout<<"Desea cargar estudiante? (S/N)"<<endl;
    cin>>rta;

    MasJoven(e,T);
    MasE(b,t);
}

//Identificar al estudiante más joven registrado.
void MasJoven(Estudiante e[], int T)
{
    for(int i=0;i<t;i++)
    {
        if(e[i].anio > e[i+1].anio)
        {
            cout<<"el alumno mas joven es "<<e[i].nombre<<endl;
        } 
        if (e[i].anio < e[i+1].anio)
        {
            cout<<"el alumno mas joven es "<<e[i+1].nombre<<endl;
        }
        if(e[i].anio == e[i+1].anio)
        {
            if (e[i].mes == e[i+1].mes)
            {
                if (e[i].dia == e[i+1].dia)
                {
                    cout<<"los alumnos mas jovenes son "<<e[i].nombre<<" "<<e[i+1].nombre<<" ";
                }
                if (e[i].dia > e[i+1].dia)
                {
                    cout<<"el alumno mas joven es "<<e[i].nombre<<endl;
                }
                if (e[i].dia < e[i+1].dia)
                {
                    cout<<"el alumno mas joven es "<<e[i+1].nombre<<endl;
                }
                
            }
            if (e[i].mes > e[i+1].mes)
            {
                cout<<"el alumno mas joven es "<<e[i].nombre<<endl;
            }
            if (e[i].mes < e[i+1].mes)
            {
                cout<<"el alumno mas joven es "<<e[i+1].nombre<<endl;
            }
        }

    }
};

//Identificar el barrio con más estudiantes registrados.
void MasE(Barrio b[], int t)
{
    int max = 0, nro;
    string nombre;


    for(int i=0;i<t;i++)
    {
        if(b[i].contador >= max)
        {
            max=b[i].contador;
            nro=b[i].nro;
            nombre=b[i].nombre;
        }

    }

    cout<<"El barrio con mas estudiantes es el barrio "<<nro<<"-"<<nombre<<" con "<<max<<" estudiantes"<<endl;

}
