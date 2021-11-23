//const char nombreArchi[] = {"usuarios.dat"};
#define ARCHIUSER "usuarios.dat"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <wchar.h>
#include <locale.h>
#include "stUsuarios.h"
#include "stPelicula.h"
#include "listaDeListas.h"
#include "menuAdministrador.h"
#include "menuUsuario.h"
#include "login.h"
#include "menuPrincipal.h"
#include "gotoxy.h"

stUsuario usuarioConectado;


int main()
{

    setlocale(LC_ALL, "");


    system("COLOR C0"); // ZZ para ver todos los colores, primer color fondo, ssegundo letra


    menuPpal();

//mostrarPeliFavEnArchivo();





    return 0;
}

