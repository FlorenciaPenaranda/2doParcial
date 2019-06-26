#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "entregas.h"

/** \brief Parsea los datos de las entregas desde el archivo (modo texto).
 *
 * \param pFile FILE* puntero a archivo.
 * \param pArrayListEntrega LinkedList* puntero al array de entregas.
* \return int ret -1 si el puntero pFile es NULL o el puntero pArrayListEntrega es NULL,
                   0 si logro parsear el archivo.
 *
 */
int parser_EntregaFromText(FILE* pFile, LinkedList* pArrayListEntrega)
{
    int ret = -1;
    char bufferId[400];
    char bufferTipo[400];
    char BufferCantidad[400];
    char bufferImporte[400];
    Entrega *pAuxEntrega;

    if(pFile != NULL && pArrayListEntrega != NULL)
    {
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferTipo,BufferCantidad,bufferImporte);
            pAuxEntrega = entrega_newParametros(bufferId,bufferTipo,BufferCantidad,bufferImporte);
            if(pAuxEntrega != NULL)
            {
                ll_add(pArrayListEntrega, pAuxEntrega);
                ret = 0;
            }
        }
        fclose(pFile);
    }
    return ret;
}

