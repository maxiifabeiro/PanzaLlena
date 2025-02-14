#ifndef CLSCLIENTE_H_INCLUDED
#define CLSCLIENTE_H_INCLUDED

int numeroAutomaticoCliente();

class Cliente{
    private:
        int numeroCliente;
        char nombre[30];
        char apellido[30];
        char telefono[15];
        int dni;
        char direccion[30];
        bool estado;
    public:
        Cliente();

        void setNumeroCliente(int num){numeroCliente = num;}
        void setNombre(const char* n) { strcpy(nombre, n); }
        void setApellido(const char* a){strcpy(apellido,a);}
        void setTelefono(const char* t){strcpy(telefono,t); }
        void setDni(int ndni){dni = ndni;}
        void setDireccion(const char *direc){strcpy(direccion,direc);}
        void setEstado(bool e){estado = e;}

        int getNumeroCliente(){return numeroCliente;}
        const char* getNombre() { return nombre; }
        const char* getApellido() { return apellido; }
        const char* getTelefono(){ return telefono; }
        int getDni(){return dni;}
        const char* getDireccion(){return direccion;}
        bool getEstado(){ return estado; }


        bool operator==(const Cliente& otro) const {
            return numeroCliente == otro.numeroCliente &&
               strcmp(nombre, otro.nombre) == 0 &&
               strcmp(apellido, otro.apellido) == 0 &&
               strcmp(telefono, otro.telefono) == 0 &&
               dni == otro.dni &&
               strcmp(direccion, otro.direccion) == 0 &&
               estado == otro.estado;
        }

        void Cargar();
        void Mostrar();
};

Cliente::Cliente(){estado=false;}

void Cliente::Cargar(){
    numeroCliente=numeroAutomaticoCliente();
    cout<<"INGRESE NUMERO DE CLIENTE: "<<numeroCliente<<endl;
    cout<<"INGRESE NOMBRE DEL CLIENTE: ";
    cargarCadena(nombre,29);
    cout<<"INGRESE APELLIDO DEL CLIENTE: ";
    cargarCadena(apellido,29);
    cout<<"INGRESE NUMERO DE TELEFONO DEL CLIENTE: ";
    cargarCadena(telefono,14);
    cout<<"INGRESE DNI: ";
    cin>>dni;
    if(dni < 1)
    {
    cout<<"DNI INVALIDO";
    return;
    }
    cout<<"INGRESE DIRECCION: ";
    cargarCadena(direccion,29);

    estado = true;
}

void Cliente::Mostrar(){
    if(estado==true){
        cout<<"NUMERO DEL CLIENTE :"<<numeroCliente<<endl;
        cout<<"NOMBRE DEL CLIENTE: "<<nombre<<endl;
        cout<<"APELLIDO DEL CLIENTE: "<<apellido<<endl;
        cout<<"NUMERO DE TELEFONO DEL CLIENTE: "<<telefono<<endl;
        cout<<"NUMERO DE DNI: "<<dni<<endl;
        cout<<"DIRECCION: "<<direccion<<endl;
    }
}


#endif // CLSCLIENTE_H_INCLUDED
