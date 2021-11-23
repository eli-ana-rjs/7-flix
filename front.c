#include "front.h"

void recuadro(int xs, int ys, int xi, int yi){


    for(int i = xs; i <= xi; i++){
        gotoxy(i,ys); ///linea superior
        printf("_");
        gotoxy(i,yi); ///linea inferior
        printf("_");
    }
    for(int i = ys; i <= yi; i++){
        gotoxy(xs,i); ///linea der
        printf("|");
        gotoxy(xi,i); ///linea izq
        printf("|");
    }

}
