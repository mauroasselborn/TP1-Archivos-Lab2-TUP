#ifndef SMENUJUGADOR_H_INCLUDED
#define SMENUJUGADOR_H_INCLUDED

#include "cJugador.h"

void subMenuJugador()
{
    int opcion;

    Jugador jugador;


    while (true)
    {

        borrarPantalla();
        encabezado("MENU JUGADORES");
        colorTexto(15);

        cout << "1) AGREGAR JUGADOR"                << endl;
        cout << "2) LISTAR JUGADOR POR DNI"         << endl;
        cout << "3) LISTAR TODOS LOS JUGADORES"     << endl;
        cout << "4) MODIFICAR FECHA DE INSCRIPCION" << endl;
        cout << "5) ELIMINAR REGISTRO DE JUGADOR"   << endl;
        cout << "--------------------------------"  << endl;
        cout << "0) VOLVER AL MENU PRINCIPAL"       << endl;

        cout << endl << " Elija Una Opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 0:
            colorTexto(14);
            return;
        case 1:
            jugador.agregarJugador();
            break;
        case 2:
            jugador.listarJugadorPorDNI();
            break;
        case 3:
            jugador.listarJugadores();
            break;
        case 4:
            //jugador.modificarFechaIngreso();
            break;
        case 5:
            jugador.eliminarJugador();
            break;
        default:
            entradaIncorrecta();
            break;
        }
    }
}

#endif // SMENUJUGADOR_H_INCLUDED
