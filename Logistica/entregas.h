#ifndef Entrega_H_INCLUDED
#define Entrega_H_INCLUDED

#include "LinkedList.h"

typedef struct
{
    int id;
    char tipo[128];
    int cantidad;
    float importe;
}Entrega;

Entrega* entrega_new();
Entrega* entrega_newParametros(char* idStr,char* tipoStr,char* cantidadStr, char* importeStr);
void entrega_delete();

int entrega_setId(Entrega* this,int id);
int entrega_getId(Entrega* this,int* id);

int entrega_setTipo(Entrega* this,char* tipo);
int entrega_getTipo(Entrega* this,char* tipo);

int entrega_setCantidad(Entrega* this,int cantidad);
int entrega_getCantidad(Entrega* this,int* cantidad);

int entrega_setImporte(Entrega* this,float importe);
int entrega_getImporte(Entrega* this,float* importe);

int entrega_setIdStr(Entrega* this, char* id);
int entrega_getIdStr(Entrega* this, char* resultado);

int entrega_setCantidadStr(Entrega* this,char* cantidad);
int entrega_getCantidadStr(Entrega* this,char* resultado);

int entrega_setImporteStr(Entrega* this,char* importe);
int entrega_getImporteStr(Entrega* this,char* resultado);

int entrega_lastId(LinkedList* pArrayListEntrega);
int entrega_findById(LinkedList* pArrayListEntrega, int *posicionId, int id);
int entrega_compararPorNombre(void* this1, void* this2);


#endif // Entrega_H_INCLUDED
