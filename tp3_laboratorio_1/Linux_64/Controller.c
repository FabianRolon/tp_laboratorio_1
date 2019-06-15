#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"
#include "utn.h"
#define MAX_EMPLOYEE 9999
#define MAX 1000
#define ASCENDENTE 1
#define DESCENDENTE 0


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    FILE* pFile;
    pFile = NULL;
    pFile = fopen(path,"r");

    if(pFile!=NULL)
    {
        if(path != NULL && pArrayListEmployee != NULL)
        {
             if(!parser_EmployeeFromText(pFile , pArrayListEmployee))
             {
                printf("\nCarga exitosa\n");
                fclose(pFile);
                retorno = 0;
             }
        }
     }
     return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pFile;
    pFile = NULL;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "rb");
        if(!parser_EmployeeFromBinary(pFile ,pArrayListEmployee))
        {
            printf("Carga exitosa\n");
            retorno = 0;
        }
    }
     return retorno;
}


/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int idAux;
    char bufferId[MAX];
    char bufferNombre[MAX];
    char bufferHorasTrabajadas[MAX];
    char bufferSueldo[MAX];
    Employee *bufferEmp;
    idAux = controller_nextId(pArrayListEmployee);
    snprintf(bufferId,MAX, "%d", idAux);

    if (pArrayListEmployee != NULL)
        {
            if( utn_getName("\n\nIngrese el nombre del empleado: ",
                "Error, vuelva a ingresar\n\n",1,50,2,
                bufferNombre) == 0 &&
                utn_getAlfanumerico("\n\nIngrese las horas trabajadas: ",
                "Error, vuelva a ingresar\n\n",1,51,2,
                bufferHorasTrabajadas) == 0 &&
                utn_getAlfanumerico("\n\nIngrese el sueldo: ",
                "Error, vuelva a ingresar\n\n",1,51,2,bufferSueldo) == 0)
            {
                bufferEmp = employee_newParametros(bufferId,
                                                   bufferNombre,
                                                   bufferHorasTrabajadas,
                                                   bufferSueldo);
                ll_add(pArrayListEmployee, bufferEmp);
                printf("Exito, empleado agregado!\n");
                retorno = 0;
            }else
            {
                printf("ERROR, reintentos agotados!\n");
                retorno = -2;
            }
        }else
        {
            printf("ERROR, NULL\n");
        }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int opcion;
    int idIngresado;
    int posicionId;
    int auxId;
    char bufferId[MAX];
    char auxNombre[MAX];
    char bufferHorasTrabajadas[MAX];
    char bufferSueldo[MAX];
    int auxHoras;
    int auxSueldo;
    char seguir = 's';
    Employee *pEmployee;
    if(pArrayListEmployee != NULL)
    {
        if(!utn_getUnsignedInt("\nIngrese el ID de empleado a modificar: ",
            "\nError, ID inválido.",1,MAX_EMPLOYEE, 2, &idIngresado))
        {
            if( !findEmployeeById(  pArrayListEmployee,
                                    idIngresado,
                                    &posicionId))
                    {
                        pEmployee = ll_get(pArrayListEmployee, posicionId);
                        if(pEmployee != NULL)
                        {
                            if( !employee_getId(pEmployee, &auxId)&&
                                !employee_getNombre(pEmployee, auxNombre)&&
                                !employee_getHorasTrabajadas(pEmployee, &auxHoras)&&
                                !employee_getSueldo(pEmployee, &auxSueldo))
                                {
                                    printf("\n\nLos datos del empleado son:\n\n");
                                    printf("Nombre : %s Id: %d Horas: %d Sueldo: %d\n",
                                           auxNombre,
                                           auxId,
                                           auxHoras,
                                           auxSueldo );
                                }
                        }
                    }
                    snprintf(bufferHorasTrabajadas,MAX, "%d", auxHoras);
                    snprintf(bufferSueldo, MAX, "%d", auxSueldo);
            while(seguir == 's')
            {
                printf("Elija el dato que desea modificar\n\n");

                printf("\n\n1-Nombre");
                printf("\n\n2-Horas trabajadas");
                printf("\n\n3-Sueldo");
                printf("\n\n4-Salir de la modificacion");

                utn_getUnsignedInt("\n\t\tIngrese opcion: ", "Ingreso incorrecto\n", 1, 4, 2, &opcion);


                switch(opcion)
                {
                    case 1:
                        if (!utn_getName("\n\nIngrese el nombre del empleado: ",
                            "Error, vuelva a ingresar\n\n",1,50,2,
                            auxNombre))
                        {
                            printf("El dato fue modificado con exito.\n\n");
                        }
                        break;
                    case 2:
                        if (!utn_getAlfanumerico("\n\nIngrese las horas trabajadas: ",
                            "Error, vuelva a ingresar\n\n",1,51,2,
                            bufferHorasTrabajadas))
                        {
                            printf("El dato fue modificado con exito.\n\n");
                        }
                        break;

                    case 3:
                         if (   !utn_getAlfanumerico("\n\nIngrese el sueldo: ",
                                "Error, vuelva a ingresar\n\n",1,51,2,bufferSueldo))
                            {
                                printf("El dato fue modificado con exito.\n\n");
                            }

                        break;

                    case 4:
                        snprintf(bufferId,MAX, "%d", auxId);
                        pEmployee = employee_newParametros( bufferId,
                                                            auxNombre,
                                                            bufferHorasTrabajadas,
                                                            bufferSueldo);
                        if(pEmployee != NULL)
                            ll_set(pArrayListEmployee, posicionId, pEmployee);
                        seguir = 'n';
                        retorno = 0;
                        break;
                }
            }
        }
    }
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int idIngresado;
    int posicionId;
    Employee *pEmployee;
    if (pArrayListEmployee != NULL)
    {
        if( !utn_getUnsignedInt("\nIngrese el ID de empleado a dar de baja: ",
            "\nError, ID inválido.",1,MAX_EMPLOYEE, 2, &idIngresado))
            {
                if( !findEmployeeById(pArrayListEmployee,
                    idIngresado,
                    &posicionId))
                    {
                        pEmployee = ll_pop(pArrayListEmployee, posicionId);
                        if(pEmployee != NULL)
                        {
                            employee_delete(pEmployee);
                            printf("\n¡Empleado borrado exitosamente!\n\n");
                            retorno = 0;
                        }
                    }
                    else
                    {
                        printf("\nNo se encontró el ID\n\n");
                        retorno = -2;
                    }
            }
            else
            {
                printf("\nReintentos agotados\n\n");
                retorno = -3;
            }
    }

    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    char option = 'n';
    char option2 = 'n';
    int pagina = 99;
    Employee *empleado;
    char bufferNombre[1000];
    int bufferId, bufferSueldo, bufferHoras;

    do
    {
        for(i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            empleado = (Employee*)ll_get(pArrayListEmployee, i);
            employee_getNombre(empleado, bufferNombre);
            employee_getId(empleado, &bufferId);
            employee_getHorasTrabajadas(empleado,&bufferHoras);
            employee_getSueldo(empleado, &bufferSueldo);
            printf("Nombre : %s Id: %d Horas: %d Sueldo: %d\n",
                   bufferNombre,
                   bufferId,
                   bufferHoras,
                   bufferSueldo );
            if(i == pagina)
            {
                do
                {
                    utn_getChar("\n\tPresione 's' para siguiente pagina: ",
                    "Error, vuelva a intentar",1,2,2,&option2);
                    pagina+=99;
                    system("clear");
                }while(option2 == 'n');
            }
        }
        utn_getChar("\n\tPresione 's' para volver al menu principal: ",
                    "Error, vuelva a intentar",1,2,2,&option);
    }while(option == 'n');
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(pArrayListEmployee != NULL)
    {
        ll_sort(pArrayListEmployee, employee_compare, ASCENDENTE);
        retorno = 0;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv(modo texto)
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int bufferId;
    int bufferHorasTrabajadas;
    int bufferSueldo;
    char bufferIdStr[MAX];
    char bufferNombre[MAX];
    char bufferHorasTrabajadasStr[MAX];
    char bufferSueldoStr[MAX];
    FILE* pFile = NULL;
    Employee *pEmployee = NULL;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "w");
        if(pFile != NULL)
        {
          //  fprintf (pFile, "id,nombre,horasTrabajadas,sueldo\n");
            for(int i =0 ; i<ll_len(pArrayListEmployee) ; i++)
            {
                pEmployee = (Employee*)ll_get(pArrayListEmployee, i);
                if(pEmployee != NULL)
                {
                    if( !employee_getNombre(pEmployee, bufferNombre)&&
                        !employee_getId(pEmployee, &bufferId)&&
                        !employee_getHorasTrabajadas(pEmployee,
                                                     &bufferHorasTrabajadas)&&
                        !employee_getSueldo(pEmployee, &bufferSueldo))
                        {
                            snprintf(bufferIdStr,MAX, "%d", bufferId);
                            snprintf(bufferHorasTrabajadasStr,MAX, "%d",
                                     bufferHorasTrabajadas);
                            snprintf(bufferSueldoStr,MAX, "%d", bufferSueldo);
                            fprintf (pFile, "%s,%s,%s,%s\n",
                                     bufferIdStr,
                                     bufferNombre,
                                     bufferHorasTrabajadasStr,
                                     bufferSueldoStr);

                        }else{printf("Error al guardar\n");}
                }else{printf("Error al guardar\n");}

            }
            fclose(pFile);
            printf("Se ha guardado correctamente\n");
            retorno = 0;
        }else{printf("Error al guardar\n");}
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pFile = NULL;
    Employee * pEmployee = NULL;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "wb");
        if(pFile != NULL)
        {
            for(int i =0 ; i<ll_len(pArrayListEmployee) ; i++)
            {
                pEmployee = ll_get(pArrayListEmployee, i);
                if(pEmployee != NULL)
                    fwrite(pEmployee, sizeof(Employee), 1, pFile);
            }
            fclose(pFile);
            printf("Guardado con exito\n");
            retorno = 0;
        }
    }
    return retorno;
}


int controller_nextId(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    int idAux;
    int idMax;
    Employee *pEmployee;
    if(pArrayListEmployee != NULL)
    {
        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            pEmployee = (Employee*)ll_get(pArrayListEmployee, i);
            if(i == 0)
            {
                employee_getId(pEmployee, &idMax);
            }
            else
            {
                employee_getId(pEmployee, &idAux);
                if(idAux > idMax)
                {
                    idMax = idAux;
                }
            }
        }
        retorno = idMax+1;
    }
    return retorno;
}
void Controller_printMenu()
{
    printf("\t\t*MENU*");
    printf("\n\n1-Cargar los datos de los empleados desde el archivo data.csv (modo texto).");
    printf("\n\n2-Cargar los datos de los empleados desde el archivo data.bin (modo binario)");
    printf("\n\n3-Alta de empleado");
    printf("\n\n4-Modificar datos de empleado");
    printf("\n\n5-Baja de empleado");
    printf("\n\n6-Listar empleados");
    printf("\n\n7-Ordenar empleados");
    printf("\n\n8-Guardar los datos de los empleados en el archivo data.csv (modo texto)");
    printf("\n\n9-Guardar los datos de los empleados en el archivo data.bin (modo binario)");
    printf("\n\n10-Salir\n");
}
