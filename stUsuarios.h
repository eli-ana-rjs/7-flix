#ifndef STUSUARIOS_H_INCLUDED
#define STUSUARIOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include "gotoxy.h"

///-------------------------- Estructura con datos del USUARIO-----------------
typedef struct
{
    int idUsuario;
    char nombre[20];
    char apellido[20];
    char dni[15];
    char nombreUsuario[30];
	char password[8];
	int isAdmin; /// 1: es administrador del sistema || 0: es usuario del sistema
    int baja; /// 1: usuario dado de baja

}stUsuario;

typedef struct
{
    stUsuario dato;
    struct lista2Usuario* ante;
    struct lista2Usuario* ste;

}lista2Usuario;



///--------------------- Funciones para la carga de Datos e Ingreso del USUARIO-------------------
/// --- Formulario que muestra para cargar
void mostrarFormulUsuario();

///Cargar datos Usuario
stUsuario cargarDatosUsuario ();

///---------------------- Muestra 1 usuario--------------------
void mostrarDatos1Usuario(stUsuario aux);

///-----------Muestra datos de login--------
void mostrarDatosIngresoUs (stUsuario aux);

/// Contar registros del archivo
int cantidadRegistrosArchivo(char nombreArchi []);

/// Cargar al archivo un usuario que se registra
void cargarUnUsario2Archivo();

///--------------- Cargar archivo con las estructuras----------------
void cargarMuchosArchivoUsuarios(); /// arreglar, porque no cambia administrador ni id---- Se arregló cuando use la func anterior

/// ----------------------- Mostrar USUARIOS de un archivo --------------------
void mostrarUsuariosArchivo ();

///__________________________________ FUNCIONES PARA LISTAS__________________________________________

///----------- inicializar lista------
lista2Usuario* iniclista2U();

///----------- Crear nodo doble--------
lista2Usuario* crearNodolis2Us (stUsuario dato);

///---------Agregar al principio-----------
lista2Usuario* agregarAlppioL2U (lista2Usuario* listaU, lista2Usuario* nvoUs);

///----- Agregar en orden POR ID-------------------
lista2Usuario* agregarEnOrdenL2UporID (lista2Usuario* listaU, lista2Usuario* nvoUs);

///-----------Cargar LISTA2 con estructuras-----------------
lista2Usuario* cargarListaUsuarios ();

///------------- Mostrar lista Usuarios-------------
void mostrarLista2Us (lista2Usuario* listaU);


///Buscar nodo por ID
lista2Usuario* buscarNodoXid (lista2Usuario* lista, int id); ///Agregsr palabra usuario!! a nombre de la fx

/// ----Mostar nodo buscado------------
void mostarUsBuscadoXid (lista2Usuario* aux);

///----Mostrar lista ordenada por ID-----------
void mostrarListaOrdenaPorId(lista2Usuario* lista);

///------------------ Dar de baja Usuario-------------------
lista2Usuario* bajaXelUsuario (lista2Usuario* lista);  /// Busca por el ID ya cargado???

/// Baja de usuario
lista2Usuario* bajaUsuario(lista2Usuario* lista, int idUsuarioConectado);  ///SIRVE esta????

/// Usuario se da de baja
void usuarioSeDaDeBaja(lista2Usuario* lista, int idUsuarioConectado);

/// Ordenar en una nueva lista por apellido -----

lista2Usuario* ordenarPorApellido(lista2Usuario* lista, lista2Usuario* listaOrdenada);

/// Modificar datos de un usuario---
stUsuario formularioModificarDatos(stUsuario aux);

/// Baja Lógica de Usuario
stUsuario formularioBajaDelServicio(stUsuario aux);

///---Función que cambia la estructura en el archivo con la baja del usuario
void bajaDeUsuarioEnArchivo(int idUsuario);

///---Función que cambia la estructura en el archivo
void modificarDatosEnArchivo(int idUsuario);

///-------------Pasar los datos del archivo a la Lista de USUARIOS----------------------------
lista2Usuario* pasarDeArchivoALista2 (char nombreArchi[], lista2Usuario* lista);

///
lista2Usuario* pasarArchiToListaApellido (char nombreArchi[], lista2Usuario* lista);









#endif // STUSUARIOS_H_INCLUDED
