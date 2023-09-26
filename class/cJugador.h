#ifndef CJUGADOR_H
#define CJUGADOR_H

#include "cFecha.h"
#include "cArchivo.h"

class Jugador
{
private:
    int DNI;
    char nombre[30];
    char apellido[30];
    char email[30];
    char telefono[30];
    int claustro; //(1: docente; 2 alumno; 3 no docente; 4 graduado)
    int deporte; //(numero entre 1 y 10)
    int numeroDeEquipo; //(numero entero)
    Fecha fechaDeIncripcion;
    float matricula;
    bool estado;

public:
    ///Constructor/Destructor
    Jugador(bool _estado);

    ///GETTERS
    int getDNI(){return DNI;}
    const char* getNombre() const {return nombre;}
    const char* getApellido() const {return apellido;}
    const char* getEmail() const {return email;}
    const char* getTelefono() const {return telefono;}
    int getClaustro() const {return claustro;}
    int getDeporte() const {return deporte;}
    int getNumeroDeEquipo() const {return numeroDeEquipo;}
    Fecha getFechaDeIncripcion() const {return fechaDeIncripcion;}
    float getMatricula() const {return matricula;}
    bool getEstado() const {return estado;}

    ///SETTERS
    void setDNI(int _DNI){ DNI = _DNI; }
    void setNombre(const char *_nombre){ strcpy(nombre , _nombre); }
    void setApellido(const char *_apellido){ strcpy(apellido , _apellido); }
    void setEmail(const char *_email){ strcpy(email , _email); }
    void setTelefono(const char *_telefono){ strcpy(telefono , _telefono); }
    void setClaustro(int _claustro){claustro = _claustro;}
    void setDeporte(int _deporte){deporte = _deporte;}
    void setNumeroDeEquipo(int _numeroDeEquipo){ numeroDeEquipo = _numeroDeEquipo; }
    void setFechaDeIncripcion(int _dia, int _mes, int _anio){
        fechaDeIncripcion.setDia(_dia);
        fechaDeIncripcion.setMes(_mes);
        fechaDeIncripcion.setAnio(_anio);
    }
    void setMatricula(float _matricula){ matricula = _matricula; }
    void setEstado(bool _estado){ estado = _estado; }

    ///METODOS
    void agregarJugador(void);
    void listarJugadorPorDNI(void);
    void listarJugadores(void);
    void modificarFechaIngreso(void);
    void eliminarJugador(void);

    bool existeDNI(int _DNI);

};

Jugador::Jugador(bool _estado = true) { estado = _estado; }


void Jugador::agregarJugador(void){

    borrarPantalla();
    encabezado("CARGANDO JUGADORES");
    colorTexto(15);

    int tmpDNI;
    char tmpNombre[30];
    char tmpApellido[30];
    char tmpEmail[30];
    char tmpTelefono[30];
    int tmpClaustro;
    int tmpDeporte;
    int tmpNumeroDeEquipo;
    int _dia, _mes, _anio;
    Fecha tmpFechaDeIncripcion;
    float tmpMatricula;


    cout << "Ingrese el DNI: ";
    cin >> tmpDNI;
    if(existeDNI(tmpDNI)) return;
    cin.ignore();
    cout << "Ingrese el nombre: ";
    cin.getline(tmpNombre,30);
    cout << "Ingrese el apellido: ";
    cin.getline(tmpApellido,30);
    cout << "Ingrese el email: ";
    cin.getline(tmpEmail,30);
    cout << "Ingrese el telefono: ";
    cin.getline(tmpTelefono,30);
    cout << "Ingrese el N de claustro: ";
    cin >> tmpClaustro;
    cout << "Ingrese el N de deporte: ";
    cin >> tmpDeporte;
    cout << "Ingrese el N de equipo: ";
    cin >> tmpNumeroDeEquipo;
    cout << "Ingrese fecha de incripcion dia, mes, a" << char(164)<<"o: ";
    cin >> _dia;
    gotoxy ( 45, 11 ); cout << "/ "; cin >> _mes;
    gotoxy ( 49, 11 ); cout << "/ "; cin >> _anio;
    cout << "Ingrese matricula $: ";
    cin >> tmpMatricula;




    ///SETEOS
    setDNI(tmpDNI);
    setNombre(tmpNombre);
    setApellido(tmpApellido);
    setEmail(tmpEmail);
    setTelefono(tmpTelefono);
    setClaustro(tmpClaustro);
    setDeporte(tmpDeporte);
    setNumeroDeEquipo(tmpNumeroDeEquipo);
    setFechaDeIncripcion(_dia, _mes, _anio);
    setMatricula(tmpMatricula);

    Archivo<Jugador> archivo("files/Jugadores.dat");
    archivo.escribirArchivo(*this);

}

///LISTAR JUGADOR POR DNI
void Jugador::listarJugadorPorDNI(){

    FILE * archivo;
    Jugador jugador;
    int _DNI;
    bool encontrado = false;

    if( (archivo = fopen("files/Jugadores.dat","rb")) == NULL)
    {
        cerr << "\nError Al Abrir El Archivo" << endl;
        pause();
        return;
    }

    borrarPantalla();
    encabezado("LISTANDO JUGADOR");
    colorTexto(15);

    cout << "Ingrese el DNI del Jugador: ";
    cin >> _DNI;
    cout << endl;
    const char _vClaustro[4][15] = {"Docente","Alumno","No Docente","Graduado"};

    while(fread(&jugador, sizeof(jugador),1,archivo) == 1){

        if(jugador.getEstado() && jugador.getDNI() == _DNI){

            cout << "DNI: " << jugador.getDNI() << endl;
            cout << "NOMBRE: " << jugador.getNombre() << endl;
            cout << "APELLIDO: " << jugador.getApellido() << endl;
            cout << "EMAIL: " << jugador.getEmail() << endl;
            cout << "TELEFONO: " << jugador.getTelefono() << endl;
            cout << "CLAUSTRO: " << _vClaustro[jugador.getClaustro()] << endl;
            cout << "DEPORTE: " << jugador.getNumeroDeEquipo() << endl;
            cout << "FECHA DE INSCRIPCION: " << jugador.getFechaDeIncripcion().getDia() << "/" << jugador.getFechaDeIncripcion().getMes() << "/" << jugador.getFechaDeIncripcion().getAnio() << endl;
            cout << "MATRICULA: " << jugador.getMatricula() << endl;
            encontrado = true;
            //pause();
            break;
        }
    }

    fclose(archivo);
    if(!encontrado) cout << "\n\nDNI No Encontrado, \nEl DNI proporcionado no se encuentra o se encuentra dado de baja" << endl;
    pause();
}


///MOSTRAR TODOS LOS JUGADORES
void Jugador::listarJugadores(){

    FILE * archivo;
    Jugador jugador;


    if( (archivo = fopen("files/Jugadores.dat","rb")) == NULL)
    {
        cerr << "\nError Al Abrir El Archivo" << endl;
        pause();
        return;
    }


    const char _vClaustro[4][15] = {"Docente","Alumno","No Docente","Graduado"};

    while(fread(&jugador, sizeof(jugador),1,archivo) == 1){

        borrarPantalla();
        encabezado("LISTANDO JUGADORES");
        colorTexto(15);

        if(jugador.getEstado()){
            cout << "DNI: " << jugador.getDNI() << endl;
            cout << "NOMBRE: " << jugador.getNombre() << endl;
            cout << "APELLIDO: " << jugador.getApellido() << endl;
            cout << "EMAIL: " << jugador.getEmail() << endl;
            cout << "TELEFONO: " << jugador.getTelefono() << endl;
            cout << "CLAUSTRO: " << _vClaustro[jugador.getClaustro()] << endl;
            cout << "DEPORTE: " << jugador.getNumeroDeEquipo() << endl;
            cout << "FECHA DE INSCRIPCION: " << jugador.getFechaDeIncripcion().getDia() << "/" << jugador.getFechaDeIncripcion().getMes() << "/" << jugador.getFechaDeIncripcion().getAnio() << endl;
            cout << "MATRICULA: " << jugador.getMatricula() << endl;

            pause();
        }
    }

    fclose(archivo);

}
/// MODIFICA LA FECHA DE INSCRIPCION
void Jugador::modificarFechaIngreso(){}


///REALIZA LA BAJA LOGICA DE UN JUGADOR POR SU DNI
void Jugador::eliminarJugador(){

    FILE * archivo;
    if( (archivo = fopen("files/Jugadores.dat","rb+")) == NULL)
    {
        cerr << "\nError Al Abrir El Archivo" << endl;
        pause();
        return;
    }

    Jugador jugador;
    bool encontrado = false;
    int _DNI;

    borrarPantalla();
    encabezado("BORRANDO JUGADOR");
    colorTexto(15);

    cout << "Ingrese el DNI del Jugador: ";
    cin >> _DNI;

    while(fread(&jugador, sizeof(jugador),1,archivo) == 1){

        if(jugador.getDNI() == _DNI && jugador.getEstado()){

            jugador.setEstado(false);
            fseek(archivo,  -sizeof(jugador),SEEK_CUR);
            fwrite(&jugador, sizeof(jugador),1,archivo);
            encontrado = true;
            fclose(archivo);
            break;
        }
    }

    if(encontrado) cout << "\n\nBorrado Logico Exitoso" << endl;
    else cout << "\n\nBorrado Logico Fallido, \nEl DNI proporcionado no se encuentra o ya se encuentra dado de baja" << endl;
    pause();
}


///VALIDA SI EL DNI EXISTE EN EL ARCHIVO,  CON O SIN BAJA LOGICA Y LO INFORMA
bool Jugador::existeDNI(int _DNI){

    FILE * archivo;
    if( (archivo = fopen("files/Jugadores.dat","rb")) == NULL)
    {
        cerr << "\nError Al Abrir El Archivo" << endl;
        pause();
        return true;
    }

    Jugador jugador;
    bool encontrado = false;

    while(fread(&jugador, sizeof(jugador),1,archivo) == 1){

        if(jugador.getDNI() == _DNI){

            encontrado = true;

            if(jugador.getEstado()){
                cout << "\n\nDNI Duplicado" << endl;
            }else{
                cout << "\n\nDNI Encontrado en un Jugador dado de Baja" << endl;
            }

            pause();
            break;
        }
    }

    fclose(archivo);
    return encontrado;
}


#endif // CJUGADOR_H
