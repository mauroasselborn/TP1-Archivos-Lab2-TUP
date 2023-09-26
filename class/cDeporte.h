#ifndef CDEPORTE_H_INCLUDED
#define CDEPORTE_H_INCLUDED


#include "cArchivo.h"

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
};

Deporte::Deporte(bool _estado = true) {
    estado = _estado;
}

///
void Deporte::agregarDeporte()
{
    borrarPantalla();
    encabezado("CARGANDO DEPORTES");
    colorTexto(15);

    char tmpNombre[30];
    int tmpTipoDeporte;
    int tmpAnioOrigen;

    cin.ignore();
    cout << "Ingrese el nombre: ";
    cin.getline(tmpNombre,30);

    cout << "Ingrese el tipo de Deporte: ";
    cin >> tmpTipoDeporte;

    if(!validarTipoDeporte(tmpTipoDeporte)) return;

    cout << "Ingrese a" << char(164) << "o de origen: ";
    cin >> tmpAnioOrigen;

    if(!validarAnioOrigen(tmpAnioOrigen)) return;


    ///SETEOS

    setIdDeporte(obtenerUltimoID() + 1);
    setNombre(tmpNombre);
    setTipoDeporte(tmpTipoDeporte);
    setAnioOrigen(tmpAnioOrigen);


    Archivo<Deporte> archivo("files/Deportes.dat");
    archivo.escribirArchivo(*this);
}

///
void Deporte::listarDeportePorID() {}

///
void Deporte::listarDeportes() {}

///
void Deporte::eliminarDeporte(){}

///
void Deporte::modificarAnioOrigen(){}

///
bool Deporte::validarDeporte(int _ID){

    FILE * archivo;
    if((archivo = fopen("files/Deportes.dat","rb")) == NULL)
    {
        cerr << "\n\nError Al Abrir El Archivo" << endl;
        pause();
        return false;
    }

    Deporte deporte;
    bool valida = true;

    while(fread(&deporte, sizeof(deporte),1,archivo) == 1){

        if(deporte.getIdDeporte() == _ID){

            valida = false;

            if(deporte.getEstado()){
                cout << "\n\nID Duplicado" << endl;
            }else{
                cout << "\n\nID Encontrado pero dado de Baja" << endl;
            }

            pause();
            break;
        }
    }

    fclose(archivo);
    return valida;
}

bool Deporte::validarTipoDeporte(int _tipoDeporte)
{
    if(_tipoDeporte >= 1 && _tipoDeporte <=21) return true;
    else {
        cout << "\n\nSolo se admiten valores de 1 a 21" << endl;
        pause();
        return false;
    }
}
bool Deporte::validarAnioOrigen(int _anio){

    if(_anio >= 1800 && _anio <= 2023) return true;
    else {
        cout << "\n\nSolo se admiten valores desde 1800 a 2023" << endl;
        pause();
        return false;
    }
}

/// OBTIENE LA CANTIDAD DE REGISTROS
int Deporte::obtenerUltimoID() {

    FILE* archivo;

    if((archivo = fopen("files/Deportes.dat", "rb")) == NULL)
    {
        cerr << "\n\nError Al Abrir El Archivo" << endl;
        pause();
        return -1;
    }


    fseek(archivo, 0, SEEK_END);
    int cantidadRegistros = ftell(archivo) / sizeof(Deporte);
    fclose(archivo);

    return cantidadRegistros;
}

#endif // CDEPORTE_H_INCLUDED



