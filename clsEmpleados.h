#ifndef CLSEMPLEADOS_H_INCLUDED
#define CLSEMPLEADOS_H_INCLUDED

int numeroAutomaticoEmpleados();

class Empleados{
    private:
        int idEmpleado;
        char nombre[30];
        char apellido[30];
        int dni;
        char telefono[15];
        Fecha fechaContratacion;
        char email[30];
        bool estado;
    public:
        Empleados();
        void setIdEmpleado(int num){idEmpleado=num;}
        void setNombre(const char* n) { strcpy(nombre, n); }
        void setApellido(const char* a){strcpy(apellido,a);}
        void setDni(int d){dni=d;}
        void setTelefono(const char * t){strcpy(telefono, t);}
        void setFechaContratacion(Fecha f){fechaContratacion=f;}
        void setEmail(const char* em){strcpy(email,em);}
        void setEstado(bool e){estado = e;}

        int getIdEmpleado(){return idEmpleado;}
        const char* getNombre() { return nombre; }
        const char* getApellido() { return apellido; }
        int getDni(){return dni;}
        const char* getTelefono(){return telefono;}
        Fecha getFechaContratacion(){return fechaContratacion;}
        const char* getEmail() { return email; }
        bool getEstado(){return estado;}

        void Cargar();
        void Mostrar();
};

Empleados::Empleados(){estado=false;}

void Empleados::Cargar(){
    idEmpleado=numeroAutomaticoEmpleados();
    cout<<"NUMERO DE EMPLEADO: "<<idEmpleado<<endl;
    cout<<"INGRESE NOMBRE DEL EMPLEADO: ";
    cargarCadena(nombre,29);
    cout<<"INGRESE APELLIDO DEL EMPLEADO: ";
    cargarCadena(apellido,29);
    cout<<"INGRESE NUMERO DE DNI DEL EMPLEADO: ";
    cin>>dni;
    if(dni < 1)
    {
    cout<<"DNI INVALIDO";
    return;
    }
    cout<<"INGRESE NUMERO DE TELEFONO: ";
    cargarCadena(telefono, 14);
    cout<<"INGRESE FECHA DE CONTRATACION: "<<endl;
    if (fechaContratacion.Cargar() == false) {
        cout << "INTERRUPCION DE CARGA POR FECHA INVALIDA" << endl;
        return;
    }else {cout << "FECHA VALIDA, CONTINUE LA CARGA" << endl;}
    cout<<"INGRESE EMAIL DEL EMPLEADO: "<<endl;
    cargarCadena(email,29);

    estado = true;
}

void Empleados::Mostrar(){
    if(estado==true){
        cout<<"ID DE EMPLEADO: "<<idEmpleado<<endl;
        cout<<"NOMBRE DEL EMPLEADO: "<<nombre<<endl;
        cout<<"APELLIDO DEL EMPLEADO: "<<apellido<<endl;
        cout<<"NUMERO DE DNI: "<<dni<<endl;
        cout<<"NUMERO DE TELEFONO DEL EMPLEADO: "<<telefono<<endl;
        cout<<"FECHA DE CONTRATACION: ";
        fechaContratacion.Mostrar();
        cout<<"EMAIL DEL EMPLEADO: "<<email<<endl;
    }
}


#endif // CLSEMPLEADOS_H_INCLUDED
