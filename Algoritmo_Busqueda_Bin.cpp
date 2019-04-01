#include <stdio.h>
int main()
{
    int b, i, j, k, v[12];
    for (i = 0; i < 12; i++) //Te va a pedir que llenes el arreglo de v[12] con 12 valores diferentes
        scanf("%d", &v[i]);
    printf("fin del llenado\n"); //cuando el bucle termine te mandara el mensaje fin de llenado
    printf("ingrese numero a buscar "); //pedira el numero a buscar en el arreglo
    scanf("%d", &b);
    i = 0; //al igual que j el arreglo no se inicia en 1
    j = 12 - 1; //j vale 11 porque en el arreglo se inicia desde 0 y  no desde 1
    do // Inicio do while: mientras i sea menor que j que va en decremento segun k -1
    {
        k = (i + j) / 2; //Se divide la busqueda en 2
        if (v[k] <= b)
            i = k + 1; //Va de la mitad de 6 hacia arriba
        if (v[k] >= b)
            j = k - 1; //va de la mitad de 6 hacia abajo 
    } while (i <= j);
    printf("elemento %d esta en %d\n", v[k], k); //determina el ultimo valor de k
    return 0;
}