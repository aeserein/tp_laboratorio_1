#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>


float sumarDos(float n1, float n2) {
    float resultado;
    resultado = n1+n2;
    return resultado;
}

float restarDos(float n1, float n2) {
    float resultado;
    resultado = n1-n2;
    return resultado;
}

float multiplicarDos(float n1, float n2) {
    float resultado;
    resultado = n1*n2;
    return resultado;
}

float dividirDos(float n1, float n2) {
    float resultado;
    resultado = n1/n2;
    return resultado;
}

long factorialDe(float n) {
    int numero = (int)n;
    long resultado = 1;
    if (numero!=0) {
        int f;
        for (f=1 ; f<=numero ; f++) {
            resultado = resultado*f;
        }
    }
    return resultado;
}

float ingresarFloat(char texto[32]) {
    float n;
    printf("%s" , texto);
    scanf("%f" , &n);
    return n;
}

int ingresarInt(char texto[32]) {
    int n;
    printf("%s" , texto);
    scanf("%d" , &n);
    return n;
}

void pausaYClear(void) {
    printf("\n");
    system("pause");
    system("cls");
}

int continuar(void) {
    char letra;
    do {
        printf("%cContinuar? S/N\t\t" , 168);
        letra = getche();
        letra = toupper(letra);
    } while (letra!='S' && letra!='N');

    return (letra=='S');
}

void imprimirTituloCalculadora(void){
    printf("*****************\n");
    printf("*  CALCULADORA  *\n");
    printf("*****************\n\n");
}

void calculadora(void) {

    unsigned short opcion;
    float numeroUno;
    float numeroDos;
    float suma;
    float resta;
    float multiplicacion;
    float division;
    long factorial1;
    long factorial2;
    unsigned short bOperaciones = 0;    // Bandera para que rebote si no se ingresaron los operandos o fueron cambiados
    unsigned short bNumeroUno = 0;      // Bandera para declarar que float numeroUno est� ingresado
    unsigned short bNumeroDos = 0;      // Bandera para declarar que float numeroDos est� ingresado


    do {
        imprimirTituloCalculadora();
        printf("1. Ingresar primer operando");
        if (bNumeroUno == 1) {
            printf("\t> %.2f\n" , numeroUno);
        } else {
            printf("\n");
        }
        printf("2. Ingresar segundo operando");
        if (bNumeroDos == 1) {
            printf("\t> %.2f\n" , numeroDos);
        } else {
            printf("\n");
        }
        printf("3. Calcular operaciones");
        if (bOperaciones) {
            printf("\t\tx\n");
        } else {
            printf("\n");
        }
        printf("4. Mostrar resultados\n");
        printf("-----------------\n");
        printf("5. Salir\n\n");
        opcion = ingresarFloat("Elija opcion:\t\t"); // No s� c�mo pasar string con caracteres especiales

        switch (opcion) {
            case 1 :{
                numeroUno = ingresarFloat("Ingrese numero uno:\t");
                bNumeroUno = 1;
                if (bOperaciones) {
                    bOperaciones = 0;
                }
                break;
            }
            case 2 : {
                numeroDos = ingresarFloat("Ingrese numero dos:\t");
                bNumeroDos = 1;
                if (bOperaciones) {
                    bOperaciones = 0;
                }
                break;
            }
            case 3 : {
                if (bNumeroUno && bNumeroDos) {
                    suma = sumarDos(numeroUno, numeroDos);
                    resta = restarDos(numeroUno, numeroDos);
                    multiplicacion = multiplicarDos(numeroUno, numeroDos);
                    if (numeroDos!=0) {
                        division = dividirDos(numeroUno, numeroDos);
                    }
                    factorial1 = factorialDe(numeroUno);
                    factorial2 = factorialDe(numeroDos);

                    bOperaciones = 1;
                    printf("\n%cResultados listos!\n" , 173);
                } else {
                    printf("\nPrimero ingrese dos n%cmeros.\n" , 163);
                }
                    break;
            }
            case 4 : {
                if (bOperaciones) {
                    printf("\nSUMA\t\t-  %.2f + %.2f:\t%.2f\n" , numeroUno, numeroDos, suma);
                    printf("RESTA\t\t-  %.2f - %.2f:\t%.2f\n" , numeroUno, numeroDos, resta);
                    printf("MULTIPLICACI%cN  -  %.2f * %.2f:\t%.2f\n" , 224 , numeroUno, numeroDos, multiplicacion);
                    if (numeroDos!=0) {
                        printf("DIVISI%cN\t-  %.2f / %.2f:\t%.2f\n" , 224 , numeroUno, numeroDos, division);
                    } else {
                        printf("DIVISI%cN\t-  %.2f / %.0f:\tError\n" , 224 , numeroUno, numeroDos);
                    }
                    if (numeroUno-(int)numeroUno==0 && numeroUno>0) {
                        printf("FACTORIAL\t-  %.0f!:\t%li\n" , numeroUno, factorial1);
                    } else {
                        printf("FACTORIAL\t-  %.2f!: Error\n" , numeroUno);
                    }
                    if (numeroDos-(int)numeroDos==0 && numeroDos>0) {
                        printf("FACTORIAL\t-  %.0f!:\t%li\n" , numeroDos, factorial2);
                    } else {
                        printf("FACTORIAL\t-  %.2f!: Error\n" , numeroDos);
                    }
                } else {
                    printf("\nCalcule los valores antes de verlos en pantalla.\n");
                }
                break;
            }
            case 5 : {
                break;
            }
            default : {
                printf("\nOpci%cn inv%clida\n" , 162 , 160);
            }

        }
        if (opcion!=5) {
            pausaYClear();
        }
    } while (opcion!=5);


}
