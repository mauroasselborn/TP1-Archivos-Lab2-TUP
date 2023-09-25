#ifndef SMENUCONFIGURACION_H_INCLUDED
#define SMENUCONFIGURACION_H_INCLUDED

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
        colorTexto(15);

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
                //copiaDeSegArchivoJugadores();
                break;
            case 2:
                //copiaDeSegArchivoDeportes();
                break;
            case 3:
                //restaurarArchivoJugadores();
                break;
            case 4:
                //restaurarArchivoDeportes();
                break;
            case 5:
                //establecerDatosInicio();
                break;

            default:
                entradaIncorrecta();
                break;
        }
    }
}
#endif // SMENUCONFIGURACION_H_INCLUDED
