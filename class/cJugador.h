#ifndef CJUGADOR_H
#define CJUGADOR_H

#include "cFecha.h"
#include "cDeporte.h"
#include "cArchivoJugador.h"

class Jugador
{
private:
    int DNI;
    char nombre[30];
    char apellido[30];
    char email[30];
    char telefono[30];
    int claustro; //(1: docente; 2 alumno; 3 no docente; 4 graduado)
    int deporte;
    int numeroDeEquipo;
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

    bool validarDNI(int _DNI);
    bool validarQueExistaDNI(int _DNI);
    bool validarClaustro(int _claustro);
    bool validarMatricula(int _matricula);

};

class ArchivoJugador{

private:
    char rutaArchivo[30];
public:
    ///CONSTRUCTOR
    ArchivoJugador(const char *_rutaArchivo){ strcpy(rutaArchivo, _rutaArchivo); }

    ///GETTERS
    const char* getRutaArchivo(){ return rutaArchivo; }


    ///SETTERS
    void setRuta(const char* _ruta){ strcpy(rutaArchivo, _ruta); }


    ///METODOS
    void escribirArchivo(Jugador jugador){

        FILE *archivo;

        if( (archivo = fopen(getRutaArchivo(),MODO_APPEND_B)) == NULL)
        {
            cerr << "\nError Al Abrir El Archivo" << endl;
            pause();
            exit(1);
        }

        fwrite(&jugador, sizeof(jugador),1,archivo);
        fclose(archivo);
    }
};

Jugador::Jugador(bool _estado = true) { estado = _estado; }


/// AGREGA UN JUGADOR AL ARCHIVO
void Jugador::agregarJugador(void)
{

    borrarPantalla();
    encabezado("CARGANDO JUGADORES");


    int tmpDNI;
    char tmpNombre[30];
    char tmpApellido[30];
    char tmpEmail[30];
    char tmpTelefono[30];
    int tmpClaustro;
    int tmpDeporte;
    int tmpNumeroDeEquipo;
    int _dia, _mes, _anio;
    float tmpMatricula;
    Deporte tmpDep;
    Fecha fecha;

    bool salir;



    do{
        cout << "Ingrese el DNI: ";
        cin >> tmpDNI;
    }while(continuar(3,validarDNI(tmpDNI), &salir));
    if(salir) return;


    cin.ignore();
    cout << "Ingrese el nombre: ";
    cin.getline(tmpNombre,30);
    cout << "Ingrese el apellido: ";
    cin.getline(tmpApellido,30);
    cout << "Ingrese el email: ";
    cin.getline(tmpEmail,30);
    cout << "Ingrese el telefono: ";
    cin.getline(tmpTelefono,30);


    do{
        cout << "Ingrese el Nro de claustro: ";
        cin >> tmpClaustro;
    }while(continuar(8,validarClaustro(tmpClaustro), &salir));
    if(salir) return;


    do{
        cout << "Ingrese el Nro de deporte: ";
        cin >> tmpDeporte;
    }while(continuar(9,tmpDep.validarDeporte(tmpDeporte), &salir));
    if(salir) return;


    cout << "Ingrese el Nro de equipo: ";
    cin >> tmpNumeroDeEquipo;


    do{
        cout << "Ingrese fecha de incripcion dia, mes, a" << char(164)<<"o: "; cin >> _dia;
        gotoxy ( 45, 11 ); cout << " / "; cin >> _mes;
        gotoxy ( 50, 11 ); cout << " / "; cin >> _anio;
    }while(continuar(11,fecha.validarFecha(_dia, _mes, _anio), &salir));
    if(salir) return;



    do{
        cout << "Ingrese matricula $: ";
        cin >> tmpMatricula;
    }while(continuar(12,validarMatricula(tmpMatricula), &salir));
    if(salir) return;

    Jugador jugador;

    ///SETEOS
    jugador.setDNI(tmpDNI);
    jugador.setNombre(tmpNombre);
    jugador.setApellido(tmpApellido);
    jugador.setEmail(tmpEmail);
    jugador.setTelefono(tmpTelefono);
    jugador.setClaustro(tmpClaustro);
    jugador.setDeporte(tmpDeporte);
    jugador.setNumeroDeEquipo(tmpNumeroDeEquipo);
    jugador.setFechaDeIncripcion(_dia, _mes, _anio);
    jugador.setMatricula(tmpMatricula);

    ArchivoJugador archivo(RUTA_JUGADORES);
    archivo.escribirArchivo(jugador);

}

///LISTAR JUGADOR POR DNI
void Jugador::listarJugadorPorDNI()
{

    FILE * archivo;
    Jugador jugador;
    int _DNI;
    bool salir = false;

    if( (archivo = fopen(RUTA_JUGADORES,MODO_LECTURA_B)) == NULL)
    {
        cerr << "\nError Al Abrir El Archivo" << endl;
        pause();
        exit(1);
    }


    borrarPantalla();
    encabezado("LISTANDO JUGADOR");

    do{
        cout << "Ingrese el DNI del Jugador: ";
        cin >> _DNI;
        cout << "\n";
    }while(continuar(3,validarQueExistaDNI(_DNI), &salir));
    if(salir) {fclose(archivo); return;}



    const char _vClaustro[4][15] = {"Docente","Alumno","No Docente","Graduado"};

    while(fread(&jugador, sizeof(jugador),1,archivo) == 1){

        if(jugador.getEstado() && jugador.getDNI() == _DNI){

            cout << "DNI: " << jugador.getDNI() << endl;
            cout << "NOMBRE: " << jugador.getNombre() << endl;
            cout << "APELLIDO: " << jugador.getApellido() << endl;
            cout << "EMAIL: " << jugador.getEmail() << endl;
            cout << "TELEFONO: " << jugador.getTelefono() << endl;
            cout << "CLAUSTRO: " << "(" << jugador.getClaustro() << ") " << _vClaustro[jugador.getClaustro() -1] << endl;
            cout << "DEPORTE: " << jugador.getDeporte() << endl;
            cout << "NUMERO DE EQUIPO: " << jugador.getNumeroDeEquipo() << endl;
            cout << "FECHA DE INSCRIPCION: " << jugador.getFechaDeIncripcion().getDia() << "/" << jugador.getFechaDeIncripcion().getMes() << "/" << jugador.getFechaDeIncripcion().getAnio() << endl;
            cout << "MATRICULA: " << jugador.getMatricula() << "$" <<endl;
            break;
        }
    }
    fclose(archivo);
}


///MOSTRAR TODOS LOS JUGADORES
void Jugador::listarJugadores(){

    FILE * archivo;
    Jugador jugador;
    Deporte deporte;


    if( (archivo = fopen(RUTA_JUGADORES,MODO_LECTURA_B)) == NULL)
    {
        cerr << "\n\nError Al Abrir El Archivo" << endl;
        pause();
        exit(1);
    }


    const char _vClaustro[4][15] = {"Docente","Alumno","No Docente","Graduado"};

    while(fread(&jugador, sizeof(jugador),1,archivo) == 1){

        borrarPantalla();
        encabezado("LISTANDO JUGADORES");


        if(jugador.getEstado()){
            cout << "DNI: " << jugador.getDNI() << endl;
            cout << "NOMBRE: " << jugador.getNombre() << endl;
            cout << "APELLIDO: " << jugador.getApellido() << endl;
            cout << "EMAIL: " << jugador.getEmail() << endl;
            cout << "TELEFONO: " << jugador.getTelefono() << endl;
            cout << "CLAUSTRO: " << "(" << jugador.getClaustro() << ") " << _vClaustro[jugador.getClaustro() -1] << endl;
            cout << "DEPORTE: " << jugador.getDeporte() << endl;
            cout << "NUMERO DE EQUIPO: " << jugador.getNumeroDeEquipo() << endl;
            cout << "FECHA DE INSCRIPCION: " << jugador.getFechaDeIncripcion().getDia() << "/" << jugador.getFechaDeIncripcion().getMes() << "/" << jugador.getFechaDeIncripcion().getAnio() << endl;
            cout << "MATRICULA: " << jugador.getMatricula() << "$" << endl;

            pause();
        }
    }

    fclose(archivo);

}


/// MODIFICA LA FECHA DE INSCRIPCION
void Jugador::modificarFechaIngreso()
{
    FILE * archivo;
    if( (archivo = fopen(RUTA_JUGADORES,MODO_LEC_ESC_B)) == NULL)
    {
        cerr << "\n\nError Al Abrir El Archivo" << endl;
        pause();
        exit(1);
    }

    Jugador jugador;
    Fecha fecha;

    bool encontrado = false;
    int _DNI, _dia, _mes, _anio;
    bool salir = false;

    borrarPantalla();
    encabezado("CAMBIANDO FECHA DE INGRESO");

    do{
        cout << "Ingrese el DNI del Jugador: ";
        cin >> _DNI;
    }while(continuar(3,validarQueExistaDNI(_DNI), &salir));
    if(salir) {fclose(archivo); return;}


    while(fread(&jugador, sizeof(jugador),1,archivo) == 1){

        if(jugador.getDNI() == _DNI && jugador.getEstado())
        {
            do{
                cout << "Ingrese fecha de incripcion dia, mes, a" << char(164)<<"o: ";
                cin >> _dia;
                gotoxy ( 45, 4 ); cout << " / "; cin >> _mes;
                gotoxy ( 50, 4 ); cout << " / "; cin >> _anio;
            }while(continuar(4,fecha.validarFecha(_dia, _mes, _anio), &salir));
            if(salir) {fclose(archivo); return;}


            jugador.setFechaDeIncripcion(_dia, _mes, _anio);
            fseek(archivo, ftell(archivo) - sizeof(jugador),SEEK_SET);
            fwrite(&jugador, sizeof(jugador),1,archivo);
            encontrado = true;
            break;
        }
    }
    fclose(archivo);
    gotoxy(0,15);
    if(encontrado) cout << "Modificacion Exitosa" << endl;
    else cout << "Modificacion Fallida, \nEl DNI proporcionado no se encuentra o se encuentra dado de baja" << endl;
}


///REALIZA LA BAJA LOGICA DE UN JUGADOR POR SU DNI
void Jugador::eliminarJugador()
{

    FILE * archivo;
    if( (archivo = fopen(RUTA_JUGADORES,MODO_LEC_ESC_B)) == NULL)
    {
        cerr << "\n\nError Al Abrir El Archivo" << endl;
        pause();
        exit(1);
    }

    Jugador jugador;
    bool encontrado = false;
    int _DNI;
    bool salir;

    borrarPantalla();
    encabezado("BORRANDO JUGADOR");


    do{
        cout << "Ingrese el DNI del Jugador: ";
        cin >> _DNI;
    }while(continuar(3,validarQueExistaDNI(_DNI), &salir));
    if(salir) {fclose(archivo); return;}

    while(fread(&jugador, sizeof(jugador),1,archivo) == 1){

        if(jugador.getDNI() == _DNI && jugador.getEstado()){

            jugador.setEstado(false);
            fseek(archivo, ftell(archivo) - sizeof(jugador), SEEK_SET);
            fwrite(&jugador, sizeof(jugador),1,archivo);
            encontrado = true;
            break;
        }
    }
    fclose(archivo);
    if(encontrado) cout << "\n\nBorrado Logico Exitoso" << endl;
    else cout << "\n\nBorrado Logico Fallido, \nEl DNI proporcionado no se encuentra o ya se encuentra dado de baja" << endl;
    pause();
}


///VALIDA SI EL DNI EXISTE EN EL ARCHIVO,  CON O SIN BAJA LOGICA Y LO INFORMA
bool Jugador::validarDNI(int _DNI){

    FILE * archivo;
    if( (archivo = fopen(RUTA_JUGADORES,MODO_APP_LEC_B)) == NULL)
    {
        cerr << "\n\nError Al Abrir El Archivo" << endl;
        pause();
        exit(1);
    }

    Jugador jugador;
    bool valida = true;

    while(fread(&jugador, sizeof(jugador),1,archivo) == 1){

        if(jugador.getDNI() == _DNI){

            valida = false;

            if(jugador.getEstado()){
                gotoxy(0,15);
                cout << "DNI Duplicado" << endl;
            }else{
                gotoxy(0,15);
                cout << "DNI Encontrado en un Jugador dado de Baja" << endl;
            }

            break;
        }
    }

    fclose(archivo);
    return valida;
}


/// VALIDA QUE EXISTA PARA LA MODIFICACION DE FECHA DE INGRESO
bool Jugador::validarQueExistaDNI(int _DNI){

    FILE * archivo;
    if( (archivo = fopen(RUTA_JUGADORES,MODO_APP_LEC_B)) == NULL)
    {
        cerr << "\n\nError Al Abrir El Archivo" << endl;
        pause();
        exit(1);
    }

    Jugador jugador;

    while(fread(&jugador, sizeof(jugador),1,archivo) == 1){


        if(jugador.getDNI() == _DNI)
        {

            if(jugador.getEstado()){
                fclose(archivo);
                return true;
            }
            else
            {
                gotoxy(0,15);
                cout << "DNI Encontrado en un Jugador dado de Baja" << endl;
                fclose(archivo);
                return false;

            }
        }
    }
    gotoxy(0,15);
    cout << "DNI no Encontrado" << endl;
    fclose(archivo);
    return false;
}

/// VALIDA EL CLAUSTRO
bool Jugador::validarClaustro(int _claustro){
    if(_claustro >= 1 && _claustro <= 4) return true;
    else{
        gotoxy(0,15);
        cout << "Solo se admiten valores de 1 a 4" << endl;
        return false;
    }
}


/// VALIDA EL MATRICULA
bool Jugador::validarMatricula(int _matricula){
    if(_matricula >= 0) return true;
    else {
        gotoxy(0,15);
        cout << "Solo se admite valor 0 o mayor a 0" << endl;
        return false;
    }
}




#endif // CJUGADOR_H
