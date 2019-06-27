#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "entregas.h"
#include "utn.h"
#include "LinkedList.h"

/** \brief Reserva espacio en memoria para un entrega
 * \param void vacio
 * \return Entrega* un puntero al espacio reservado para cargar un entrega
 */
Entrega* entrega_new(void)
{
    return (Entrega*) malloc(sizeof(Entrega));
}

/** \brief Valida los elementos que contiene una entrega y los carga en una variable Entrega
 *
 * \param idStr char* id del entrega.
 * \param tipoStr char* tipo  de la entrega.
 * \param cantidadStr char* cantidad del entrega.
 * \param importeStr char* importe del entrega.
 * \return Entrega* pAuxEntrega, devuelve - NULL si puntero a idStr/tipoStr/cantidadStr/importeStr NULL,
 *                               devuelve - puntero si valido sus elementos.
 *
 */
Entrega* entrega_newParametros(char* idStr,char* tipoStr,char* cantidadStr, char* importeStr)
{
    Entrega* pEntrega = entrega_new();
    Entrega* retorno = NULL;

    if(pEntrega != NULL && idStr != NULL && tipoStr != NULL && cantidadStr != NULL && importeStr != NULL)
    {
        if(!entrega_setIdStr(pEntrega, idStr) &&
                !entrega_setTipo(pEntrega, tipoStr) &&
                !entrega_setCantidadStr(pEntrega, cantidadStr) &&
                !entrega_setImporteStr(pEntrega, importeStr))
        {

            retorno = pEntrega;
        }
        else
        {
            entrega_delete(pEntrega);
        }
    }
    return retorno;
}

/** \brief Libera el espacio reservado en memoria para una entrega.
 *
 * \param Entrega* this puntero a la entrega
 * \return int retorno -1 si this NULL,
 *                     0 si logro liberar el espacio reservado.
 *
 */
void entrega_delete(Entrega* this)
{
    if(this != NULL)
    {
        return free(this);
    }
}

/** \brief Valida el elemento id de la entrega y lo carga en la estructura Entrega
 *
 * \param this Entrega* puntero a la entrega
 * \param id int id del entrega
 * \return int retorno -1 si no pudo validar el ID
 *                      0 si pudo validar y cargar el ID:
 *
 */
int entrega_setId(Entrega* this,int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el id de un entrega.
 *
 * \param this Entrega* puntero a entrega.
 * \param resultado int* id de Entrega
 * \return int retorno -1 si this es NULL o id es NULL,
 *                      0 si se obtuvo el id.
 *
 */
int entrega_getId(Entrega* this,int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->id;
        retorno = 0;
    }
    return retorno;
}

/** \brief Valida el elemento tipo del entrega y lo carga en la estructura Entrega.
 *
 * \param this Entrega* puntero al entrega.
 * \param tipo char* tipo del entrega.
 * \return int retorno -1 si no pudo validar el tipo.
 *                      0 si pudo validar y cargar el tipo.
 *
 */
int entrega_setTipo(Entrega* this,char* tipo)
{
    int retorno = -1;
    if(this != NULL && tipo != NULL)
    {
        strcpy(this->tipo,tipo);
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el tipo de un entrega.
 *
 * \param this Entrega* puntero a entrega.
 * \param resultado char* tipo de entrega
 * \return int retorno -1 si this es NULL o tipo es NULL,
 *                      0 si se obtuvo el tipo.
 *
 */
int entrega_getTipo(Entrega* this,char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strcpy(resultado,this->tipo);
        retorno = 0;
    }
    return retorno;
}

/** \brief Valida el elemento cantidad del entrega y lo carga en la estructura Entrega.
 *
 * \param this Entrega* puntero al entrega.
 * \param cantidad char* cantidad del entrega.
 * \return int retorno -1 si no pudo validar el cantidad.
 *                      0 si pudo validar y cargar el cantidad.
 *
 */
int entrega_setCantidad(Entrega* this,int cantidad)
{
    int retorno = -1;
    if(this != NULL && cantidad >= 0)
    {
        this->cantidad = cantidad;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el cantidad de un entrega.
 *
 * \param this Entrega* puntero a entrega.
 * \param resultado char* cantidad de entrega
 * \return int retorno -1 si this es NULL o cantidad es NULL,
 *                      0 si se obtuvo el cantidad.
 *
 */
int entrega_getCantidad(Entrega* this,int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->cantidad;
        retorno = 0;
    }
    return retorno;
}

/** \brief Valida el elemento importe de la entrega y lo carga en la estructura Entrega
 *
 * \param this Entrega* puntero al entrega
 * \param importe int importe del entrega.
 * \return int retorno -1 si no pudo validar el importe.
 *                      0 si pudo validar y cargar el importe.
 *
 */
int entrega_setImporte(Entrega* this,float importe)
{
    int retorno = -1;
    if(this != NULL && importe >= 0)
    {
        this->importe = importe;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el importe de un entrega.
 *
 * \param this Entrega* puntero a entrega.
 * \param resultado int* importe de Entrega
 * \return int retorno -1 si this es NULL o importe es NULL,
 *                      0 si se obtuvo el importe.
 *
 */
int entrega_getImporte(Entrega* this,float* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->importe;
        retorno = 0;
    }
    return retorno;
}

/** \brief Valida el elemento id string de la entrega y lo carga en la estructura Entrega.
 *
 * \param this Entrega* puntero al entrega.
 * \param id char* id de la entrega.
 * \return int retorno -1 si no pudo validar el id.
 *                      0 si pudo validar y cargar el id.
 *
 */
int entrega_setIdStr(Entrega* this, char* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL && !validarNumero(id))//Validar que lo que recibe es un numero.
    {
        retorno = entrega_setId(this,atoi(id));
    }
    return retorno;
}

/** \brief Obtiene el id de tipo string de una entrega.
 *
 * \param this Entrega* puntero a entrega.
 * \param resultado char* ID de entrega
 * \return int retorno -1 si this es NULL o ID es NULL,
 *                      0 si se obtuvo el ID.
 *
 */
int entrega_getIdStr(Entrega* this, char* resultado)
{
    int retorno = -1;
    int bufferInt; // para no usar el operador flecha
    if(this != NULL && resultado != NULL)
    {
        entrega_getId(this, &bufferInt);
        sprintf(resultado, "%d", bufferInt);
        retorno = 0;
    }
    return retorno;
}

/** \brief Valida el elemento cantidad de la entrega y lo carga en la estructura Entrega.
 *
 * \param this Entrega* puntero al entrega.
 * \param cantidad char* cantidad del entrega.
 * \return int retorno -1 si no pudo validar el cantidad.
 *                      0 si pudo validar y cargar el cantidad.
 *
 */
int entrega_setCantidadStr(Entrega* this,char* cantidad)
{
    int retorno = -1;
    if(this != NULL && cantidad != NULL && !validarNumero(cantidad))//Validar que lo que recibe es un numero.
    {
        retorno = entrega_setCantidad(this,atoi(cantidad));
    }
    return retorno;
}

/** \brief Obtiene el cantidad de tipo string de un entrega.
 *
 * \param this Entrega* puntero a entrega.
 * \param resultado char* cantidad de entrega
 * \return int retorno -1 si this es NULL o cantidad es NULL,
 *                      0 si se obtuvo el cantidad.
 *
 */
int entrega_getCantidadStr(Entrega* this,char* resultado)
{
    int retorno = -1;
    int bufferInt; // para no usar el operador flecha
    if(this != NULL && resultado != NULL)
    {

        entrega_getCantidad(this, &bufferInt);
        sprintf(resultado, "%d", bufferInt);
        retorno = 0;
    }
    return retorno;
}



/** \brief Valida el elemento importe del entrega y lo carga en la estructura Entrega.
 *
 * \param this Entrega* puntero al entrega.
 * \param importe char* importe del entrega.
 * \return int retorno -1 si no pudo validar el importe.
 *                      0 si pudo validar y cargar el importe.
 *
 */
int entrega_setImporteStr(Entrega* this,char* importe)
{
    int retorno = -1;
    if(this != NULL && importe != NULL && !validFloat(importe))//Validar que lo que recibe es un numero.
    {
        retorno = entrega_setImporte(this,atof(importe));
    }
    return retorno;
}

/** \brief Obtiene el cantidad de tipo string de un entrega.
 *
 * \param this Entrega* puntero a entrega.
 * \param resultado char* cantidad de entrega
 * \return int retorno -1 si this es NULL o cantidad es NULL,
 *                      0 si se obtuvo el cantidad.
 *
 */
int entrega_getImporteStr(Entrega* this,char* resultado)
{
    int retorno = -1;
    float bufferFloat; // para no usar el operador flecha
    if(this != NULL && resultado != NULL)
    {
        entrega_getImporte(this, &bufferFloat);
        sprintf(resultado, "%f", bufferFloat);
        retorno = 0;
    }
    return retorno;
}


/** \brief Compara entre dos nombres de la lista de entrega.
 *
 * \param this1 void* primer entrega.
 * \param this2 void* segundo entrega
 * \return int retorno: -1 si el segundo nombre es el mayor,
 *                       1 si el primer nombre es el mayor,
 *                       0 si son iguales.
 *
 */
/*
int entrega_compararPorNombre(void* this1, void* this2)
{
    char auxNombreA[4096];
    char auxNombreB[4096];

    entrega_getNombre((Entrega*)this1, auxNombreA);
    entrega_getNombre((Entrega*)this2, auxNombreB);


    if(strcmp(auxNombreA, auxNombreB) > 0)
    {
        return 1;
    }
    if(strcmp(auxNombreA, auxNombreB) < 0)
    {
        return -1;
    }
    return 0;
}
*/
/** \brief Recorre la lista de entrega, busca el id maximo y lo incrementa en uno al retornarlo
 *
 * \param LinkedList* pArrayEntrega puntero al array de entrega.
 * \return retunr el id maximo incrementado en uno.
 *
 */
int entrega_lastId(LinkedList* pArrayListEntrega)
{
    int IdAux;
    int IdMax;
    Entrega* pEntrega;

    if(pArrayListEntrega != NULL)
    {
        for(int i=0 ; i<ll_len(pArrayListEntrega); i++)
        {
            pEntrega = ll_get(pArrayListEntrega, i);
            //entrega_getId(pEntrega, &IdAux);
            if(pEntrega != NULL)
            {
                entrega_getId(pEntrega, &IdAux);
                //printf("%d-", IdAux);
                if(IdAux > IdMax)
                {
                    IdMax = IdAux;
                }
                else
                {
                    continue;
                }
            }
        }
    }
    return IdMax+1;
}

/** \brief busca la posicion en la que se encuentra un ID que solicita al usuario.
*
* \param LinkedList* pArrayEntrega puntero al array de entrega.
* \param posicionId int* puntero al ID a buscar.
* \return int retorno -1 si pArrayEntrega NULL, si pEntrega es NULL, o el ID a buscar no existe en la lista.
*                      0 si encontro el ID buscado, y como parametro por referencia la posicion del mismo.
*
*/
int Entrega_findById(LinkedList* pArrayListEntrega, int *posicionId, int id)
{
    int ret = -1;
    int idAux;
    Entrega *pEntrega = NULL;

    if(pArrayListEntrega != NULL && posicionId >= 0 && id >= 0)
    {
        for(int i = 0; i < ll_len(pArrayListEntrega); i++)
        {
            pEntrega = ll_get(pArrayListEntrega, i);
            if(pEntrega != NULL)
            {
                entrega_getId(pEntrega, &idAux);
                if(id == idAux)
                {
                    *posicionId = i;
                    ret = 0;
                }
            }
        }
    }
    return ret;
}

int entrega_regularTipo (void* this)
{
    int ret = 0;
    char auxEntrega[50];

    if(this!= NULL)
    {
        entrega_getTipo((Entrega*)this, auxEntrega);
        if(!strcmp("REGULAR", auxEntrega))
        {
            ret=1;
        }

    }
    return ret;
}

int entrega_plusTipo (void* this)
{
    int ret = 0;
    char auxEntrega[50];

    if(this!= NULL)
    {
        entrega_getTipo((Entrega*)this, auxEntrega);
        if(!strcmp("PLUS", auxEntrega))
        {
            ret=1;
        }
    }
    return ret;
}

int entrega_goldTipo (void* this)
{
    int ret = 0;
    char auxEntrega[50];

    if(this!= NULL)
    {
        entrega_getTipo((Entrega*)this, auxEntrega);
        if(!strcmp("GOLD", auxEntrega))
        {
            ret=1;
        }

    }
    return ret;
}

int entrega_cantidadBultos (LinkedList* pArrayListEntrega, int* bultosTotales)
{
    int ret = -1;
    int i = 0;
    Entrega* pAuxEntrega;
    int auxBultos;
    int sumadorBultos = 0;

    if(pArrayListEntrega != NULL)
    {
        for(i=0; i<=ll_len(pArrayListEntrega); i++)
        {
            pAuxEntrega = ll_get(pArrayListEntrega, i);
            if(pAuxEntrega != NULL)
            {
                if(!entrega_getCantidad(pAuxEntrega, &auxBultos))
                {
                    sumadorBultos += auxBultos;
                    ret = 0;
                }
            }
        }
        *bultosTotales = sumadorBultos;
    }
    return ret;
}

int entrega_importeTotal (LinkedList* pArrayListEntrega, float* importeTotalEntregas)
{
    int ret = -1;
    int i = 0;
    Entrega* pAuxEntrega;
    float auxImporte;
    float sumadorImporte = 0;

    if(pArrayListEntrega != NULL)
    {
        for(i=0; i<=ll_len(pArrayListEntrega); i++)
        {
            pAuxEntrega = ll_get(pArrayListEntrega, i);
            if(pAuxEntrega != NULL)
            {
                if(!entrega_getImporte(pAuxEntrega, &auxImporte))
                {
                    sumadorImporte += auxImporte;
                    ret = 0;
                }
            }
        }
        *importeTotalEntregas = sumadorImporte;
    }
    return ret;
}


