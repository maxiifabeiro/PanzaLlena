#ifndef FUNCIONESCLIENTES_H_INCLUDED
#define FUNCIONESCLIENTES_H_INCLUDED

int numeroAutomaticoCliente(){
    Cliente obj;
    ArchivoClientes arcCli("clientes.dat");
    int i, num = 1;
    int cantCli = arcCli.contarRegistrosClientes();

        for(i = 1; i <= cantCli; i++){
            obj = arcCli.leerRegistroClientes(i);
            num++;
        }
    return num;
}


void listarClientes(){
    ArchivoClientes arcCli;
    arcCli.listarArchivoClientes();
}


void altaClientes(){
    ArchivoClientes arcCli("clientes.dat");
    Cliente obj;
    obj.Cargar();
    int pos=arcCli.buscarRegistroClientes(obj.getNumeroCliente());
    if(pos >= 0){
        cout<<"YA EXISTE ESE NUMERO DE CLIENTE EN EL ARCHIVO"<<endl;
        obj.setEstado(false);
    }
    if(obj.getEstado()==true){
        if(arcCli.grabarRegistroClientes(obj)){
        cout<<"EL REGISTRO FUE GRABADO CON EXITO"<<endl;
        }else{
        cout<<"NO SE PUDO GRABAR EL REGISTRO"<<endl;
        }
}
}
void modificarRegistroTelefonoClientes() {
    ArchivoClientes arcCli("clientes.dat");
    int num;
    cout << "INGRESE EL NUMERO DE CLIENTE A MODIFICAR: ";
    cin >> num;
    int pos = arcCli.buscarRegistroClientes(num);
    if (pos < 0) {
        cout << "EL NUMERO INGRESADO NO EXISTE EN EL ARCHIVO" << endl;
        return;
    }
    Cliente* obj = new Cliente;
    *obj = arcCli.leerRegistroClientes(pos);

    char nuevoTelefono[15];

    cout << "INGRESE EL NUEVO NUMERO DE TELEFONO: ";
    cargarCadena (nuevoTelefono, 14);
    obj->setTelefono(nuevoTelefono);

    if (arcCli.modificarRegistroClientes(*obj, pos)) {
     cout << "MODIFICADO CON EXITO" << endl;
    } else {
        cout << "NO PUDO SER MODIFICADO" << endl;
    }

    delete obj;
}


void bajaLogicaCliente(){
    ArchivoClientes arcCli;
    int num;
    cout << "INGRESE EL NUMERO DE CLIENTE A DAR DE BAJA: ";
    cin >> num;
    int pos = arcCli.buscarRegistroClientes(num);
    if (pos < 0) {
        cout << "EL NUMERO INGRESADO NO FUE ENCONTRADO" << endl;
        return;
    }
    Cliente obj;
    obj = arcCli.leerRegistroClientes(pos);
    obj.Mostrar();
    cout << "¿DESEA BORRAR EL REGISTRO? (S/N): ";
    char respuesta;
    cin >> respuesta;
    if (respuesta == 'S' || respuesta == 's') {
        obj.setEstado(false);

    if (arcCli.modificarRegistroClientes(obj, pos)) {
        cout << "REGISTRO ELIMINADO" << endl;
    } else {
        cout << "NO SE PUDO ELIMINAR EL REGISTRO" << endl;
    }
    }else return;
}

void buscarRegistroCliente(){
    int num;
    cout << "INGRESE EL NUMERO DEL CLIENTE A BUSCAR: ";
    cin >> num;
    system("cls");
    ArchivoClientes arcCli;
    int pos = arcCli.buscarRegistroClientes(num);
    if (pos < 0) {
        cout << "NO EXISTE UN CLIENTE CON ESE NUMERO EN EL ARCHIVO" << endl;
        system("cls");
        return;
    }
    Cliente* obj = new Cliente;
    *obj = arcCli.leerRegistroClientes(pos);
    obj->Mostrar();
    delete obj;
}


#endif // FUNCIONESCLIENTES_H_INCLUDED
