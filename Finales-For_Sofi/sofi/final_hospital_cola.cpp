#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

//lista de 5 nodos donde las prioridades, osea que cada prioriedad es una cola 
struct Paciente
{
    char nombre_paciente[40];
    int prioriedad;
};

struct NodoPaciente{
    Paciente info;
    NodoPaciente* sgte;
};

struct colasPrioriedad
{
    NodoPaciente* frente[5];
    NodoPaciente* fin[5];
};


void crearColaPrioriedad();
void insertarEnPrioriedad();
void elementoMinimo();
void quitarMinimo();
bool colaVacia();
void prioriedadVacia();


int main()
{
    //hago menu 
    switch (rta)
    {
    case 1:
        crearColaPrioriedad();
        break;
    
    case 2:
        void insertarEnPrioriedad();

        break;
    
    case 3:
        elementoMinimo();

        break;
    case 4:
        colaVacia();

        break;
    
    case 5:
        prioriedadVacia();
        break;

    }

};

void crearColaPrioriedad(colasPrioriedad*& colas)
{
    for (int i = 0; i < 5; i++)
    {
        colas->frente[i] = NULL;
        colas->fin[i] = NULL;
    }
    
};

//precondicion: paciente con nro de prioriedad y categoria
//poscondicion: paciente se agrga al final de la cola 
void insertarEnPrioriedad(colasPrioriedad& colas, int prioriedad, char nombre[])
{
    NodoPaciente* nuevoPaciente = new NodoPaciente;
    strcpy(nuevoPaciente->info.nombre_paciente, nombre);
    nuevoPaciente->info.prioriedad = prioriedad;
    nuevoPaciente->sgte = NULL;

    if(colas.frente[prioriedad]== NULL)
    {
        colas.frente[prioriedad] = colas.fin[prioriedad] = nuevoPaciente;
    }else 
    {
        colas.fin[prioriedad]->sgte = nuevoPaciente;
        colas.fin[prioriedad]= nuevoPaciente;
    }

};
void elementoMinimo(colasPrioriedad& frente)
{
    for (int i = 0; i < 5; i++)
    {
        if (frente.frente[i]->info.prioriedad != NULL)
        {
            cout<<"Paciente de mayor prioriedad "<<frente.frente[i]->info;
        }
        cout<<"no hay pacientes en la cola"<<endl;
    }
};
void quitarMinimo(colasPrioriedad& colas){
    for (int i = 0; i < 5; i++)
    {
        if (colas.frente[i] == NULL)
        {
            colas.fin[i] == NULL;
        };

        NodoPaciente* aux = colas.frente[i];

        colas.frente[i] = colas.frente[i]->sgte;

        if (colas.frente[i] == NULL)
        {
            colas.fin[i] == NULL;
        };
        
        delete aux;

    }

};

bool colaVacia(colasPrioriedad* cola, int cola_vacia)
{
    if (cola->frente[cola_vacia] == NULL)
    {
        return true;
    }else return false;
};

void prioriedadVacia(colasPrioriedad* cola)
{
    for (int i = 0; i < 5; i++)
    {
        if(cola->frente[i]!= NULL)
        {
            return false; // alguna cola por lo menos no esta vacia
        };
    };
    return true;
    
};

