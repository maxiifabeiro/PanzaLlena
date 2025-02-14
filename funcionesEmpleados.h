#ifndef FUNCIONESEMPLEADOS_H_INCLUDED
#define FUNCIONESEMPLEADOS_H_INCLUDED

int numeroAutomaticoEmpleados(){
    Empleados obj;
    ArchivoEmpleados arcEmp("empleados.dat");
    int i, num = 1;
    int cantEmp = arcEmp.contarRegistrosEmpleados();

        for(i = 1; i <= cantEmp; i++){
            obj = arcEmp.leerRegistroEmpleados(i);
            num++;
        }
    return num;
}


void listarEmpleados(){
    ArchivoEmpleados arcEmp;
    arcEmp.listarArchivoEmpleados();
}


void altaEmpleados(){
    ArchivoEmpleados arcEmp("empleados.dat");
    Empleados obj;
    obj.Cargar();
    int pos=arcEmp.buscarRegistroEmpleados(obj.getIdEmpleado());
    if(pos >= 0){
        cout<<"YA EXISTE UN EMPLEADO CON ESE NUMERO EN EL ARCHIVO"<<endl;
        obj.setEstado(false);
    }
    if(obj.getEstado()==true){
        if(arcEmp.grabarRegistroEmpleados(obj)){
       cout<<"EL REGISTRO FUE GRABADO CON EXITO"<<endl;
        }else{
        cout<<"NO SE PUDO GRABAR EL REGISTRO"<<endl;
        }
}
}
void modificarRegistroEmailEmpleado() {
    ArchivoEmpleados arcEmp("empleados.dat");
    int num;
    cout << "INGRESE EL NUMERO DE EMPLEADO A MODIFICAR: ";
    cin >> num;
    int pos = arcEmp.buscarRegistroEmpleados(num);
    if (pos < 0) {
        cout << "EL NUMERO INGRESADO NO EXISTE EN EL ARCHIVO" << endl;
        return;
    }
    Empleados* obj = new Empleados;
    *obj = arcEmp.leerRegistroEmpleados(pos);

    char nuevoEmail[50];
    cout << "INGRESE EL NUEVO EMAIL: ";
    cargarCadena(nuevoEmail, 49);
    obj->setEmail(nuevoEmail);

    if (arcEmp.modificarRegistroEmpleados(*obj, pos)) {
        cout << "MODIFICADO CON EXITO" << endl;
    } else {
        cout << "NO PUDO SER MODIFICADO" << endl;
    }

    delete obj;
}

void bajaLogicaEmpleados() {
    ArchivoEmpleados arcEmp;
    Empleados obj;
    int num;
    cout << "INGRESE EL NUMERO DE EMPLEADO A DAR DE BAJA: ";
    cin >> num;
    int pos = arcEmp.buscarRegistroEmpleados(num);
    if (pos < 0) {
        cout << "EL NUMERO INGRESADO NO FUE ENCONTRADO" << endl;
        return;
    }
    obj = arcEmp.leerRegistroEmpleados(pos);
    obj.Mostrar();
    cout << "¿DESEA BORRAR EL REGISTRO? (S/N): ";
    char respuesta;
    cin >> respuesta;
    if (respuesta == 'S' || respuesta == 's') {
        obj.setEstado(false);

    if (arcEmp.modificarRegistroEmpleados(obj, pos)) {
        cout << "REGISTRO ELIMINADO" << endl;
    } else {
        cout << "NO SE PUDO ELIMINAR EL REGISTRO" << endl;
    }
    }else return;
}

void buscarRegistroEmpleados() {
    int num;
    cout << "INGRESE EL NUMERO DEL EMPLEADO A BUSCAR: ";
    cin >> num;
    system("cls");
    ArchivoEmpleados arcEmp;
    int pos = arcEmp.buscarRegistroEmpleados(num);
    if (pos < 0) {
        cout << "NO EXISTE UN EMPLEADO CON ESE NUMERO EN EL ARCHIVO" << endl;
        system("cls");
        return;
    }
    Empleados* obj = new Empleados;
    *obj = arcEmp.leerRegistroEmpleados(pos);
    obj->Mostrar();
    delete obj;
}
#endif // FUNCIONESEMPLEADOS_H_INCLUDED
