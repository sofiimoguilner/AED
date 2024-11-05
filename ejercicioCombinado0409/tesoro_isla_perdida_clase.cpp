#include <iostream>

using namespace std;

struct Pista {
    int codigo;
    int dificultad;
    char desc[256];
    int resultadoEsperado;
};

// Función para crear archivos binarios con datos "dummy"
void crearArchivosDummy() {
    FILE *file1 = fopen("archivo1.dat", "wb");
    FILE *file2 = fopen("archivo2.dat", "wb");


    // Pistas para archivo1.dat
    Pista pistas1[] = {
        {1, 5, "Pista A1", 10},
        {3, 2, "Pista A2", 20},
        {3, 8, "Pista A3", 1},
        {5, 7, "Pista A4", 30}
    };

    // Pistas para archivo2.dat
    Pista pistas2[] = {
        {1, 6, "Pista B5", 10},
        {2, 4, "Pista B10", 15},
        {3, 6, "Pista B20", 25},
        {6, 9, "Pista B30", 35}
    };

    // Escribir las pistas en archivo1.dat
    for (int i = 0; i < 4; i++) {
        fwrite(&pistas1[i], sizeof(Pista), 1, file1);
    }

    // Escribir las pistas en archivo2.dat
    for (int i = 0; i < 4; i++) {
        fwrite(&pistas2[i], sizeof(Pista), 1, file2);
    }

    fclose(file1);
    fclose(file2);

    cout << "Archivos dummy creados con éxito." << endl;
}

// Función para mostrar todos los elementos de un archivo binario
void mostrarArchivo() {
    FILE *file = fopen("pistas_combinadas.dat", "rb");

    if (!file) {
        cout << "Error al abrir el archivo " << "pistas_combinadas.dat" << endl;
        return;
    }

    Pista pista;
    while (fread(&pista, sizeof(Pista), 1, file)) {
        cout << "Código: " << pista.codigo << ", Dificultad: " << pista.dificultad
             << ", Descripción: " << pista.desc << ", Resultado esperado: " << pista.resultadoEsperado << endl;
    }

    fclose(file);
}



int main() {
    // Crear archivos dummy antes de combinar
    crearArchivosDummy();

    // Combinar los archivos creados
    // combinarPistas();

    // Mostrar el contenido del archivo combinado
    mostrarArchivo();

    int continuar = true;
    while (continuar) {
        int accion;
        cout << "Ingrese la acción deseada: " << endl;
        cout << "1 - Conteo de pistas por código "<< endl;
        cout << "2 - Resolver pista "<< endl;
        cout << "Cualquier otro valor - Salir "<< endl;
        cin >> accion;
        switch (accion)
        {
        case 1:
            // conteoPorCodigo();
            break;
        case 2:
            // resolverPista();
            break;
        default:
            continuar = false;
            break;
        }
    }

    return 0;
}

/*Los exploradores han encontrado dos listas de pistas provenientes de diferentes archivos, 
pero para seguir adelante necesitan 
combinar ambos archivos en uno solo que mantenga el orden por código. 
Cada archivo está ordenado por código 
y el resultado será una única lista ordenada de pistas que utilizarán como guía.*/

void aparearArchivos_para_Combinacion() {
 FILE *archivo1 = fopen("archivo1.dat", "rb");
 FILE *archivo2 = fopen("archivo2.dat", "rb");
 FILE *archivoSalida = fopen("pistas_pistascombinadas.dat", "wb");

 Pista pista1, pista2;

 bool hayPista1 = fread(&pista1, sizeof(Pista), 1, archivo1);
 bool hayPista2 = fread(&reg2, sizeof(Pista), 1, archivo2);

 while (hayPista1 && hayPista2) 
 {
    if (pista1.codigo< pista2.codigo) {
 fwrite(&pista1, sizeof(Pista), 1, archivoSalida);
 hayPista1 = fread(&pista1, sizeof(Pista), 1, archivo1);
 } else {
 fwrite(&pista2, sizeof(Pista), 1, archivoSalida);
 hayPista2 = fread(&pista2, sizeof(Pista), 1, archivo2);
 }
 }

 while (hayPista1) 
 {
 fwrite(&pista1, sizeof(Pista), 1, archivoSalida);
 hayReg1 = fread(&pista1, sizeof(Pista), 1, archivo1);
 }

 while (hayPista2) {
 fwrite(&pista2, sizeof(Pista), 1, archivoSalida);
 hayReg2 = fread(&pista2, sizeof(Pista), 1, archivo2);
 }

 fclose(archivo1);
 fclose(archivo2);
 fclose(archivoSalida);
}

/*Mostrá por pantalla cuantas pistas hay de cada código y 
cual es el promedio de nivel de dificulta de cada código. 
Al finalizar debe mostrar ademas cual es el código con promedio 
de dificultad de pistas más bajo. */

void conteo_corteDeControl()
 {
 FILE *archivo = fopen("pistas_pistascombinadas.dat", "rb");

 Pista p;

 int codigoActual;
 int contador = 0;

 while (fread(&p, sizeof(Pista), 1, archivo)) 
 {
   if (codigoActual != p.codigo) 
   {
    if (contador > 0) 
      {
           cout<< "Codigo:"<<codigoActual
           <<",Cantidad:"<<contador<< endl;
     }   (categoriaActual, registro.categoria);
         contador = 1;
      } else {
          contador++;
      }
      }
      
if (contador > 0) {

 fread(&p, sizeof(Pista), 1, archivo)
 cout << "Categoría: " << codigoActual 
  << ", Cantidad: " << contador << endl;
  }
 

 fclose(archivo);
}