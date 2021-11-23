#ifndef MENUADMINISTRADOR_H_INCLUDED
#define MENUADMINISTRADOR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stUsuarios.h"
#include "stPelicula.h"

#define dimension 100

typedef struct
{
    char  titulo[50];
    int id;
    int redireccion;

} itemMenu;

typedef struct
{
    char titulo[50];
    itemMenu opciones[10];
    int cantidadDeOpciones;
} Menu;

void configurarMenuAdministrador (Menu menus[]);
int buscarRedireccionPorId(Menu *menuActual, int id);
void iniciar_programaAdmin();

#endif // MENUADMINISTRADOR_H_INCLUDED
