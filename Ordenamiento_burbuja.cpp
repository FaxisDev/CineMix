#include <stdio.h>
#define N 6 //Se define que el arreglo de N es 6 como constante
void intercambia(int *f, int *g)
{
    int tmp; // Sera la variable que esta en contante cambio
    tmp = *f; //Lo que se ingrese en f se mantendra en cambio con tmp
    *f = *g; //f ahora valdra g sin afectar tmp
    *g = tmp; //el valdra de g valdra  lo de tmp
}
int main()
{
    int i, j, v[N] = {3, 4, 5, 2, 6, 8};
    for (i = N - 1; i > 1; i--) //i en este primer inicio valdra 5 (6 - 1)
        for (j = 0; j < i; j++) //j iniciara desde 6 y terminara hasta i
            if (v[j] > v[j + 1]) //determina que si el valor del arreglo actual es mayor que el el de la siguiente posicion de j
                intercambia(&v[j], &v[j + 1]); //se intercambia el valor a la funcion
    for (i = 0; i < N; i++)
        printf("%d\n", v[i]); //se muestra de forma ordenada el vector
    return 0;
}