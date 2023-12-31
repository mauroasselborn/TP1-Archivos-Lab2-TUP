#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <time.h>


using namespace std;



///Include Headers
#include "headers/constantes.h"
#include "headers/funcionesGlobales.h"
#include "headers/utilidades.h"
#include "headers/sMenuJugador.h"
#include "headers/sMenuDeportes.h"
#include "headers/sMenuReportes.h"
#include "headers/sMenuConfiguracion.h"


int main()
{

    tituloTP();
    system("mode con cols=100 lines=20");

    int opcion;

    while (true)
    {

        borrarPantalla();
        encabezado("MENU PRINCIPAL");

        cout << "1) MENU JUGADORES" << endl;
        cout << "2) MENU DEPORTES" << endl;
        cout << "3) REPORTES" << endl;
        cout << "4) CONFIGURACION" << endl;
        cout << "--------------------------------" << endl;
        cout << "0) FIN DEL PROGRAMA" << endl;
        cout << endl;


        cout << endl << "-Elija Una Opcion: ";
        cin >> opcion;

        switch (opcion)
        {
            case 0:
                colorTexto(14);
                exit(1);
            case 1:
                subMenuJugador();
                break;
            case 2:
                subMenuDeportes();
                break;
            case 3:
                subMenuReportes();
                break;
            case 4:
                subMenuConfiguracion();
                break;
            default:
                entradaIncorrecta();
                break;
        }
    }
    return 0;
}
