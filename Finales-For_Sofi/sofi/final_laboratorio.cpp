#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

/*Declare una función que reciba un archivo y retorne el puntero a una lista ordenada 
de palabras sin repetición de las mismas y con la cantidad de ocurrencias de las mismas en el archivo */

/*Desarrolle la función declarada en el punto anterior teniendo en cuenta que las 
cadenas leídas pueden contener caracteres en mayúscula o minúscula y que en la lista deben estar 
con mayúscula inicial y sin repetirse. Considere que la longitud máxima de cada palabra es de 30 caracteres.*/

//funciones que puedo usar sin desarrollar
bool esMayuscula(char);//retorna si el carcter es mayuscula o no 
bool esMinuscula(char); //retorna si el carcter es minuscula o no
char obtenerMayuscula(char);// devuelve el caracter en mayuscula
char obtenerMinuscula(char);// lo mismo que arriba pero minuscula

//objetivo mostrar el contenido de un archivo  ordenado alfabéticamente, 
//en orden creciente, con las palabras con mayúscula inicial, 
//sin repetición de las mismas así como la frecuencia de aparición de las mismas.

// para el archivo 
struct Archivo
{
    char nombre_droga[30];
};

// para la lista
struct Droga
{
    char nombre[30];
    int repeticiones; // veo ctas veces se repite un programa
};

struct NodoDroga
{
    Droga info;
    
    NodoDroga * sgte;
};


NodoDroga* lista_ordenada (char drogas_de_archivo[]);//devuelve la lista
void ModificarPalabra(char nombreDroga[]);//funcion para que la primera letra sea Mayuscula y el resto minuscula
void insertarOrdenado(NodoDroga* aux, char nombre_droga[]);
int main(){};




NodoDroga* lista_ordenada (char drogas_de_archivo[]){

  FILE* archivo = fopen(drogas_de_archivo, "rb");// no le pongo comillas a drogas_de_archivo, ya que asi me toma lo qu es la cadena de caracteres
  
  Archivo archivoDrogas;

  NodoDroga* lista = NULL; //creamos lsta
  bool encontrado = false;

  fread(&archivoDrogas, sizeof(archivo), 1, archivo);
  
  while (!feof(archivo))
  {
     ModificarPalabra(archivoDrogas.nombre_droga);

     NodoDroga* aux = lista;

     while (aux!=NULL)
     {
        if (strcmp(aux->info.nombre,archivoDrogas.nombre_droga)==0)
        {
            aux->info.repeticiones++;
            encontrado = true;
        }
        aux = aux->sgte;
     }
     if(!encontrado)
        {
            insertarOrdenado(aux, archivoDrogas.nombre_droga);
        }
  }
  return lista;
}

void ModificarPalabra(char nombreDroga[])
{
    int i = 0;
    while (nombreDroga[i]!= '\0')
    {
        if(i == 0)
        {
           if (esMayuscula(nombreDroga[i]) == false)
           {
              nombreDroga[i] = obtenerMayuscula(nombreDroga[i]);
           };
        }else 
        {
            if (esMinuscula(nombreDroga[i]) == false)
            {
                nombreDroga[i]= obtenerMinuscula(nombreDroga[i]);
            }
            
        }
        i++;
    }

};

void insertarOrdenado(NodoDroga*& lista, Droga droga)
{
    NodoDroga* nuevo = new NodoDroga;
    strcpy(nuevo->info.nombre, droga.nombre);
    nuevo->info.repeticiones = droga.repeticiones;
    nuevo->sgte = NULL;
    if (lista == NULL || strcmp(lista->info.nombre, droga.nombre)>1)
    {
        nuevo->sgte = lista;
        lista = nuevo;
        
    }else 
    {
        NodoDroga* aux = lista;
        while (aux!= NULL)
        {
            aux = aux->sgte;
        }
        
        nuevo->sgte = aux->sgte;
        aux->sgte = nuevo;
    }
    
}