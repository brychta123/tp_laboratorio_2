#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

#include "EMPLEADOS.H"

#define T 1000
#define TSEC 10
int menudeopciones(char []);
int main()

{
   eEmpleado lista[T];
   eSector sectores[TSEC];
   int opcion;

   inicializarEmpleados(lista, T);
   inicializarSectores(sectores, TSEC);


   do{
        system("cls");
        opcion=funcionMenu();
        switch(opcion){
            case 0:
                cargarSectores(sectores, TSEC);
                break;
            case 1:
                altaEmpleado(lista, sectores, T, TSEC);
                break;
            case 2:
                modificarEmpleado(lista, sectores, T, TSEC);
                break;
            case 3:
                bajaEmpleado(lista, sectores, T, TSEC);
                break;
            case 4:
                menuInformes(lista, sectores, T, TSEC);
                break;
            case 5:
                break;
            default:
                system("cls");
        }
   }while(opcion!=5);

    return 0;
}


