#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "ArrayEmployees.h"
#include <math.h>


#define QTY_ARRAY_EMPLOYEE 10
#define SORT_UP 1
#define SORT_DOWN 0

int main()
{
    int opcion;
    int opcionInforme;
    int contadorIdEmployee=1;
    int value;
    float cantidadSalary;
    float sumaSalary;
    float promedioSalary;
    promedioSalary = sumaSalary/cantidadSalary;

    Employee arrayEmployee[QTY_ARRAY_EMPLOYEE];
    value = initEmployees(arrayEmployee,QTY_ARRAY_EMPLOYEE);

    if(value == 0)
    {
        printf("Entidad inicializada correctamente");
    }
    else
    {
        printf("Ocurrio un error al inicializar");
    }

    //*******************************************************************
    arrayEmployee[0].idEmployee=1;
    arrayEmployee[0].isEmpty=0;
    arrayEmployee[0].sector=1;
    arrayEmployee[0].salary=123;
    strcpy(arrayEmployee[0].lastName,"Sanchez");
    strcpy(arrayEmployee[0].name,"Gerardo");
    contadorIdEmployee++;

    arrayEmployee[1].idEmployee=2;
    arrayEmployee[1].isEmpty=0;
    arrayEmployee[1].sector=2;
    arrayEmployee[1].salary=321;
    strcpy(arrayEmployee[1].lastName,"Gomez");
    strcpy(arrayEmployee[1].name,"Ramiro");
    contadorIdEmployee++;

    arrayEmployee[2].idEmployee=3;
    arrayEmployee[2].isEmpty=0;
    arrayEmployee[2].sector=1;
    arrayEmployee[2].salary=220;
    strcpy(arrayEmployee[2].lastName,"Juarez");
    strcpy(arrayEmployee[2].name,"Felipe");
    contadorIdEmployee++;

    arrayEmployee[3].idEmployee=4;
    arrayEmployee[3].isEmpty=0;
    arrayEmployee[3].sector=3;
    arrayEmployee[3].salary=221;
    strcpy(arrayEmployee[3].lastName,"Rodriguez");
    strcpy(arrayEmployee[3].name,"Nicolas");
    contadorIdEmployee++;


    //********************************************************************

    do
    {
        utn_getUnsignedInt("\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar \n5) Informes \n6) Salir\n",                   //cambiar
                      "\nError",1,sizeof(int),1,11,1,&opcion);
        switch(opcion)
        {
            case 1:
                addEmployee(arrayEmployee,QTY_ARRAY_EMPLOYEE,&contadorIdEmployee);                   //cambiar
                break;

            case 2:
            if(emp_isValidNotEmpty(arrayEmployee,QTY_ARRAY_EMPLOYEE) == 0)
            {
                modifyEmployee(arrayEmployee,QTY_ARRAY_EMPLOYEE);
            }
            else
            {
                printf("\n\nNo se realizo ninguna Alta aun.");
            }
                break;

            case 3:
                if(emp_isValidNotEmpty(arrayEmployee,QTY_ARRAY_EMPLOYEE) == 0)
                {
                    removeEmployee(arrayEmployee,QTY_ARRAY_EMPLOYEE);
                }
                else
                {
                    printf("/n/nNo se realizo ninguna Alta aun.");
                }
                break;

            case 4:
                if(emp_isValidNotEmpty(arrayEmployee,QTY_ARRAY_EMPLOYEE) == 0)
                {
                    printEmployees(arrayEmployee,QTY_ARRAY_EMPLOYEE);
                }
                else
                {
                    printf("/n/nNo se realizo ninguna Alta aun.");
                }
                break;
            case 5:
                utn_getUnsignedInt("\n\n1) Listado de los empleados ordenados alfabéticamente por Apellido y Sector. \n2) Total y promedio de los salarios y cuantos superan el promedio \n3) Salir\n",                   //cambiar
                      "\nError",1,sizeof(int),1,4,1,&opcionInforme);

                switch(opcionInforme)
                {
                    case 1:
                        sortEmployees(arrayEmployee,QTY_ARRAY_EMPLOYEE,1,1);
                        printEmployees(arrayEmployee,QTY_ARRAY_EMPLOYEE);
                        break;
                    case 2:
                        promedioSalario(arrayEmployee, QTY_ARRAY_EMPLOYEE, &cantidadSalary, &sumaSalary);
                        printf("\n\nEl promedio de los salarios es: %f \n\nLa cantidad total es: %f", promedioSalary , sumaSalary);
                        break;
                }
                break;
            case 6:
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=6);
    return 0;
}
