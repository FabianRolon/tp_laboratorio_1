#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

int main()
{
    int option = 0;
    int flag = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
        Controller_printMenu();
        utn_getUnsignedInt( "\n\t\tIngrese opcion: ",
                            "Ingreso incorrecto\n",1,12,2,&option);
        system("clear");
        switch (option)
        {
        case 1:
            if(!controller_loadFromText("data.csv", listaEmpleados))
                flag = 1;
            break;
        case 2:
             if(!controller_loadFromBinary("data.bin", listaEmpleados))
                flag = 1;
            break;
        case 3:
                if(!controller_addEmployee(listaEmpleados))
                    flag = 1;
            break;
        case 4:
            if(flag)
            {
                controller_editEmployee(listaEmpleados);
            }else{printf("\nNo hay datos cargados para modificar");}
            break;
        case 5:
            if(flag)
            {
                controller_removeEmployee(listaEmpleados);
            }else{
                printf("\nNo hay datos cargados para dar de baja");}
            break;
        case 6:
            if(flag)
            {
                controller_ListEmployee(listaEmpleados);
            }else{printf("\nNo hay datos cargados para mostrar");}
            break;
        case 7:
            if(flag)
            {
                controller_sortEmployee(listaEmpleados);
                controller_ListEmployee(listaEmpleados);
            }else{printf("\nNo hay datos cargados para mostrar");}
            break;
        case 8:
            if(flag)
            {
                controller_saveAsText("data.csv" ,listaEmpleados);
            }else{
                printf("\nNo hay datos cargados para guardar");}
            break;
        case 9:
            if(flag)
            {
                controller_saveAsBinary("data.bin", listaEmpleados);
            }else{
                printf("\nNo hay datos cargados para guardar");}
            break;
        case 10:
            option = 10;
            break;
        }
    }while(option != 10);
    return 0;
}
