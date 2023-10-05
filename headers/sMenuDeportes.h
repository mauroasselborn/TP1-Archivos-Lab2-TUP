#ifndef SMENUDEPORTES_H_INCLUDED
#define SMENUDEPORTES_H_INCLUDED


#include "cDeporte.h"

void subMenuDeportes()
{
    int opcion;
    Deporte deporte;

    while (true)
    {
        borrarPantalla();
        encabezado("MENU DEPORTES");


        cout << "1) AGREGAR DEPORTE" << endl;
        cout << "2) LISTAR DEPORTE POR ID" << endl;
        cout << "3) LISTAR TODO" << endl;
        cout << "4) MODIFICAR A" << char(165) << "O DE ORIGEN" << endl;
        cout << "5) ELIMINAR REGISTRO" << endl;
        cout << "--------------------------------" << endl;
        cout << "0) VOLVER AL MENU PRINCIPAL" << endl;

        cout << endl << "-Elija Una Opcion: ";
        cin >> opcion;

        switch (opcion)
        {
            case 0:
                return;
                break;
            case 1:
                deporte.agregarDeporte();
                break;
            case 2:
                deporte.listarDeportePorID();
                break;
            case 3:
                deporte.listarDeportes();
                break;
            case 4:
                deporte.modificarAnioOrigen();
                break;
            case 5:
                deporte.eliminarDeporte();
                break;

            default:
                entradaIncorrecta();
                break;
        }
    }
}


#endif // SMENUDEPORTES_H_INCLUDED
