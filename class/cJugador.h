#ifndef CJUGADOR_H
#define CJUGADOR_H

#include "cFecha.h"

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
    Jugador();
    ~Jugador();

    ///GETTERS
    int getDNI(){return DNI;}
    char getNombre() const {return *nombre;}
    char getApellido() const {return *apellido;}
    char getEmail() const {return *email;}
    char getTelefono() const {return *telefono;}
    int getClaustro() const {return claustro;}
    int getDeporte() const {return deporte;}
    int getNumeroDeEquipo() const {return numeroDeEquipo;}
    Fecha getFechaDeIngreso() const {return fechaDeIncripcion;}
    float getMatricula() const {return matricula;}
    bool getEstado() const {return estado;}

    ///SETTERS
    void setDNI(int _DNI){ DNI = _DNI; }
    void setNombre(char *_nombre){ strcpy(nombre , _nombre); }
    void setApellido(char *_apellido){ strcpy(apellido , _apellido); }
    void setEmail(char *_email){ strcpy(email , _email); }
    void setTelefono(char *_telefono){ strcpy(telefono , _telefono); }
    void setClaustro(int _claustro){claustro = _claustro;}
    void setDeporte(int _deporte){deporte = _deporte;}
    void setNumeroDeEquipo(int _numeroDeEquipo){ numeroDeEquipo = _numeroDeEquipo; }
    //void setFechaDeIngreso(int _dia, int _mes, int _anio){}
    void setMatricula(float _matricula){ matricula = _matricula; }
    void setEstado(bool _estado){ estado = _estado; }

    ///METODOS
    void agregarJugador(void);
    void listarJugadorPorDNI(void);
    void listarJugadores(void);
    void modificarFechaIngreso(void);
    void eliminarJugador(void);

};


void Jugador::agregarJugador(void){

}


void Jugador::listarJugadorPorDNI(){}

void Jugador::listarJugadores(){}

void Jugador::modificarFechaIngreso(){}

void Jugador::eliminarJugador(){}


#endif // CJUGADOR_H
