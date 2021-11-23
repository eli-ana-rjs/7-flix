#include "menuAdministrador.h"

void configurarMenuAdministrador (Menu menus[])
{

    /// Menu Administrador de usuario [0].


    strcpy(menus[0].titulo, "\t\tAdministrador");
    menus[0].cantidadDeOpciones = 3;


    strcpy( menus[0].opciones[0].titulo, "Administrar Usuarios");
    menus[0].opciones[0].id = 1;
    menus[0].opciones[0].redireccion = 1;


    strcpy( menus[0].opciones[1].titulo, "Administrar Películas");
    menus[0].opciones[1].id = 2;
    menus[0].opciones[1].redireccion = 2;


    strcpy( menus[0].opciones[2].titulo, "Salir");
    menus[0].opciones[2].id = 0;
    menus[0].opciones[2].redireccion = -1;



    /// Sub-menú Administrar Usuarios [1].

    strcpy(menus[1].titulo, "\t\tSub-Menú Administrar Usuarios ");
    menus[1].cantidadDeOpciones = 5;

    strcpy( menus[1].opciones[0].titulo, "Alta de Usuario");
    menus[1].opciones[0].id = 1;
    menus[1].opciones[0].redireccion = 1001;

    strcpy( menus[1].opciones[1].titulo, "Ver listado de Usuarios");
    menus[1].opciones[1].id = 2;
    menus[1].opciones[1].redireccion = 1002;

    strcpy( menus[1].opciones[2].titulo, "Modificar usuario");
    menus[1].opciones[2].id = 3;
    menus[1].opciones[2].redireccion = 1003;

    strcpy( menus[1].opciones[3].titulo, "Baja de usuario");
    menus[1].opciones[3].id = 4;
    menus[1].opciones[3].redireccion = 1004;

    strcpy( menus[1].opciones[4].titulo, "Volver al Menú Principal");
    menus[1].opciones[4].id = 0;
    menus[1].opciones[4].redireccion = 0;



    ///SubMenu Administrar Peliculas [2] ---------------------------------------------

    strcpy(menus[2].titulo, "\t\tSub-menú Administrar Películas");
    menus[2].cantidadDeOpciones = 5;

    strcpy( menus[2].opciones[0].titulo, "Dar de alta una película");
    menus[2].opciones[0].id = 1;
    menus[2].opciones[0].redireccion = 1005;

    strcpy( menus[2].opciones[1].titulo, "Ver listado de películas");
    menus[2].opciones[1].id = 2;
    menus[2].opciones[1].redireccion = 1006;

    strcpy( menus[2].opciones[2].titulo, "Modificar datos de una película");
    menus[2].opciones[2].id = 3;
    menus[2].opciones[2].redireccion = 1007;

    strcpy( menus[2].opciones[3].titulo, "Baja de película");
    menus[2].opciones[3].id = 4;
    menus[2].opciones[3].redireccion = 1008;

    strcpy( menus[2].opciones[4].titulo, "Volver");
    menus[2].opciones[4].id = 0;
    menus[2].opciones[4].redireccion = 0;

}


/// Cada menu tiene id de 1 a x. Hace esta logica para buscar la redireccion de este elemento. Y me permite que el usuario pueda apretar 1
/// en el menu principal, y en los siguientes submenues.

int buscarRedireccionPorId(Menu *menuActual, int id)
{
    for(int i = 0; i < menuActual->cantidadDeOpciones; i++)
    {
        if(menuActual->opciones[i].id == id)
        {
            return menuActual->opciones[i].redireccion;
        }
    }
}

void iniciar_programaAdmin()
{
    int menuActual = 0;
    int redirMenu;
    Menu menus[30];


    configurarMenuAdministrador(menus);

    lista2Usuario* lista = iniclista2U();
    lista2Usuario* listaOrdenada = iniclista2U();
     lista2Usuario* nodoBuscado2 = NULL;
    lista = pasarDeArchivoALista2("usuarios.dat",lista);

    nodoPelicula* listaPeli = inicListaPelic();
    listaPeli = pasarDeArchivoAListaPeli("pelicula.dat", listaPeli);
    nodoPelicula* peliBuscada=NULL;
    char nombrePeli[30];

    int idBuscado = 0;
    int genero;


    while( menuActual != -1) /// -1 salir del programa
    {
        /// imprime el titulo del menu actual
        printf("\n\n\n");
        printf("%s\n", menus[menuActual].titulo);


        /// subraya el titulo
        printf("\t\t");
        for (int i = 0; i < strlen(menus[menuActual].titulo); i++)
        {
            printf("=");
        }
        printf("\t\t\n");

        /// Imprimo el menu actual.


        for ( int i = 0; i < menus[menuActual].cantidadDeOpciones; i++)
        {
            printf("\t\t");
            printf("[%i] %s\n", menus[menuActual].opciones[i].id, menus[menuActual].opciones[i].titulo);
        }


        printf("\n\t\tSeleccione el menu al que desea acceder\n");
        fflush(stdin);
        printf("\t\t");
        scanf("%i", &redirMenu);
        int redireccion = buscarRedireccionPorId(&menus[menuActual], redirMenu);

        /// En los casos en que redireccion sea menor a 1000 me va a redirigir a la siguiente lista de opciones segun corresponda
        ///En los casos donde redireccion sea mayor a 1000 se ha asignado dentro un switch, en cada caso, el llamado a la funcion que
        ///se deba ejecutar en cada caso

        if( redireccion < 1000)
        {
            menuActual = redireccion;
            system("cls");
        }
        else
        {
            switch ( redireccion )
            {

            case 1001 :


                system("cls");

                cargarMuchosArchivoUsuarios();
                lista= pasarDeArchivoALista2("usuarios.dat", lista);

                break;


            case 1002 :

                /// Mostrar lista de usuarios
                system("cls");
                mostrarListaOrdenaPorId(lista);

                break;


            case 1003 :

                system("cls");
                printf("\n\n\t\tIngrese id del usuario\n\t\t");
                scanf("%d", &idBuscado);

                ///  buscar usuario por id
               nodoBuscado2 = buscarNodoXid(lista, idBuscado);
               if(nodoBuscado2!=NULL){

                /// mostrar información del usuario encontrado o lanzar mensaje indicando que no existe ese usuario en el sistema
                mostrarDatos1Usuario(nodoBuscado2->dato);

                system("pause");
                system("cls");

                modificarDatosEnArchivo(idBuscado);
               lista = pasarDeArchivoALista2("usuarios.dat",lista);
               }else
               {
                   printf("\nEl usuario ingresado no existe. Intente otra vez\n");
               }

                break;


            case 1004 :

                system("cls");
                ///Pedir id del usuario que se desea dar de baja
                gotoxy(15,9);
                printf("Ingrese id del usuario: ");
                gotoxy(40,9);
                scanf("%d", &idBuscado);

                ///  buscar usuario por id
                nodoBuscado2 = buscarNodoXid(lista, idBuscado);


                if( nodoBuscado2->dato.baja != 1)
                {
                    /// función que cambia el estado eliminado a 0
                    bajaDeUsuarioEnArchivo(nodoBuscado2->dato.idUsuario);
                     lista = pasarDeArchivoALista2("usuarios.dat",lista);
                    gotoxy(15, 11);
                    printf("\n\n");

                    /// msj -> el usuario ha sido dado de baja
                    gotoxy(15, 12);

                    printf("El usuario con id %d, ha sido dado de baja", idBuscado);
                    printf("\n\n");

                }
                else
                {
                    gotoxy(15,12);
                    printf("El usuario indicado ya esta dado de baja");

                    printf("\n\n");
                }

                break;

            case 1005 :


                system("cls");
                cargarMuchasPeliToArchivo();
                listaPeli = pasarDeArchivoAListaPeli("pelicula.dat", listaPeli);

                break;


            case 1006 :

                system("cls");
                mostrarListaPelicula(listaPeli);

                break;


            case 1007:

                ///Modificar datos Pelicula
                printf("\t\tIngrese nombre de la película a modificar:\n\t\t");
                fflush(stdin);
                gets(nombrePeli);

                ///  buscar por id
                peliBuscada= buscarPeliPorTitulo(listaPeli,nombrePeli);

                /// mostrar información del usuario encontrado o lanzar mensaje indicando que no existe ese usuario en el sistema
                printf("\t\tDatos de la película seleccionada:\n\n");
                mostrar1Pelicula(peliBuscada->dato);
                system("pause");
                system("cls");

                modificarDatosEnArchivoPelicula(peliBuscada->dato.idPelicula);
                 listaPeli = pasarDeArchivoAListaPeli("pelicula.dat", listaPeli);
               // printf("\n\t\tLa modificación será visualizada en el próximo inicio se sesión.");

            break;


            case 1008:

                ///Baja de pelicula
                printf("\t\tIngrese nombre de la película a dar de baja:\n\t\t");
                fflush(stdin);
                gets(nombrePeli);

                ///  buscar por id
                peliBuscada= buscarPeliPorTitulo(listaPeli,nombrePeli);

                /// mostrar información del usuario encontrado o lanzar mensaje indicando que no existe ese usuario en el sistema
                printf("\t\tDatos de la película seleccionada:\n\n");
                mostrar1Pelicula(peliBuscada->dato);
                system("pause");
                system("cls");
                bajaDePeliculaEnArchivo(peliBuscada->dato.idPelicula);
                listaPeli = pasarDeArchivoAListaPeli("pelicula.dat", listaPeli);

                break;


            default:
                printf("Opcion no implementada\n");
                break;
            }
            system ("pause");
            system("cls");

        }
    }

    printf("\nFin programa\n");
}
