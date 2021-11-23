#ifndef STPELICULA_H_INCLUDED
#define STPELICULA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include "gotoxy.h"
#include "listaDeListas.h"

///----------------------------------- Estructura con la informacion de las PELICULAS -------------------------
typedef struct
{
    int idPelicula;
    char titulo[30];
    char informacion[100];///link que accede a la imagen, resumen, director año, duración,
    char genero[20];
    int baja; /// 0 alta, baja1
} stPelicula;


typedef struct
{
    stPelicula dato;
    struct nodoPelicula* sig;
} nodoPelicula;

typedef struct
{
    stPelicula peliculaFav;
    struct nodoSecPeliFav* sig;
} nodoSecPeliFav; /// lista de peliculas FAVORITAS es secundari

typedef struct
{
    stUsuario dato; /// caja -> a que usuario le quiero agregar una pelicula en su lista de pelisFav
    nodoSecPeliFav* listaFav; ///nodo, lista de peliculas
    struct celdaPrinFav* ante;
    struct celdaPrinFav* sig;
} celdaPrinFav; ///nodoCaja





void mostrarForPelicula ();

stPelicula cargarDatosPelicula ();

void mostrar1Pelicula (stPelicula peli);

///Inicicalizar la lista
nodoPelicula* inicListaPelic();
///Crear un nodo Pelicula
nodoPelicula* crearNodoPeli (stPelicula dato);

///Agregar al Principio de la lista
nodoPelicula* agregarPeliAlPrincipio(nodoPelicula* lista, nodoPelicula* nuevo);

/// Función que busca el último nodo de la lista
nodoPelicula* buscarUltimaPelicula ( nodoPelicula * lista);


/// Buscar una pelicula por nombre
nodoPelicula* buscarPeliPorTitulo (nodoPelicula * lista, char titulo[20]);

/// Agrega pelicula al FINAL
nodoPelicula* agregarAlFinal (nodoPelicula* lista, nodoPelicula* nuevoNodo);

/// Mostrar 1 Nodo
void mostrarNodoPelicula(nodoPelicula* aux);
/// Mostrar una lista de peliculas

void mostrarListaPelicula(nodoPelicula* lista);

/// Borrar Pelicula por TITULO
nodoPelicula* borrarPeliPorTitulo (nodoPelicula* lista, char titulo[20]);

/// Consultar genero a ver

int consultarGeneroPelicula();

///Mostrar peliculas por genero elegido
void mostrarPeliculasPorGenero(char genero[], nodoPelicula* lista);

void muestraGeneroElegido (int genero, nodoPelicula* lista);

///Preguntar que pelicula quiere ver, la busca por nombre y la muestra
nodoPelicula* elegirYmostrarPelicula(nodoPelicula* lista);


/// Agregar Pelicula en orden por TITULO

nodoPelicula* agregarEnOrdenPeli (nodoPelicula * lista, nodoPelicula * nuevoNodo);



/// Pasar de ARCHIVO a una LISTA

nodoPelicula * archivoAListaPeli ( nodoPelicula * lista, char peliArch[]);
/// Existe Pelicula en la lista

nodoPelicula* existePelicula (nodoPelicula* lista, nodoPelicula* buscado);

///----------------------Funciones de pasar ARCHIVOS <--> LISTAS-------------------

/// Cargar al archivo con UN registro de Pelicula
void cargar1PeliToArchivo();

///--------------- Cargar archivo con MUCHAS PELICULAS----------------
void cargarMuchasPeliToArchivo();

/// ----------------------- Mostrar USUARIOS de un archivo --------------------

void mostrarPeliEnArchivo ();

///-------------Pasar los datos del archivo a la Lista de PELICULAS----------------------------
nodoPelicula* pasarDeArchivoAListaPeli (char peliArch[], nodoPelicula* listaPeli);


///--------Pasar LISAT de Pelicula al ARCHIVO--------
void pasarDeListaPeli_Archivo(char peliArch[], nodoPelicula* lista);







///Crear nodo de Lista de listas
celdaPrinFav * crearNodoCeldaFav(stUsuario dato);

///Cargar al principio en Lista de listas
celdaPrinFav* agregarAlPpioCelda(celdaPrinFav* lista,celdaPrinFav* nuevo );

/// Cargar una pelicula favorita de un usuario en especifico
celdaPrinFav* altaPeliculaFav(celdaPrinFav* listaPrinFav, stUsuario usuarioConectado, stPelicula peliAgregada);

///Ver pelicula y agregar  a la lista de peliculas favoritas del usuario
stPelicula verPelicula(nodoPelicula* lista);

/// Mostrar lista de lista
void mostrarListaDePeliculasFavoritas(celdaPrinFav* listaDelista, stUsuario usuarioActual);

/// Pasar lista de peliculas favoritas del usuario a un archivo
void pasarListaPeliFavToArchi( celdaPrinFav* listaDelista,stUsuario usuarioConectado );

/// pasar de archivo  de peliculas fav del usuario a lista de lista
celdaPrinFav* pasarArch2listaCompuesta (stUsuario usuarioConectado, celdaPrinFav* listaCompLista);









#endif // STPELICULA_H_INCLUDED
