#ifndef SMENUREPORTES_H_INCLUDED
#define SMENUREPORTES_H_INCLUDED

void subMenuReportes()
{

    int opcion;

    while (true)
    {

        borrarPantalla();
        encabezado("MENU REPORTES");


        cout << "1) "                                               << endl;
        cout << "2) "                                               << endl;
        cout << "3) "                                               << endl;
        cout << "4) "                                               << endl;
        cout << "5) "                                               << endl;
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

                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;

            default:
                entradaIncorrecta();
                break;
        }
    }
}

#endif // SMENUREPORTES_H_INCLUDED
