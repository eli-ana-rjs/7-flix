#include "stUsuarios.h"

///--------------------- Funciones para la carga de Datos e Ingreso del USUARIO-------------------

void mostrarFormulUsuario()
{
    gotoxy(8,2);
    printf("INGRESE SUS DATOS PERSONALES:");
    //nombre
    gotoxy(15,4);
    printf("Nombre................:");

    //apellido
    gotoxy(15,5);
    printf("Apellido..............:");

    //dni
    gotoxy(15,6);
    printf("DNI...................:");

    gotoxy(8,12);
    printf("DATOS DE INGRESO:");

    //nombreUsuario
    gotoxy(15,14);
    printf("Ingrese nombre de usuario:");

    //password
    gotoxy(15,15);
    printf("Ingrese contraseña:");
    gotoxy(55,15);
    printf("(Debe contener 8 caracteres)");

}


stUsuario cargarDatosUsuario ()
{
    stUsuario aux;
    aux.baja=0;
    aux.idUsuario = 0;
    aux.isAdmin = 0;

    hidecursor(1);
    mostrarFormulUsuario();
    //Nombre
    gotoxy(38,4);
    fflush(stdin);
    scanf("%s", &aux.nombre);
    //Apellido
    gotoxy(38,5);
    fflush(stdin);
    scanf("%s", &aux.apellido);
    //DNI
    gotoxy(38,6);
    fflush(stdin);
    scanf("%s", &aux.dni);
    //Usuario
    gotoxy(41,14);
    fflush(stdin);
    scanf("%s", &aux.nombreUsuario);
    //Contraseña
    gotoxy(34,15);
    fflush(stdin);
    scanf("%s", &aux.password);


    hidecursor(0);

    return aux;
}



///---------------------- Muestra 1 usuario------------------------

void mostrarDatos1Usuario(stUsuario aux)
{

    printf("\n\t\tNombre: %s\n", aux.nombre);
    printf("\t\tApellido: %s\n", aux.apellido);
    printf("\t\tDNI: %s\n", aux.dni);

    if ( aux.isAdmin == 1 )
    {

        printf("\t\tAdminsitrador\n");
    }
    else
    {
        if( aux.baja !=  0 )
            printf("\t\tUsuario dado de baja");
        else
            printf("\t\tUsuario registrado");
    }

    printf("\n\n");

}

///-----------Muestra datos de login--------
void mostrarDatosIngresoUs (stUsuario aux)
{
    printf("\t\tId usuario: %d\n", aux.idUsuario);
    printf("\t\tNombre de usuario: %s\n", aux.nombreUsuario);
    printf("\t\tContraseña: %s", aux.password);
    printf("\n\t\t---------------------------\n\n\n\t\t");
}


/// Contar registros del archivo
int cantidadRegistrosArchivo( char nombreArchi [] )
{
    int cantidadRegistros;

    fseek( nombreArchi, 0, SEEK_END );
    cantidadRegistros = ftell (nombreArchi )/sizeof( stUsuario );

    return cantidadRegistros;
}

/// Cargar al archivo un usuario que se registra
void cargarUnUsario2Archivo()
{
    FILE* user = fopen("usuarios.dat","ab");

    if( user != NULL )
    {
        stUsuario persona;

        int cantidadDeRegistros = cantidadRegistrosArchivo(user);
        persona= cargarDatosUsuario();
        persona.idUsuario = cantidadDeRegistros + 1;
        if(cantidadDeRegistros < 2)  /// los primeros son ADmin
        {
            persona.isAdmin = 1;
        }

        fwrite(&persona,sizeof(stUsuario),1,user);

        gotoxy(12,22);
        printf("Gracias por registrarse\n");

        gotoxy(12,23);
        system("pause");
        system("cls");

        fclose(user);

    }

}

///--------------- Cargar archivo con las estructuras----------------
void cargarMuchosArchivoUsuarios()
{
    int opcion=0;

    while (opcion!=27)
    {
        cargarUnUsario2Archivo();
        gotoxy(12,20);
        printf("Si desea salir presione ESC");
        opcion=getch();
        if(opcion ==27)
        {
            gotoxy(12,22);
            printf("Gracias por registrarse");
        }
        system("cls");
    }
}


/// ----------------------- Mostrar USUARIOS de un archivo --------------------

void mostrarUsuariosArchivo ()
{
    FILE* usuario = fopen("usuarios.dat","rb");
    stUsuario persona;

    if(usuario!=NULL)
    {
        while(fread(&persona,sizeof(stUsuario),1,usuario)>0)
        {
            printf("\nDATOS DEL USUARIO:\n");
            mostrarDatos1Usuario(persona);
            printf("\nDATOS DE INGRESO DE USUARIO:\n");
            mostrarDatosIngresoUs(persona);

            printf("\n---------------------------------\n");

        }
    }
    fclose(usuario);
}



///__________________________________ FUNCIONES PARA LISTAS__________________________________________

///----------- inicializar lista------
lista2Usuario* iniclista2U()
{
    return NULL;
}

///----------- Crear nodo doble--------
lista2Usuario* crearNodolis2Us (stUsuario dato)
{
    lista2Usuario* aux= (lista2Usuario*) malloc (sizeof(lista2Usuario));
    aux->dato= dato;
    aux->ante= NULL;
    aux->ste=NULL;

    return aux;
}

///---------Agregar al principio-----------
lista2Usuario* agregarAlppioL2U (lista2Usuario* listaU, lista2Usuario* nvoUs)
{
    if(listaU!=NULL)
    {
        nvoUs->ste=listaU;

    }
    listaU= nvoUs;

    return listaU;
}


///----- Agregar en orden POR ID------------------- no va, se ordena sola
lista2Usuario* agregarEnOrdenL2UporID (lista2Usuario* listaU, lista2Usuario* nvoUs)
{
    if (listaU==NULL)
    {
        listaU= nvoUs;
    }
    else if(nvoUs->dato.idUsuario < listaU->dato.idUsuario)
    {
        listaU=agregarAlppioL2U(listaU,nvoUs);
    }
    else
    {
        lista2Usuario* seg= listaU->ste;
        lista2Usuario* ante= listaU;
        while((seg!=NULL)&&(nvoUs->dato.idUsuario>seg->dato.idUsuario))
        {
            ante=seg;
            seg=seg->ste;
        }

        ante->ste= nvoUs;
        nvoUs->ante=ante;
        nvoUs->ste=seg;

        if(seg!=NULL)
        {
            seg->ante=nvoUs;
        }
    }

    return listaU;
}


///-----------Cargar LISTA2 con estructuras-----------------
lista2Usuario* cargarListaUsuarios ()
{
    lista2Usuario* lista=NULL;
    lista2Usuario* nvoNodo;
    stUsuario persona;
    int opcion=0;

    while (opcion!=27)
    {
        persona= cargarDatosUsuario();
        nvoNodo= crearNodolis2Us(persona);
        lista= agregarEnOrdenL2UporID(lista,nvoNodo);
        gotoxy(12,20);
        printf("Si desea salir presione ESC");
        opcion=getch();
        system("cls");
    }

    return lista;
}

///------------- Mostrar lista Usuarios------------- Admin usuarios

void mostrarLista2Us (lista2Usuario* listaU)
{
    lista2Usuario* seg= listaU;
    while(seg!=NULL)
    {
        mostrarDatos1Usuario(seg->dato);
        seg= seg->ste;
    }
}


///----------- Buscar Usuario por ID------------

///Buscar nodo por ID

lista2Usuario* buscarNodoXid (lista2Usuario* lista, int id)
{
    lista2Usuario* seg= lista;

    while( (seg != NULL ) && ( seg -> dato.idUsuario != id ) )
    {
        seg = seg -> ste;
    }

    return seg;
}

/// Mostar nodo buscado
void mostarUsBuscadoXid ( lista2Usuario* aux )
{
    if(aux != NULL)
    {
        mostrarDatos1Usuario( aux->dato );
    }
    else
    {
        printf("\nEl usuario no se encuentra en el registro");
    }
}

/// Muestra lista de usuarios ordenados por id
void mostrarListaOrdenaPorId(lista2Usuario* lista)
{

    lista2Usuario* seg = lista;

    while(seg != NULL)
    {
        mostrarDatos1Usuario(seg->dato);
        mostrarDatosIngresoUs(seg->dato);
        seg = seg -> ste;

    }
}

/// Buscar usuario por nombre y retorna el nodo encontrado
/// Usamos esta función para hacer el primer chequeo del login, si ingresa con un nombre correcto de usuario.

lista2Usuario* buscarUsuarioPorNombre(lista2Usuario* lista, char nombreUsuario[30])
{
    lista2Usuario* seg = lista;

    while((seg != NULL) && (strcmpi(seg->dato.nombreUsuario, nombreUsuario) != 0))
    {
        seg = seg -> ste;
    }
    if( seg == NULL)
    {
        printf("El usuario ingresado no existe\n");
    }
    return seg;

}

///------------------ Dar de baja Usuario || Aministrar usuarios -------------------

lista2Usuario* bajaXelUsuario (lista2Usuario* lista)
{
    char control= 's';
    int identif=0;

    printf("\n\t\tIngrese ID del usario que desea ver");
    fflush(stdin);
    scanf("%d", &identif);

    lista2Usuario* aux=buscarNodoXid(lista,identif);
    mostarUsBuscadoXid(aux);

    printf("\n\t\t¿Desea realizar la BAJA del usuario?");
    fflush(stdin);
    scanf("%d",&control);
    if(control=='s')
    {
        aux  -> dato.baja = 1;

        printf("\n\t\t BAJA EXITOSA");

        return lista;
    }
}

/// El usuario da de baja el servicio

/*lista2Usuario* bajaUsuario(lista2Usuario* lista, int idUsuarioConectado)
{

    lista2Usuario* nodoEncontrado = buscarNodoXid(lista,idUsuarioConectado);

    nodoEncontrado -> dato.idUsuario = 1;

    return lista;
}

void usuarioSeDaDeBaja(lista2Usuario* lista, int idUsuarioConectado)
{
    char control = 's';

    printf("Desea dar de baja el servicio?\n\n");
    fflush(stdin);
    scanf("%c", &control);

    if( control == 's')
    {
        bajaUsuario(lista, idUsuarioConectado);
        system("cls");
        gotoxy(20,20);
    }
}*/

/// Baja Lógica de Usuario
stUsuario formularioBajaDelServicio(stUsuario aux)
{
    char eleccion;


    gotoxy(15,11);
    printf("Desea dar de baja el servicio? S/N");

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
void bajaDeUsuarioEnArchivo(int idUsuario)
{
    stUsuario aux;
    int flag=0;

    FILE* usuarios=fopen("usuarios.dat","r+b");

    if(usuarios)
    {
        while((fread(&aux,sizeof(aux),1,usuarios)>0)&& (!flag))
        {
            if(aux.idUsuario == idUsuario)
            {
                aux=formularioBajaDelServicio(aux);

                fseek(usuarios,sizeof(aux)*(-1),SEEK_CUR);
                fwrite(&aux,sizeof(aux),1,usuarios);
                flag=1;
                fclose(usuarios);
            }
        }
    }

    fclose(usuarios);
}

///-----------Agregar en orden por el APELLIDO--------------

lista2Usuario* agregarEnOrdenL2UporApel(lista2Usuario* listaU, lista2Usuario* nvoUs)
{
    if (listaU==NULL)
    {
        listaU= nvoUs;
    }
    else
    {
        if(strcmpi(nvoUs->dato.apellido, listaU->dato.apellido) <0)
        {
            listaU=agregarAlppioL2U(listaU,nvoUs);
        }
        else
        {
            lista2Usuario* seg= listaU->ste;
            lista2Usuario* anterior= listaU;
            while((seg!=NULL) && (strcmpi(nvoUs->dato.apellido, seg->dato.apellido) >= 0))
            {
                anterior=seg;
                seg=seg->ste;
            }

            anterior->ste= nvoUs;
            nvoUs->ante=anterior;
            nvoUs->ste=seg;

            if(seg!=NULL)
            {
                seg->ante=nvoUs;
            }
        }
    }
    return listaU;
}

/// Ordenar en una nueva lista por apellido -----

lista2Usuario* ordenarPorApellido(lista2Usuario* lista, lista2Usuario* listaOrdenada)
{
    if(lista)
    {
        lista2Usuario* nodoAux;

        while(lista!=NULL)
        {
            nodoAux = lista;
            lista= lista->ste;

            nodoAux->ste=NULL;
            nodoAux->ante=NULL;

            listaOrdenada= agregarEnOrdenL2UporApel(listaOrdenada,nodoAux);
        }

    }
    return listaOrdenada;
}


/// Modificar datos de un usuario---
stUsuario formularioModificarDatos(stUsuario aux)
{
    int opcion=0;
    char nombre[20];
    char apellido[20];
    char password[20];

    gotoxy(15,11);
    printf("Seleccione la opción a modificar");
    gotoxy(15,13);
    printf("1. Nombre y Apellido    2. Contraseña \n");
    gotoxy(15,15);
    printf("Opción:");
    fflush(stdin);
    scanf("%d", &opcion);
    system("cls");

    if( opcion == 1)
    {
        gotoxy(15,8);
        printf("Ingrese los datos: ");

        gotoxy(15,10);
        printf("Nombre: ");
        fflush(stdin);
        scanf("%s", &nombre);
        strcpy(aux.nombre,nombre);

        gotoxy(15,12);
        printf("Apellido: ");
        fflush(stdin);
        scanf("%s", &apellido);
        strcpy(aux.apellido,apellido);

    }
    else if(opcion == 2)
    {
        gotoxy(15,8);
        printf("Ingrese: ");

        gotoxy(15,10);
        printf("Contraseña: ");
        fflush(stdin);
        scanf("%s", &password);
        strcpy(aux.password,password);

    }
    else
    {
        printf("\nOpción incorrecta. Vuelva a intentar\n");
    }


    return aux;
}

///---Función que cambia la estructura en el archivo con la información modificada del usuario
void modificarDatosEnArchivo(int idUsuario)
{
    stUsuario aux;
    int flag=0;

    FILE* usuarios=fopen("usuarios.dat","r+b");

    if(usuarios)
    {
        while((fread(&aux,sizeof(aux),1,usuarios)>0)&& (!flag))
        {
            if(aux.idUsuario == idUsuario)
            {
                aux=formularioModificarDatos(aux);

                fseek(usuarios,sizeof(aux)*(-1),SEEK_CUR);
                fwrite(&aux,sizeof(aux),1,usuarios);
                flag=1;
                fclose(usuarios);
            }
        }
    }
    fclose(usuarios);
}




///-------------Pasar los datos del archivo a la Lista de USUARIOS----------------------------
lista2Usuario* pasarDeArchivoALista2 (char nombreArchi[], lista2Usuario* lista)
{
    FILE* usuario= fopen(nombreArchi, "rb");

    if (usuario != NULL)
    {
        stUsuario aux;
        lista2Usuario* nuevo;
        while (fread(&aux,sizeof(stUsuario),1,usuario) > 0)
        {
            nuevo= crearNodolis2Us(aux);
            lista= agregarEnOrdenL2UporID(lista,nuevo);
        }
        fclose(usuario);
    }
    return lista;
}


///-------------Pasar los datos del archivo a la Lista de USUARIOS en orden alfabetico----------------------------
lista2Usuario* pasarArchiToListaApellido (char nombreArchi[], lista2Usuario* lista)
{
    FILE* usuario= fopen("usuarios.dat", "rb");

    if (usuario != NULL)
    {
        stUsuario aux;
        lista2Usuario* nuevo;
        while (fread(&aux,sizeof(stUsuario),1,usuario) > 0)
        {
            nuevo= crearNodolis2Us(aux);
            lista= agregarEnOrdenL2UporApel(lista,nuevo);
        }
        fclose(usuario);
    }
    return lista;

}
