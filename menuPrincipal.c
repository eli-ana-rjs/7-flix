#include "menuPrincipal.h"

void menuPpal()
{
    ///por aca iria el recuadro -> ver

    int opcion;
    gotoxy(20,5);
    printf("Menú Principal");

    gotoxy(20,7);
    printf("----------------");

    gotoxy(20,9);
    printf("1. Ingresar al sistema");

    gotoxy(20,11);
    printf("2. Registrarse");

    gotoxy(20,13);
    printf("Ingrese una opción");
    fflush(stdin);
    gotoxy(20,15);
    scanf("%d", &opcion);

    switch(opcion)
    {
    case 1:

        inicioSesion();
        break;

    case 2:


        printf("\n");
        system("cls");
        cargarUnUsario2Archivo();
        inicioSesion();

        break;

    default:

        printf("\nHa ingresado una opción incorrecta\n");
    }

}

