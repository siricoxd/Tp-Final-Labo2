#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MESES=12;
const int DIAS=31;

typedef struct{
    int ganancias[DIAS][MESES];
    struct nodoGananciasAnio * siguiente;
}nodoGananciasAnio;

