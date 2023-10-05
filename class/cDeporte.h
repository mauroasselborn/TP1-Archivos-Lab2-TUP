#ifndef CDEPORTE_H_INCLUDED
#define CDEPORTE_H_INCLUDED


#include "cArchivoDeporte.h"


class Deporte {
private:
    int idDeporte;
    char nombre[30];
    int tipoDeporte;
    int anioOrigen;
    bool estado;

public:
    Deporte(bool _estado);

    /// GETTERS
    int getIdDeporte() const { return idDeporte; }
    const char* getNombre() const { return nombre; }
    int getTipoDeporte() const { return tipoDeporte; }
    int getAnioOrigen() const { return anioOrigen; }
    bool getEstado() const { return estado; }

    /// SETTERS
    void setIdDeporte(int _idDeporte) { idDeporte = _idDeporte; }
    void setNombre(const char* _nombre) { strcpy(nombre, _nombre); }
    void setTipoDeporte(int _tipoDeporte) { tipoDeporte = _tipoDeporte; }
    void setAnioOrigen(int _anioOrigen) { anioOrigen = _anioOrigen; }
    void setEstado(bool _estado) { estado = _estado; }

    /// METODOS
    void agregarDeporte();
    void listarDeportePorID();
    void listarDeportes();
    void eliminarDeporte();
    void modificarAnioOrigen();
    int obtenerUltimoID();
    bool validarDeporte(int _ID);
    bool validarTipoDeporte(int _deporte);
    bool validarAnioOrigen(int _anio);
    void obtenerNombrePorID(int _idDeporte);
};

class ArchivoDeporte{

private:
    char rutaArchivo[30];
public:
    ///CONSTRUCTOR
    ArchivoDeporte(const char *_rutaArchivo){ strcpy(rutaArchivo, _rutaArchivo); }

    ///GETTERS
    const char* getRutaArchivo(){ return rutaArchivo; }


    ///SETTERS
    void setRuta(const char* _ruta){ strcpy(rutaArchivo, _ruta); }


    ///METODOS
    void escribirArchivo(Deporte deporte){

        FILE* archivo;

        if( (archivo = fopen(getRutaArchivo(),MODO_APPEND_B)) == NULL)
        {
            cerr << "\nError Al Abrir El Archivo" << endl;
            pause();
            exit(1);
        }

        fwrite(&deporte, sizeof(deporte),1,archivo);
        fclose(archivo);
    }
};

Deporte::Deporte(bool _estado = true) {
    estado = _estado;
}

/// AGREGA UN DEPORTE AL ARCHIVO
void Deporte::agregarDeporte()
{
    borrarPantalla();
    encabezado("CARGANDO DEPORTES");


    char tmpNombre[30];
    int tmpTipoDeporte;
    int tmpAnioOrigen;
    bool salir;
    Deporte deporte;

    cin.ignore();
    cout << "Ingrese el nombre: ";
    cin.getline(tmpNombre,30);



    do{
        cout << "Ingrese el tipo de Deporte: ";
        cin >> tmpTipoDeporte;
    }while(continuar(4,validarTipoDeporte(tmpTipoDeporte), &salir));
    if(salir) return;



    do{
        cout << "Ingrese a" << char(164) << "o de origen: ";
        cin >> tmpAnioOrigen;
    }while(continuar(5,validarAnioOrigen(tmpAnioOrigen), &salir));
    if(salir) return;


    ///SETEOS

    deporte.setIdDeporte(obtenerUltimoID() + 1);
    deporte.setNombre(tmpNombre);
    deporte.setTipoDeporte(tmpTipoDeporte);
    deporte.setAnioOrigen(tmpAnioOrigen);


    ArchivoDeporte archivo(RUTA_DEPORTE);
    archivo.escribirArchivo(deporte);
}

/// LISTA UN DEPORTE POR ID
void Deporte::listarDeportePorID()
{
    FILE * archivo;
    Deporte deporte;
    int id;
    bool salir;


    if( (archivo = fopen(RUTA_DEPORTE,MODO_LECTURA_B)) == NULL)
    {
        cerr << "\n\nError Al Abrir El Archivo" << endl;
        pause();
        return;
    }

    borrarPantalla();
    encabezado("LISTANDO DEPORTE");

    do{
        cout << "Ingrese el ID de Deporte: ";
        cin >> id;
        cout << "\n";
    }while(continuar(3,validarDeporte(id), &salir));
    if(salir) {fclose(archivo); return;}


    while(fread(&deporte, sizeof(deporte),1,archivo) == 1){



        if(deporte.getIdDeporte() == id && deporte.getEstado())
        {
            cout << "ID: " << deporte.getIdDeporte() << endl;
            cout << "NOMBRE: " << deporte.getNombre() << endl;
            cout << "TIPO DE DEPORTE: " << deporte.getTipoDeporte() << endl;
            cout << "A"<< char(165) << "O DE ORIGEN: " << deporte.getAnioOrigen() << endl;
            pause();
            break;
        }
    }

    fclose(archivo);
}

/// LISTA TODOS LOS DEPORTES
void Deporte::listarDeportes()
{

    FILE * archivo;
    Deporte deporte;


    if( (archivo = fopen(RUTA_DEPORTE,MODO_LECTURA_B)) == NULL)
    {
        cerr << "\n\nError Al Abrir El Archivo" << endl;
        pause();
        exit(1);
    }


    while(fread(&deporte, sizeof(deporte),1,archivo) == 1){

        borrarPantalla();
        encabezado("LISTANDO DEPORTES");


        if(deporte.getEstado())
        {
            cout << "ID: " << deporte.getIdDeporte() << endl;
            cout << "NOMBRE: " << deporte.getNombre() << endl;
            cout << "TIPO DE DEPORTE: " << deporte.getTipoDeporte() << endl;
            cout << "A"<< char(164) << "O DE ORIGEN: " << deporte.getAnioOrigen() << endl;

            pause();
        }
    }
    fclose(archivo);
}

/// REALIZA LA BAJA LOGICA
void Deporte::eliminarDeporte()
{
    FILE * archivo;
    if( (archivo = fopen(RUTA_DEPORTE,MODO_LEC_ESC_B)) == NULL)
    {
        cerr << "\n\nError Al Abrir El Archivo" << endl;
        pause();
        exit(1);
    }

    Deporte deporte;
    int id;
    bool salir;

    borrarPantalla();
    encabezado("BORRANDO DEPORTE");


    do{
        cout << "Ingrese el ID de Deporte: ";
        cin >> id;
        cout << "\n";
    }while(continuar(3,validarDeporte(id), &salir));
    if(salir) {fclose(archivo); return;}

    while(fread(&deporte, sizeof(deporte),1,archivo) == 1){

        if(deporte.getIdDeporte() == id && deporte.getEstado()){

            deporte.setEstado(false);
            fseek(archivo, ftell(archivo) - sizeof(deporte),SEEK_SET);
            fwrite(&deporte, sizeof(deporte),1,archivo);
            break;
        }
    }
    cout << "\n\nBorrado Logico Exitoso" << endl;
    fclose(archivo);
    pause();
}

/// MODIFICA EL AÑO DE ORIGEN
void Deporte::modificarAnioOrigen()
{
    FILE * archivo;
    if( (archivo = fopen(RUTA_DEPORTE,MODO_LEC_ESC_B)) == NULL)
    {
        cerr << "\n\nError Al Abrir El Archivo" << endl;
        pause();
        exit(1);
    }

    Deporte deporte;
    int id;
    int anio;
    bool salir;



    borrarPantalla();
    encabezado("MODIFICANDO FECHA DE ORIGEN");

    do{
        cout << "Ingrese el ID de Deporte: ";
        cin >> id;
    }while(continuar(3,validarDeporte(id), &salir));
    if(salir) {fclose(archivo); return;}

    while(fread(&deporte, sizeof(deporte),1,archivo) == 1){

        if(deporte.getIdDeporte() == id){

            do{
                cout << "Ingrese el nuevo a" << char(164) << "o de origen: ";
                cin >> anio;
            }while(continuar(4,validarAnioOrigen(anio), &salir));
            if(salir) {fclose(archivo); return;}


            deporte.setAnioOrigen(anio);
            fseek(archivo, ftell(archivo) - sizeof(deporte),SEEK_SET);
            fwrite(&deporte, sizeof(deporte),1,archivo);
            break;
        }
    }
    fclose(archivo);
    cout << "\n\nModificacion Exitosa" << endl;
    pause();
}

/// VALIDA EL ID DE DEPORTE
bool Deporte::validarDeporte(int _idDeporte)
{

    FILE * archivo;
    if((archivo = fopen(RUTA_DEPORTE,MODO_LECTURA_B)) == NULL)
    {
        cerr << "\n\nError Al Abrir El Archivo" << endl;
        pause();
        exit(1);
    }

    Deporte deporte;

    while(fread(&deporte, sizeof(deporte),1,archivo) == 1){

        if(deporte.getIdDeporte() == _idDeporte)
        {
            if(deporte.getEstado())
            {
                fclose(archivo);
                return true;
            }else
            {
                gotoxy(0,15);
                cout << "ID dado de baja en el archivo Deportes.dat" << endl;
                return false;
            }

        }

    }

    fclose(archivo);
    gotoxy(0,15);
    cout << "No se encuentra el Numero de Deportes en el archivo Deportes.dat" << endl;
    return false;
}

/// VALIDA TIPO DE DEPORTE
bool Deporte::validarTipoDeporte(int _tipoDeporte)
{
    if(_tipoDeporte >= 1 && _tipoDeporte <=21) return true;
    else {
        gotoxy(0,15);
        cerr << "Solo se admiten valores de 1 a 21" << endl;
        return false;
    }
}

/// VALIDA EL AÑO DE ORIGEN
bool Deporte::validarAnioOrigen(int _anio)
{

    if(_anio >= 1800 && _anio <= 2023) return true;
    else {
        gotoxy(0,15);
        cerr << "Solo se admiten valores desde 1800 a 2023" << endl;
        return false;
    }
}

/// OBTIENE LA CANTIDAD DE REGISTROS
int Deporte::obtenerUltimoID()
{

    FILE* archivo;

    if((archivo = fopen(RUTA_DEPORTE,MODO_APP_LEC_B)) == NULL)
    {
        cerr << "\n\nError Al Abrir El Archivo" << endl;
        pause();
        exit(1);
    }

    fseek(archivo, 0, SEEK_END);
    int cantidadRegistros = ftell(archivo) / sizeof(Deporte);
    fclose(archivo);

    return cantidadRegistros;
}

#endif // CDEPORTE_H_INCLUDED

