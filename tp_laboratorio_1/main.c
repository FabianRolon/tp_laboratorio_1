#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float A='s';
    float B='s';
    float suma;
    float resta;
    float division;
    float multiplicacion;
    long int factorial;

    while(seguir=='s')
    {
        if(A == 's')
        {
            printf("\n1- Ingresar 1er operando (A=x)\n");
        }
        else
        {
            printf("\n1- Ingresar 1er operando (A=%.2f)\n", A);
        }
        if(B == 's')
        {
            printf("2- Ingresar 2do operando (B=y)\n");
        }
        else
        {
            printf("2- Ingresar 2do operando (B=%.2f)\n", B);
        }
            printf("3- Calcular la suma (A+B)\n");
            printf("4- Calcular la resta (A-B)\n");
            printf("5- Calcular la division (A/B)\n");
            printf("6- Calcular la multiplicacion (A*B)\n");
            printf("7- Calcular el factorial (A!)\n");
            printf("8- Calcular todas las operaciones\n");
            printf("9- Salir\n\n");

            scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                getFloat( "\nIngrese 1er operando: ",
                        "\nEl dato ingresado es invalido\n",
                        -999999999999999999,
                        99999999999999999, 3, &A);
                break;
            case 2:
                getFloat("\nIngrese 2do operando: ",
                         "\nEl dato ingresado es invalido\n",
                         -999999999999999999,
                         99999999999999999, 3, &B);
                break;
            case 3:
                suma = sumador(A, B);
                printf("\nLa suma es: %.2f\n\n", suma);
                break;
            case 4:
                resta = restador(A, B);
                printf("\nLa resta es: %.2f\n\n", resta);
                break;
            case 5:
                division = dividir(A, B,
                "\nERROR! La division por cero es imposible!\n");
                printf("\nLa division es: %.2f\n\n", division);
                break;

            case 6:
                multiplicacion = multiplicador(A, B);
                printf("\nLa multiplicacion es: %.2f\n\n", multiplicacion);
                break;
            case 7:
                calculaFactorial(A, &factorial, "A debe ser mayor igual a cero");
                printf("\nEl factorial de A es: %li\n", factorial);
                break;
            case 8:
                suma = sumador(A, B);
                printf("\nLa suma es: %.2f\n\n", suma);
                resta = restador(A, B);
                printf("\nLa resta es: %.2f\n\n", resta);
                division = dividir(A, B,
                "\nERROR! La division por cero es imposible!\n");
                printf("\nLa division es: %.2f\n\n", division);
                multiplicacion = multiplicador(A, B);
                printf("\nLa multiplicacion es: %.2f\n\n", multiplicacion);
                calculaFactorial(A, &factorial,
                "A debe ser mayor igual a cero");
                printf("\nEl factorial de A es: %li\n", factorial);
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }
    return 0;
}
