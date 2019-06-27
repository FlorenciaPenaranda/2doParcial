#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "entregas.h"
#include "parser.h"
#include "utn.h"

/** \brief Carga los datos de las entregas desde el archivo data (modo texto).
 *
 * \param path char* puntero al archivo a cargar
 * \param pArrayListEntregas LinkedList* puntero al array de entregas.
 * \return int ret -1 si el puntero path es NULL o el puntero pArrayListEntregas es NULL,
                    0 si logra cargar los datos.
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEntregas)
{
    int ret = -1;
    FILE* pFileAux = NULL;

    if(path != NULL && pArrayListEntregas != NULL)
    {
        pFileAux = fopen(path, "r");
        if(pFileAux != NULL)
        {
            if(!parser_EntregaFromText(pFileAux, pArrayListEntregas))
            {
                printf("\tCARGA EXITOSA!\n");
                ret = 0;
            }
        }
    }
    return ret;
}

/** \brief Listar entregas
 *
 * \param pArrayListEntregas LinkedList* puntero al array de entregas.
 * \return int ret -1 si no puede mostar toda la lista de los entregas,
                    0 si logra mostar toda la lista de los entregas.
 *
 */
int controller_ListEntregas(LinkedList* pArrayListEntregas)
{
    int ret = -1;
    Entrega * pEntrega = NULL;
    char bufferId[400];
    char bufferTipo[400];
    int bufferCantidad;
    float bufferImporte;

    for(int i=0; i<ll_len(pArrayListEntregas); i++)
    {
        pEntrega = ll_get(pArrayListEntregas, i);//guardar en un puntero a empleado
        if(pEntrega != NULL)
        {
            if(!entrega_getIdStr(pEntrega, bufferId) &&
                    !entrega_getTipo(pEntrega,bufferTipo) &&
                    !entrega_getCantidad(pEntrega, &bufferCantidad) &&
                    !entrega_getImporte(pEntrega, &bufferImporte))
            {
                printf("ID:%s TIPO: %s CANTIDAD: %d IMPORTE: %.2f\n", bufferId, bufferTipo, bufferCantidad, bufferImporte);
                ret = 0;
            }
        }

    }
    return ret;
}
/** \brief Guarda los datos de las entregas en el archivo informes.txt (modo texto).
 *
 * \param path char* puntero al archivo a guardar
 * \param pArrayListEntregas LinkedList* puntero al array de entregas.
 * \return int ret -1 si el puntero si no puede guardar los datos,
 *                  0 si logra guardar los datos.
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEntregas)
{
    int ret = -1;
    FILE* pFileAux = NULL;
    int cantidadTotaEntregas;
    LinkedList* entregasRegular = ll_newLinkedList();
    int cantidadRegulares;
    LinkedList* entregasPlus = ll_newLinkedList();
    int cantidadPlus;
    LinkedList* entregasGold = ll_newLinkedList();
    int cantidadGold;

    int cantidadBultosEntregados;
    float importeTotalEntregas;

    if(path != NULL && pArrayListEntregas != NULL)
    {
        pFileAux = fopen(path, "w");
        if(pFileAux != NULL)
        {
            cantidadTotaEntregas = ll_len(pArrayListEntregas);

            entregasRegular = ll_filter(pArrayListEntregas, entrega_regularTipo);
            cantidadRegulares = ll_len(entregasRegular);
            entregasPlus = ll_filter(pArrayListEntregas, entrega_plusTipo);
            cantidadPlus = ll_len(entregasPlus);
            entregasGold = ll_filter(pArrayListEntregas, entrega_goldTipo);
            cantidadGold = ll_len(entregasGold);

            //entrega_cantidadBultos(pArrayListEntregas, &cantidadBultosEntregados);
            entrega_importeTotal(pArrayListEntregas, &importeTotalEntregas);


            fprintf(pFileAux,"\t\tINFORME DE ENTREGASº\n\n");
            //fprintf(pFileAux, "%s, %s, %s, %s\n", bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
            fprintf(pFileAux,"- Cantidad total de entregas: %d\n", cantidadTotaEntregas );
            fprintf(pFileAux,"- Cantidad de entregas por tipo: %d (REGULAR) - %d (PLUS) - %d (GOLD) \n", cantidadRegulares, cantidadPlus, cantidadGold);
            if(! entrega_cantidadBultos(pArrayListEntregas, &cantidadBultosEntregados))
            {
                fprintf(pFileAux,"- Cantidad total de bultos entregados: %d\n", cantidadBultosEntregados);
            }
            fprintf(pFileAux,"- Promedio de bultos por entrega: %.2f\n", (float)cantidadBultosEntregados/cantidadTotaEntregas);
            fprintf(pFileAux,"- Importe promedio por entrega: %.2f  \n", (float)importeTotalEntregas/cantidadTotaEntregas);

        }
        fclose(pFileAux);
    }
    return ret;
}
