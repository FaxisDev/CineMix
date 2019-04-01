#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <stack>
#include <string>

using namespace std;

//Se declaran las 7 salas del cine (8 porque se tomara desde el 1)
//Pila :: SALA[8] || Pelicula[16]

stack<int> Sala[8][16];

//Lista de pelicula
string *lista_peliculas = new string[16];

int main(int argc, char const *argv[])
{

    //Lista de peliculas
    lista_peliculas[1] = "Avengers";
    lista_peliculas[2] = "Terror Bajo las Sabanas";
    lista_peliculas[3] = "Otra Estupida pelicula";
    lista_peliculas[4] = "Fallout X";
    lista_peliculas[5] = "Fernanda: El contra-ataque";
    lista_peliculas[6] = "Algo mas que amigos";
    lista_peliculas[7] = "Mi novio es un wey";
    lista_peliculas[8] = "Mi Mayor Engaño: La Conquista";
    lista_peliculas[9] = "Anabell Vs Chuky: El Renacer";
    lista_peliculas[10] = "Tu Ex Es Un Patan 2";
    lista_peliculas[11] = "Hollyboy";
    lista_peliculas[12] = "Hellboy";
    lista_peliculas[13] = "Alien Vs Depredador 3000";
    lista_peliculas[14] = "Paganos";
    lista_peliculas[15] = "Simona la mona";
    int opcion = 0;
    do
    {
        //Ver salas
        cout << "CINEMEX" << endl;
        cout << "Bienvenido al Menu: ¿Que desea hacer? " << endl;
        cout << "==============" << endl;
        cout << "[1] Ver detalles de Salas" << endl;
        cout << "[2] Ver Pelicula-Sala Mas Vista" << endl;
        cout << "[3] Ingresar clientes a Salas" << endl;
        cout << "[4] Salir" << endl;

        opcion = 0;
        cin >> opcion;

        if (opcion == 1)
        {
            int sala_opcion = 0;
            cout << "Selecciona La sala para ver detalles: " << endl;
            int b = 0;
            do
            {
                for (b = 1; b <= 7; b++)
                {
                    cout << "[" << b << "] - Sala: " << b << endl;
                }
                cin >> sala_opcion;
                if (!(sala_opcion > 0 && sala_opcion <= 7))
                {
                    cout << "Esa opcion no existe | Ingresa nuevamente" << endl;
                }
            } while (!(sala_opcion > 0 && sala_opcion <= 7));

            //Aqui se mostrara el detalle de esa sala
            cout << "detalles de la sala: " << sala_opcion << endl;
            for (int i = 1; i <= 15; i++)
            {
                cout << "Para la Pelicula: '" << lista_peliculas[i] << "' Tiene: " << 50 - (Sala[sala_opcion][i].size()) << " lugares disponibles." << endl;
            }
        }
        else if (opcion == 2)
        {
            int numero = 0;
            int mayor = 0;

            for (int x = 1; x <= 7; x++)
            {
                for (int y = 1; y <= 15; y++)
                {

                    numero = Sala[x][y].size();

                    if (numero > mayor)
                    {
                        mayor = numero;
                    }
                }
            }

            cout << "Salas & Peliculas con mayor ganancia: " << endl;
            for (int x = 1; x <= 7; x++)
            {
                for (int y = 1; y <= 15; y++)
                {

                    if (Sala[x][y].size() == mayor)
                    {
                        cout << "La mejor sala: " << x << " La mejor Pelicula: " << lista_peliculas[y] << " Cantidad de Asientos:" << Sala[x][y].size() << endl;
                    }
                }
            }
        }
        else if (opcion == 3)
        {
            int sala_opcion = 0, pelicula_opcion = 0, cantidad = 0;
            cout << "Selecciona La sala para meter clientes: " << endl;
            int b = 0;
            do
            {
                for (b = 1; b <= 7; b++)
                {
                    cout << "[" << b << "] - Sala: " << b << endl;
                }
                cin >> sala_opcion;
                if (!(sala_opcion > 0 && sala_opcion <= 7))
                {
                    cout << "Esa opcion no existe | Ingresa nuevamente" << endl;
                }
            } while (!(sala_opcion > 0 && sala_opcion <= 7));

            cout << " Que pelicula veran? " << endl
                 << endl;
            do
            {
                for (int y = 1; y <= 15; y++)
                {
                    cout << y << "- " << lista_peliculas[y] << endl;
                }

                cin >> pelicula_opcion;

                if (!(pelicula_opcion > 0 && pelicula_opcion <= 15))
                {
                    cout << "Esa opcion no existe | Ingresa nuevamente" << endl;
                }
            } while (!(pelicula_opcion > 0 && pelicula_opcion <= 15));

            cout << " Cuantos veran la pelicula? " << endl;
            if ((50 - (Sala[sala_opcion][pelicula_opcion].size())) <= 0)
            {
                cout << " Lo sentimos esta ocupado todos los asientos " << endl;
            }
            else
            {
                do
                {
                    cantidad = 0;
                    cin >> cantidad;
                    if (!(cantidad > 0 && cantidad <= (50 - (Sala[sala_opcion][pelicula_opcion].size()))))
                    {
                        cout << "Estas fuera del rango de asientos disponibles intentalo de nuevo " << endl;
                    }
                    else
                    {
                        int u = 1;
                        while (u <= cantidad)
                        {
                            Sala[sala_opcion][pelicula_opcion].push(1);
                            u++;
                        }
                    }
                } while (!(cantidad > 0 && cantidad <= (50 - (Sala[sala_opcion][pelicula_opcion].size()))));
            }

            cout << ">> Sala: " << sala_opcion << " Pelicula: " << lista_peliculas[pelicula_opcion] << " Asientos comprados: " << cantidad << endl;
        }
        else if (opcion == 4)
        {
            cout << "Saliendo.. bye" << endl;
            break;
        }
        else
        {
            cout << "Esa opcion no existe! intentalo de nuevo " << endl;
        }
    } while (true);

    _getch();
    return 0;
}
