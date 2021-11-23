#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <wchar.h>
#include <locale.h>
#include "stUsuarios.h"
#include "menuAdministrador.h"
#include "menuUsuario.h"


#define TECLA_ENTER 13
#define TECLA_BACKSPACE 8
#define LONGITUD 30

#define NUMERO_USUARIOS 100

extern stUsuario usuarioConectado;

void inicioSesion();

#endif // LOGIN_H_INCLUDED
