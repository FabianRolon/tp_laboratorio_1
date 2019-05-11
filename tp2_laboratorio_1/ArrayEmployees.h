#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
#define TAMANO_STRING 51

typedef struct
{
    int idEmployee;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;

int initEmployees(Employee* list, int len);
int emp_buscarEmpty(Employee array[], int size, int* posicion);
int findEmployeeById(Employee array[], int size, int valorBuscado, int* posicion);
int addEmployee(Employee array[], int size, int* contadorID);
int removeEmployee(Employee array[], int sizeArray);
int modifyEmployee(Employee *arrayEmployee, int sizeArray);
int sortEmployees(Employee array[],int size, int orderFirst, int orderSecond);
int printEmployees(Employee array[], int size);
int emp_isValidNotEmpty(Employee array[], int size);
int promedioSalario(Employee *arrayEmployee, int size, float *cantidadSalarios, float *suma);

#endif // ARRAYEMPLOYEES_H_INCLUDED
