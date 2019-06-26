#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controller.h"
#include "entregas.h"
#include "parser.h"

int main()
{
    LinkedList* listaEntregas = ll_newLinkedList();

    //char seguir='s'; //MENU
    //int opcion; //MENU
    //int flag = 0;

    controller_loadFromText("data.csv", listaEntregas);

    controller_ListEntregas(listaEntregas);

    return 0;

    /*while (seguir=='s')
    {
        printf("\n\t\t MENU DE INFORMES DE VENTAS");
        printf("\n1- Cantidad total de entregas.");// 1000
        printf("\n2- Cantidad de entregas por tipo.");// 364 (gold) 325(regular) 311(plus)
        printf("\n3- Cantidad total de bultos entregados.");//
        printf("\n4- Promedio de bultos por entrega.");//
        printf("\n5- Importe promedio por entrega.");//

        printf("\n\n6-SALIR\n");

        do
        {
            printf("\n\t\tingrese opcion: ");
            scanf("\n%d",&opcion);
            system("cls"); //limpia la pantalla en windows
            //system("clear"); //limpia pantalla en linux
            //buffer[strlen(buffer)-1]= "\0" saca el enter que se toma como caracter

        }
        while (opcion<1 || opcion>6);

        switch (opcion)
        {
        case 1:

            break;

        case 2:

            break;

        case 3:

            break;

        case 4:

            break;

        case 5:

            break;

        case 6:
            seguir='n';
            break;
        }
    }
    return 0;*/
}
