#include <stdio.h>

#define LIBRE
#define OCUPADO
typedef struct{

 int id;
 char nombre[20];

} eSector;

typedef struct{

 int id;
 char nombre[51];
 char apellido[51];
 float salario;
 int sector;
 int isEmpty;

} eEmpleado;

int funcionMenu ();
int seencuentranEmpleados(eEmpleado lista[], int tam);
int inicializarEmpleados (eEmpleado lista[], int tam);
int altaEmpleado(eEmpleado lista[], eSector sectores[], int tam, int tamSec);
int buscarLibre(eEmpleado lista[], int tam);
void conseguirNombre(eEmpleado lista[], int index, char mensaje[], char mensajeError[]);
void conseguirApellido(eEmpleado lista[], int index, char mensaje[], char mensajeError[]);
int generarId(eEmpleado lista[], int tam);
float conseguirSalario(char mensaje[], char mensajeError[]);
int elegirSector(eSector sectores[], int tamSec);
void mostrarSectores(eSector sectores[], int tamSec);
void inicializarSectores(eSector sectores[], int tamSec);
void hardCodearSectores(eSector sectores[], int tamSec);
void modificarEmpleado(eEmpleado lista[], eSector sectores[], int tam, int tamSec);
int buscarEmpleado(eEmpleado lista[], int tam, int idABuscar);
void mostrarEmpleado(eEmpleado empleado, eSector sectores[], int tamSec);
void mostrarEmpleados(eEmpleado lista[], eSector sectores[], int tam, int tamSec);
int averiguarSector(eEmpleado empleado, eSector sectores[], int tamSec);
void bajaEmpleado(eEmpleado lista[], eSector sectores[], int tam, int tamSec);
void cargarSectores(eSector sectores[], int tamSec);
void totalPromedioSalarios(eEmpleado lista[], int tam);
void menuInformes(eEmpleado lista[], eSector sectores[], int tam, int tamSec);
void hardCodearEmpleados(eEmpleado lista[], int tam);
int conseguirPositivo(char mensaje[], char mensajeError[]);
void ordenarEmpleados(eEmpleado lista[], eSector sectores[], int tam, int tamSec);
