#ifndef SMENUDEPORTES_H_INCLUDED
#define SMENUDEPORTES_H_INCLUDED

void subMenuDeportes()
{
    int opcion;

    while (true)
    {
        borrarPantalla();
        encabezado("MENU DEPORTES");
        colorTexto(15);

        cout << "1) AGREGAR DEPORTE" << endl;
        cout << "2) LISTAR DEPORTE POR ID" << endl;
        cout << "3) LISTAR TODO" << endl;
        cout << "4) MODIFICAR AÑO DE ORIGEN" << endl;
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
                //agregarDeporte();
                break;
            case 2:
                //listarDeportePorID();
                break;
            case 3:
                //listarTodo();
                break;
            case 4:
                //modificarAnioOrigen();
                break;
            case 5:
                //eliminarRegistro();
                break;

            default:
                entradaIncorrecta();
                break;
        }
    }
}


#endif // SMENUDEPORTES_H_INCLUDED
