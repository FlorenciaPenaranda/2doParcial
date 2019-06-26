#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "entregas.h"
#include "parser.h"
#include "utn.h"

/** \brief Carga los datos de las entregas desde el archivo data (modo texto).
 *
 * \param path char* puntero al archivo a cargar
 * \param pArrayListEntregas LinkedList* puntero al array de empleados.
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
        printf("Parametros Validos\n");
        pFileAux = fopen("data.csv", "r");
        if(pFileAux != NULL)
        {
            printf("Archivo abierto");
            if(!parser_EntregaFromText(pFileAux, pArrayListEntregas))
            {
                ret = 0;
            }
        }else
            printf("Archivo no abierto");
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
                printf("ID:%s, TIPO: %s, CANTIDAD: %d, IMPORTE: %.2f\n", bufferId, bufferTipo, bufferCantidad, bufferImporte);
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
    Entrega * pEntrega = NULL;
    char bufferId[400];
    char bufferTipo[400];
    char bufferCantidad[400];
    char bufferImporte[400];

    if(path != NULL && pArrayListEntregas != NULL)
    {
        pFileAux = fopen(path, "w");
        if(pFileAux != NULL)
        {
            for(int i =0; i<ll_len(pArrayListEntregas); i++)
            {
                pEntrega = ll_get(pArrayListEntregas, i);
                if(!entrega_getIdStr(pEntrega, bufferId) &&
                        !entrega_getTipo(pEntrega,bufferTipo) &&
                        !entrega_getCantidadStr(pEntrega, bufferCantidad) &&
                        !entrega_getImporteStr(pEntrega, bufferImporte))
                {
                    fprintf(pFileAux, "%s, %s, %s, %s\n", bufferId,bufferTipo,bufferCantidad,bufferImporte);
                    ret = 0;
                }
                else
                {
                    entrega_delete(pEntrega);
                }
            }
        }
        fclose(pFileAux);
    }
    return ret;
}
