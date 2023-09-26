#ifndef CARCHIVO_H_INCLUDED
#define CARCHIVO_H_INCLUDED


template <typename T>

class Archivo{

private:
    char rutaArchivo[30];
public:
    ///CONSTRUCTOR
    Archivo(const char *_rutaArchivo){ strcpy(rutaArchivo, _rutaArchivo); }

    ///GETTERS
    char* getRutaArchivo(){ return rutaArchivo; }


    ///SETTERS
    void setRuta(const char _ruta){ rutaArchivo = _ruta; }


    ///METODOS
    void escribirArchivo(T& objeto){

        FILE* archivo;

        if( (archivo = fopen(getRutaArchivo(),"ab")) == NULL)
        {
            cerr << "\nError Al Abrir El Archivo" << endl;
            pause();
            return;
        }

        fwrite(&objeto, sizeof(T),1,archivo);
        fclose(archivo);
    }
};

#endif // CARCHIVO_H_INCLUDED
