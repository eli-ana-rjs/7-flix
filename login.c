#include "login.h"

void inicioSesion()
{

    char usuario[LONGITUD + 1] ; /// Longitud: cant de caracteres que ingresa el usuario, uno más para el fin de cadena
    char clave[LONGITUD + 1];

    int intento = 0;
    int ingreso = 0; // F, no puedo ingresar
    char caracter;
    int i = 0;



    do
    {
        system("cls");
        gotoxy(20,7);
        printf("\n\t\t INICIO DE SESIÓN\n");
        printf("\n\t\t-----------------\n");
        printf("\n\t\tUSUARIO: ");
        fflush(stdin);
        scanf("%s", &usuario);
        printf("\n\n\t\tCONTRASEÑA: ");

        /// Inicializo y declaro las listas
        lista2Usuario* lista = iniclista2U();
        lista = pasarDeArchivoALista2("usuarios.dat", lista);

        lista2Usuario* usuarioEncontrado = buscarUsuarioPorNombre(lista,usuario); /// chequeo que el usuario conectado este en la lista
        usuarioConectado = usuarioEncontrado->dato;

        while(caracter = getch()) /// lectura de la clave, para que no me muestre el caracter ingresado
        {
            if(caracter == TECLA_ENTER) /// reconoce que termino de ingresar la contraseña por el enter
            {
                clave[i]= '\0';
                break;
            }
            else if( caracter == TECLA_BACKSPACE ) /// cuando borro
            {
                if(i > 0)
                {
                    i--;
                    printf("\b \b"); /// retrocedo el cursor, imprimo espacio y vuelvo a retroceder el cursor
                }
            }
            else
            {
                if( i < LONGITUD )
                {
                    printf("*");
                    clave[i] = caracter; /// guardo el caracter en la posicion i
                    i++;
                }
            }
        }

        system("cls");


        if(strcmpi(clave,usuarioConectado.password) == 0 ) /// si entro chequeo la contraseña
        {
            ingreso = 1;

            break;
        }

        if( ingreso == 0)
        {
            printf("\n\tUsuario y/o contraseña incorrectas\n");
            intento++;
            system("pause");
        }
    }
    while(intento < 3 && ingreso == 0 ); /// tres intentos para ingresar

    if(ingreso == 1)
    {


        /// opciones para cada tipo de usuario
        if( usuarioConectado.isAdmin == 1) // isAdmin == 1 ---> muestra el menu para las acciones que puede realizar un administrador del sistema
        {

            int menuAdmin[30];

            gotoxy(20,7);
            printf("\n\tBienvenida/o al Sistema\n");
            gotoxy(20,9);
            printf("\n\n\n");

            system("pause");
            system("cls");

            iniciar_programaAdmin();

        }
        else if( usuarioConectado.isAdmin == 0 ) /// menu para el usuario
        {

            if( usuarioConectado.baja == 0 )
            {
                int menuUsers[30];
                printf("\n\tBienvenida/o al Sistema\n");

                system("pause");
                system("cls");

                iniciar_programaUser();
            }
            else
            {
                gotoxy(10,10);
                printf("El servicio está dado de baja.");
                gotoxy(10,11);
                printf("Lo contactaremos para reactivar el servicio");
                gotoxy(10,12);
                printf("\n\n");
            }


        }
        else
        {

            printf("La opción ingresada no es correcta. Debe indicar: 1. Administrador de Usuarios ...\n");

        }
    }
    else
    {
        printf("\n\tHa sobrepasado el número de intentos permitidos\n");
        system("cls");
        printf("\n\tEn caso de no estar registrado en nuestro sistema, lo redireccionaremos a la sección de registro \n");
        /// llamar a la función de registro de un nuevo usuario
    }
}

