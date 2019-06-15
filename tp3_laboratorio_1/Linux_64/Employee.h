#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo);
Employee* employee_newParametrosInt(int id, char* nombreStr,int horasTrabajadas, int sueldo);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);
int employee_setIdString(Employee* this, char* idStr);
int employee_getIdString(Employee* this, char* result);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
int employee_setHorasTrabajadasStr(Employee* this,char* horasTrabajadas);
int employee_getHorasTrabajadasStr(Employee* this,char* result);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);
int employee_setSueldoStr(Employee* this,char *sueldo);
int employee_getSueldoStr(Employee* this,char* result);

int findEmployeeById(LinkedList* pArrayListEmployee, int id, int *posicionId);
int employee_compare(void* this1, void* this2);

#endif // employee_H_INCLUDED
