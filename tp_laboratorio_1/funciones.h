#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

int getFloat(
    char *mensaje,
    char *mensajeError,
    float minimo,
    float maximo,
    int reintentos,
    float *resultado);

int isValidFloat(float numero, float maximo, float minimo);

float sumador(float primerTermino, float segundoTermino);
float restador(float primerTermino, float segundoTermino);
float dividir(float dividendo, float divisor, char *mensajeError);
float multiplicador(float primerTermino, float segundoTermino);
int calculaFactorial(int valor,long int *factorial, char *mensajeError);

#endif // FUNCIONES_H_INCLUDED
