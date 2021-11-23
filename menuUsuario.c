#include "menuUsuario.h"

void configurarMenuUsuario (MenuUser menus[])
{

    /// Menu de Usuario [0].

    strcpy(menus[0].titulo, "\t\tUsuario");
    menus[0].cantidadDeOpciones = 5;

    strcpy( menus[0].opciones[0].titulo, "Ver mi perfil");
    menus[0].opciones[0].id = 1;
    menus[0].opciones[0].redireccion = 1;

    strcpy( menus[0].opciones[1].titulo, "Mostrar películas");
    menus[0].opciones[1].id = 2;
    menus[0].opciones[1].redireccion = 2;

    strcpy( menus[0].opciones[2].titulo, "Buscar película");
    menus[0].opciones[2].id = 3;
    menus[0].opciones[2].redireccion = 3;

    strcpy( menus[0].opciones[3].titulo, "Dar de baja el servicio");
    menus[0].opciones[3].id = 4;
    menus[0].opciones[3].redireccion = 1001;


    strcpy( menus[0].opciones[4].titulo, "Salir");
    menus[0].opciones[4].id = 0;
    menus[0].opciones[4].redireccion = -1;

    /// Sub-menú ver pefil [1].

    strcpy(menus[1].titulo, "\t\tSub-Menú Ver perfil ");
    menus[1].cantidadDeOpciones = 3;

    strcpy( menus[1].opciones[0].titulo, "Mis datos");
    menus[1].opciones[0].id = 1;
    menus[1].opciones[0].redireccion = 1002;

    strcpy( menus[1].opciones[1].titulo, "Modificar mi información ");
    menus[1].opciones[1].id = 2;
    menus[1].opciones[1].redireccion = 1003;

    strcpy( menus[1].opciones[2].titulo, "Volver al Menú Principal");
    menus[1].opciones[2].id = 0;
    menus[1].opciones[2].redireccion = 0;

    /// SubMenu Mostrar listados de peliculas  [2]

    strcpy(menus[2].titulo, " \t\tSub-menú Mostrar listados de películas ");
    menus[2].cantidadDeOpciones = 4;

    strcpy( menus[2].opciones[0].titulo, "Todas las películas");
    menus[2].opciones[0].id = 1;
    menus[2].opciones[0].redireccion = 1005;

    strcpy( menus[2].opciones[1].titulo, "Películas por genero");
    menus[2].opciones[1].id = 2;
    menus[2].opciones[1].redireccion = 1007;

    strcpy( menus[2].opciones[2].titulo, "Mis películas favoritas");
    menus[2].opciones[2].id = 3;
    menus[2].opciones[2].redireccion = 1004;

    strcpy( menus[2].opciones[3].titulo, "Volver");
    menus[2].opciones[3].id = 0;
    menus[2].opciones[3].redireccion = 0;

    ///SubMenu Buscar pelicula [3]

    strcpy(menus[3].titulo, "\t\tSubmenú Buscar película");
    menus[3].cantidadDeOpciones = 2;

    strcpy( menus[3].opciones[0].titulo, "Título ");
    menus[3].opciones[0].id = 1;
    menus[3].opciones[0].redireccion = 1006;

    strcpy( menus[3].opciones[1].titulo, "Volver");
    menus[3].opciones[1].id = 0;
    menus[3].opciones[1].redireccion = 0;

}

/// Cada menu tiene id de 1 a x. Hace esta logica para buscar la redireccion de este elemento. Y me permite que el usuario pueda apretar 1
/// en el menu principal, y en los siguientes submenues.

int buscarRedireccionPorIdUser(MenuUser *menuActual, int id)
{
    for(int i = 0; i < menuActual->cantidadDeOpciones; i++)
    {
        if(menuActual->opciones[i].id == id)
        {
            return menuActual->opciones[i].redireccion;
        }
    }
}

void iniciar_programaUser()
{
    int menuActual = 0;
    int redirMenu;
    MenuUser menus[20];
    stUsuario usuario;
    lista2Usuario* lista = iniclista2U();
    int genero;

    nodoPelicula* listaPeliculas = inicListaPelic();
    listaPeliculas=pasarDeArchivoAListaPeli("pelicula.dat",listaPeliculas);
    stPelicula buscado ;
    celdaPrinFav* lisCompfav= iniclista2U();
    lisCompfav = pasarArch2listaCompuesta(usuarioConectado, lisCompfav);

    char fav ;




    configurarMenuUsuario(menus);


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
                ///Baja del servicio por parte del usuario
                system("cls");
                bajaDeUsuarioEnArchivo(usuarioConectado.idUsuario);
                printf("\n\n");
                if( usuarioConectado.baja == 1)
                {
                    system("C:\\Users\\apunt\\Desktop\\proy2\\assets\\vuelvaProntos.png");
                }

                printf("\t\t");
                system ("pause");
                system("cls");

                break;

            case 1002 :


                mostrarDatos1Usuario(usuarioConectado);
                //  lista = pasarDeArchivoALista2("usuarios.dat", lista);

                break;

            case 1003 :

                modificarDatosEnArchivo(usuarioConectado.idUsuario);
                lista = pasarDeArchivoALista2("usuarios.dat", lista);

                break;

            case 1004 :
                /// Mostrar lista de peliculas favoritas
                lisCompfav = pasarArch2listaCompuesta(usuarioConectado, lisCompfav);
                mostrarListaDePeliculasFavoritas(lisCompfav, usuarioConectado);

                break;

            case 1005:
                /// Listado con todas las peliculas
                mostrarListaPelicula(listaPeliculas);

                break;


            case 1006 :
                /// buscar pelicula por titulo
                buscado = verPelicula(listaPeliculas);

                system("pause");
                system("cls");

                gotoxy(47,10);
                printf("Desea agregar esta pelicula a su lista de favoritos? s/n");
                gotoxy(83,10);
                fflush(stdin);
                scanf("%c", &fav);


                if(fav == 's')
                {
                    lisCompfav = altaPeliculaFav(lisCompfav, usuarioConectado, buscado);
                    gotoxy(3,15);
                    printf("Película agregada con ÉXITO!!!");
                    pasarListaPeliFavToArchi(lisCompfav,usuarioConectado);

                }

                lisCompfav = pasarArch2listaCompuesta(usuarioConectado, lisCompfav);


                break;

            case 1007 :

                /// Lista de peliculas buscada por genero
                genero= consultarGeneroPelicula();
                system("cls");
                muestraGeneroElegido(genero,listaPeliculas);


                break;


            default:
                printf("Opcion no implementada\n");
                break;
            }
            printf("\t\t");
            system ("pause");
            system("cls");

        }
    }

    printf("\n\n");
    printf("\n\t\tFin programa\n");
}
