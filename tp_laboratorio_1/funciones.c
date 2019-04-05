#include <stdio.h>
#include <stdlib.h>

/**
 * \brief Toma un numero y lo valida que no exceda los maximo y minimo ingresados
 * \param numero es el numero que toma
 * \param maximo es el limite mayor
 * \param minimo es el limite menor
 * \return 1 si sale bien y 0 si sale mal
 *
 */
int isValidFloat(float numero, float maximo, float minimo)
{
    if(numero >= minimo && numero <= maximo)
    {
        return 1;
    }
    return 0;
}


/**
 * \brief Solicita un numero al usuario y devuelve el resultado
 * \param mensaje es el mebsaje que muestra en pantalla
 * \param mensaje error es el mensaje que muestra en caso de error
 * \param minimo es el limite menor
 * \param maximo es el limite mayor
 * \param reintentos es el limite que se le da al usuario para intentar ingresar
 un numero valido
 * \param resultado devuelve el parametro por referencia
 * \return -1 si sale mal y 0 si sale bien
 *
 */
int getFloat(
char *mensaje,
char *mensajeError,
float minimo,
float maximo,
int reintentos,
float *resultado)
{
    float buffer;
    int retorno = -1;

    if(mensaje != NULL && mensajeError != NULL && resultado != NULL &&
       maximo >= minimo && reintentos >= 0)
    {
        do
        {
            printf("%s", mensaje);
            scanf("%f", &buffer);
            if(isValidFloat(buffer, maximo, minimo))
            {
                *resultado = buffer;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
            }
            reintentos--;
        }while(reintentos >=0);
    }
    return retorno;
}


/**
 * \brief Toma dos numero y los suma
 * \param primerTermino es el primer valor a sumar
 * \param segundoTermino es el segundo valor a sumar
 * \return la suma de los parametros
 *
 */
float sumador(float primerTermino, float segundoTermino)
{
    return primerTermino + segundoTermino;
}


/**
 * \brief Toma dos numero y los resta
 * \param primerTermino es el primer valor a restar
 * \param segundoTermino es el segundo valor a restar
 * \return la resta de los parametros
 *
 */
float restador(float primerTermino, float segundoTermino)
{
    return primerTermino - segundoTermino;
}


/**
 * \brief Toma dos numero y los divide
 * \param dividendo es el primer dividendo de la division
 * \param divisor es el divisor de la division
 * \param mensajeError es el mensaje que devuelve si hay un error
 * \return la divison de los parametros
 *
 */
float dividir(float dividendo, float divisor, char *mensajeError)
{
    if(divisor == 0)
    {
        printf("%s", mensajeError);
    }

    return dividendo / divisor;
}


/**
 * \brief Toma dos numero y los multiplica
 * \param primerTermino es el primer valor a multiplicar
 * \param segundoTermino es el sugundo valor a multiplicar
 * \return la multiplicacion de los parametros
 *
 */
float multiplicador(float primerTermino, float segundoTermino)
{
    return primerTermino * segundoTermino;
}


/**
 * \brief toma un numero y calcula el factorial
 * \param valor es el numero que desea calcular
 * \param factorial devuelve el factorial del numero ingresado
 * \param mensajeError devuelve el mensaje si ocurre algun error
 * \return -1 si ocurre un error 0 si todo sale bien
 *
 */
int calculaFactorial(int valor,long int *factorial, char *mensajeError)
{
    int retorno = -1;
    int i;
    long int acumulador = 1;
    int auxiliar = 0;

    if(factorial != NULL && mensajeError != NULL && valor >= 0)
    {

        if(valor == 0)
        {
            *factorial = 1;
        }
        else
        {
            for(i=0; i<valor; i++)
            {
                auxiliar++;
                acumulador *= auxiliar;
            }
            *factorial = acumulador;
            retorno = 0;
        }
    }
    else
    {
        printf("%s", mensajeError);
    }
    return retorno;
}


