#ifndef FUNCIONESGLOBALES_H_INCLUDED
#define FUNCIONESGLOBALES_H_INCLUDED

#include "utilidades.h"

bool continuar(short y, bool valida, bool *salir);






bool continuar(short y, bool valida, bool *salir)
{
    *salir = false;
    if(!valida)
    {
        char op;
        cout << "Reintentar Ingreso S/N ?: ";
        cin >> op;
        if(op == 's' || op == 'S')
        {
            gotoxy(0,15);
            cout << "                                                                      " << endl;
            cout << "                                                                      ";
            gotoxy(0,y);
            cout << "                                                                      ";
            gotoxy(0,y);
            return true;

        }
        else if(op == 'n' || op == 'N')
        {
            *salir = true;
            return false;
        }
        else return false;
    }else return false;
}

#endif // FUNCIONESGLOBALES_H_INCLUDED
