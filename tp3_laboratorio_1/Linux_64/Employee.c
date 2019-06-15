#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"

Employee* employee_new()
{
    return (Employee*) malloc(sizeof(Employee));
}

void employee_delete(Employee *this)
{

    if(this != NULL)
    {
        free(this);
    }
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo)
{
    Employee* pEmployee=employee_new();
    void *retorno = NULL;
    if( pEmployee!=NULL &&
        idStr != NULL &&
        nombreStr != NULL &&
        horasTrabajadasStr != NULL &&
        sueldo != NULL)
    {
        if( !employee_setIdString(pEmployee, idStr)&&
            !employee_setNombre(pEmployee,nombreStr)&&
            !employee_setHorasTrabajadasStr(pEmployee,horasTrabajadasStr)&&
            !employee_setSueldoStr(pEmployee,sueldo))
            {
                retorno = pEmployee;
            }
            else
            {
                employee_delete(pEmployee);
            }
    }
    return retorno;
}

Employee* employee_newParametrosInt(int id, char* nombreStr,int horasTrabajadas, int sueldo)
{
    void *retorno = NULL;
    Employee* pEmployee = employee_new();
    if( pEmployee!=NULL &&
        id > 0 &&
        nombreStr != NULL &&
        horasTrabajadas > 0 &&
        sueldo > 0)
    {
        if( !employee_setId(pEmployee, id) &&
            !employee_setNombre(pEmployee,nombreStr) &&
            !employee_setHorasTrabajadas(pEmployee,horasTrabajadas) &&
            !employee_setSueldo(pEmployee,sueldo))
        {
            retorno = pEmployee;
        }
        else
        {
            employee_delete(pEmployee);
        }
    }
    return retorno;
}

int employee_setId(Employee* this,int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

int employee_getId(Employee* this,int* id)
{
    int retorno = -1;
    if(this != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL && isLetter(nombre))
    {
        strncpy(this->nombre,nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(nombre,this->nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas >= 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo >= 0)
    {
        this->sueldo = sueldo;
        retorno = 0;
    }
    return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = -1;
    if(this != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 0;
    }
    return retorno;
}

int employee_setIdString(Employee* this, char* idStr)
{
    int retorno = -1;
    if(this != NULL && idStr != NULL)
        if(isValidNumber(idStr))
        {
            retorno = employee_setId(this,atoi(idStr));
        }
    return retorno;
}
int employee_getIdString(Employee* this, char* result)
{
    int retorno = -1;
    int bufferInt;

    if(this != NULL && result != NULL)
    {
        employee_getId(this,&bufferInt);
        sprintf(result,"%d",bufferInt);
        retorno = 0;
    }
    return retorno;
}

int employee_setHorasTrabajadasStr(Employee* this,char* horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas != NULL && (isValidNumber(horasTrabajadas)))
    {

        retorno = employee_setHorasTrabajadas(this,atoi(horasTrabajadas));///si salio bien retorna 0 sino -1
    }
    return retorno;
}

int employee_getHorasTrabajadasStr(Employee* this,char* result)
{
    int retorno = -1;
    int bufferInt;

    if(this != NULL && result != NULL)
    {
        employee_getHorasTrabajadas(this,&bufferInt);
        sprintf(result,"%d",bufferInt);
        retorno = 0;
    }
    return retorno;
}

int employee_setSueldoStr(Employee* this,char *sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo != NULL && (isValidNumber(sueldo)))
    {

        retorno = employee_setSueldo(this,atoi(sueldo));///si salio bien retorna 0 sino -1
    }
    return retorno;
}
int employee_getSueldoStr(Employee* this,char* result)
{
    int retorno = -1;
    int bufferInt;

    if(this != NULL && result != NULL)
    {
        employee_getSueldo(this,&bufferInt);
        sprintf(result,"%d",bufferInt);
        retorno = 0;
    }
    return retorno;
}
int findEmployeeById(LinkedList* pArrayListEmployee, int id, int *posicionId)
{
    int retorno = -1;
    int i;
    int idAux;
    Employee *pEmployee;
    if(pArrayListEmployee != NULL && id > 0 && posicionId > 0)
    {
        for(i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            pEmployee = ll_get(pArrayListEmployee, i);
            if(pEmployee != NULL)
            {
                employee_getId(pEmployee, &idAux);
                if(id == idAux)
                {
                    *posicionId = i;
                    retorno = 0;
                }
            }
        }
    }
    return retorno;
}

int employee_compare(void* this1, void* this2)
{
    int retorno;
    int auxCmp;
    char nombreUno[1000];
    char nombreDos[1000];
    if( !employee_getNombre((Employee*)this1,nombreUno)&&
        !employee_getNombre((Employee*)this2,nombreDos))
        {
            auxCmp = strcmp(nombreUno,nombreDos);
            if(auxCmp < 0)
            {
                retorno = -1;
            }
            if(!auxCmp)
            {
                retorno = 0;
            }
            if(auxCmp > 0)
            {
                retorno = 1;
            }
        }
    return retorno;
}
