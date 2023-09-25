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
    bool escribirArchivo(const char _rutaArchivo, T& objeto){
        FILE* archivo = fopen(_rutaArchivo,"ab");
         if(archivo == NULL) {
            cout << "Error al abrir el Archivo" << endl;
            return false;
        }

        fwrite(&objeto, sizeof(T),1,archivo);
        fclose(archivo);
        return true;
    }

    bool leerArchivo(const char _rutaArchivo, T& objeto){
        FILE* archivo = fopen(_rutaArchivo,"rb");
        if(archivo == NULL) {
            cout << "Error al abrir el Archivo" << endl;
            return false;
        }

        fread(&objeto, sizeof(T),1,archivo);
        fclose(archivo);
        return true;
    }
};

#endif // CARCHIVO_H_INCLUDED
