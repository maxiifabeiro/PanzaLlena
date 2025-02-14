#ifndef FUNCIONESCARTA_H_INCLUDED
#define FUNCIONESCARTA_H_INCLUDED

void listarCarta(){
    ArchivoCarta arcCar;
    arcCar.listarArchivoCarta();
}


void altaCarta(){
    ArchivoCarta arcCar("carta.dat");
    Carta obj;
    obj.Cargar();
    int pos=arcCar.buscarRegistroCarta(obj.getIdCarta());
    if(pos >= 0){
        cout<<"YA EXISTE UN PLATO CON ESA ID EN EL ARCHIVO"<<endl;
        obj.setEstado(false);
    }
    if(obj.getEstado()==true){
        if(arcCar.grabarRegistroCarta(obj)){
            cout<<"EL REGISTRO FUE GRABADO CON EXITO"<<endl;
        }else{
        cout<<"NO SE PUDO GRABAR EL REGISTRO"<<endl;
        }
}
}
void modificarCarta(){
    ArchivoCarta arcCar("carta.dat");
    int num;
    cout << "INGRESE EL ID DEL PLATO A MODIFICAR: ";
    cin >> num;
    int pos = arcCar.buscarRegistroCarta(num);
    if (pos < 0) {
        cout << "EL ID DEL PLATO NO EXISTE EN EL ARCHIVO" << endl;
        return;
    }
    Carta* obj = new Carta;
    *obj = arcCar.leerRegistroCarta(pos);

    double nuevoPrecio;
    cout << "INGRESE EL NUEVO IMPORTE DEL PRODUCTO: $";
    cin >> nuevoPrecio;
    obj->setPrecio(nuevoPrecio);
    if (arcCar.modificarRegistroCarta(*obj, pos)) {
        cout << "MODIFICADO CON EXITO" << endl;
    } else {
        cout << "NO PUDO SER MODIFICADO" << endl;
    }

    delete obj;
}

void bajaLogicaCarta(){
    ArchivoCarta arcCar;
    Carta obj;
    int num;
    cout << "INGRESE EL ID DEL PRODUCTO A DAR DE BAJA: ";
    cin >> num;
    int pos = arcCar.buscarRegistroCarta(num);
    if (pos < 0) {
        cout << "EL ID INGRESADO NO FUE ENCONTRADO" << endl;
        return;
    }
    obj = arcCar.leerRegistroCarta(pos);
    obj.Mostrar();
    cout << "¿DESEA BORRAR EL REGISTRO? (S/N): ";
    char respuesta;
    cin >> respuesta;
    if (respuesta == 'S' || respuesta == 's') {
        obj.setEstado(false);
    if (arcCar.modificarRegistroCarta(obj, pos)) {
        cout << "REGISTRO ELIMINADO CON EXITO" << endl;
    } else {
        cout << "NO SE PUDO ELIMINAR EL REGISTRO" << endl;
    }
    }else return;
}

void buscarRegistroCarta(){
    int num;
    cout << "INGRESE EL ID DEL PLATO A BUSCAR: ";
    cin >> num;
    system("cls");
    ArchivoCarta arcCar;
    int pos = arcCar.buscarRegistroCarta(num);
    if (pos < 0) {
        cout << "NO EXISTE ESE ID PLATO EN EL ARCHIVO" << endl;
        system("cls");
        return;
    }
    Carta* obj = new Carta;
    *obj = arcCar.leerRegistroCarta(pos);
    obj->Mostrar();
    delete obj;
}

#endif // FUNCIONESCARTA_H_INCLUDED
