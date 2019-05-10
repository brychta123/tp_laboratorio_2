
#include "EMPLEADOS.H"

int funcionMenu(){

    int opcion;

    printf("\n\t----SISTEMA PARA ADMINISTRAR NOMINA DE EMPLEADOS----");
    printf("\n\n\t0- Cargar sectores");
    printf("\n\t1- Dar de Alta un empleado");
    printf("\n\t2- Modificar un empleado");
    printf("\n\t3- Dar de Baja un empleado");
    printf("\n\t4- Informar datos:");
    printf("\n\n\t   1- Listado de empleados ordenados alfabeticamente\n\t   por nombre y sector.");
    printf("\n\t   2- Total y promedio de los salarios,\n\t   y cuantos empleados superan el promedio.");
    printf("\n\n\t5- Salir");
    printf("\n\nOpcion: ");

    scanf("%d", &opcion);

    return opcion;
}

int inicializarEmpleados (eEmpleado lista[], int t){

    int funciona=-1;

    for(int i=0 ; i<t ; i++){
        lista[i].isEmpty=1;
    }

    if(lista[t-1].isEmpty==1){
        funciona=0;
    }

    return funciona;

}

int buscarLibre(eEmpleado lista[], int t){

    int indexLibre=-1;

    for(int i=0 ; i<t ; i++){
        if(lista[i].isEmpty==1){
            indexLibre=i;
            break;
        }
    }

    return indexLibre;

}

int generarId(eEmpleado lista[], int t){

    int indexLibre=buscarLibre(lista, t);
    int idAnterior;
    int id=-1;

    if(indexLibre==0){
        id=1000;
    }else{
        idAnterior=lista[indexLibre-1].id;
        id=idAnterior+1;
    }

    return id;

}

void conseguirNombre(eEmpleado lista[], int index, char mensaje[], char mensajeError[]){

    char aux[50];
    int len;
    int flagOK;

    printf("\n%s", mensaje);
    fflush(stdin);
    gets(aux);

    do{

        len=strlen(aux);
        flagOK=1;
        for(int i=0 ; i<len ; i++){
            if(isalpha(aux[i])==0){
               flagOK=0;
            }
        }

        if(flagOK==0){
            printf("%s", mensajeError);
            fflush(stdin);
            gets(aux);
        }else{
            strcpy(lista[index].nombre, aux);
        }

    }while(flagOK==0);

}

void conseguirApellido(eEmpleado lista[], int index, char mensaje[], char mensajeError[]){

    char aux[50];
    int len;
    int flagOK;

    printf("\n%s", mensaje);
    fflush(stdin);
    gets(aux);

    do{

        len=strlen(aux);
        flagOK=1;
        for(int i=0 ; i<len ; i++){
            if(isalpha(aux[i])==0){
               flagOK=0;
            }
        }

        if(flagOK==0){
            printf("%s", mensajeError);
            fflush(stdin);
            gets(aux);
        }else{
            strcpy(lista[index].apellido, aux);
        }

    }while(flagOK==0);

}

int altaEmpleado(eEmpleado lista[], eSector sectores[], int t, int tamSec){

    int indexLibre=buscarLibre(lista, t);
    int idEmp;

    if(indexLibre==-1){
        printf("No hay lugar en el sistema para otro empleado.");
    }else{

        system("cls");
        printf("---Agregar empleado---\n");
        idEmp=generarId(lista, t);
        lista[indexLibre].id=idEmp;
        printf("\nID: %d\n", idEmp);

        conseguirNombre(lista, indexLibre, "Nombre: ", "Error, ingrese nombre valido: ");
        conseguirApellido(lista, indexLibre, "Apellido: ", "Error, ingrese apellido valido: ");
        lista[indexLibre].salario=conseguirSalario("Salario: $", "Error, ingrese salario valido: $");
        lista[indexLibre].sector=elegirSector(sectores, tamSec);
        lista[indexLibre].isEmpty=0;

        printf("\nCarga de empleado exitosa, presione una tecla para continuar");
        fflush(stdin);
        getch();

    }

    return 1;

}

float conseguirSalario(char mensaje[], char mensajeError[]){

    char aux[50];
    int len;
    int flagOK;
    float salario;

    printf("\n%s", mensaje);
    fflush(stdin);
    gets(aux);

    do{

        flagOK=1;
        len=strlen(aux);

        for(int i=0 ; i<len ; i++){
            if(isdigit(aux[i])!=1 && aux[i]!='.'){
                flagOK=0;
            }
        }

        if(flagOK==0){
            printf("\n%s", mensajeError);
            fflush(stdin);
            gets(aux);
        }else{
            salario=atof(aux);
        }

    }while(flagOK==0);

    return salario;

}

int conseguirPositivo(char mensaje[], char mensajeError[]){

    char aux[50];
    int len;
    int flagOK;
    int positivo;

    printf("\n%s", mensaje);
    fflush(stdin);
    gets(aux);

    do{

        flagOK=1;
        len=strlen(aux);

        for(int i=0 ; i<len ; i++){
            if(isdigit(aux[i])!=1){
                flagOK=0;
            }
        }

        if(flagOK==0){
            printf("\n%s", mensajeError);
            fflush(stdin);
            gets(aux);
        }else{
            positivo=atoi(aux);
        }

    }while(flagOK==0);

    return positivo;

}

int elegirSector(eSector sectores[], int tamSec){

    int idSector;
    int sectoresEnUso=0;

    for(int i=0 ; i<tamSec ; i++){
        if(sectores[i].id!=0){
            sectoresEnUso++;
        }
    }

    printf("\n\t0- No asignar sector\n");
    mostrarSectores(sectores, tamSec);
    idSector=conseguirPositivo("Elija un sector: ", "Sector invalido. Intente de nuevo: ");

    while(idSector<0 || idSector>sectoresEnUso){
       idSector=conseguirPositivo("Sector invalido. Intente de nuevo: ", "Sector invalido. Intente de nuevo: ");
    }

    return idSector;

}

void mostrarSectores(eSector sectores[], int tamSec){

    for(int i=0 ; i<tamSec ; i++){
        if(sectores[i].id!=0){
            printf("\n\t%d- %s", sectores[i].id, sectores[i].nombre);
            printf("\n");
        }
    }

}

void inicializarSectores(eSector sectores[], int tamSec){

    for(int i=0 ; i<tamSec ; i++){
        sectores[i].id=0;
        strcpy(sectores[i].nombre, "Sin sector asignado");
    }

}

void hardCodearSectores(eSector sectores[], int tamSec){

    eSector sectAux[]={{1, "RRHH"},{2, "Ventas"},{3, "Compras"},{4, "Gerencia"},{5, "Calidad"}};

    for(int i=0 ; i<tamSec ; i++){
        sectores[i]=sectAux[i];
    }

}

void modificarEmpleado(eEmpleado lista[], eSector sectores[], int t, int tamSec){

    int idModificar;
    int indexModificar;
    int campoModificar;

    if(seencuentranEmpleados(lista, t)){
        printf("\nAun no se han ingresado empleados\n\n");
        system("pause");
    }else{

        mostrarEmpleados(lista, sectores, t, tamSec);
        idModificar=conseguirPositivo("\nIngrese el ID del empleado a modificar: ", "ID invalido. Intente nuevamente: ");
        indexModificar=buscarEmpleado(lista, t, idModificar);

        while(indexModificar==-1){
            idModificar=conseguirPositivo("ID invalido. Intente nuevamente: ", "ID invalido. Intente nuevamente: ");
            indexModificar=buscarEmpleado(lista, t, idModificar);
        }

        do{
            system("cls");
            printf("\nEmpleado seleccionado legajo %d", idModificar);
            printf("\n\n%4s %12s %12s %10s %9s", "ID", "Nombre", "Apellido", "Salario","Sector");
            mostrarEmpleado(lista[indexModificar], sectores, tamSec);
            printf("\n\nCampos: ");
            printf("\n\n\t1-Nombre\n\t2-Apellido\n\t3-Salario\n\t4-Sector\n\t5- Terminar modificacion");
            campoModificar=conseguirPositivo("\nIngrese campo a modificar: ","Error. Ingrese campo valido: ");

                switch(campoModificar){
                    case 1:
                        conseguirNombre(lista, indexModificar, "Ingrese nuevo nombre: ", "Ingrese nombre valido: ");
                        break;
                    case 2:
                        conseguirApellido(lista, indexModificar, "Ingrese nuevo apellido: ", "Ingrese apellido valido: ");
                        break;
                    case 3:
                        lista[indexModificar].salario=conseguirSalario("Ingrese nuevo salario: $", "Ingrese salario valido: $");
                        break;
                    case 4:
                         lista[indexModificar].sector=elegirSector(sectores, tamSec);
                        break;
                    case 5:
                        printf("\n\tModificacion terminada\n\n");
                        system("pause");
                        break;
                    default:
                        system("cls");
                        break;
                }

            }while(campoModificar!=5);

        }
}

int buscarEmpleado(eEmpleado lista[], int t, int idABuscar){

    int indexEmpleado=-1;

    for(int i=0; i<t ; i++){
        if(lista[i].id==idABuscar && lista[i].isEmpty!=1){
            indexEmpleado=i;
            break;
        }
    }

    return indexEmpleado;
}

void mostrarEmpleado(eEmpleado empleado, eSector sectores[], int tamSec){

    int indexSector=averiguarSector(empleado, sectores, tamSec);

    printf("\n%d %12s %12s %10.2f %9s", empleado.id, empleado.nombre, empleado.apellido, empleado.salario, sectores[indexSector].nombre);


}

int averiguarSector(eEmpleado empleado, eSector sectores[], int tamSec){

    int indexSector;

    for(int i=0 ; i<tamSec ; i++){
        if(empleado.sector==sectores[i].id){
            indexSector=i;
            break;
        }
    }

    return indexSector;

}

void mostrarEmpleados(eEmpleado lista[], eSector sectores[], int t, int tamSec){


    if(seencuentranEmpleados(lista, t)){
        printf("Aun no se han ingresado empleados");
    }else{
         printf("\n%4s %12s %12s %10s %9s \n", "ID", "Nombre", "Apellido", "Salario","Sector");
        for(int i=0 ; i<t ; i++){
            if(lista[i].isEmpty!=1){
                mostrarEmpleado(lista[i], sectores, tamSec);
            }
        }
    }
}

int seencuentranEmpleados(eEmpleado lista[], int t){

    int empEmpty=1;

    for(int i=0 ; i<t ; i++){
        if(lista[i].isEmpty!=1){
            empEmpty=0;
            break;
        }
    }

    return empEmpty;
}

void bajaEmpleado(eEmpleado lista[], eSector sectores[], int t, int tamSec){

    int idBaja;
    int indexBuscar;
    char confirmoBaja;

    if(seencuentranEmpleados(lista, t)){
        printf("\nAun no se han ingresado empleados\n\n");
        system("pause");
    }else{

        mostrarEmpleados(lista, sectores, t, tamSec);
        idBaja=conseguirPositivo("\nIngrese el ID a dar de baja: ", "Error. Ingrese nuevamente: ");

        indexBuscar=buscarEmpleado(lista, t, idBaja);

        if(indexBuscar==-1){
                printf("\nNo existe ningun empleado con ese ID\n");
                system("pause");
        }else{
            printf("\nEmpleado con ID %d: ", idBaja);
            printf("\n%4s %12s %12s %10s %9s \n", "ID", "Nombre", "Apellido", "Salario","Sector");
            mostrarEmpleado(lista[indexBuscar], sectores, averiguarSector(lista[indexBuscar], sectores, tamSec));

            printf("\n\nConfirmar la baja de este empleado? S/N: ");
            fflush(stdin);
            confirmoBaja=tolower(getchar());

            if(confirmoBaja=='n'){
                printf("\nBaja de empleado cancelada\n");
                system("pause");
            }else{
                printf("\nBaja de empleado confirmada\n");
                system("pause");
                lista[indexBuscar].isEmpty=1;
            }
        }
    }


}

void cargarSectores(eSector sectores[], int tamSec){

    char opcion;
    int j;

    do{
        for(j=0 ; j<tamSec ; j++){
            if(sectores[j].id==0){
                sectores[j].id=j+1;
                break;
            }
        }

        printf("\nSector %d, ingrese descripcion: ", j+1);
        fflush(stdin);
        gets(sectores[j].nombre);
        printf("\nIngresar otro sector? S/N: ");
        fflush(stdin);
        opcion=getchar();
        opcion=tolower(opcion);

    }while(opcion=='s');

}

void totalPromedioSalarios(eEmpleado lista[], int t){

    float salariosTotal=0;
    int cantidadSalarios=0;
    float promedioSalarios;
    int contadorSuperan=0;

    if(seencuentranEmpleados(lista, t)){
        printf("\nAun no se han ingresado empleados");
    }else{

        for(int i=0 ; i<t ; i++){
            if(lista[i].isEmpty!=1){
                salariosTotal+=lista[i].salario;
                cantidadSalarios++;
            }
        }

        promedioSalarios=(float)salariosTotal/cantidadSalarios;

        printf("\nTotal de salarios: $%.1f", salariosTotal);
        printf("\nPromedio de salarios: $%.1f", promedioSalarios);

        for(int i=0 ; i<t ; i++){
            if(lista[i].isEmpty!=1 && lista[i].salario>promedioSalarios)
                contadorSuperan++;
        }

        printf("\nEmpleados que superan el promedio: %d\n", contadorSuperan);
        system("pause");
    }
}

void menuInformes(eEmpleado lista[], eSector sectores[], int t, int tamSec){

    int opcion;

    do{
        system("cls");
        printf("Informes: ");
        printf("\n\n\t1- Listado de empleados ordenados alfabeticamente\n\t   por nombre y sector");
        printf("\n\n\t2- Total y promedio de los salarios,\n\t   y cuantos empleados superan el promedio.");
        printf("\n\n\t3-Volver al menu principal");
        printf("\n\nOpcion: ");
        scanf("%d", &opcion);

        switch(opcion){
            case 1:
                ordenarEmpleados(lista, sectores, t, tamSec);
                mostrarEmpleados(lista, sectores, t, tamSec);
                system("pause");
                break;
            case 2:
                totalPromedioSalarios(lista, t);
                system("pause");
                break;
            case 3:
                break;
            default:
                system("cls");
        }

    }while(opcion!=3);

}


void ordenarEmpleados(eEmpleado lista[], eSector sectores[], int t, int tamSec){

    eEmpleado auxEmp;

    for(int i=0 ; i<t-1 ; i++){
        for(int j=i+1 ; j<t ; j++){
            if(lista[i].sector>lista[j].sector){
                auxEmp=lista[i];
                lista[i]=lista[j];
                lista[j]=auxEmp;
            }
        }
    }

    for(int i=0 ; i<t-1 ; i++){
        for(int j=i+1 ; j<t ; j++){
            if(lista[i].sector==lista[j].sector && stricmp(lista[i].nombre, lista[j].nombre)==1){
                auxEmp=lista[i];
                lista[i]=lista[j];
                lista[j]=auxEmp;
            }else{
                if(lista[i].sector==lista[j].sector && stricmp(lista[i].nombre, lista[j].nombre)==0){
                    if(stricmp(lista[i].apellido, lista[j].apellido)==1){
                        auxEmp=lista[i];
                        lista[i]=lista[j];
                        lista[j]=auxEmp;
                    }
                }
            }
        }
    }

}



