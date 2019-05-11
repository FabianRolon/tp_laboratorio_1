#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utn.h"
#include "ArrayEmployees.h"

#define TAMANO_STRING 51


/** \brief  To indicate that all position in the array are empty,
 *          this function put the flag (isEmpty) in TRUE in all
 *          position of the array
 * \param arrayEmployee Employee* Pointer to array of employees
 * \param cantidad int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee *arrayEmployee, int cantidad)
{
    int retorno = -1;
    int i;

    for (i = 0; i < cantidad; i++)
    {
        arrayEmployee[i].isEmpty = 1;
        retorno=0;
    }

    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int findEmployeeById(Employee array[], int size, int valorBuscado, int* posicion)                    //cambiar fantasma
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idEmployee==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca el primer lugar vacio en un array
* \param array employee Array de employee
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int emp_buscarEmpty(Employee array[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief add in a existing arrayEmployee of employees the values received as parameters
 *     in the first empty position
 * \param array employee Array de employee
 * \param size int
 * \param id int
 * \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 */
  int addEmployee(Employee *arrayEmployee, int cantidad, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(arrayEmployee!=NULL && cantidad>0 && contadorID!=NULL)
    {
        if(emp_buscarEmpty(arrayEmployee,cantidad,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {

            arrayEmployee[posicion].idEmployee=*contadorID;
            arrayEmployee[posicion].isEmpty=0;
            utn_getName("\nIngrese el nombre: ","\nError",1,TAMANO_STRING,1,arrayEmployee[posicion].name);
            utn_getName("\nIngrese el apellido: ","\nError",1,TAMANO_STRING,1,arrayEmployee[posicion].lastName);
            utn_getFloat("\nIngrese el salario: ","\nError",1,sizeof(float),0,1,1,&arrayEmployee[posicion].salary);
            utn_getUnsignedInt("\nIngrese el sector: ","\nError",1,sizeof(int),1,10,1,&arrayEmployee[posicion].sector);
            printf("\n Posicion: %d\n ID: %d\n Sector: %d\n Salario: %f\n Nombre: %s\n Apellido: %s",
                   posicion, arrayEmployee[posicion].idEmployee,arrayEmployee[posicion].sector,arrayEmployee[posicion].salary,arrayEmployee[posicion].name,arrayEmployee[posicion].lastName);
            (*contadorID)++;
            retorno=0;
        }
    }
    return retorno;
}

/*****************************************
/ ** \brief Borra un elemento del array por ID
* \param array employee Array de employee
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int removeEmployee(Employee *arrayEmployee, int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    if(arrayEmployee!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(findEmployeeById(arrayEmployee,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            arrayEmployee[posicion].isEmpty=2;
            retorno=0;
        }
    }
    return retorno;
}


/** \brief Busca un elemento por ID y modifica sus campos
* \param array employee Array de employee
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int modifyEmployee(Employee *arrayEmployee, int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    int opcion;
    if(arrayEmployee!=NULL && sizeArray>0)
    {
        printEmployees(arrayEmployee, sizeArray);
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(findEmployeeById(arrayEmployee,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {
                printf("\n Posicion: %d\n ID: %d\n Sector: %d\n Salario: %f\n Nombre: %s\n Apellido: %s",
                   posicion, arrayEmployee[posicion].idEmployee,arrayEmployee[posicion].sector,arrayEmployee[posicion].salary,arrayEmployee[posicion].name,arrayEmployee[posicion].lastName);
                utn_getUnsignedInt("\n\nModificar: \n\n1-Sector \n2-Salario \n3-Nombre \n4-Apellido \n5-Salir y volver al menu anterior\n","\nError",1,5,1,5,2,&opcion);
                switch(opcion)
                {
                    case 1:
                        utn_getUnsignedInt("\nIngrese el sector: ","\nError",1,sizeof(int),1,10,1,&arrayEmployee[posicion].sector);
                        break;
                    case 2:
                        utn_getFloat("\nIngrese el salario: ","\nError",1,sizeof(float),0,1,1,&arrayEmployee[posicion].salary);
                        break;
                    case 3:
                        utn_getName("\nIngrese el nombre: ","\nError",1,TAMANO_STRING,1,arrayEmployee[posicion].name);
                        break;
                    case 4:
                        utn_getName("\nIngrese el apellido: ","\nError",1,TAMANO_STRING,1,arrayEmployee[posicion].lastName);
                        break;
                    case 5:
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion != 5);
            retorno=0;
        }
    }
    return retorno;
}

/** \brief Ordena por campo XXXXX los elementos de un array ante la igualdad de estos ordena por el campo ZZZZZZ
* \param array employee Array de employee
* \param size int Tamaño del array
* \param orderFirst int Determina si el orden del primer criterio es ascendete o descendente
* \param orderSecond int Determina si el orden del segunbdo criterio es ascendete o descendente
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int sortEmployees(Employee *arrayEmployee,int size, int orderFirst, int orderSecond)                              //cambiar employee
{
    int retorno=-1;
    int i;
    Employee buffer;
    int flagSwap;

    if(arrayEmployee!=NULL && size>=0)
    {
        do
        {
            flagSwap=0;
            for (i = 1; i < size-1; i++)
            {
                if( ((strcmp(arrayEmployee[i].lastName,arrayEmployee[i+1].lastName) < 0) && orderFirst) ||
                    ((strcmp(arrayEmployee[i].lastName,arrayEmployee[i+1].lastName) > 0) && !orderFirst) )
                {
                    flagSwap=1;
                    buffer = arrayEmployee[i];
                    arrayEmployee[i] = arrayEmployee[i+1];
                    arrayEmployee[i+1] = buffer;
                }
                else if(strcmp(arrayEmployee[i].lastName,arrayEmployee[i+1].lastName) == 0)
                {
                    if( ((arrayEmployee[i].sector < arrayEmployee[i+1].sector) && orderSecond) ||
                        ((arrayEmployee[i].sector > arrayEmployee[i+1].sector) && !orderSecond) )
                    {
                        flagSwap=1;
                        buffer = arrayEmployee[i];
                        arrayEmployee[i] = arrayEmployee[i+1];
                        arrayEmployee[i+1] = buffer;
                    }
                }
            }
        }while(flagSwap);
        retorno=0;
    }
    return retorno;
}

/** \brief Lista los elementos de un array
* \param array employee Array de employee
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se arrayEmployeea exitosamente
*
*/
int printEmployees(Employee array[], int size)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
                printf("\n Posicion: %d\n ID: %d\n Sector: %d\n Salario: %f\n Nombre: %s\n Apellido: %s\n\n",
                   i, array[i].idEmployee,array[i].sector,array[i].salary,array[i].name,array[i].lastName);
        }
        retorno=0;
    }
    return retorno;
}

int emp_isValidNotEmpty(Employee array[], int size)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==0)
            {
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

int promedioSalario(Employee *arrayEmployee, int size, float *cantidadSalarios, float *suma)
{
    int retorno = -1;
    int i;
    int sumador = 0;
    int contador = 0;
    for(i = 0;i < size;i++)
    {
        if(arrayEmployee[i].isEmpty == 0)
        {
            sumador += arrayEmployee[i].salary;
            contador++;
        }
    }
    return retorno;
}
