#ifndef SMENUCONFIGURACION_H_INCLUDED
#define SMENUCONFIGURACION_H_INCLUDED

#include "cJugador.h"

void subMenuConfiguracion();
void copiaDeSegArchivoJugadores();
void copiaDeSegArchivoDeportes();
void restaurarArchivoJugadores();
void restaurarArchivoDeportes();
void establecerDatosInicio();


void subMenuConfiguracion()
{

    int opcion;

    while (true)
    {

        borrarPantalla();
        encabezado("MENU CONFIGURACION");


        cout << "1) COPIA DE SEGURIDAD DEL ARCHIVO DE JUGADORES"    << endl;
        cout << "2) COPIA DE SEGURIDAD DEL ARCHIVO DE DEPORTES"     << endl;
        cout << "3) RESTAURAR EL ARCHIVO DE JUGADORES"              << endl;
        cout << "4) RESTAURAR EL ARCHIVO DE DEPORTES"               << endl;
        cout << "5) ESTABLECER DATOS DE INICIO"                     << endl;
        cout << "--------------------------------"                  << endl;
        cout << "0) VOLVER AL MENU PRINCIPAL"                       << endl;

        cout << endl << "-Elija Una Opcion: ";
        cin >> opcion;

        switch (opcion)
        {
            case 0:
                return;
                break;
            case 1:
                copiaDeSegArchivoJugadores();
                break;
            case 2:
                copiaDeSegArchivoDeportes();
                break;
            case 3:
                restaurarArchivoJugadores();
                break;
            case 4:
                restaurarArchivoDeportes();
                break;
            case 5:
                establecerDatosInicio();
                break;

            default:
                entradaIncorrecta();
                break;
        }
    }
}


void copiaDeSegArchivoJugadores()
{
    remove(RUTA_BKP_JUGADORES);
    system("copy files\\Jugadores.dat files\\backups\\Jugadores.bkp");
}

void copiaDeSegArchivoDeportes()
{
    remove(RUTA_BKP_DEPORTES);
    system("copy files\\Deportes.dat files\\backups\\Deportes.bkp");
}

void restaurarArchivoJugadores()
{
    remove(RUTA_JUGADORES);
    system("copy files\\backups\\Jugadores.bkp files\\Jugadores.dat");}

void restaurarArchivoDeportes()
{
    remove(RUTA_DEPORTE);
    system("copy files\\backups\\Deportes.bkp files\\Deportes.dat");
}


void establecerDatosInicio()
{
    remove(RUTA_JUGADORES);    remove(RUTA_DEPORTE);
    system("copy files\\BackUps\\DatosdeInicio\\DatosInicioJugadores.ini files\\Jugadores.dat");
    system("copy files\\BackUps\\DatosdeInicio\\DatosInicioDeportes.ini files\\Deportes.dat");
}

#endif // SMENUCONFIGURACION_H_INCLUDED
