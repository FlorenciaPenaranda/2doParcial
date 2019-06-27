#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controller.h"
#include "entregas.h"
#include "parser.h"

int main()
{
    LinkedList* listaEntregas = ll_newLinkedList();



    controller_loadFromText("data.csv", listaEntregas);



    controller_saveAsText("entregas.csv", listaEntregas);





    return 0;
}
