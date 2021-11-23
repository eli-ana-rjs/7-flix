#ifndef MENUUSUARIO_H_INCLUDED
#define MENUUSUARIO_H_INCLUDED


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

#define dimension 100


typedef struct
{
    char  titulo[50];
    int id;
    int redireccion;

} itemMenuUser;

typedef struct
{
    char titulo[50];
    itemMenuUser opciones[10];
    int cantidadDeOpciones;
} MenuUser;

void configurarMenuUsuario (MenuUser menus[]);
int buscarRedireccionPorIdUser(MenuUser *menuActual, int id);
void iniciar_programaUser();

#endif // MENUUSUARIO_H_INCLUDED
