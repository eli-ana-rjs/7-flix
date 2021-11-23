#ifndef GOTOXY_H_INCLUDED
#define GOTOXY_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void color(int x);
void gotoxy(int X,int Y);
int whereX();
int whereY();
void hidecursor(int ver);

#endif // GOTOXY_H_INCLUDED
