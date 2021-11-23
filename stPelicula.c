#include "stPelicula.h"

///-------------------- Funciones de carga de PELICULA-------------------------------

void mostrarForPelicula ()
{
    gotoxy(10,3);
    printf("Id de película:...........:");

    gotoxy(10,4);
    printf("Título:...................:");

    gotoxy(10,5);
    printf("Información...............:");

    gotoxy(10,6);
    printf("Género:...................:");

}

stPelicula cargarDatosPelicula ()
{
    stPelicula aux;
    hidecursor(1);
    mostrarForPelicula();

    ///Id de película
    gotoxy(37,3);
    scanf("%d",&aux.idPelicula );

    ///Título
    gotoxy(37,4);
    fflush(stdin);
    gets(aux.titulo);

    ///Información
    gotoxy(37,5);
    fflush(stdin);
    gets(aux.informacion);

    ///Genero
    gotoxy(37,6);
    gets(aux.genero);

    aux.baja=0;

    hidecursor(0);

    return aux;

}

void mostrar1Pelicula (stPelicula peli)
{
    printf("\n\t Id de película:%d",peli.idPelicula);
    printf("\n\t Título:%s", peli.titulo);
    printf("\n\t Género:%s",peli.genero);
    printf("\n\n\t-------------------------------\n\n");
}

///----Agrega la imagen al archivo-------
void mostrarImgPeli(stPelicula peli)
{
    printf("\n\t Información: %s",peli.informacion);
}


///Inicicalizar la lista
nodoPelicula* inicListaPelic()
{
    return NULL;
}

///Crear un nodo Pelicula
nodoPelicula* crearNodoPeli (stPelicula dato)
{

    nodoPelicula* nuevaPeli= (nodoPelicula*) malloc(sizeof(nodoPelicula));
    nuevaPeli->dato=dato;
    nuevaPeli->sig=NULL;

    return nuevaPeli;
}

///Agregar al Principio de la lista
nodoPelicula* agregarPeliAlPrincipio(nodoPelicula* lista, nodoPelicula* nuevo)
{


    if(lista!=NULL)
    {
        nuevo->sig=lista;
    }
    lista=nuevo;

    return lista;
}


/// Función que busca el último nodo de la lista
nodoPelicula* buscarUltimaPelicula ( nodoPelicula * lista)
{
    nodoPelicula * seguidora = lista;
    if ( seguidora != NULL )
    {
        while ( seguidora->sig != NULL )
        {
            seguidora = seguidora->sig;
        }
    }
    return seguidora;
}


/// Buscar una pelicula por nombre
nodoPelicula* buscarPeliPorTitulo (nodoPelicula * lista, char titulo[20])
{
    nodoPelicula * seguidora = lista;

    while ( seguidora != NULL && strcmpi(seguidora->dato.titulo,titulo)!=0)
    {
        seguidora = seguidora->sig;
    }

    return seguidora;
}

/// Agrega pelicula al FINAL
nodoPelicula* agregarAlFinal (nodoPelicula* lista, nodoPelicula* nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nodoPelicula* ultimo = buscarUltimaPelicula(lista);
        ultimo->sig= nuevoNodo;
    }
    return lista;
}

/// Mostrar 1 Nodo
void mostrarNodoPelicula(nodoPelicula* aux)
{
    mostrar1Pelicula(aux->dato);
}

/// Mostrar una lista de peliculas

void mostrarListaPelicula(nodoPelicula* lista)
{
    nodoPelicula* seg = lista;

    while (seg!= NULL)
    {
        mostrarNodoPelicula(seg);
        seg = seg->sig;
    }

}

/// Borrar Pelicula por TITULO
nodoPelicula* borrarPeliPorTitulo (nodoPelicula* lista, char titulo[20])
{
    nodoPelicula* seguidora;
    nodoPelicula* anterior;

    if ((lista != NULL) && (strcmpi(seguidora->dato.titulo,titulo)== 0))
    {
        nodoPelicula* aux = lista;
        lista = lista->sig;
        free(aux);
    }
    else
    {
        seguidora = lista;
        while (seguidora != NULL && strcmp(seguidora->dato.titulo,titulo)!= 0 )
        {
            anterior = seguidora;
            seguidora = seguidora->sig;
        }
        if( seguidora !=NULL)
        {
            anterior->sig = seguidora->sig;
            free(seguidora);
        }
    }
    return lista;
}



///Preguntar que pelicula quiere ver, la busca por nombre y la muestra
nodoPelicula* elegirYmostrarPelicula(nodoPelicula* lista)
{

    system("cls");

    char titulo[30];

    gotoxy(10,3);
    printf("Ingrese el título de la película que desea ver");
    gotoxy(10,4);
    printf("Titulo:");
    gotoxy(17,4);
    gets(titulo);

    nodoPelicula* buscado = buscarPeliPorTitulo(lista,titulo);

    mostrar1Pelicula(buscado->dato);

    return buscado;

}




/// Agregar Pelicula en orden por TITULO

nodoPelicula* agregarEnOrdenPeli (nodoPelicula * lista, nodoPelicula * nuevoNodo)
{
    if ( lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        if ( strcmp(nuevoNodo->dato.titulo,lista->dato.titulo)<0)
        {
            lista = agregarPeliAlPrincipio(lista, nuevoNodo);
        }
        else
        {
            nodoPelicula * ante = lista;
            nodoPelicula * seg = lista->sig;

            while( (seg != NULL) && (strcmp(nuevoNodo->dato.titulo,seg->dato.titulo)>0))
            {
                ante = seg;
                seg = seg->sig;
            }
            ante->sig = nuevoNodo;
            nuevoNodo->sig = seg;
        }

    }
    return lista;
}



/// Consultar genero a ver

int consultarGeneroPelicula()
{
    int genero;

    system("cls");
    gotoxy(10,3);
    printf("Seleccione género de películas: ");

    gotoxy(10,4);
    printf("[1] Comedia ");

    gotoxy(10,5);
    printf("[2] Drama ");

    gotoxy(10,6);
    printf("[3] Acción ");

    gotoxy(10,7);
    printf("[4] Suspenso");

    gotoxy(10,8);
    printf("[5] Ciencia ficción");

    gotoxy(10,9);
    printf("Opción:");
    gotoxy(18,9);
    scanf("%d", &genero);

    return genero;
}


void muestraGeneroElegido (int genero, nodoPelicula* lista)
{

    switch(genero)
    {
    case 1:
        mostrarPeliculasPorGenero("comedia",lista);
        break;

    case 2:
        mostrarPeliculasPorGenero("drama",lista);
        break;

    case 3:
        mostrarPeliculasPorGenero("accion",lista);
        break;

    case 4:
        mostrarPeliculasPorGenero("suspenso",lista);
        break;

    case 5:
        mostrarPeliculasPorGenero("ciencia ficcion",lista);
        break;

    default:
        printf("\nEl valor ingresado no se encuentra disponible");
    }
}

///Mostrar peliculas por genero elegido
void mostrarPeliculasPorGenero(char genero[30], nodoPelicula* lista)
{
    nodoPelicula* seg = lista;

    while (seg != NULL)
    {
        if(strcmpi(seg->dato.genero,genero) == 0 )
        {
            mostrarNodoPelicula(seg);
        }
        seg = seg->sig;
    }

}


/// Pasar de ARCHIVO a una LISTA

nodoPelicula * archivoAListaPeli ( nodoPelicula * lista, char peliArch[])
{
    FILE * archivoPeli = fopen(peliArch, "rb");
    stPelicula aux;
    while(fread(&aux, sizeof(aux),1,archivoPeli)>0)
    {
        lista = agregarPeliAlPrincipio(lista,crearNodoPeli(aux));
    }
    fclose(archivoPeli);
    return lista;
}

/// Existe Pelicula en la lista

nodoPelicula* existePelicula (nodoPelicula* lista, nodoPelicula* buscado)
{

    nodoPelicula* rta = 0;
    nodoPelicula* seg = lista;

    while( seg != NULL)
    {
        if ( (strcmp(seg->dato.titulo,buscado->dato.titulo)==0) && (seg->dato.idPelicula == buscado->dato.idPelicula))
        {
            rta = 1;
        }
        seg = seg->sig;
    }

    return rta;
}


///----------------------Funciones de pasar ARCHIVOS <--> LISTAS-------------------

/// Cargar al archivo con UN registro de Pelicula
void cargar1PeliToArchivo()
{
    FILE* pelicula = fopen("pelicula.dat","ab");

    if(pelicula !=NULL)
    {
        stPelicula peli;
        peli= cargarDatosPelicula();
        fwrite(&peli,sizeof(peli),1,pelicula);

        system("pause");
        system("cls");

        fclose(pelicula);
    }
}

///--------------- Cargar archivo con MUCHAS PELICULAS----------------
void cargarMuchasPeliToArchivo()
{
    int opcion=0;

    while (opcion!=27)
    {
        cargar1PeliToArchivo();
        gotoxy(12,20);
        printf("Si desea salir presione ESC");
        opcion=getch();
        system("cls");
    }
}


/// Modificar datos de una PELICULA ---
stPelicula formularioModificarDatosPelicula(stPelicula aux)
{
    int opcion=0;
    char titulo[20];
    char genero[20];

    gotoxy(15,11);
    printf("Seleccione la opción a modificar");
    gotoxy(15,13);
    printf("1. Título      2. Género \n");
    gotoxy(15,15);
    printf("Opción:");
    fflush(stdin);
    scanf("%d", &opcion);

    if( opcion == 1)
    {
        gotoxy(15,18);
        printf("Ingrese título: ");
        fflush(stdin);
        gets(titulo);
        strcpy(aux.titulo,titulo);

    }
    else if(opcion == 2)
    {
        gotoxy(15,20);
        printf("Ingrese género: ");
        fflush(stdin);
        gets(genero);
        strcpy(aux.genero,genero);

    }
    else
    {
        printf("Opción incorrecta. Vuelva a intentar");
    }


    return aux;
}

///---Función que cambia la estructura en el archivo con la información modificada de la PELICULA
void modificarDatosEnArchivoPelicula(int idPelicula)
{
    stPelicula aux;
    int flag=0;

    FILE* pelicula = fopen("pelicula.dat","r+b");

    if(pelicula)
    {
        while((fread(&aux,sizeof(aux),1,pelicula)>0)&& (!flag))
        {
            if(aux.idPelicula == idPelicula)
            {
                aux=formularioModificarDatosPelicula(aux);

                fseek(pelicula,sizeof(aux)*(-1),SEEK_CUR);
                fwrite(&aux,sizeof(aux),1,pelicula);
                flag=1;
                fclose(pelicula);
            }
        }
    }
    fclose(pelicula);
}


/// Baja Lógica de Pelicula
stPelicula formularioBajaDePelicula(stPelicula aux)
{
    char eleccion;

    gotoxy(15,11);
    printf("Desea dar de baja la película? S/N");
    gotoxy(50,11);
    fflush(stdin);
    scanf("%c", &eleccion);

    if( eleccion == 's' )
    {
        aux.baja = 1;
    }

    return aux;
}

///---Función que cambia la estructura en el archivo con la baja del usuario
void bajaDePeliculaEnArchivo(int idPelicula)
{
    stPelicula aux;
    int flag=0;

    FILE* pelicula=fopen("pelicula.dat","r+b");

    if(pelicula)
    {
        while((fread(&aux,sizeof(aux),1,pelicula)>0)&& (!flag))
        {
            if(aux.idPelicula == idPelicula)
            {
                aux=formularioBajaDePelicula(aux);

                fseek(pelicula,sizeof(aux)*(-1),SEEK_CUR);
                fwrite(&aux,sizeof(aux),1,pelicula);
                flag=1;
                fclose(pelicula);
            }
        }
    }

    fclose(pelicula);
}



/// ----------------------- Mostrar PELICULAS de un archivo --------------------

void mostrarPeliEnArchivo ()
{
    FILE* pelicula = fopen("pelicula.dat","rb");
    stPelicula peli;

    if(pelicula!=NULL)
    {
        while(fread(&peli,sizeof(peli),1,pelicula)>0)
        {

            printf("\n\tINFORMACIÓN:\n");
            mostrar1Pelicula(peli);
        }
    }
    fclose(pelicula);
}

///-------------Pasar los datos del archivo a la Lista de PELICULAS----------------------------
nodoPelicula* pasarDeArchivoAListaPeli (char peliArch[], nodoPelicula* listaPeli)
{
    FILE* pelicula= fopen("pelicula.dat", "rb");

    if (pelicula != NULL)
    {

        stPelicula aux;
        nodoPelicula* nuevo;
        while (fread(&aux,sizeof(stPelicula),1,pelicula) > 0)
        {

            nuevo= crearNodoPeli(aux);

            listaPeli= agregarPeliAlPrincipio(listaPeli,nuevo);
        }

        fclose(pelicula);
    }
    return listaPeli;
}




///--------Pasar LISAT de Pelicula al ARCHIVO--------
void pasarDeListaPeliArchivo(char peliArch[], nodoPelicula* lista)
{
    stPelicula pelicula;
    FILE* peli = fopen("pelicula.dat","ab");


    if (peli!=NULL && lista!=NULL)
    {
        while (lista!=NULL)
        {
            pelicula= lista->dato;
            fwrite(&pelicula,sizeof(pelicula),1,peli);
            lista= lista->sig;
        }
    }
    fclose(peli);
}

/// Crear nodo secundario lista de peliculas favoritas
nodoSecPeliFav* crearNodoSec(stPelicula dato)
{

   nodoSecPeliFav* nuevaPeli= (nodoSecPeliFav*) malloc(sizeof(nodoSecPeliFav));
    nuevaPeli->peliculaFav=dato;
    nuevaPeli->sig=NULL;

    return nuevaPeli;
}

///Crear nodo de Lista de listas
celdaPrinFav * crearNodoCeldaFav(stUsuario dato)
{
    celdaPrinFav* aux= (celdaPrinFav*) malloc (sizeof(celdaPrinFav));
    aux->dato= dato;
    aux->listaFav = inicListaPelic();
    aux->ante= NULL;
    aux->sig=NULL;

    return aux;
}


///Cargar al principio en Lista de listas
celdaPrinFav* agregarAlPpioCelda(celdaPrinFav* lista,celdaPrinFav* nuevo )
{
    nuevo->sig=lista;
    if(lista != NULL)
    {
        lista->ante = nuevo;
    }

    return nuevo;
}

/// Busca un nodo en la Lista de Listas
/// busca si el usuario con ese id esta en la lista grande
celdaPrinFav* buscarListaDeLista (celdaPrinFav* listaCompLista, int idUsuarioConectado)
{
    celdaPrinFav* seg= listaCompLista;
    celdaPrinFav* buscado=NULL;
    int flag=0;

    while(seg!=NULL && flag==0)
    {
        if(seg->dato.idUsuario == idUsuarioConectado)
        {
            buscado=seg;
            flag = -1;
        }

        seg = seg -> sig;
    }

    return buscado; /// me retorna el nodo en el que encontro al usuario o null si no lo encontro
}

/// Cargar una pelicula favorita de un usuario en especifico

celdaPrinFav* altaPeliculaFav(celdaPrinFav* listaPrinFav, stUsuario usuarioConectado, stPelicula peliAgregada)
{

    nodoSecPeliFav* nuevaPeli = crearNodoSec(peliAgregada);

    celdaPrinFav* usuarioActual= buscarListaDeLista(listaPrinFav, usuarioConectado.idUsuario);

    if( usuarioActual == NULL)
    {

        celdaPrinFav* nuevaCelda = crearNodoCeldaFav(usuarioConectado);

        listaPrinFav = agregarAlPpioCelda(listaPrinFav, nuevaCelda);
        usuarioActual= listaPrinFav;
    }

    usuarioActual -> listaFav = agregarPeliAlPrincipio(usuarioActual->listaFav,nuevaPeli); // lista Fav es la lista del usuario

    return listaPrinFav;
}

///Ver pelicula y agregar  a la lista de peliculas favoritas del usuario
stPelicula verPelicula(nodoPelicula* lista)
{
    char opcion = 's' ;
    char peliEncontrada[30];
    nodoPelicula* buscado =  NULL;

    printf("Ingrese el tiulo de la película: ");
    fflush(stdin);
    gets(peliEncontrada);
    buscado = buscarPeliPorTitulo(lista,peliEncontrada);

    if(buscado==NULL)
    {
        printf("La pelicula que deseas ver pronto llegará.....");

    }
    else
    {
        mostrarNodoPelicula(buscado);
        mostrarImgPeli( buscado->dato);
    }

    return buscado->dato;
}

/// Mostrar lista peliculas favoritas
void mostrarListaPeliculaFav(nodoSecPeliFav* listaFav)
{
    nodoSecPeliFav* seg = listaFav;
    while( seg != NULL)
    {
        mostrar1Pelicula( seg -> peliculaFav);
        seg = seg -> sig;
    }
}


/// Mostrar lista de lista del usuario conectado
void mostrarListaDePeliculasFavoritas(celdaPrinFav* listaDelista, stUsuario usuarioActual)
{
    if( listaDelista != NULL)
    {
        celdaPrinFav* buscado = buscarNodoXid(listaDelista, usuarioActual.idUsuario);

        mostrarListaPeliculaFav(buscado->listaFav);

    }
    else
    {
        gotoxy(10,10);
        printf("No tiene películas favoritas");
    }
}



/// Pasar lista de peliculas favoritas del usuario a un archivo
void pasarListaPeliFavToArchi( celdaPrinFav* listaDelista,stUsuario usuarioConectado)
{
    char nombreArchi[20];
    stPelicula peliNueva;

    nombreArchi[0] = '\0';
    strcat(nombreArchi, usuarioConectado.nombreUsuario);
    strcat(nombreArchi, ".dat");

    celdaPrinFav* buscado = buscarNodoXid(listaDelista, usuarioConectado.idUsuario);


    FILE *archi = fopen(nombreArchi, "wb");

    if( nombreArchi != NULL )
    {
        while( buscado->listaFav != NULL )
        {
            peliNueva =buscado->listaFav->peliculaFav;
            fwrite(&peliNueva, sizeof(stPelicula), 1, archi);
            buscado->listaFav = buscado->listaFav->sig;

        }

    }
    fclose(archi);
}



/// pasar de archivo  de peliculas fav del usuario a lista de lista
celdaPrinFav* pasarArch2listaCompuesta (stUsuario usuarioConectado, celdaPrinFav* listaCompLista)
{
    char nombreArchi[20];

    nombreArchi[0] = '\0';
   strcat(nombreArchi, usuarioConectado.nombreUsuario);
    strcat(nombreArchi, ".dat");

    FILE* usuario= fopen(nombreArchi, "rb");

    if (usuario != NULL)
    {

        stPelicula aux;
        nodoSecPeliFav* nuevo;
        while (fread(&aux,sizeof(stUsuario),1,usuario) > 0)
        {
            nuevo= crearNodoSec(aux);
            listaCompLista= altaPeliculaFav(listaCompLista,usuarioConectado,nuevo->peliculaFav); // cambie aux
        }
        fclose(usuario);

    }
    return listaCompLista;
}


///Mostrar registros de pelis favoritas de usuario específico-
void mostrarPeliFavEnArchivo ()
{
    FILE* pelicula = fopen("leo10.dat","rb");
    stPelicula peli;

    if(pelicula!=NULL)
    {
        while(fread(&peli,sizeof(peli),1,pelicula)>0)
        {
            printf("\nINFORMACIÓN:\n");
            mostrar1Pelicula(peli);

            printf("\n---------------------------------\n");

        }
    }
    fclose(pelicula);
}

